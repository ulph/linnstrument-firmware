/********************************* ls_font: LinnStrument LED Font Drawing *************************
This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/
or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
***************************************************************************************************
These routines allow text to be drawn and scrolled using the LinnStrument LEDS.

Several sized of fonts are defined to take up a different amount of space on the LinnStrument
surface.
**************************************************************************************************/

struct Character {
  byte width;
  char* data;
};

/******************************************* Tiny Font *******************************************/

static Character tiny_blank = { 2,
  "  "
  "  "
  "  "
  "  "  };

static Character tiny_0 = { 3,
  "000"
  "0 0"
  "0 0"
  "000" };

static Character tiny_1 = { 2,
  " 0"
  "00"
  " 0"
  " 0" };

static Character tiny_2 = { 3,
  "000"
  "  0"
  "00 "
  "000" };

static Character tiny_3 = { 3,
  "000"
  " 0 "
  "  0"
  "00 " };

static Character tiny_4 = { 3,
  "0 0"
  "0 0"
  "000"
  "  0" };

static Character tiny_5 = { 3,
  "000"
  "00 "
  "  0"
  "00 " };

static Character tiny_6 = { 3,
  "0  "
  "000"
  "0 0"
  "000" };

static Character tiny_7 = { 3,
  "000"
  "  0"
  " 0 "
  "0  " };

static Character tiny_8 = { 3,
  "000"
  "000"
  "0 0"
  "000" };

static Character tiny_9 = { 3,
  "000"
  "0 0"
  "000"
  "  0" };

/******************************************* Small Font ******************************************/

static Character small_blank = { 2,
  "  "
  "  "
  "  "
  "  "
  "  "
  "  "
  "  "
  "  "  };

static Character small_excl = { 3,
  "   "
  "   "
  " 0 "
  " 0 "
  " 0 "
  "   "
  " 0 "
  "   " };

static Character small_quot = { 2,
  "  "
  "  "
  "00"
  "00"
  "  "
  "  "
  "  "
  "  " };

static Character small_hash = { 5,
  "     "
  "     "
  " 0 0 "
  "00000"
  " 0 0 "
  "00000"
  " 0 0 "
  "     " };

static Character small_dollar = { 5,
  "     "
  "     "
  " 000 "
  "0 0  "
  " 000 "
  "  0 0"
  " 000 "
  "     " };

static Character small_perc = { 5,
  "     "
  "     "
  " 0   "
  "   0 "
  "  0  "
  " 0   "
  "   0 "
  "     " };

static Character small_amp = { 5,
  "     "
  "     "
  " 00  "
  "0  0 "
  " 00  "
  "0  00"
  " 00 0"
  "     " };

static Character small_squot = { 3,
  "   "
  "   "
  " 0 "
  " 0 "
  "   "
  "   "
  "   "
  "   " };

static Character small_lparen = { 2,
  "  "
  "  "
  " 0"
  "0 "
  "0 "
  "0 "
  " 0"
  "  " };

static Character small_rparen = { 2,
  "  "
  "  "
  "0 "
  " 0"
  " 0"
  " 0"
  "0 "
  "  " };

static Character small_mult = { 5,
  "     "
  "     "
  "0 0 0"
  " 000 "
  "00000"
  " 000 "
  "0 0 0"
  "     " };

static Character small_plus = { 3,
  "   "
  "   "
  "   "
  " 0 "
  "000"
  " 0 "
  "   "
  "   " };

static Character small_comma = { 2,
  "  "
  "  "
  "  "
  "  "
  "  "
  " 0"
  " 0"
  "0 " };

static Character small_minus = { 3,
  "   "
  "   "
  "   "
  "   "
  "000"
  "   "
  "   "
  "   " };

static Character small_dot = { 1,
  " "
  " "
  " "
  " "
  " "
  " "
  "0"
  " " };

static Character small_div = { 3,
  "   "
  "   "
  "   "
  "  0"
  " 0 "
  "0  "
  "   "
  "   " };

static Character small_0 = { 4,
  "    "
  " 00 "
  "0  0"
  "0  0"
  "0  0"
  "0  0"
  " 00 "
  "    " };

static Character small_1 = { 4,
  "    "
  "  0 "
  " 00 "
  "  0 "
  "  0 "
  "  0 "
  " 000"
  "    " };

static Character small_2 = { 4,
  "    "
  " 00 "
  "0  0"
  "  0 "
  " 0  "
  "0   "
  "0000"
  "    " };

static Character small_3 = { 4,
  "    "
  "000 "
  "   0"
  " 00 "
  "   0"
  "   0"
  "000 "
  "    " };

static Character small_4 = { 4,
  "    "
  "  00"
  " 0 0"
  "0  0"
  "0000"
  "   0"
  "   0"
  "    " };

static Character small_5 = { 4,
  "    "
  "0000"
  "0   "
  "000 "
  "   0"
  "0  0"
  " 00 "
  "    " };

static Character small_6 = { 4,
  "    "
  " 000"
  "0   "
  "000 "
  "0  0"
  "0  0"
  " 00 "
  "    " };

static Character small_7 = { 4,
  "    "
  "0000"
  "   0"
  "   0"
  "  0 "
  " 0  "
  "0   "
  "    " };

static Character small_8 = { 4,
  "    "
  " 00 "
  "0  0"
  " 00 "
  "0  0"
  "0  0"
  " 00 "
  "    " };

static Character small_9 = { 4,
  "    "
  " 00 "
  "0  0"
  " 000"
  "   0"
  "  0 "
  " 0  "
  "    " };

static Character small_colon = { 2,
  "  "
  "  "
  "  "
  "0 "
  "  "
  "0 "
  "  "
  "  " };

static Character small_semi = { 2,
  "  "
  "  "
  "  "
  "  "
  " 0"
  "  "
  " 0"
  "0 " };

static Character small_lt = { 3,
  "   "
  "   "
  "  0"
  " 0 "
  "0  "
  " 0 "
  "  0"
  "   " };

static Character small_eq = { 3,
  "   "
  "   "
  "   "
  "000"
  "   "
  "000"
  "   "
  "   " };

static Character small_gt = { 3,
  "   "
  "   "
  "0  "
  " 0 "
  "  0"
  " 0 "
  "0  "
  "   " };

static Character small_quest = { 3,
  "   "
  "   "
  "00 "
  "  0"
  " 0 "
  "   "
  " 0 "
  "   " };

static Character small_at = { 5,
  "     "
  "     "
  " 000 "
  "0 0 0"
  "0  0 "
  "0    "
  " 000 "
  "     " };

static Character small_A = { 4,
  "    "
  "    "
  " 00 "
  "0  0"
  "0000"
  "0  0"
  "0  0"
  "    " };

static Character small_B = { 4,
  "    "
  "    "
  "000 "
  "0  0"
  "000 "
  "0  0"
  "000 "
  "    " };

static Character small_C = { 4,
  "    "
  "    "
  " 000"
  "0   "
  "0   "
  "0   "
  " 000"
  "    " };

static Character small_D = { 4,
  "    "
  "    "
  "000 "
  "0  0"
  "0  0"
  "0  0"
  "000 "
  "    " };

static Character small_E = { 3,
  "   "
  "   "
  "000"
  "0  "
  "00 "
  "0  "
  "000"
  "   " };

static Character small_F = { 3,
  "   "
  "   "
  "000"
  "0  "
  "00 "
  "0  "
  "0  "
  "   " };

static Character small_G = { 4,
  "    "
  "    "
  " 00 "
  "0   "
  "0 00"
  "0  0"
  " 00 "
  "    " };

static Character small_H = { 4,
  "    "
  "    "
  "0  0"
  "0  0"
  "0000"
  "0  0"
  "0  0"
  "    " };

static Character small_I = { 3,
  "   "
  "   "
  "000"
  " 0 "
  " 0 "
  " 0 "
  "000"
  "   " };

static Character small_J = { 3,
  "   "
  "   "
  "000"
  "  0"
  "  0"
  "  0"
  "00 "
  "   " };

static Character small_K = { 4,
  "    "
  "    "
  "0  0"
  "0 0 "
  "00  "
  "0 0 "
  "0  0"
  "    " };

static Character small_L = { 3,
  "   "
  "   "
  "0  "
  "0  "
  "0  "
  "0  "
  "000"
  "   " };

static Character small_M = { 5,
  "     "
  "     "
  "0   0"
  "00 00"
  "0 0 0"
  "0   0"
  "0   0"
  "     " };

static Character small_N = { 4,
  "    "
  "    "
  "0  0"
  "00 0"
  "0 00"
  "0  0"
  "0  0"
  "    " };

static Character small_O = { 4,
  "    "
  "    "
  " 00 "
  "0  0"
  "0  0"
  "0  0"
  " 00 "
  "    " };

static Character small_P = { 4,
  "    "
  "    "
  "000 "
  "0  0"
  "000 "
  "0   "
  "0   "
  "    " };

static Character small_Q = { 4,
  "     "
  "     "
  " 00  "
  "0  0 "
  "0 00 "
  "0  0 "
  " 00 0"
  "     " };

static Character small_R = { 4,
  "    "
  "    "
  "000 "
  "0  0"
  "000 "
  "0 0 "
  "0  0"
  "    " };

static Character small_S = { 4,
  "    "
  "    "
  " 000"
  "0   "
  " 00 "
  "   0"
  "000 "
  "    " };

static Character small_T = { 3,
  "   "
  "   "
  "000"
  " 0 "
  " 0 "
  " 0 "
  " 0 "
  "   " };

static Character small_U = { 4,
  "    "
  "    "
  "0  0"
  "0  0"
  "0  0"
  "0  0"
  " 00 "
  "    " };

static Character small_V = { 5,
  "     "
  "     "
  "0   0"
  "0   0"
  "0   0"
  " 0 0 "
  "  0  "
  "     " };

static Character small_W = { 5,
  "     "
  "     "
  "0   0"
  "0   0"
  "0 0 0"
  "00 00"
  "0   0"
  "     " };

static Character small_X = { 5,
  "     "
  "     "
  "0   0"
  " 0 0 "
  "  0  "
  " 0 0 "
  "0   0"
  "     " };

static Character small_Y = { 5,
  "     "
  "     "
  "0   0"
  " 0 0 "
  "  0  "
  "  0  "
  "  0  "
  "     " };

static Character small_Z = { 4,
  "    "
  "    "
  "0000"
  "   0"
  "  0 "
  " 0  "
  "0000"
  "    " };

static Character small_lsqbrack = { 2,
  "  "
  "  "
  "00"
  "0 "
  "0 "
  "0 "
  "00"
  "  " };

static Character small_backslash = { 3,
  "   "
  "   "
  "   "
  "0  "
  " 0 "
  "  0"
  "   "
  "   " };

static Character small_rsqbrack =  { 3,
  "  "
  "  "
  "00"
  " 0"
  " 0"
  " 0"
  "00"
  "  " };

static Character small_pow = { 3,
  "   "
  "   "
  " 0 "
  "0 0"
  "   "
  "   "
  "   "
  "   " };

static Character small_under = { 3,
  "   "
  "   "
  "   "
  "   "
  "   "
  "   "
  "000"
  "   " };

static Character small_backtick = { 3,
  "  "
  "  "
  "0 "
  " 0"
  "  "
  "  "
  "  "
  "  " };

static Character small_lbrace = { 3,
  "   "
  "   "
  " 00"
  " 0 "
  "0  "
  " 0 "
  " 00"
  "   " };

static Character small_pipe = { 1,
  " "
  " "
  "0"
  "0"
  "0"
  "0"
  "0"
  " " };

static Character small_rbrace = { 3,
  "   "
  "   "
  "00 "
  " 0 "
  "  0"
  " 0 "
  "00 "
  "   " };

static Character small_tilde = { 5,
  "     "
  "     "
  "     "
  " 0   "
  "0 0 0"
  "   0 "
  "     "
  "     " };

/******************************************** Big Font *******************************************/

static Character big_blank = { 5,
  "     "
  "     "
  "     "
  "     "
  "     "
  "     "
  "     "
  "     " };

static Character big_excl = { 5,
  "     "
  "  0  "
  "  0  "
  "  0  "
  "  0  "
  "     "
  "  0  "
  "     " };

static Character big_quot = { 5,
  "     "
  " 00  "
  " 00  "
  "  00 "
  "     "
  "     "
  "     "
  "     " };

static Character big_hash = { 5,
  "     "
  "     "
  " 0 0 "
  "00000"
  " 0 0 "
  "00000"
  " 0 0 "
  "     " };

static Character big_dollar = { 5,
  "     "
  "  0  "
  " 0000"
  "0 0  "
  " 000 "
  "  0 0"
  "0000 "
  "  0  " };

static Character big_perc = { 5,
  "     "
  "     "
  " 0  0"
  "   0 "
  "  0  "
  " 0   "
  "0  0 "
  "     " };

static Character big_amp = { 5,
  "     "
  "     "
  " 00  "
  "0  0 "
  " 00  "
  "0  00"
  " 00 0"
  "     " };

static Character big_squot = { 5,
  "     "
  "  0  "
  "  0  "
  "   0 "
  "     "
  "     "
  "     "
  "     " };

static Character big_lparen = { 5,
  "     "
  "  00 "
  " 0   "
  " 0   "
  " 0   "
  " 0   "
  "  00 "
  "     " };

static Character big_rparen = { 5,
  "     "
  " 00  "
  "   0 "
  "   0 "
  "   0 "
  "   0 "
  " 00  "
  "     " };

static Character big_mult = { 5,
  "     "
  "     "
  "0 0 0"
  " 000 "
  "00000"
  " 000 "
  "0 0 0"
  "     " };

static Character big_plus = { 5,
  "     "
  "     "
  "  0  "
  "  0  "
  "00000"
  "  0  "
  "  0  "
  "     " };

static Character big_comma = { 5,
  "     "
  "     "
  "     "
  "     "
  "     "
  "  0  "
  "  0  "
  " 0   " };

static Character big_minus = { 5,
  "     "
  "     "
  "     "
  "     "
  "00000"
  "     "
  "     "
  "     " };

static Character big_dot = { 5,
  "     "
  "     "
  "     "
  "     "
  "     "
  "     "
  "  0  "
  "     " };

static Character big_div = { 5,
  "     "
  "     "
  "    0"
  "   0 "
  "  0  "
  " 0   "
  "0    "
  "     " };

static Character big_0 = { 5,
  "     "
  " 000 "
  "0   0"
  "0  00"
  "0 0 0"
  "00  0"
  " 000 "
  "     " };

static Character big_1 = { 5,
  "     "
  "  0  "
  " 00  "
  "0 0  "
  "  0  "
  "  0  "
  "00000"
  "     " };

static Character big_2 = { 5,
  "     "
  " 000 "
  "0   0"
  "   0 "
  "  0  "
  " 0   "
  "00000"
  "     " };

static Character big_3 = { 5,
  "     "
  " 000 "
  "0   0"
  "  00 "
  "    0"
  "0   0"
  " 000 "
  "     " };

static Character big_4 = { 5,
  "     "
  "   00"
  "  0 0"
  " 0  0"
  "00000"
  "    0"
  "    0"
  "     " };

static Character big_5 = { 5,
  "     "
  "00000"
  "0    "
  "0000 "
  "    0"
  "0   0"
  " 000 "
  "     " };

static Character big_6 = { 5,
  "     "
  " 000 "
  "0    "
  "0000 "
  "0   0"
  "0   0"
  " 000 "
  "     " };

static Character big_7 = { 5,
  "     "
  "00000"
  "    0"
  "   0 "
  "  0  "
  " 0   "
  "0    "
  "     " };

static Character big_8 = { 5,
  "     "
  " 000 "
  "0   0"
  " 000 "
  "0   0"
  "0   0"
  " 000 "
  "     " };

static Character big_9 = { 5,
  "     "
  " 000 "
  "0   0"
  "0   0"
  " 0000"
  "    0"
  " 000 "
  "     " };

static Character big_colon = { 5,
  "     "
  "     "
  "     "
  "  0  "
  "     "
  "  0  "
  "     "
  "     " };

static Character big_semi = { 5,
  "     "
  "     "
  "     "
  "  0  "
  "     "
  "  0  "
  "  0  "
  " 0   " };

static Character big_lt = { 5,
  "     "
  "     "
  "   0 "
  "  0  "
  " 0   "
  "  0  "
  "   0 "
  "     " };

static Character big_eq = { 5,
  "     "
  "     "
  "     "
  "00000"
  "     "
  "00000"
  "     "
  "     " };

static Character big_gt = { 5,
  "     "
  "     "
  " 0   "
  "  0  "
  "   0 "
  "  0  "
  " 0   "
  "     " };

static Character big_quest = { 5,
  "     "
  " 000 "
  "0   0"
  "   0 "
  "  0  "
  "     "
  "  0  "
  "     " };

static Character big_at = { 5,
  "     "
  "     "
  " 000 "
  "0 0 0"
  "0  0 "
  "0    "
  " 000 "
  "     " };

static Character big_A = { 5,
  "     "
  " 000 "
  "0   0"
  "0   0"
  "00000"
  "0   0"
  "0   0"
  "     " };

static Character big_B = { 5,
  "     "
  "0000 "
  "0   0"
  "0000 "
  "0   0"
  "0   0"
  "0000 "
  "     " };

static Character big_C = { 5,
  "     "
  " 000 "
  "0   0"
  "0    "
  "0    "
  "0   0"
  " 000 "
  "     " };

static Character big_D = { 5,
  "     "
  "0000 "
  "0   0"
  "0   0"
  "0   0"
  "0   0"
  "0000 "
  "     " };

static Character big_E = { 5,
  "     "
  "00000"
  "0    "
  "0000 "
  "0    "
  "0    "
  "00000"
  "     " };

static Character big_F = { 5,
  "     "
  "00000"
  "0    "
  "0000 "
  "0    "
  "0    "
  "0    "
  "     " };

static Character big_G = { 5,
  "     "
  " 000 "
  "0   0"
  "0    "
  "0 000"
  "0   0"
  " 000 "
  "     " };

static Character big_H = { 5,
  "     "
  "0   0"
  "0   0"
  "00000"
  "0   0"
  "0   0"
  "0   0"
  "     " };

static Character big_I = { 5,
  "     "
  " 000 "
  "  0  "
  "  0  "
  "  0  "
  "  0  "
  " 000 "
  "     " };

static Character big_J = { 5,
  "     "
  "    0"
  "    0"
  "    0"
  "0   0"
  "0   0"
  " 000 "
  "     " };

static Character big_K = { 5,
  "     "
  "0   0"
  "0  0 "
  "000  "
  "0 0  "
  "0  0 "
  "0   0"
  "     " };

static Character big_L = { 5,
  "     "
  "0    "
  "0    "
  "0    "
  "0    "
  "0    "
  "00000"
  "     " };

static Character big_M = { 5,
  "     "
  "0   0"
  "00 00"
  "0 0 0"
  "0   0"
  "0   0"
  "0   0"
  "     " };

static Character big_N = { 5,
  "     "
  "0   0"
  "00  0"
  "0 0 0"
  "0  00"
  "0   0"
  "0   0"
  "     " };

static Character big_O = { 5,
  "     "
  " 000 "
  "0   0"
  "0   0"
  "0   0"
  "0   0"
  " 000 "
  "     " };

static Character big_P = { 5,
  "     "
  "0000 "
  "0   0"
  "0   0"
  "0000 "
  "0    "
  "0    "
  "     " };

static Character big_Q = { 5,
  "     "
  " 000 "
  "0   0"
  "0   0"
  "0 0 0"
  "0  0 "
  " 00 0"
  "     " };

static Character big_R = { 5,
  "     "
  "0000 "
  "0   0"
  "0   0"
  "0000 "
  "0  0 "
  "0   0"
  "     " };

static Character big_S = { 5,
  "     "
  " 0000"
  "0    "
  " 000 "
  "    0"
  "    0"
  "0000 "
  "     " };

static Character big_T = { 5,
  "     "
  "00000"
  "  0  "
  "  0  "
  "  0  "
  "  0  "
  "  0  "
  "     " };

static Character big_U = { 5,
  "     "
  "0   0"
  "0   0"
  "0   0"
  "0   0"
  "0   0"
  " 000 "
  "     " };

static Character big_V = { 5,
  "     "
  "0   0"
  "0   0"
  "0   0"
  "0   0"
  " 0 0 "
  "  0  "
  "     " };

static Character big_W = { 5,
  "     "
  "0   0"
  "0   0"
  "0   0"
  "0 0 0"
  "0 0 0"
  " 0 0 "
  "     " };

static Character big_X = { 5,
  "     "
  "0   0"
  " 0 0 "
  "  0  "
  "  0  "
  " 0 0 "
  "0   0"
  "     " };

static Character big_Y = { 5,
  "     "
  "0   0"
  " 0 0 "
  "  0  "
  "  0  "
  "  0  "
  "  0  "
  "     " };

static Character big_Z = { 5,
  "     "
  "00000"
  "   0 "
  "  0  "
  " 0   "
  "0    "
  "00000"
  "     " };

static Character big_lsqbrack = { 5,
  "     "
  " 000 "
  " 0   "
  " 0   "
  " 0   "
  " 0   "
  " 000 "
  "     " };

static Character big_backslash = { 5,
  "     "
  "     "
  "0    "
  " 0   "
  "  0  "
  "   0 "
  "    0"
  "     " };

static Character big_rsqbrack =  { 5,
  "     "
  " 000 "
  "   0 "
  "   0 "
  "   0 "
  "   0 "
  " 000 "
  "     " };

static Character big_pow = { 5,
  "     "
  "  0  "
  " 0 0 "
  "0   0"
  "     "
  "     "
  "     "
  "     " };

static Character big_under = { 5,
  "     "
  "     "
  "     "
  "     "
  "     "
  "     "
  "     "
  "00000" };

static Character big_backtick = { 5,
  "     "
  " 0   "
  "  0  "
  "     "
  "     "
  "     "
  "     "
  "     " };

static Character big_lbrace = { 5,
  "   00"
  "  0  "
  "  0  "
  " 0   "
  "  0  "
  "  0  "
  "   00"
  "     " };

static Character big_pipe = { 5,
  "     "
  "  0  "
  "  0  "
  "  0  "
  "  0  "
  "  0  "
  "  0  "
  "     " };

static Character big_rbrace = { 5,
  "00   "
  "  0  "
  "  0  "
  "   0 "
  "  0  "
  "  0  "
  "00   "
  "     " };

static Character big_tilde = { 5,
  "     "
  "     "
  "     "
  " 0   "
  "0 0 0"
  "   0 "
  "     "
  "     " };

struct Font {
  byte height;
  char* chars;
  Character** data;
};

Character* tinyChars[] = {
  &tiny_blank, &tiny_0, &tiny_1, &tiny_2, &tiny_3, &tiny_4, &tiny_5, &tiny_6, &tiny_7, &tiny_8, &tiny_9
};
struct Font tinyFont = { 4, " 0123456789", tinyChars };

Character* smallChars[] = {
  &small_blank, &small_excl, &small_quot, &small_hash, &small_dollar, &small_perc, &small_amp, &small_squot, &small_lparen, &small_rparen, &small_mult, &small_plus, &small_comma, &small_minus, &small_dot, &small_div,
  &small_0, &small_1, &small_2, &small_3, &small_4, &small_5, &small_6, &small_7, &small_8, &small_9,
  &small_colon, &small_semi, &small_lt, &small_eq, &small_gt, &small_quest, &small_at,
  &small_A, &small_B, &small_C, &small_D, &small_E, &small_F, &small_G, &small_H, &small_I, &small_J, &small_K, &small_L, &small_M, &small_N, &small_O, &small_P, &small_Q, &small_R, &small_S, &small_T, &small_U, &small_V, &small_W, &small_X, &small_Y, &small_Z,
  &small_lsqbrack, &small_backslash, &small_rsqbrack, &small_pow, &small_under, &small_backtick, &small_lbrace, &small_pipe, &small_rbrace, &small_tilde
};
struct Font smallFont = { 8, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`{|}~", smallChars };

Character* bigChars[] = {
  &big_blank, &big_excl, &big_quot, &big_hash, &big_dollar, &big_perc, &big_amp, &big_squot, &big_lparen, &big_rparen, &big_mult, &big_plus, &big_comma, &big_minus, &big_dot, &big_div,
  &big_0, &big_1, &big_2, &big_3, &big_4, &big_5, &big_6, &big_7, &big_8, &big_9,
  &big_colon, &big_semi, &big_lt, &big_eq, &big_gt, &big_quest, &big_at,
  &big_A, &big_B, &big_C, &big_D, &big_E, &big_F, &big_G, &big_H, &big_I, &big_J, &big_K, &big_L, &big_M, &big_N, &big_O, &big_P, &big_Q, &big_R, &big_S, &big_T, &big_U, &big_V, &big_W, &big_X, &big_Y, &big_Z,
  &big_lsqbrack, &big_backslash, &big_rsqbrack, &big_pow, &big_under, &big_backtick, &big_lbrace, &big_pipe, &big_rbrace, &big_tilde
};
struct Font bigFont = { 8, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`{|}~", bigChars };

unsigned font_width_string(char* str, struct Font* font) {
  unsigned width = 0;
  char c;
  while ((c=*str++) != 0) {
    char* p = strchr(font->chars,c);
    if (p) {
      width += (font->data[p - font->chars]->width + 1);
    }
  }

  return width;
}

// Draw a string of characters starting at a specific column/row
void font_draw_string(int col, int row, char* str, byte color, struct Font* font, boolean erase, boolean reversed) {
  int i;
  if (reversed) { i = strlen(str) - 1; }
  else          { i = 0; }

  while ((reversed && i >= 0) || (!reversed && i < strlen(str))) {
    char c = str[i];
    char* p = strchr(font->chars, c);
    if (p) {
      int i = p - font->chars;                        // offset into font_chars gives character index
      font_draw_char(col, row, font->data[i]->data, color, font->data[i]->width, font->height, erase, reversed);
      col += (font->data[i]->width + 1);
      if (erase) {
        font_draw_blank_column(col,row,font->height);     // 1 blank pixel between characters
      }
    }

    if (reversed) { --i; }
    else          { ++i; }
    
    performContinuousTasks(micros());
  }
}

void tinyfont_draw_string(int col, int row, char* str, byte color) {
  tinyfont_draw_string(col, row, str, color, true);
}

void tinyfont_draw_string(int col, int row, char* str, byte color, boolean erase) {
  tinyfont_draw_string(col, row, str, color, erase, false);
}

void tinyfont_draw_string(int col, int row, char* str, byte color, boolean erase, boolean reversed) {
  font_draw_string(col, row, str, color, &tinyFont, erase, reversed);
}

void smallfont_draw_string(int col, int row, char* str, byte color) {
  smallfont_draw_string(col, row, str, color, true);
}

void smallfont_draw_string(int col, int row, char* str, byte color, boolean erase) {
  smallfont_draw_string(col, row, str, color, erase, false);
}

void smallfont_draw_string(int col, int row, char* str, byte color, boolean erase, boolean reversed) {
  font_draw_string(col, row, str, color, &smallFont, erase, reversed);
}

void bigfont_draw_string(int col, int row, char* str, byte color) {
  bigfont_draw_string(col, row, str, color, true);
}

void bigfont_draw_string(int col, int row, char* str, byte color, boolean erase) {
  bigfont_draw_string(col, row, str, color, erase, false);
}

void bigfont_draw_string(int col, int row, char* str, byte color, boolean erase, boolean reversed) {
  font_draw_string(col, row, str, color, &bigFont, erase, reversed);
}

// Draw a single character at col,row
static void font_draw_char(int col, int row, char* fontdata, byte color, byte width, byte height, boolean erase, boolean reversed)
{
  for (byte r = 0; r < height; ++r) {
    for (byte c = 0; c < width; ++c) {
      char thechar = *fontdata++;

      int destcol;
      int destrow;

      if (reversed) {
        destcol = col + width - c;
        destrow = row + r;
      }
      else {
        destcol = col + c + 1;
        destrow = row + height - 1 - r;
      }

      if (destcol < 1 || destcol >= NUMCOLS || destrow < 0 || destrow > 7) {
        continue;
      }
      if (erase || thechar != ' ') {
        setLed(destcol, destrow, (thechar != ' ' ? color : 0), cellOn);
      }
    }
  }
}

// Draw a single-pixel-wide blank column
static void font_draw_blank_column(int col, int row, byte height)
{
  if (col >= 0 && col < NUMCOLS) {
    for (byte r = row; r < height; ++r) {
      setLed(col, r, 0, cellOn);
    }
  }
}

void small_scroll_text_flipped(char* str, byte color) {
  font_scroll_text_flipped(&smallFont, str, color);
}

void big_scroll_text_flipped(char* str, byte color) {
  font_scroll_text_flipped(&bigFont, str, color);
}

void font_scroll_text_flipped(struct Font* font, char* str, byte color) {
  unsigned long origInterval = ledRefreshInterval;
  ledRefreshInterval = 200;

  animationActive = true;
  stopAnimation = false;

  int totalwidth = font_width_string(str, font);
  int i;
  for (i = totalwidth; i >= -NUMCOLS && !stopAnimation; --i) {
    font_draw_string( -i, 0, str, color, font, true, true);

    if (i < 0) {
      for (byte col = 0; col <= -i; ++col) {
        for (byte row = 0; row < font->height; ++row) {
          clearLed(col, row);
        }
      }
    }

    delayUsecWithScanning(40000);
  }

  clearDisplay();

  animationActive = false;

  ledRefreshInterval = origInterval;
}

void small_scroll_text(char* str, byte color) {
  font_scroll_text(&smallFont, str, color);
}

void big_scroll_text(char* str, byte color) {
  font_scroll_text(&bigFont, str, color);
}

void font_scroll_text(struct Font* font, char* str, byte color) {
  unsigned long origInterval = ledRefreshInterval;
  ledRefreshInterval = 200;

  animationActive = true;
  stopAnimation = false;

  int totalwidth = font_width_string(str, font);
  for (int i = 0; i < totalwidth && !stopAnimation; ++i) {
    font_draw_string( -i, 0, str, color, font, true, false);
    delayUsecWithScanning(40000);
  }

  clearDisplay();

  animationActive = false;

  ledRefreshInterval = origInterval;
}
