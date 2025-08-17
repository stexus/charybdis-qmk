/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "keycodes.h"
#include "keymap_us.h"
#include "modifiers.h"
#include QMK_KEYBOARD_H

enum charybdis_keymap_layers { LAYER_BASE = 0, LAYER_NAV_NUM, LAYER_SYM_NAV, LAYER_DEBUG_SYM, LAYER_MOUSE, LAYER_TMUX, LAYER_FN, LAYER_OSM_RIGHT, LAYER_OSM_LEFT };
enum custom_keycodes { TMUX_SPLIT_H = SAFE_RANGE, TMUX_SPLIT_V, TMUX_NEXT_WIN, TMUX_PREV_WIN, TMUX_COPY_MODE, TMUX_CLOSE_PANE, TMUX_CLOSE_WIN, TMUX_PREV_SESH, TMUX_NEXT_SESH, TMUX_NEW_WIN, TMUX_MOVE_WIN_LEFT, TMUX_MOVE_WIN_RIGHT, TMUX_MOVE_PANE_LEFT, TMUX_MOVE_PANE_RIGHT, NEXT_ERR, PREV_ERR, VIM_SAVE };

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌───────────────────┬─────────────────┬─────────────────┬─────────────────┬────────────────────────┬──────────────────────┐   ┌───────────────────────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┐
//        │       caps        │        1        │        2        │        3        │           4            │          5           │   │           6           │        7        │        8        │        9        │        0        │        -        │
//        ├───────────────────┼─────────────────┼─────────────────┼─────────────────┼────────────────────────┼──────────────────────┤   ├───────────────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┤
//        │        tab        │        q        │        w        │        e        │           r            │          t           │   │           y           │        u        │        i        │        o        │        p        │    bACKSPACE    │
//        ├───────────────────┼─────────────────┼─────────────────┼─────────────────┼────────────────────────┼──────────────────────┤   ├───────────────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┤
//        │ MT(MOD_LSFT, esc) │ MT(MOD_LCTL, a) │ MT(MOD_LALT, s) │ MT(MOD_LGUI, d) │    MT(MOD_LSFT, f)     │  LT(LAYER_TMUX, g)   │   │           h           │ MT(MOD_RSFT, j) │ MT(MOD_RGUI, k) │ MT(MOD_RALT, l) │ MT(MOD_RCTL, ;) │ MT(MOD_RSFT, ') │
//        ├───────────────────┼─────────────────┼─────────────────┼─────────────────┼────────────────────────┼──────────────────────┤   ├───────────────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┤
//        │     MOD_LCTL      │        z        │        x        │        c        │           v            │          b           │   │           n           │        m        │        ,        │        .        │        /        │        _        │
//        └───────────────────┴─────────────────┴─────────────────┼─────────────────┼────────────────────────┼──────────────────────┤   ├───────────────────────┼─────────────────┼─────────────────┴─────────────────┴─────────────────┴─────────────────┘
//                                                                │       no        │ LT(LAYER_NAV_NUM, ent) │ LT(LAYER_MOUSE, spc) │   │ LT(CW_TOGG, LAYER_FN) │       spc       │
//                                                                └─────────────────┼────────────────────────┼──────────────────────┤   ├───────────────────────┼─────────────────┘
//                                                                                  │           no           │ MO(LAYER_DEBUG_SYM)  │   │   MO(LAYER_SYM_NAV)   │
//                                                                                  └────────────────────────┴──────────────────────┘   └───────────────────────┘
[LAYER_BASE] = LAYOUT(
      KC_CAPS              , KC_1               , KC_2               , KC_3               , KC_4                        , KC_5                    ,     KC_6                  , KC_7               , KC_8               , KC_9               , KC_0                  , KC_MINUS             ,
      KC_TAB               , KC_Q               , KC_W               , KC_E               , KC_R                        , KC_T                    ,     KC_Y                  , KC_U               , KC_I               , KC_O               , KC_P                  , KC_BACKSPACE         ,
      MT(MOD_LSFT, KC_ESC) , MT(MOD_LCTL, KC_A) , MT(MOD_LALT, KC_S) , MT(MOD_LGUI, KC_D) , MT(MOD_LSFT, KC_F)          , LT(LAYER_TMUX, KC_G)    ,     KC_H                  , MT(MOD_RSFT, KC_J) , MT(MOD_RGUI, KC_K) , MT(MOD_RALT, KC_L) , MT(MOD_RCTL, KC_SCLN) , MT(MOD_RSFT, KC_QUOT),
      MOD_LCTL             , KC_Z               , KC_X               , KC_C               , KC_V                        , KC_B                    ,     KC_N                  , KC_M               , KC_COMM            , KC_DOT             , KC_SLSH               , KC_UNDERSCORE        ,
                                                                       XXXXXXX            , LT(LAYER_NAV_NUM, KC_ENTER) , LT(LAYER_MOUSE, KC_SPC) ,     LT(CW_TOGG, LAYER_FN) , KC_SPC                                                                                                      ,
                                                                                            XXXXXXX                     , MO(LAYER_DEBUG_SYM)     ,     MO(LAYER_SYM_NAV)
),

//        ┌───────────────┬─────────────────┬─────────────┬─────────────┬─────────────┬───────────────┐   ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
//        │  tRANSPARENT  │   tRANSPARENT   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │  tRANSPARENT  │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        ├───────────────┼─────────────────┼─────────────┼─────────────┼─────────────┼───────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │  tRANSPARENT  │ LCTL(LSFT(tab)) │  LCTL(tab)  │   LGUI(c)   │   LGUI(v)   │ LGUI(LSFT(c)) │   │ tRANSPARENT │      4      │      5      │      6      │ tRANSPARENT │ tRANSPARENT │
//        ├───────────────┼─────────────────┼─────────────┼─────────────┼─────────────┼───────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │ OSM(MOD_LSFT) │     LALT(4)     │   LALT(3)   │   LALT(2)   │   LALT(1)   │    LALT(9)    │   │ tRANSPARENT │      1      │      2      │      3      │      0      │ tRANSPARENT │
//        ├───────────────┼─────────────────┼─────────────┼─────────────┼─────────────┼───────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │  tRANSPARENT  │     LALT(9)     │   LALT(8)   │   LALT(7)   │   LALT(a)   │    LALT(6)    │   │ tRANSPARENT │      7      │      8      │      9      │ tRANSPARENT │ tRANSPARENT │
//        └───────────────┴─────────────────┴─────────────┼─────────────┼─────────────┼───────────────┤   ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────┴─────────────┘
//                                                        │ tRANSPARENT │     no      │  tRANSPARENT  │   │ tRANSPARENT │   RCTL(b)   │
//                                                        └─────────────┼─────────────┼───────────────┤   ├─────────────┼─────────────┘
//                                                                      │ tRANSPARENT │  tRANSPARENT  │   │     spc     │
//                                                                      └─────────────┴───────────────┘   └─────────────┘
[LAYER_NAV_NUM] = LAYOUT(
      KC_TRANSPARENT , KC_TRANSPARENT     , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT   ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , LCTL(LSFT(KC_TAB)) , LCTL(KC_TAB)   , LGUI(KC_C)     , LGUI(KC_V)     , LGUI(LSFT(KC_C)) ,     KC_TRANSPARENT , KC_4           , KC_5           , KC_6           , KC_TRANSPARENT , KC_TRANSPARENT,
      OSM(MOD_LSFT)  , LALT(KC_4)         , LALT(KC_3)     , LALT(KC_2)     , LALT(KC_1)     , LALT(KC_9)       ,     KC_TRANSPARENT , KC_1           , KC_2           , KC_3           , KC_0           , KC_TRANSPARENT,
      KC_TRANSPARENT , LALT(KC_9)         , LALT(KC_8)     , LALT(KC_7)     , LALT(KC_A)     , LALT(KC_6)       ,     KC_TRANSPARENT , KC_7           , KC_8           , KC_9           , KC_TRANSPARENT , KC_TRANSPARENT,
                                                             KC_TRANSPARENT , XXXXXXX        , KC_TRANSPARENT   ,     KC_TRANSPARENT , RCTL(KC_B)                                                                        ,
                                                                              KC_TRANSPARENT , KC_TRANSPARENT   ,     KC_SPC
),

//        ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐   ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │    bspc     │   LCTL(w)   │ tRANSPARENT │     up      │ tRANSPARENT │ tRANSPARENT │   │      ^      │      {      │      }      │      $      │  PREV_ERR   │  NEXT_ERR   │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │  MOD_LCTL   │    left     │    down     │    rght     │      w      │   │      @      │      (      │      )      │      %      │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │ tRANSPARENT │      o      │ tRANSPARENT │      i      │ tRANSPARENT │   │      #      │      [      │      ]      │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────┴─────────────┘
//                                                  │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │
//                                                  └─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┘
//                                                                │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │
//                                                                └─────────────┴─────────────┘   └─────────────┘
[LAYER_DEBUG_SYM] = LAYOUT(
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_BSPC        , LCTL(KC_W)     , KC_TRANSPARENT , KC_UP          , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_CIRCUMFLEX  , KC_LCBR        , KC_RCBR        , KC_DOLLAR      , PREV_ERR       , NEXT_ERR      ,
      KC_TRANSPARENT , MOD_LCTL       , KC_LEFT        , KC_DOWN        , KC_RIGHT       , KC_W           ,     KC_AT          , KC_LPRN        , KC_RPRN        , KC_PERC        , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_O           , KC_TRANSPARENT , KC_I           , KC_TRANSPARENT ,     KC_HASH        , KC_LBRC        , KC_RBRC        , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
                                                         KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT                                                                    ,
                                                                          KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT
),

//        ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐   ┌─────────────┬─────────────┬─────────────────┬─────────────┬─────────────┬─────────────┐
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │   tRANSPARENT   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │      `      │      <      │      -      │      >      │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ RGUI(LSFT(spc)) │ tRANSPARENT │ tRANSPARENT │     del     │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────────┼─────────────┼─────────────┼─────────────┤
//        │      ~      │      !      │      +      │      &      │      =      │ tRANSPARENT │   │    left     │    down     │       up        │    rght     │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │      _      │      *      │      |      │      \      │ tRANSPARENT │   │ tRANSPARENT │  RGUI(spc)  │   tRANSPARENT   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────────┴─────────────┴─────────────┴─────────────┘
//                                                  │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │
//                                                  └─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┘
//                                                                │ tRANSPARENT │ tRANSPARENT │   │     no      │
//                                                                └─────────────┴─────────────┘   └─────────────┘
[LAYER_SYM_NAV] = LAYOUT(
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT     , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_GRAVE       , KC_LABK        , KC_MINUS       , KC_RABK        , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , RGUI(LSFT(KC_SPC)) , KC_TRANSPARENT , KC_TRANSPARENT , KC_DEL        ,
      KC_TILDE       , KC_EXCLAIM     , KC_PLUS        , KC_AMPERSAND   , KC_EQUAL       , KC_TRANSPARENT ,     KC_LEFT        , KC_DOWN        , KC_UP              , KC_RIGHT       , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_UNDERSCORE  , KC_ASTERISK    , KC_PIPE        , KC_BACKSLASH   , KC_TRANSPARENT ,     KC_TRANSPARENT , RGUI(KC_SPC)   , KC_TRANSPARENT     , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
                                                         KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT                                                                        ,
                                                                          KC_TRANSPARENT , KC_TRANSPARENT ,     XXXXXXX
),

//        ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐   ┌───────────────┬─────────────────┬────────────────────┬─────────────────────┬─────────────────────┬──────────────────────┐
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │  tRANSPARENT  │   tRANSPARENT   │    tRANSPARENT     │     tRANSPARENT     │     tRANSPARENT     │     tRANSPARENT      │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├───────────────┼─────────────────┼────────────────────┼─────────────────────┼─────────────────────┼──────────────────────┤
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │  tRANSPARENT  │ TMUX_CLOSE_WIN  │   TMUX_PREV_SESH   │   TMUX_NEXT_SESH    │ TMUX_MOVE_PANE_LEFT │ TMUX_MOVE_PANE_RIGHT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├───────────────┼─────────────────┼────────────────────┼─────────────────────┼─────────────────────┼──────────────────────┤
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ TMUX_PREV_WIN │  TMUX_SPLIT_V   │    TMUX_SPLIT_H    │    TMUX_NEXT_WIN    │   TMUX_COPY_MODE    │     tRANSPARENT      │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├───────────────┼─────────────────┼────────────────────┼─────────────────────┼─────────────────────┼──────────────────────┤
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │  tRANSPARENT  │ TMUX_CLOSE_PANE │ TMUX_MOVE_WIN_LEFT │ TMUX_MOVE_WIN_RIGHT │     tRANSPARENT     │     tRANSPARENT      │
//        └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤   ├───────────────┼─────────────────┼────────────────────┴─────────────────────┴─────────────────────┴──────────────────────┘
//                                                  │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │  tRANSPARENT  │  TMUX_NEW_WIN   │
//                                                  └─────────────┼─────────────┼─────────────┤   ├───────────────┼─────────────────┘
//                                                                │ tRANSPARENT │ tRANSPARENT │   │  tRANSPARENT  │
//                                                                └─────────────┴─────────────┘   └───────────────┘
[LAYER_TMUX] = LAYOUT(
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT  , KC_TRANSPARENT     , KC_TRANSPARENT      , KC_TRANSPARENT      , KC_TRANSPARENT      ,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , TMUX_CLOSE_WIN  , TMUX_PREV_SESH     , TMUX_NEXT_SESH      , TMUX_MOVE_PANE_LEFT , TMUX_MOVE_PANE_RIGHT,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     TMUX_PREV_WIN  , TMUX_SPLIT_V    , TMUX_SPLIT_H       , TMUX_NEXT_WIN       , TMUX_COPY_MODE      , KC_TRANSPARENT      ,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , TMUX_CLOSE_PANE , TMUX_MOVE_WIN_LEFT , TMUX_MOVE_WIN_RIGHT , KC_TRANSPARENT      , KC_TRANSPARENT      ,
                                                         KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , TMUX_NEW_WIN                                                                                           ,
                                                                          KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT
),

//        ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐   ┌─────────────┬─────────────────┬─────────────┬───────────────┬─────────────┬─────────────┐
//        │     f12     │     f1      │     f2      │     f3      │     f4      │     f5      │   │     f6      │       f7        │     f8      │      f9       │     f10     │     f11     │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────────┼─────────────┼───────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ bRIGHTNESS_DOWN │ tRANSPARENT │ bRIGHTNESS_UP │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────────┼─────────────┼───────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │      mprv       │    mply     │     mnxt      │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────────┼─────────────┼───────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │      vold       │    mute     │     volu      │ tRANSPARENT │ tRANSPARENT │
//        └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────────┼─────────────┴───────────────┴─────────────┴─────────────┘
//                                                  │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │   tRANSPARENT   │
//                                                  └─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────────┘
//                                                                │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │
//                                                                └─────────────┴─────────────┘   └─────────────┘
[LAYER_FN] = LAYOUT(
      KC_F12         , KC_F1          , KC_F2          , KC_F3          , KC_F4          , KC_F5          ,     KC_F6          , KC_F7              , KC_F8          , KC_F9            , KC_F10         , KC_F11        ,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_BRIGHTNESS_DOWN , KC_TRANSPARENT , KC_BRIGHTNESS_UP , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_MPRV            , KC_MPLY        , KC_MNXT          , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_VOLD            , KC_MUTE        , KC_VOLU          , KC_TRANSPARENT , KC_TRANSPARENT,
                                                         KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT                                                                          ,
                                                                          KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT
),

//        ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐   ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │ tRANSPARENT │  S_D_RMOD   │   S_D_MOD   │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │    btn2     │   DRGSCRL   │   SNIPING   │    btn1     │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │ tRANSPARENT │  DPI_RMOD   │   DPI_MOD   │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────┴─────────────┘
//                                                  │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │
//                                                  └─────────────┼─────────────┼─────────────┤   ├─────────────┼─────────────┘
//                                                                │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │
//                                                                └─────────────┴─────────────┘   └─────────────┘
[LAYER_MOUSE] = LAYOUT(
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , S_D_RMOD       , S_D_MOD        , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_BTN2        , DRGSCRL        , SNIPING        , KC_BTN1        , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , DPI_RMOD       , DPI_MOD        , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
                                                         KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT                                                                    ,
                                                                          KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT
),

//        ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐   ┌─────────────┬───────────────┬───────────────┬───────────────┬───────────────┬─────────────┐
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────────┤
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────────┤
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │ OSM(MOD_RSFT) │ OSM(MOD_RGUI) │ OSM(MOD_RALT) │ OSM(MOD_RCTL) │ tRANSPARENT │
//        ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────────┤
//        │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │ tRANSPARENT │
//        └─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤   ├─────────────┼───────────────┼───────────────┴───────────────┴───────────────┴─────────────┘
//                                                  │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │  tRANSPARENT  │
//                                                  └─────────────┼─────────────┼─────────────┤   ├─────────────┼───────────────┘
//                                                                │ tRANSPARENT │ tRANSPARENT │   │ tRANSPARENT │
//                                                                └─────────────┴─────────────┘   └─────────────┘
[LAYER_OSM_RIGHT] = LAYOUT(
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , OSM(MOD_RSFT)  , OSM(MOD_RGUI)  , OSM(MOD_RALT)  , OSM(MOD_RCTL)  , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
                                                         KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT                                                                    ,
                                                                          KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT
),

//        ┌─────────────┬───────────────┬───────────────┬───────────────┬───────────────┬─────────────┐   ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
//        │ tRANSPARENT │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │ OSM(MOD_LCTL) │ OSM(MOD_LALT) │ OSM(MOD_LGUI) │ OSM(MOD_LSFT) │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        ├─────────────┼───────────────┼───────────────┼───────────────┼───────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
//        │ tRANSPARENT │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │  tRANSPARENT  │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │ tRANSPARENT │
//        └─────────────┴───────────────┴───────────────┼───────────────┼───────────────┼─────────────┤   ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────┴─────────────┘
//                                                      │  tRANSPARENT  │  tRANSPARENT  │ tRANSPARENT │   │ tRANSPARENT │ tRANSPARENT │
//                                                      └───────────────┼───────────────┼─────────────┤   ├─────────────┼─────────────┘
//                                                                      │  tRANSPARENT  │ tRANSPARENT │   │ tRANSPARENT │
//                                                                      └───────────────┴─────────────┘   └─────────────┘
[LAYER_OSM_LEFT] = LAYOUT(
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , OSM(MOD_LCTL)  , OSM(MOD_LALT)  , OSM(MOD_LGUI)  , OSM(MOD_LSFT)  , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
      KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
                                                         KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT                                                                    ,
                                                                          KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT
)
};
// [LAYER_FN] = LAYOUT(
//       KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
//       KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
//       KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
//       KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT,
//                                                          KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT , KC_TRANSPARENT                                                                    ,
//                                                                           KC_TRANSPARENT , KC_TRANSPARENT ,     KC_TRANSPARENT
// ),
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       'L', 'L', 'L', 'L', 'L', 'L',                            'R', 'R', 'R', 'R', 'R', 'R',
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       'L', 'L', 'L', 'L', 'L', 'L',                            'R', 'R', 'R', 'R', 'R', 'R',
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       '*', 'L', 'L', 'L', 'L', 'L',                            'R', 'R', 'R', 'R', 'R', '*',
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       'L', 'L', 'L', 'L', 'L', 'L',                            'R', 'R', 'R', 'R', 'R', 'R',
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                              '*', '*', '*',          '*', '*',
                                                '*',  '*',          '*'
  //                            ╰───────────────────────────╯ ╰──────────────────╯
);

// clang-format on
const uint16_t PROGMEM sd_combo[]   = {MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), COMBO_END};
combo_t                key_combos[] = {COMBO(sd_combo, VIM_SAVE)};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(LAYER_NAV_NUM, KC_ENTER):
        case LT(LAYER_MOUSE, KC_SPC):
        case LT(CW_TOGG, LAYER_FN):
        case MT(MOD_LSFT, KC_ESC):
        case MT(MOD_RSFT, KC_QUOT):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
// Remove flow tap on all thumb keys
// Remove flow tap on esc/quote, hrm SHIFT
// Decrease flow term on LCTL_T(A)
// Increase flow on ring fingers (especially RALT_T(L))
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
            case LT(LAYER_NAV_NUM, KC_ENTER):
            case LT(LAYER_MOUSE, KC_SPC):
            case LT(CW_TOGG, LAYER_FN):
            case MT(MOD_LSFT, KC_ESC):
            case MT(MOD_RSFT, KC_QUOT):
            case MT(MOD_LSFT, KC_F):
            case MT(MOD_RSFT, KC_J):
                return 0;
            case MT(MOD_LCTL, KC_A):
            case MT(MOD_RCTL, KC_SCLN):
                return FLOW_TAP_TERM - 30;
            case MT(MOD_RALT, KC_L):
            case MT(MOD_LALT, KC_S):
                return FLOW_TAP_TERM + 30;

            default:
                return FLOW_TAP_TERM; // Longer timeout otherwise.
        }
    }
    return 0; // Disable Flow Tap.
}
// bool is_flow_tap_key(uint16_t keycode) {
//     if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
//         return false; // Disable Flow Tap on hotkeys.
//     }
//     switch (get_tap_keycode(keycode)) {
//         // removing A (ctl), space, enter, f, j
//         case KC_B ... KC_E: // B, C, D, E
//         case KC_G ... KC_I: // G, H, I
//         case KC_K ... KC_Z: // K, L
//         case KC_DOT:
//         case KC_COMM:
//         case KC_SCLN:
//         case KC_SLSH:
//             return true;
//     }
//     return false;
// }
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX_CLOSE_WIN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_7)));
            }
            break;
        case TMUX_PREV_SESH:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_9)));
            }
            break;
        case TMUX_NEXT_SESH:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_0)));
            }
            break;
        case TMUX_PREV_WIN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_P));
            }
            break;
        case TMUX_SPLIT_V:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_5)));
            }
            break;
        case TMUX_SPLIT_H:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_QUOTE)));
            }
            break;
        case TMUX_NEXT_WIN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_N));
            }
            break;
        case TMUX_COPY_MODE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_LBRC));
            }
            break;
        case TMUX_CLOSE_PANE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_X));
            }
            break;
        case TMUX_MOVE_WIN_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_COMMA)));
            }
            break;
        case TMUX_MOVE_WIN_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));
            }
            break;
        case TMUX_NEW_WIN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_C));
            }
            break;
        case TMUX_MOVE_PANE_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_LBRC)));
            }
            break;
        case TMUX_MOVE_PANE_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_RBRC)));
            }
            break;
        // ssh break
        // case ST_MACRO_14:
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(100) SS_TAP(X_NONUS_HASH) SS_DELAY(100) SS_TAP(X_DOT));
        //     }
        //     break;
        case VIM_SAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_D));
            }
            break;
        case NEXT_ERR:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RBRC) SS_DELAY(100) SS_TAP(X_E));
            }
            break;
        case PREV_ERR:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(100) SS_TAP(X_E));
            }
            break;
    }
    return true;
}
