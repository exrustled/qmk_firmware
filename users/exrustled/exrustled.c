#include "exrustled.h"


// Combos & declarations
enum combo_events {
  ESC_COMBO,
  SLSH_COMBO,
  ENT_COMBO,
};

const uint16_t PROGMEM esc_combo[] = {KC_P,KC_QUOT, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_COMM,KC_DOT, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_G,KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT]	= {
    [ESC_COMBO] = COMBO(esc_combo, KC_ESC),
	[SLSH_COMBO] = COMBO(slsh_combo, KC_SLSH),
	[ENT_COMBO] = COMBO(ent_combo, KC_ENT),
};

// Tap Dance declarations
enum {
    TD_SLSH_ESC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for slash, twice for esc.
    [TD_SLSH_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#if defined ALPHAS_QWERTY
  [BASE] = LAYOUT_exr(
    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,
    LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              RSFT_T(KC_J),      RCTL_T(KC_K),      RALT_T(KC_L),      RGUI_T(KC_QUOT),
    KC_Z,              KC_X,		      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT, 		   KC_SLSH,
    KC_NP,             KC_NP,             LT(MEDR, KC_ESC),  LT(NAVR, KC_SPC),  LT(MOUR, KC_TAB),  LT(NSSL, KC_ENT),  LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_NP,             KC_NP
  ),
#elif defined ALPHAS_COLEMAKDH
  [BASE] = LAYOUT_exr(
    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              RSFT_T(KC_N),      RCTL_T(KC_E),      RALT_T(KC_I),      RGUI_T(KC_O),
    KC_Z,              KC_X,      		  KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,    		   KC_SLSH,
    KC_NP,             KC_NP,             LT(MEDR, KC_ESC),  LT(NAVR, KC_SPC),  LT(MOUR, KC_TAB),  LT(NSSL, KC_ENT),  LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_NP,             KC_NP
  ),
#else
[BASE] = LAYOUT_exr(
    KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_H),      LSFT_T(KC_T),      KC_G,              KC_Y,              RSFT_T(KC_N),      RCTL_T(KC_E),      RALT_T(KC_O),      RGUI_T(KC_I),
    KC_Z,              KC_X,		      KC_M,              KC_C,              KC_V,              KC_K,              KC_L,              KC_COMM,           KC_DOT,    		   KC_SLSH,
    KC_NP,             KC_NP,             LT(MEDR, KC_ESC),  LT(NAVR, KC_SPC),  LT(MOUR, KC_TAB),  LT(NSSL, KC_ENT),  LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_NP,             KC_NP
  ),  
#endif
   [NAVR] = LAYOUT_exr(
    KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_PGUP, KC_UP,   KC_PGDN, KC_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NU,
    KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_HOME, KC_INS,  KC_END,  KC_NU,
    KC_NP,   KC_NP,   KC_NA,   KC_NA,   KC_NA,   KC_ENT,  KC_BSPC, KC_DEL,  KC_NP,   KC_NP
  ),
  [MOUR] = LAYOUT_exr(
    KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_WH_U, KC_MS_U, KC_WH_D, KC_NU,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_NU,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NU,
    KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_WH_L, KC_NU,   KC_WH_R, KC_NU,
    KC_NP,   KC_NP,   KC_NA,   KC_NA,   KC_NA,   KC_BTN1, KC_BTN3, KC_BTN2, KC_NP,   KC_NP
  ),
  [MEDR] = LAYOUT_exr(
    KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   BL_TOGG, BL_INC,  KC_VOLU, BL_DEC,  BL_BRTG,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_NU,   KC_MPRV, KC_VOLD, KC_MNXT, KC_NU,
    KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
    KC_NP,   KC_NP,   KC_NA,   KC_NA,   KC_NA,   KC_MSTP, KC_MPLY, KC_MUTE, KC_NP,   KC_NP
  ),
  [FUNL] = LAYOUT_exr(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, KC_NA,KC_NA,   KC_NA,   KC_NA,   KC_RST,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, KC_NA,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, TG(GAME),   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    KC_NP,   KC_NP,   KC_APP,  KC_SPC,  KC_TAB,  KC_NA,   KC_NA,   KC_NA,   KC_NP,   KC_NP
  ),
  [NSL] = LAYOUT_exr(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_NA,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    KC_NP,   KC_NP,   KC_DOT,  KC_0,    KC_MINS, KC_NA,   KC_NA,   KC_NA,   KC_NP,   KC_NP
  ),
  [NSSL] = LAYOUT_exr(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_NA,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_NA,
    KC_NP,   KC_NP,   KC_LPRN,   KC_RPRN, KC_UNDS, KC_NA,   KC_NA,   KC_NA,   KC_NP,   KC_NP
  ),
  [GAME] = LAYOUT_exr(
    KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,
    LSFT_T(KC_A),      KC_S,              KC_H,       		 KC_T, 			    KC_G,              KC_Y,              KC_N,      		 KC_E,      		KC_O, 		  RSFT_T(KC_I),
    LCTL_T(KC_Z),      KC_X,      		  KC_M,              KC_C,              KC_V,              KC_K,              KC_L,              KC_COMM,           KC_DOT,	   		   KC_SLSH,
    KC_NP,             KC_NP,             KC_LALT,  		 KC_SPC,  			KC_TAB,            LT(NSSL, KC_ENT),  LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_NP,             	 KC_NP
  )
};
