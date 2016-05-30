#include <stdlib.h>
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

// serial dependencies
#include <avr/pgmspace.h>
#include <stdint.h>

#include "usb_keyboard.h"
#include "print.h"


#define DEBOUNCE_PASSES 10

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))


// Layout setup

void reset(void);

// set this for layer changes that need to persist beyond one cycle
int current_layer_number = 0;
// this gets reset every cycle
int *current_layer;

#define ROW_COUNT 15
#define COL_COUNT 7
#define KEY_COUNT ROW_COUNT*COL_COUNT

int pressed_count = 0;
int presses[KEY_COUNT];
int last_pressed_count = 0;
int last_presses[KEY_COUNT];

#define CTRL(key)   (0x1000 + (key))
#define SHIFT(key)  (0x2000 + (key))
#define ALT(key)    (0x4000 + (key))
#define GUI(key)    (0x8000 + (key))

/* LAYERS and FUNCTIONS are pessimistic, there's 4095 unused numbers between
 * the USB_MAX_KEY and the CTRL mask bit.  */
#define LAYERS 64
#define FUNCTIONS 255

#define MIN_LAYER         (USB_MAX_KEY      + 1)
#define MAX_LAYER         (USB_MAX_KEY      + LAYERS)
#define MIN_FUNCTION      (MAX_LAYER        + 1)
#define MAX_FUNCTION      (MAX_LAYER        + FUNCTIONS)
#define MIN_PRE_FUNCTION  (MAX_FUNCTION     + 1)
#define MAX_PRE_FUNCTION  (MAX_FUNCTION     + FUNCTIONS)

#define LAYER(layer)          (MIN_LAYER        + (layer))
#define FUNCTION(number)      (MIN_FUNCTION     + (number))
#define PRE_FUNCTION(number)  (MIN_PRE_FUNCTION + (number))

// layout.h must define:
// * layers: array of int[KEY_COUNT]
// * layer_functions: array of void function pointers
// ... plus any functions included in layer_functions
// per_cycle void function callback
#include "layout.h"


// Matrix scanning logic

void record(int col, int row) {
  presses[pressed_count++] = (row * COL_COUNT) + col;
};

void activate_row(int row) {
  if (row < 8) {
    PORTD = (char)(~(1 << row));
    PORTC = 255;
  } else {
    row = row % 8;
    PORTC = (char)(~(1 << row));
    PORTD = 255;
  }
  _delay_us(50);
};

void scan_row(int row) {
  // hard-coded reset safety-hatch for experimentation
  // if(((~PINF) & 64) && row == 3) reset();
  unsigned int col_bits = (~PINB & 255);
  char str[128];
  for(int col = 0; col < COL_COUNT; col++) {
    if(col_bits & (1 << col)) {
      /* itoa(col, str, 10); */
      /* print("col: "); */
      /* pms_print(str); */
      /* itoa(row, str, 10); */
      /* print(" row: "); */
      /* pms_print(str); */
      /* print("\n"); */

      record(col, row);
    }
  }
};


void scan_rows() {
  pressed_count = 0;
  for(int i = 0; i < ROW_COUNT; i++) {
    activate_row(i);
    scan_row(i);
    /* pms_activate_row(i); */
    /* pms_scan_row(i); */
  };
};

// Cycle functions

void debounce(int passes_remaining) {
  while(passes_remaining) {
    last_pressed_count = pressed_count;
    for(int i = 0; i < last_pressed_count; i++) {
      last_presses[i] = presses[i];
    }

    scan_rows();

    if((pressed_count != last_pressed_count) || \
       memcmp(presses, last_presses, pressed_count)) {
      passes_remaining = DEBOUNCE_PASSES;
    } else {
      passes_remaining--;
    }
  }
};

void pre_invoke_functions() {
  for(int i = 0; i < pressed_count; i++) {
    int keycode = current_layer[presses[i]];
    if(keycode >= MIN_PRE_FUNCTION && keycode <= MAX_PRE_FUNCTION) {
      (layer_functions[keycode - MIN_PRE_FUNCTION])();
    }
  }
  per_cycle();
};

void calculate_presses() {
  int usb_presses = 0;
  char str[128];
  for(int i = 0; i < pressed_count; i++) {
    itoa(presses[i], str, 10);
    print("presses: ");
    pms_print(str);
    print("\n");

    int keycode = current_layer[presses[i]];
    itoa(keycode, str, 10);
    print("keycode: ");
    pms_print(str);
    print("\n");

    itoa(current_layer_number, str, 10);
    print("layer: ");
    pms_print(str);
    print("\n");

    if(keycode >= MIN_FUNCTION && keycode <= MAX_FUNCTION) {
      // regular layout functions
      (layer_functions[keycode - MIN_FUNCTION])();
    } else if(keycode >= MIN_PRE_FUNCTION && keycode <= MAX_PRE_FUNCTION) {
      // pre-invoke functions have already been processed
    } else if(keycode >= MIN_LAYER && keycode <= MAX_LAYER) {
      // layer set
      current_layer_number = keycode - MIN_LAYER;
    } else if(keycode == KEYBOARD_LEFT_CTRL) {
      keyboard_modifier_keys |= KEY_LEFT_CTRL;
    } else if(keycode == KEYBOARD_RIGHT_CTRL) {
      keyboard_modifier_keys |= KEY_RIGHT_CTRL;
    } else if(keycode == KEYBOARD_LEFT_SHIFT) {
      keyboard_modifier_keys |= KEY_LEFT_SHIFT;
    } else if(keycode == KEYBOARD_RIGHT_SHIFT) {
      keyboard_modifier_keys |= KEY_RIGHT_SHIFT;
    } else if(keycode == KEYBOARD_LEFT_ALT) {
      keyboard_modifier_keys |= KEY_LEFT_ALT;
    } else if(keycode == KEYBOARD_RIGHT_ALT) {
      keyboard_modifier_keys |= KEY_RIGHT_ALT;
    } else if(keycode == KEYBOARD_LEFT_GUI) {
      keyboard_modifier_keys |= KEY_LEFT_GUI;
    } else if(keycode == KEYBOARD_RIGHT_GUI) {
      keyboard_modifier_keys |= KEY_RIGHT_GUI;
    } else if(keycode > 255 && usb_presses < 6) {
      // modifier plus keypress
      keyboard_modifier_keys |= (keycode >> 8);
      keyboard_keys[usb_presses++] = (keycode & 255);
    } else if(usb_presses < 6){
      // keypress
      keyboard_keys[usb_presses++] = keycode;
    };
  };
};


// Top level stuff

void init() {
  CPU_PRESCALE(0);
  /* DDRD = 255; // rows */
  /* DDRB = DDRF = 0; // columns */
  /* PORTB = PORTF = 255; // activate pullup resistors on inputs */

  DDRD = DDRC = 255; // columns
  DDRB = 0; // rows
  PORTB = 255; // activate pullup resistors on inputs

  /* pms_init_cols(); */
  usb_init();
  while (!usb_configured()) /* wait */ ;
  _delay_ms(500);
};


void clear_keys() {
  current_layer = layers[current_layer_number];
  keyboard_modifier_keys = 0;
  for(int i = 0; i < 6; i++) {
    keyboard_keys[i] = 0;
  };
};

int main() {
  init();

  while(1) {
    clear_keys();
    debounce(DEBOUNCE_PASSES);
    pre_invoke_functions();
    calculate_presses();
    usb_keyboard_send();
  };
};

void reset(void) {
  UDCON = 1; USBCON = (1<<FRZCLK); UCSR1B = 0;
  _delay_ms(5);
#if defined(__AVR_AT90USB1286__)             // Teensy++ 2.0
  EIMSK = 0; PCICR = 0; SPCR = 0; ACSR = 0; EECR = 0; ADCSRA = 0;
  TIMSK0 = 0; TIMSK1 = 0; TIMSK2 = 0; TIMSK3 = 0; UCSR1B = 0; TWCR = 0;
  DDRA = 0; DDRB = 0; DDRC = 0; DDRD = 0; DDRE = 0; DDRF = 0;
  PORTA = 0; PORTB = 0; PORTC = 0; PORTD = 0; PORTE = 0; PORTF = 0;
  asm volatile("jmp 0x1FC00");
#endif
};
