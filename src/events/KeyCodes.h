#pragma once

/* FROM glwf3.h
 *  These key codes are inspired by the _USB HID Usage Tables v1.12_ (p. 53-60),
 *  but re-arranged to map to 7-bit ASCII for printable keys (function keys are
 *  put in the 256+ range).
 *
 *  The naming of the key codes follow these rules:
 *   - The US keyboard layout is used
 *   - Names of printable alpha-numeric characters are used (e.g. "A", "R",
 *     "3", etc.)
 *   - For non-alphanumeric characters, Unicode:ish names are used (e.g.
 *     "COMMA", "LEFT_SQUARE_BRACKET", etc.). Note that some names do not
 *     correspond to the Unicode standard (usually for brevity)
 *   - Keys that lack a clear US mapping are named "WORLD_x"
 *   - For non-printable keys, custom names are used (e.g. "F4",
 *     "BACKSPACE", etc.)
 */

 /* The unknown key */
#define MEMOGL_KEY_UNKNOWN            -1

/* Printable keys */
#define MEMOGL_KEY_SPACE              32
#define MEMOGL_KEY_APOSTROPHE         39  /* ' */
#define MEMOGL_KEY_COMMA              44  /* , */
#define MEMOGL_KEY_MINUS              45  /* - */
#define MEMOGL_KEY_PERIOD             46  /* . */
#define MEMOGL_KEY_SLASH              47  /* / */
#define MEMOGL_KEY_0                  48
#define MEMOGL_KEY_1                  49
#define MEMOGL_KEY_2                  50
#define MEMOGL_KEY_3                  51
#define MEMOGL_KEY_4                  52
#define MEMOGL_KEY_5                  53
#define MEMOGL_KEY_6                  54
#define MEMOGL_KEY_7                  55
#define MEMOGL_KEY_8                  56
#define MEMOGL_KEY_9                  57
#define MEMOGL_KEY_SEMICOLON          59  /* ; */
#define MEMOGL_KEY_EQUAL              61  /* = */
#define MEMOGL_KEY_A                  65
#define MEMOGL_KEY_B                  66
#define MEMOGL_KEY_C                  67
#define MEMOGL_KEY_D                  68
#define MEMOGL_KEY_E                  69
#define MEMOGL_KEY_F                  70
#define MEMOGL_KEY_G                  71
#define MEMOGL_KEY_H                  72
#define MEMOGL_KEY_I                  73
#define MEMOGL_KEY_J                  74
#define MEMOGL_KEY_K                  75
#define MEMOGL_KEY_L                  76
#define MEMOGL_KEY_M                  77
#define MEMOGL_KEY_N                  78
#define MEMOGL_KEY_O                  79
#define MEMOGL_KEY_P                  80
#define MEMOGL_KEY_Q                  81
#define MEMOGL_KEY_R                  82
#define MEMOGL_KEY_S                  83
#define MEMOGL_KEY_T                  84
#define MEMOGL_KEY_U                  85
#define MEMOGL_KEY_V                  86
#define MEMOGL_KEY_W                  87
#define MEMOGL_KEY_X                  88
#define MEMOGL_KEY_Y                  89
#define MEMOGL_KEY_Z                  90
#define MEMOGL_KEY_LEFT_BRACKET       91  /* [ */
#define MEMOGL_KEY_BACKSLASH          92  /* \ */
#define MEMOGL_KEY_RIGHT_BRACKET      93  /* ] */
#define MEMOGL_KEY_GRAVE_ACCENT       96  /* ` */
#define MEMOGL_KEY_WORLD_1            161 /* non-US #1 */
#define MEMOGL_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define MEMOGL_KEY_ESCAPE             256
#define MEMOGL_KEY_ENTER              257
#define MEMOGL_KEY_TAB                258
#define MEMOGL_KEY_BACKSPACE          259
#define MEMOGL_KEY_INSERT             260
#define MEMOGL_KEY_DELETE             261
#define MEMOGL_KEY_RIGHT              262
#define MEMOGL_KEY_LEFT               263
#define MEMOGL_KEY_DOWN               264
#define MEMOGL_KEY_UP                 265
#define MEMOGL_KEY_PAGE_UP            266
#define MEMOGL_KEY_PAGE_DOWN          267
#define MEMOGL_KEY_HOME               268
#define MEMOGL_KEY_END                269
#define MEMOGL_KEY_CAPS_LOCK          280
#define MEMOGL_KEY_SCROLL_LOCK        281
#define MEMOGL_KEY_NUM_LOCK           282
#define MEMOGL_KEY_PRINT_SCREEN       283
#define MEMOGL_KEY_PAUSE              284
#define MEMOGL_KEY_F1                 290
#define MEMOGL_KEY_F2                 291
#define MEMOGL_KEY_F3                 292
#define MEMOGL_KEY_F4                 293
#define MEMOGL_KEY_F5                 294
#define MEMOGL_KEY_F6                 295
#define MEMOGL_KEY_F7                 296
#define MEMOGL_KEY_F8                 297
#define MEMOGL_KEY_F9                 298
#define MEMOGL_KEY_F10                299
#define MEMOGL_KEY_F11                300
#define MEMOGL_KEY_F12                301
#define MEMOGL_KEY_F13                302
#define MEMOGL_KEY_F14                303
#define MEMOGL_KEY_F15                304
#define MEMOGL_KEY_F16                305
#define MEMOGL_KEY_F17                306
#define MEMOGL_KEY_F18                307
#define MEMOGL_KEY_F19                308
#define MEMOGL_KEY_F20                309
#define MEMOGL_KEY_F21                310
#define MEMOGL_KEY_F22                311
#define MEMOGL_KEY_F23                312
#define MEMOGL_KEY_F24                313
#define MEMOGL_KEY_F25                314
#define MEMOGL_KEY_KP_0               320
#define MEMOGL_KEY_KP_1               321
#define MEMOGL_KEY_KP_2               322
#define MEMOGL_KEY_KP_3               323
#define MEMOGL_KEY_KP_4               324
#define MEMOGL_KEY_KP_5               325
#define MEMOGL_KEY_KP_6               326
#define MEMOGL_KEY_KP_7               327
#define MEMOGL_KEY_KP_8               328
#define MEMOGL_KEY_KP_9               329
#define MEMOGL_KEY_KP_DECIMAL         330
#define MEMOGL_KEY_KP_DIVIDE          331
#define MEMOGL_KEY_KP_MULTIPLY        332
#define MEMOGL_KEY_KP_SUBTRACT        333
#define MEMOGL_KEY_KP_ADD             334
#define MEMOGL_KEY_KP_ENTER           335
#define MEMOGL_KEY_KP_EQUAL           336
#define MEMOGL_KEY_LEFT_SHIFT         340
#define MEMOGL_KEY_LEFT_CONTROL       341
#define MEMOGL_KEY_LEFT_ALT           342
#define MEMOGL_KEY_LEFT_SUPER         343
#define MEMOGL_KEY_RIGHT_SHIFT        344
#define MEMOGL_KEY_RIGHT_CONTROL      345
#define MEMOGL_KEY_RIGHT_ALT          346
#define MEMOGL_KEY_RIGHT_SUPER        347
#define MEMOGL_KEY_MENU               348

#define MEMOGL_KEY_LAST               MEMOGL_KEY_MENU