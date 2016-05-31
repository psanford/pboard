/* int layer0[44] = { */
/*     KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_0, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P,  */
/*     KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_0, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON,  */
/*     KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEYBOARD_LEFT_ALT, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH,  */
/*     KEY_ESC, KEY_TAB, KEYBOARD_LEFT_GUI, KEYBOARD_LEFT_SHIFT, KEY_BACKSPACE, KEYBOARD_LEFT_CTRL, KEY_SPACE, PRE_FUNCTION(1), KEY_MINUS, KEY_QUOTE, KEY_ENTER }; */

#define KEY_PROGRAM LAYER(1)
#define KEY_KEYPAD LAYER(2)

#define LKEY_PROGRAM LAYER(0)
#define LKEY_KEYPAD LAYER(0)

/* #define PMS_INSERT KEY_DUMMY  /\* KEY_INSERT *\/ */
#define PMS_INSERT KEY_ESC  /* KEY_INSERT */
/* #define PMS_RIGHT_SHIFT KEY_ESC /\* KEYBOARD_RIGHT_SHIFT *\/ */

#define PMS_MIDDLE_MOUSE FUNCTION(3)
#define PMS_RIGHT_SHIFT PMS_MIDDLE_MOUSE
#define PMS_RIGHT_ALT  KEY_ESC

#define KEYCOUNT 105

int layer0[KEYCOUNT] = {
/*0*/KEY_EQUAL, KEY_TAB,      KEYBOARD_LEFT_GUI,KEYBOARD_LEFT_SHIFT, KEY_DUMMY,      KEY_DUMMY,          KEY_DUMMY,
/*1*/KEY_1,     KEY_Q,        KEY_A,            KEY_Z,               KEY_TILDE,      KEY_DUMMY,          KEY_DUMMY,
/*2*/KEY_2,     KEY_W,        KEY_S,            KEY_X,               PMS_INSERT,     KEY_END,            KEY_DUMMY,
/*3*/KEY_3,     KEY_E,        KEY_D,            KEY_C,               KEY_LEFT,       KEY_HOME,           KEYBOARD_LEFT_CTRL,
/*4*/KEY_4,     KEY_R,        KEY_F,            KEY_V,               KEY_DUMMY,      KEY_DUMMY,          KEYBOARD_LEFT_ALT,
/*5*/KEY_5,     KEY_T,        KEY_G,            KEY_B,               KEY_RIGHT,      KEY_DELETE,         KEY_BACKSPACE,

/*6*/KEY_6,     KEY_Y,        KEY_H,            KEY_N,               KEY_DOWN,       KEY_SPACE,          KEY_PAGE_DOWN,
/*7*/KEY_7,     KEY_U,        KEY_J,            KEY_M,               KEY_DUMMY,      KEY_ENTER,          KEY_DUMMY,
/*8*/KEY_8,     KEY_I,        KEY_K,            KEY_COMMA,           KEY_UP,         KEYBOARD_RIGHT_CTRL,KEY_PAGE_UP,

/*9*/KEY_9,     KEY_O,        KEY_L,            KEY_PERIOD,          KEY_LEFT_BRACE, KEY_DUMMY,          PMS_RIGHT_ALT,

/*10*/KEY_0,    KEY_P,        KEY_SEMICOLON,    KEY_SLASH,           KEY_RIGHT_BRACE,KEY_DUMMY,          KEY_DUMMY,
/*11*/KEY_MINUS,KEY_BACKSLASH,KEY_QUOTE,        PMS_RIGHT_SHIFT,     KEY_DUMMY,      KEY_DUMMY,          KEY_DUMMY,
/*12*/KEY_ESC,  KEY_F3,       KEY_F6,           KEY_F9,              KEY_F12,        KEY_PAUSE,          KEY_DUMMY,
/*13*/KEY_F1,   KEY_F4,       KEY_F7,           KEY_F10,             KEY_PRINTSCREEN,KEY_PROGRAM,        KEY_DUMMY,
/*14*/KEY_F2,   KEY_F5,       KEY_F8,           KEY_F11,             KEY_SCROLL_LOCK,KEY_KEYPAD,         KEY_DUMMY,
};

int layer1[KEYCOUNT] = {
/*0*/KEY_EQUAL, KEY_TAB,      KEYBOARD_LEFT_GUI,KEYBOARD_LEFT_SHIFT, KEY_DUMMY,      KEY_DUMMY,          KEY_DUMMY,
/*1*/KEY_1,     KEY_Q,        KEY_A,            KEY_Z,               KEY_TILDE,      KEY_DUMMY,          KEY_DUMMY,
/*2*/KEY_2,     KEY_W,        KEY_S,            KEY_X,               PMS_INSERT,     KEY_END,            KEY_DUMMY,
/*3*/KEY_3,     KEY_E,        KEY_D,            KEY_C,               KEY_LEFT,       KEY_HOME,           KEYBOARD_LEFT_CTRL,
/*4*/KEY_4,     KEY_R,        KEY_F,            KEY_V,               KEY_DUMMY,      KEY_DUMMY,          KEYBOARD_LEFT_ALT,
/*5*/KEY_5,     KEY_T,        KEY_G,            KEY_B,               KEY_RIGHT,      KEY_DELETE,         KEY_BACKSPACE,

/*6*/KEY_6,     KEY_Y,        KEY_H,            KEY_N,               KEY_DOWN,       KEY_SPACE,          KEY_PAGE_DOWN,
/*7*/KEY_7,     KEY_U,        KEY_J,            KEY_M,               KEY_DUMMY,      KEY_ENTER,          KEY_DUMMY,
/*8*/KEY_8,     KEY_I,        KEY_K,            KEY_COMMA,           KEY_UP,         KEYBOARD_RIGHT_CTRL,KEY_PAGE_UP,

/*9*/KEY_9,     KEY_O,        KEY_L,            KEY_PERIOD,          KEY_LEFT_BRACE, KEY_DUMMY,          KEYBOARD_RIGHT_ALT,

/*10*/KEY_0,    KEY_P,        KEY_SEMICOLON,    KEY_SLASH,           KEY_RIGHT_BRACE,KEY_DUMMY,          KEY_DUMMY,
/*11*/KEY_MINUS,KEY_BACKSLASH,KEY_QUOTE,        PMS_MIDDLE_MOUSE,    KEY_DUMMY,      KEY_DUMMY,          KEY_DUMMY,
/*12*/KEY_ESC,  KEY_F3,       KEY_F6,           KEY_F9,              KEY_F12,        KEY_PAUSE,          KEY_DUMMY,
/*13*/KEY_F1,   KEY_F4,       KEY_F7,           KEY_F10,             KEY_PRINTSCREEN,LKEY_PROGRAM,       KEY_DUMMY,
/*14*/KEY_F2,   KEY_F5,       FUNCTION(0),      KEY_F11,             KEY_SCROLL_LOCK,LKEY_KEYPAD,        KEY_DUMMY,
};

int layer2[KEYCOUNT] = {
  /*0*/KEY_EQUAL, KEY_TAB,      KEYBOARD_LEFT_GUI,KEYBOARD_LEFT_SHIFT, KEY_DUMMY,      KEY_DUMMY,          KEY_DUMMY,
  /*1*/KEY_1,     KEY_Q,        KEY_A,            KEY_Z,               KEY_TILDE,      KEY_DUMMY,          KEY_DUMMY,
  /*2*/KEY_2,     KEY_W,        KEY_S,            KEY_X,               PMS_INSERT,     KEY_END,            KEY_DUMMY,
  /*3*/KEY_3,     KEY_E,        KEY_D,            KEY_C,               KEY_LEFT,       KEY_HOME,           KEYBOARD_LEFT_CTRL,
  /*4*/KEY_4,     KEY_R,        KEY_F,            KEY_V,               KEY_DUMMY,      KEY_DUMMY,          KEYBOARD_LEFT_ALT,
  /*5*/KEY_5,     KEY_T,        KEY_G,            KEY_B,               KEY_RIGHT,      KEY_DELETE,         KEY_BACKSPACE,

  /*6*/KEY_6,     KEY_Y,        KEY_H,            KEY_N,               KEY_DOWN,       KEY_SPACE,          KEY_PAGE_DOWN,
  /*7*/KEY_7,     KEY_U,        KEY_J,            KEY_M,               KEY_DUMMY,      KEY_ENTER,          KEY_DUMMY,
  /*8*/KEY_8,     KEY_I,        KEY_K,            KEY_COMMA,           KEY_UP,         KEYBOARD_RIGHT_CTRL,KEY_PAGE_UP,

  /*9*/KEY_9,     KEY_O,        KEY_L,            KEY_PERIOD,          KEY_LEFT_BRACE, KEY_DUMMY,          KEYBOARD_RIGHT_ALT,

  /*10*/KEY_0,    KEY_P,        KEY_SEMICOLON,    KEY_SLASH,           KEY_RIGHT_BRACE,KEY_DUMMY,          KEY_DUMMY,
  /*11*/KEY_MINUS,KEY_BACKSLASH,KEY_QUOTE,        PMS_RIGHT_SHIFT,     KEY_DUMMY,      KEY_DUMMY,          KEY_DUMMY,
  /*12*/KEY_ESC,  KEY_F3,       KEY_F6,           KEY_F9,              KEY_F12,        KEY_PAUSE,          KEY_DUMMY,
  /*13*/KEY_F1,   KEY_F4,       KEY_F7,           KEY_F10,             KEY_PRINTSCREEN,LKEY_PROGRAM,       KEY_DUMMY,
  /*14*/KEY_F2,   KEY_F5,       KEY_F8,           KEY_F11,             KEY_SCROLL_LOCK,LKEY_KEYPAD,        KEY_DUMMY,
};


#define LED_PORT PORTF
#define LED_KEYPAD_PIN 0
#define LED_SCROLL_LOCK_PIN 1
#define LED_NUM_LOCK_PIN 2
#define LED_CAPS_LOCK_PIN 3

int *layers[] = {layer0, layer1, layer2};

int fn_decay = 0;

void activate_fn() {
  fn_decay = 20;
};

int layer_to_jump = 0;

// jump to this layer when fn is released
void layer_jump() {
  layer_to_jump = 2;
};

void middle_mouse() {
  usb_mouse_buttons(0, 1, 0);
  usb_mouse_buttons(0, 0, 0);
};

int cur_active_functions[] = {0, 0, 0, 0};
int active_functions[] = {0, 0, 0, 0};

void (*layer_functions[])(void) = {reset, activate_fn, layer_jump, middle_mouse};

// When we are sending key combinations that include modifiers, the OS
// can do some level of error-correction to prevent this scenario:

// - shift down
// - a key down
// - A inserted
// - shift up
// - a inserted

// However, fn is unlike other modifiers since the OS knows nothing
// about it; from the OS's perspective the keycodes it gets before and
// after the release of fn are unrelated. Because of this, we must let
// fn apply a little after it's been released; this is what fn_decay
// does.

void per_cycle() {
  if(fn_decay > 1) {
    current_layer = layers[1];
    fn_decay--;
  } else if(fn_decay == 1) {
    current_layer_number = layer_to_jump;
    fn_decay--;
  } else {
    layer_to_jump = 0;
    fn_decay = 0;
  }
};
