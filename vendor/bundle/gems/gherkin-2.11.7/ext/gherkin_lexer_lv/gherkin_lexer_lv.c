
#line 1 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
#include <assert.h>
#include <ruby.h>

#if defined(_WIN32)
#include <stddef.h>
#endif

#ifdef HAVE_RUBY_RE_H
#include <ruby/re.h>
#else
#include <re.h>
#endif

#ifdef HAVE_RUBY_ENCODING_H
#include <ruby/encoding.h>
#define ENCODED_STR_NEW(ptr, len) \
    rb_enc_str_new(ptr, len, rb_utf8_encoding())
#else
#define ENCODED_STR_NEW(ptr, len) \
    rb_str_new(ptr, len)
#endif

#ifndef RSTRING_PTR
#define RSTRING_PTR(s) (RSTRING(s)->ptr)
#endif

#ifndef RSTRING_LEN
#define RSTRING_LEN(s) (RSTRING(s)->len)
#endif

#define DATA_GET(FROM, TYPE, NAME) \
  Data_Get_Struct(FROM, TYPE, NAME); \
  if (NAME == NULL) { \
    rb_raise(rb_eArgError, "NULL found for " # NAME " when it shouldn't be."); \
  }
 
typedef struct lexer_state {
  int content_len;
  int line_number;
  int current_line;
  int start_col;
  size_t mark;
  size_t keyword_start;
  size_t keyword_end;
  size_t next_keyword_start;
  size_t content_start;
  size_t content_end;
  size_t docstring_content_type_start;
  size_t docstring_content_type_end;
  size_t query_start;
  size_t last_newline;
  size_t final_newline;
} lexer_state;

static VALUE mGherkin;
static VALUE mGherkinLexer;
static VALUE mCLexer;
static VALUE cI18nLexer;
static VALUE rb_eGherkinLexingError;

#define LEN(AT, P) (P - data - lexer->AT)
#define MARK(M, P) (lexer->M = (P) - data)
#define PTR_TO(P) (data + lexer->P)

#define STORE_KW_END_CON(EVENT) \
  store_multiline_kw_con(listener, # EVENT, \
    PTR_TO(keyword_start), LEN(keyword_start, PTR_TO(keyword_end - 1)), \
    PTR_TO(content_start), LEN(content_start, PTR_TO(content_end)), \
    lexer->current_line, lexer->start_col); \
    if (lexer->content_end != 0) { \
      p = PTR_TO(content_end - 1); \
    } \
    lexer->content_end = 0

#define STORE_ATTR(ATTR) \
    store_attr(listener, # ATTR, \
      PTR_TO(content_start), LEN(content_start, p), \
      lexer->line_number)


#line 254 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"


/** Data **/

#line 89 "ext/gherkin_lexer_lv/gherkin_lexer_lv.c"
static const char _lexer_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 12, 1, 13, 1, 16, 1, 
	17, 1, 18, 1, 19, 1, 20, 1, 
	21, 1, 22, 1, 23, 2, 1, 18, 
	2, 4, 5, 2, 13, 0, 2, 14, 
	15, 2, 17, 0, 2, 17, 2, 2, 
	17, 16, 2, 17, 19, 2, 18, 6, 
	2, 18, 7, 2, 18, 8, 2, 18, 
	9, 2, 18, 10, 2, 18, 16, 2, 
	20, 21, 2, 22, 0, 2, 22, 2, 
	2, 22, 16, 2, 22, 19, 3, 3, 
	14, 15, 3, 5, 14, 15, 3, 11, 
	14, 15, 3, 12, 14, 15, 3, 13, 
	14, 15, 3, 14, 15, 18, 3, 17, 
	0, 11, 3, 17, 14, 15, 4, 1, 
	14, 15, 18, 4, 4, 5, 14, 15, 
	4, 17, 0, 14, 15, 5, 17, 0, 
	11, 14, 15
};

static const short _lexer_key_offsets[] = {
	0, 0, 19, 20, 21, 39, 40, 41, 
	43, 45, 50, 55, 60, 65, 69, 73, 
	75, 76, 77, 78, 79, 80, 81, 82, 
	83, 84, 85, 86, 87, 88, 89, 90, 
	91, 93, 95, 100, 107, 112, 113, 114, 
	116, 117, 118, 119, 120, 121, 122, 123, 
	134, 136, 138, 140, 142, 144, 146, 148, 
	150, 152, 154, 156, 158, 160, 162, 165, 
	167, 169, 171, 173, 175, 193, 194, 196, 
	197, 198, 199, 200, 201, 202, 203, 204, 
	205, 206, 207, 222, 224, 226, 228, 230, 
	232, 234, 236, 238, 240, 242, 244, 246, 
	248, 250, 252, 254, 256, 259, 261, 263, 
	265, 267, 269, 271, 273, 275, 277, 279, 
	281, 283, 285, 287, 289, 291, 293, 295, 
	297, 299, 301, 303, 305, 307, 309, 311, 
	313, 315, 317, 319, 321, 324, 326, 328, 
	330, 332, 334, 336, 338, 340, 342, 344, 
	346, 348, 350, 351, 352, 353, 354, 355, 
	356, 357, 358, 365, 368, 370, 372, 374, 
	376, 378, 380, 382, 384, 386, 388, 390, 
	392, 394, 396, 398, 400, 402, 404, 406, 
	407, 408, 409, 410, 411, 412, 414, 415, 
	416, 417, 418, 419, 420, 421, 422, 424, 
	425, 426, 427, 428, 429, 430, 431, 432, 
	433, 434, 435, 436, 437, 438, 439, 454, 
	456, 458, 460, 462, 464, 466, 468, 470, 
	472, 474, 476, 478, 480, 482, 484, 486, 
	488, 491, 493, 495, 497, 499, 501, 503, 
	505, 507, 509, 511, 513, 515, 517, 519, 
	521, 523, 525, 527, 529, 531, 533, 535, 
	537, 539, 541, 543, 545, 547, 549, 551, 
	553, 555, 556, 557, 572, 574, 576, 578, 
	580, 582, 584, 586, 588, 590, 592, 594, 
	596, 598, 600, 602, 604, 606, 609, 611, 
	613, 615, 617, 619, 621, 623, 625, 627, 
	629, 631, 633, 635, 637, 639, 641, 643, 
	645, 647, 649, 652, 654, 656, 658, 660, 
	662, 664, 666, 668, 671, 673, 675, 677, 
	679, 681, 683, 685, 687, 690, 692, 694, 
	696, 698, 700, 702, 704, 706, 708, 710, 
	712, 714, 716, 718, 720, 722, 724, 726, 
	728, 730, 731, 732, 733, 734, 735, 736, 
	737, 738, 739, 740, 744, 750, 753, 755, 
	761, 779, 781, 783, 785, 787, 789, 791, 
	793, 795, 797, 799, 801, 803, 805, 807, 
	809, 811, 813, 815, 817, 819, 821, 823, 
	826, 828, 830, 832, 834, 836, 838, 840, 
	842, 844, 846, 849, 851, 853, 855, 857, 
	859, 861, 863, 865, 868, 870, 872, 874, 
	876, 878, 880, 882, 884, 886, 888, 890, 
	892, 894, 896, 898, 900, 902, 904, 905, 
	906, 907, 908, 909, 910, 911, 912, 913, 
	914, 915, 916, 917, 918
};

static const char _lexer_trans_keys[] = {
	-17, 10, 32, 34, 35, 37, 42, 64, 
	66, 70, 74, 75, 80, 83, 84, 85, 
	124, 9, 13, -69, -65, 10, 32, 34, 
	35, 37, 42, 64, 66, 70, 74, 75, 
	80, 83, 84, 85, 124, 9, 13, 34, 
	34, 10, 13, 10, 13, 10, 32, 34, 
	9, 13, 10, 32, 34, 9, 13, 10, 
	32, 34, 9, 13, 10, 32, 34, 9, 
	13, 10, 32, 9, 13, 10, 32, 9, 
	13, 10, 13, 10, 95, 70, 69, 65, 
	84, 85, 82, 69, 95, 69, 78, 68, 
	95, 37, 32, 10, 13, 10, 13, 13, 
	32, 64, 9, 10, 9, 10, 13, 32, 
	64, 11, 12, 10, 32, 64, 9, 13, 
	101, 116, -60, 117, -85, -60, -115, 97, 
	58, 10, 10, 10, 32, 35, 37, 64, 
	70, 75, 80, 83, 9, 13, 10, 95, 
	10, 70, 10, 69, 10, 65, 10, 84, 
	10, 85, 10, 82, 10, 69, 10, 95, 
	10, 69, 10, 78, 10, 68, 10, 95, 
	10, 37, -60, 10, 117, -85, 10, -60, 
	10, -115, 10, 10, 97, 10, 58, 10, 
	32, 34, 35, 37, 42, 64, 66, 70, 
	74, 75, 80, 83, 84, 85, 124, 9, 
	13, 97, 97, 111, 100, 110, 116, 101, 
	107, 115, 116, 115, 58, 10, 10, 10, 
	32, 35, 37, 42, 64, 66, 70, 74, 
	75, 83, 84, 85, 9, 13, 10, 95, 
	10, 70, 10, 69, 10, 65, 10, 84, 
	10, 85, 10, 82, 10, 69, 10, 95, 
	10, 69, 10, 78, 10, 68, 10, 95, 
	10, 37, 10, 32, 10, 101, 10, 116, 
	-60, 10, 117, -85, 10, -60, 10, -115, 
	10, 10, 97, 10, 58, 10, 110, 10, 
	107, 10, 99, 10, 105, 10, 111, 10, 
	110, 10, 97, 10, 108, 10, 105, 10, 
	116, -60, 10, -127, 10, 10, 116, 10, 
	101, 10, 97, 10, 97, 10, 100, 10, 
	99, 10, 101, 10, 110, -60, 10, -127, 
	10, 10, 114, 10, 105, 10, 106, 10, 
	115, 10, 32, 58, 10, 112, -60, 10, 
	-109, 10, 10, 99, 10, 32, 10, 112, 
	10, 97, 10, 114, 10, 97, 10, 117, 
	10, 103, 10, 110, 97, 105, 114, 97, 
	117, 103, 115, 58, 10, 10, 10, 32, 
	35, 70, 124, 9, 13, -60, 10, 117, 
	-85, 10, -60, 10, -115, 10, 10, 97, 
	10, 58, 10, 110, 10, 107, 10, 99, 
	10, 105, 10, 111, 10, 110, 10, 97, 
	10, 108, 10, 105, 10, 116, -60, 10, 
	-127, 10, 10, 116, 10, 101, 101, 109, 
	-60, -109, 114, 105, 99, 105, 101, 110, 
	-60, -127, 114, 105, 106, 115, 32, 58, 
	112, -60, -109, 99, 32, 112, 97, 114, 
	97, 117, 103, 97, 58, 10, 10, 10, 
	32, 35, 37, 42, 64, 66, 70, 74, 
	75, 83, 84, 85, 9, 13, 10, 95, 
	10, 70, 10, 69, 10, 65, 10, 84, 
	10, 85, 10, 82, 10, 69, 10, 95, 
	10, 69, 10, 78, 10, 68, 10, 95, 
	10, 37, 10, 32, 10, 101, 10, 116, 
	-60, 10, 117, -85, 10, -60, 10, -115, 
	10, 10, 97, 10, 58, 10, 110, 10, 
	107, 10, 99, 10, 105, 10, 111, 10, 
	110, 10, 97, 10, 108, 10, 105, 10, 
	116, -60, 10, -127, 10, 10, 116, 10, 
	101, 10, 97, 10, 97, 10, 100, 10, 
	99, 10, 101, 10, 110, -60, 10, -127, 
	10, 10, 114, 10, 105, 10, 106, 10, 
	115, 10, 110, 10, 10, 10, 32, 35, 
	37, 42, 64, 66, 70, 74, 75, 83, 
	84, 85, 9, 13, 10, 95, 10, 70, 
	10, 69, 10, 65, 10, 84, 10, 85, 
	10, 82, 10, 69, 10, 95, 10, 69, 
	10, 78, 10, 68, 10, 95, 10, 37, 
	10, 32, 10, 101, 10, 116, -60, 10, 
	117, -85, 10, -60, 10, -115, 10, 10, 
	97, 10, 58, 10, 110, 10, 107, 10, 
	99, 10, 105, 10, 111, 10, 110, 10, 
	97, 10, 108, 10, 105, 10, 116, -60, 
	10, -127, 10, 10, 116, 10, 101, 10, 
	97, 10, 97, 111, 10, 100, 10, 110, 
	10, 116, 10, 101, 10, 107, 10, 115, 
	10, 116, 10, 115, 10, 99, 105, 10, 
	101, 10, 110, -60, 10, -127, 10, 10, 
	114, 10, 105, 10, 106, 10, 115, 10, 
	32, 58, 10, 112, -60, 10, -109, 10, 
	10, 99, 10, 32, 10, 112, 10, 97, 
	10, 114, 10, 97, 10, 117, 10, 103, 
	10, 116, 10, 117, -60, 10, -127, 10, 
	10, 99, 10, 105, 10, 106, 10, 97, 
	10, 110, 116, 117, -60, -127, 99, 105, 
	106, 97, 97, 110, 32, 124, 9, 13, 
	10, 32, 92, 124, 9, 13, 10, 92, 
	124, 10, 92, 10, 32, 92, 124, 9, 
	13, 10, 32, 34, 35, 37, 42, 64, 
	66, 70, 74, 75, 80, 83, 84, 85, 
	124, 9, 13, 10, 110, 10, 107, 10, 
	99, 10, 105, 10, 111, 10, 110, 10, 
	97, 10, 108, 10, 105, 10, 116, -60, 
	10, -127, 10, 10, 116, 10, 101, 10, 
	111, 10, 110, 10, 116, 10, 101, 10, 
	107, 10, 115, 10, 116, 10, 115, 10, 
	97, 105, 10, 114, 10, 97, 10, 117, 
	10, 103, 10, 101, 10, 109, -60, 10, 
	-109, 10, 10, 114, 10, 105, 10, 99, 
	105, 10, 101, 10, 110, -60, 10, -127, 
	10, 10, 114, 10, 105, 10, 106, 10, 
	115, 10, 32, 58, 10, 112, -60, 10, 
	-109, 10, 10, 99, 10, 32, 10, 112, 
	10, 97, 10, 114, 10, 97, 10, 117, 
	10, 103, 10, 116, 10, 117, -60, 10, 
	-127, 10, 10, 99, 10, 105, 10, 106, 
	110, 107, 99, 105, 111, 110, 97, 108, 
	105, 116, -60, -127, 116, 101, 0
};

static const char _lexer_single_lengths[] = {
	0, 17, 1, 1, 16, 1, 1, 2, 
	2, 3, 3, 3, 3, 2, 2, 2, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	2, 2, 3, 5, 3, 1, 1, 2, 
	1, 1, 1, 1, 1, 1, 1, 9, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 3, 2, 
	2, 2, 2, 2, 16, 1, 2, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 13, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 3, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 3, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 1, 1, 1, 1, 1, 1, 
	1, 1, 5, 3, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 1, 
	1, 1, 1, 1, 1, 2, 1, 1, 
	1, 1, 1, 1, 1, 1, 2, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 13, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	3, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 1, 1, 13, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 3, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 3, 2, 2, 2, 2, 2, 
	2, 2, 2, 3, 2, 2, 2, 2, 
	2, 2, 2, 2, 3, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 2, 4, 3, 2, 4, 
	16, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 3, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 3, 2, 2, 2, 2, 2, 
	2, 2, 2, 3, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 0
};

static const char _lexer_range_lengths[] = {
	0, 1, 0, 0, 1, 0, 0, 0, 
	0, 1, 1, 1, 1, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 0, 0, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};

static const short _lexer_index_offsets[] = {
	0, 0, 19, 21, 23, 41, 43, 45, 
	48, 51, 56, 61, 66, 71, 75, 79, 
	82, 84, 86, 88, 90, 92, 94, 96, 
	98, 100, 102, 104, 106, 108, 110, 112, 
	114, 117, 120, 125, 132, 137, 139, 141, 
	144, 146, 148, 150, 152, 154, 156, 158, 
	169, 172, 175, 178, 181, 184, 187, 190, 
	193, 196, 199, 202, 205, 208, 211, 215, 
	218, 221, 224, 227, 230, 248, 250, 253, 
	255, 257, 259, 261, 263, 265, 267, 269, 
	271, 273, 275, 290, 293, 296, 299, 302, 
	305, 308, 311, 314, 317, 320, 323, 326, 
	329, 332, 335, 338, 341, 345, 348, 351, 
	354, 357, 360, 363, 366, 369, 372, 375, 
	378, 381, 384, 387, 390, 393, 396, 399, 
	402, 405, 408, 411, 414, 417, 420, 423, 
	426, 429, 432, 435, 438, 442, 445, 448, 
	451, 454, 457, 460, 463, 466, 469, 472, 
	475, 478, 481, 483, 485, 487, 489, 491, 
	493, 495, 497, 504, 508, 511, 514, 517, 
	520, 523, 526, 529, 532, 535, 538, 541, 
	544, 547, 550, 553, 556, 559, 562, 565, 
	567, 569, 571, 573, 575, 577, 580, 582, 
	584, 586, 588, 590, 592, 594, 596, 599, 
	601, 603, 605, 607, 609, 611, 613, 615, 
	617, 619, 621, 623, 625, 627, 629, 644, 
	647, 650, 653, 656, 659, 662, 665, 668, 
	671, 674, 677, 680, 683, 686, 689, 692, 
	695, 699, 702, 705, 708, 711, 714, 717, 
	720, 723, 726, 729, 732, 735, 738, 741, 
	744, 747, 750, 753, 756, 759, 762, 765, 
	768, 771, 774, 777, 780, 783, 786, 789, 
	792, 795, 797, 799, 814, 817, 820, 823, 
	826, 829, 832, 835, 838, 841, 844, 847, 
	850, 853, 856, 859, 862, 865, 869, 872, 
	875, 878, 881, 884, 887, 890, 893, 896, 
	899, 902, 905, 908, 911, 914, 917, 920, 
	923, 926, 929, 933, 936, 939, 942, 945, 
	948, 951, 954, 957, 961, 964, 967, 970, 
	973, 976, 979, 982, 985, 989, 992, 995, 
	998, 1001, 1004, 1007, 1010, 1013, 1016, 1019, 
	1022, 1025, 1028, 1031, 1034, 1037, 1040, 1043, 
	1046, 1049, 1051, 1053, 1055, 1057, 1059, 1061, 
	1063, 1065, 1067, 1069, 1073, 1079, 1083, 1086, 
	1092, 1110, 1113, 1116, 1119, 1122, 1125, 1128, 
	1131, 1134, 1137, 1140, 1143, 1146, 1149, 1152, 
	1155, 1158, 1161, 1164, 1167, 1170, 1173, 1176, 
	1180, 1183, 1186, 1189, 1192, 1195, 1198, 1201, 
	1204, 1207, 1210, 1214, 1217, 1220, 1223, 1226, 
	1229, 1232, 1235, 1238, 1242, 1245, 1248, 1251, 
	1254, 1257, 1260, 1263, 1266, 1269, 1272, 1275, 
	1278, 1281, 1284, 1287, 1290, 1293, 1296, 1298, 
	1300, 1302, 1304, 1306, 1308, 1310, 1312, 1314, 
	1316, 1318, 1320, 1322, 1324
};

static const short _lexer_trans_targs[] = {
	2, 4, 4, 5, 15, 17, 31, 34, 
	37, 39, 69, 70, 145, 181, 345, 346, 
	347, 4, 0, 3, 0, 4, 0, 4, 
	4, 5, 15, 17, 31, 34, 37, 39, 
	69, 70, 145, 181, 345, 346, 347, 4, 
	0, 6, 0, 7, 0, 9, 8, 8, 
	9, 8, 8, 10, 10, 11, 10, 10, 
	10, 10, 11, 10, 10, 10, 10, 12, 
	10, 10, 10, 10, 13, 10, 10, 4, 
	14, 14, 0, 4, 14, 14, 0, 4, 
	16, 15, 4, 0, 18, 0, 19, 0, 
	20, 0, 21, 0, 22, 0, 23, 0, 
	24, 0, 25, 0, 26, 0, 27, 0, 
	28, 0, 29, 0, 30, 0, 428, 0, 
	32, 0, 4, 16, 33, 4, 16, 33, 
	0, 0, 0, 0, 35, 36, 4, 36, 
	36, 34, 35, 35, 4, 36, 34, 36, 
	0, 38, 0, 31, 0, 40, 414, 0, 
	41, 0, 42, 0, 43, 0, 44, 0, 
	45, 0, 47, 46, 47, 46, 47, 47, 
	4, 48, 4, 62, 367, 375, 386, 47, 
	46, 47, 49, 46, 47, 50, 46, 47, 
	51, 46, 47, 52, 46, 47, 53, 46, 
	47, 54, 46, 47, 55, 46, 47, 56, 
	46, 47, 57, 46, 47, 58, 46, 47, 
	59, 46, 47, 60, 46, 47, 61, 46, 
	47, 4, 46, 63, 47, 353, 46, 64, 
	47, 46, 65, 47, 46, 66, 47, 46, 
	47, 67, 46, 47, 68, 46, 4, 4, 
	5, 15, 17, 31, 34, 37, 39, 69, 
	70, 145, 181, 345, 346, 347, 4, 0, 
	31, 0, 71, 72, 0, 31, 0, 73, 
	0, 74, 0, 75, 0, 76, 0, 77, 
	0, 78, 0, 79, 0, 80, 0, 82, 
	81, 82, 81, 82, 82, 4, 83, 97, 
	4, 98, 100, 120, 121, 123, 121, 144, 
	82, 81, 82, 84, 81, 82, 85, 81, 
	82, 86, 81, 82, 87, 81, 82, 88, 
	81, 82, 89, 81, 82, 90, 81, 82, 
	91, 81, 82, 92, 81, 82, 93, 81, 
	82, 94, 81, 82, 95, 81, 82, 96, 
	81, 82, 4, 81, 82, 68, 81, 82, 
	99, 81, 82, 97, 81, 101, 82, 106, 
	81, 102, 82, 81, 103, 82, 81, 104, 
	82, 81, 82, 105, 81, 82, 68, 81, 
	82, 107, 81, 82, 108, 81, 82, 109, 
	81, 82, 110, 81, 82, 111, 81, 82, 
	112, 81, 82, 113, 81, 82, 114, 81, 
	82, 115, 81, 82, 116, 81, 117, 82, 
	81, 118, 82, 81, 82, 119, 81, 82, 
	105, 81, 82, 97, 81, 82, 122, 81, 
	82, 97, 81, 82, 124, 81, 82, 125, 
	81, 82, 126, 81, 127, 82, 81, 128, 
	82, 81, 82, 129, 81, 82, 130, 81, 
	82, 131, 81, 82, 132, 81, 82, 133, 
	68, 81, 82, 134, 81, 135, 82, 81, 
	136, 82, 81, 82, 137, 81, 82, 138, 
	81, 82, 139, 81, 82, 140, 81, 82, 
	141, 81, 82, 142, 81, 82, 143, 81, 
	82, 104, 81, 82, 97, 81, 146, 175, 
	0, 147, 0, 148, 0, 149, 0, 150, 
	0, 151, 0, 152, 0, 154, 153, 154, 
	153, 154, 154, 4, 155, 4, 154, 153, 
	156, 154, 161, 153, 157, 154, 153, 158, 
	154, 153, 159, 154, 153, 154, 160, 153, 
	154, 68, 153, 154, 162, 153, 154, 163, 
	153, 154, 164, 153, 154, 165, 153, 154, 
	166, 153, 154, 167, 153, 154, 168, 153, 
	154, 169, 153, 154, 170, 153, 154, 171, 
	153, 172, 154, 153, 173, 154, 153, 154, 
	174, 153, 154, 160, 153, 176, 0, 177, 
	0, 178, 0, 179, 0, 180, 0, 151, 
	0, 182, 337, 0, 183, 0, 184, 0, 
	185, 0, 186, 0, 187, 0, 188, 0, 
	189, 0, 190, 0, 191, 257, 0, 192, 
	0, 193, 0, 194, 0, 195, 0, 196, 
	0, 197, 0, 198, 0, 199, 0, 200, 
	0, 201, 0, 202, 0, 203, 0, 204, 
	0, 206, 205, 206, 205, 206, 206, 4, 
	207, 221, 4, 222, 224, 244, 245, 247, 
	245, 256, 206, 205, 206, 208, 205, 206, 
	209, 205, 206, 210, 205, 206, 211, 205, 
	206, 212, 205, 206, 213, 205, 206, 214, 
	205, 206, 215, 205, 206, 216, 205, 206, 
	217, 205, 206, 218, 205, 206, 219, 205, 
	206, 220, 205, 206, 4, 205, 206, 68, 
	205, 206, 223, 205, 206, 221, 205, 225, 
	206, 230, 205, 226, 206, 205, 227, 206, 
	205, 228, 206, 205, 206, 229, 205, 206, 
	68, 205, 206, 231, 205, 206, 232, 205, 
	206, 233, 205, 206, 234, 205, 206, 235, 
	205, 206, 236, 205, 206, 237, 205, 206, 
	238, 205, 206, 239, 205, 206, 240, 205, 
	241, 206, 205, 242, 206, 205, 206, 243, 
	205, 206, 229, 205, 206, 221, 205, 206, 
	246, 205, 206, 221, 205, 206, 248, 205, 
	206, 249, 205, 206, 250, 205, 251, 206, 
	205, 252, 206, 205, 206, 253, 205, 206, 
	254, 205, 206, 255, 205, 206, 229, 205, 
	206, 221, 205, 259, 258, 259, 258, 259, 
	259, 4, 260, 274, 4, 275, 277, 297, 
	298, 307, 335, 336, 259, 258, 259, 261, 
	258, 259, 262, 258, 259, 263, 258, 259, 
	264, 258, 259, 265, 258, 259, 266, 258, 
	259, 267, 258, 259, 268, 258, 259, 269, 
	258, 259, 270, 258, 259, 271, 258, 259, 
	272, 258, 259, 273, 258, 259, 4, 258, 
	259, 68, 258, 259, 276, 258, 259, 274, 
	258, 278, 259, 283, 258, 279, 259, 258, 
	280, 259, 258, 281, 259, 258, 259, 282, 
	258, 259, 68, 258, 259, 284, 258, 259, 
	285, 258, 259, 286, 258, 259, 287, 258, 
	259, 288, 258, 259, 289, 258, 259, 290, 
	258, 259, 291, 258, 259, 292, 258, 259, 
	293, 258, 294, 259, 258, 295, 259, 258, 
	259, 296, 258, 259, 282, 258, 259, 274, 
	258, 259, 299, 300, 258, 259, 274, 258, 
	259, 301, 258, 259, 302, 258, 259, 303, 
	258, 259, 304, 258, 259, 305, 258, 259, 
	306, 258, 259, 282, 258, 259, 308, 328, 
	258, 259, 309, 258, 259, 310, 258, 311, 
	259, 258, 312, 259, 258, 259, 313, 258, 
	259, 314, 258, 259, 315, 258, 259, 316, 
	258, 259, 317, 68, 258, 259, 318, 258, 
	319, 259, 258, 320, 259, 258, 259, 321, 
	258, 259, 322, 258, 259, 323, 258, 259, 
	324, 258, 259, 325, 258, 259, 326, 258, 
	259, 327, 258, 259, 281, 258, 259, 329, 
	258, 259, 330, 258, 331, 259, 258, 332, 
	259, 258, 259, 333, 258, 259, 334, 258, 
	259, 281, 258, 259, 299, 258, 259, 274, 
	258, 338, 0, 339, 0, 340, 0, 341, 
	0, 342, 0, 343, 0, 344, 0, 79, 
	0, 71, 0, 31, 0, 347, 348, 347, 
	0, 352, 351, 350, 348, 351, 349, 0, 
	350, 348, 349, 0, 350, 349, 352, 351, 
	350, 348, 351, 349, 352, 352, 5, 15, 
	17, 31, 34, 37, 39, 69, 70, 145, 
	181, 345, 346, 347, 352, 0, 47, 354, 
	46, 47, 355, 46, 47, 356, 46, 47, 
	357, 46, 47, 358, 46, 47, 359, 46, 
	47, 360, 46, 47, 361, 46, 47, 362, 
	46, 47, 363, 46, 364, 47, 46, 365, 
	47, 46, 47, 366, 46, 47, 67, 46, 
	47, 368, 46, 47, 369, 46, 47, 370, 
	46, 47, 371, 46, 47, 372, 46, 47, 
	373, 46, 47, 374, 46, 47, 67, 46, 
	47, 376, 380, 46, 47, 377, 46, 47, 
	378, 46, 47, 379, 46, 47, 374, 46, 
	47, 381, 46, 47, 382, 46, 383, 47, 
	46, 384, 47, 46, 47, 385, 46, 47, 
	67, 46, 47, 387, 407, 46, 47, 388, 
	46, 47, 389, 46, 390, 47, 46, 391, 
	47, 46, 47, 392, 46, 47, 393, 46, 
	47, 394, 46, 47, 395, 46, 47, 396, 
	68, 46, 47, 397, 46, 398, 47, 46, 
	399, 47, 46, 47, 400, 46, 47, 401, 
	46, 47, 402, 46, 47, 403, 46, 47, 
	404, 46, 47, 405, 46, 47, 406, 46, 
	47, 66, 46, 47, 408, 46, 47, 409, 
	46, 410, 47, 46, 411, 47, 46, 47, 
	412, 46, 47, 413, 46, 47, 66, 46, 
	415, 0, 416, 0, 417, 0, 418, 0, 
	419, 0, 420, 0, 421, 0, 422, 0, 
	423, 0, 424, 0, 425, 0, 426, 0, 
	427, 0, 44, 0, 0, 0
};

static const unsigned char _lexer_trans_actions[] = {
	0, 54, 0, 5, 1, 0, 29, 1, 
	29, 29, 29, 29, 29, 29, 29, 29, 
	35, 0, 43, 0, 43, 0, 43, 54, 
	0, 5, 1, 0, 29, 1, 29, 29, 
	29, 29, 29, 29, 29, 29, 35, 0, 
	43, 0, 43, 0, 43, 139, 48, 9, 
	106, 11, 0, 134, 45, 45, 45, 3, 
	122, 33, 33, 33, 0, 122, 33, 33, 
	33, 0, 122, 33, 0, 33, 0, 102, 
	7, 7, 43, 54, 0, 0, 43, 114, 
	25, 0, 54, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 149, 126, 57, 110, 23, 0, 
	43, 43, 43, 43, 0, 27, 118, 27, 
	27, 51, 27, 0, 54, 0, 1, 0, 
	43, 0, 43, 0, 43, 0, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 144, 57, 54, 0, 54, 0, 
	69, 33, 69, 84, 84, 84, 84, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 13, 0, 0, 54, 0, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	54, 0, 0, 54, 13, 0, 130, 31, 
	60, 57, 31, 63, 57, 63, 63, 63, 
	63, 63, 63, 63, 63, 66, 31, 43, 
	0, 43, 0, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 144, 
	57, 54, 0, 54, 0, 72, 33, 84, 
	72, 84, 84, 84, 84, 84, 84, 84, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 15, 0, 54, 15, 0, 54, 
	0, 0, 54, 0, 0, 0, 54, 0, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 54, 0, 0, 54, 15, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 0, 54, 
	0, 0, 54, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 0, 54, 0, 0, 
	54, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	15, 0, 54, 0, 0, 0, 54, 0, 
	0, 54, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 0, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 144, 57, 54, 
	0, 54, 0, 81, 84, 81, 0, 0, 
	0, 54, 0, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 54, 0, 0, 
	54, 21, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 0, 54, 0, 0, 54, 0, 54, 
	0, 0, 54, 0, 0, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 144, 57, 54, 0, 54, 0, 78, 
	33, 84, 78, 84, 84, 84, 84, 84, 
	84, 84, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 19, 0, 54, 19, 
	0, 54, 0, 0, 54, 0, 0, 0, 
	54, 0, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 54, 0, 0, 54, 
	19, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	0, 54, 0, 0, 54, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 0, 54, 
	0, 0, 54, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 144, 57, 54, 0, 54, 
	0, 75, 33, 84, 75, 84, 84, 84, 
	84, 84, 84, 84, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 17, 0, 
	54, 17, 0, 54, 0, 0, 54, 0, 
	0, 0, 54, 0, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 54, 0, 
	0, 54, 17, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 0, 54, 0, 0, 54, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	0, 54, 0, 0, 54, 0, 0, 0, 
	54, 0, 0, 54, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 17, 0, 54, 0, 0, 
	0, 54, 0, 0, 54, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 0, 54, 0, 0, 
	54, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 43, 0, 
	43, 0, 43, 0, 43, 0, 0, 0, 
	43, 54, 37, 37, 87, 37, 37, 43, 
	0, 39, 0, 43, 0, 0, 54, 0, 
	0, 39, 0, 0, 54, 0, 93, 90, 
	41, 96, 90, 96, 96, 96, 96, 96, 
	96, 96, 96, 99, 0, 43, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 0, 54, 0, 0, 
	54, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 0, 54, 
	0, 0, 54, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 0, 54, 0, 
	0, 54, 0, 0, 0, 54, 0, 0, 
	54, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	13, 0, 54, 0, 0, 0, 54, 0, 
	0, 54, 0, 54, 0, 0, 54, 0, 
	0, 54, 0, 0, 54, 0, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	54, 0, 0, 54, 0, 0, 54, 0, 
	0, 0, 54, 0, 0, 54, 0, 54, 
	0, 0, 54, 0, 0, 54, 0, 0, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 43, 0, 43, 
	0, 43, 0, 43, 0, 0
};

static const unsigned char _lexer_eof_actions[] = {
	0, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43, 43, 43, 43, 
	43, 43, 43, 43, 43
};

static const int lexer_start = 1;
static const int lexer_first_final = 428;
static const int lexer_error = 0;

static const int lexer_en_main = 1;


#line 258 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"

static VALUE 
unindent(VALUE con, int start_col)
{
  VALUE re;
  /* Gherkin will crash gracefully if the string representation of start_col pushes the pattern past 32 characters */
  char pat[32]; 
  snprintf(pat, 32, "^[\t ]{0,%d}", start_col); 
  re = rb_reg_regcomp(rb_str_new2(pat));
  rb_funcall(con, rb_intern("gsub!"), 2, re, rb_str_new2(""));

  return Qnil;

}

static void 
store_kw_con(VALUE listener, const char * event_name, 
             const char * keyword_at, size_t keyword_length, 
             const char * at,         size_t length, 
             int current_line)
{
  VALUE con = Qnil, kw = Qnil;
  kw = ENCODED_STR_NEW(keyword_at, keyword_length);
  con = ENCODED_STR_NEW(at, length);
  rb_funcall(con, rb_intern("strip!"), 0);
  rb_funcall(listener, rb_intern(event_name), 3, kw, con, INT2FIX(current_line)); 
}

static void
store_multiline_kw_con(VALUE listener, const char * event_name,
                      const char * keyword_at, size_t keyword_length,
                      const char * at,         size_t length,
                      int current_line, int start_col)
{
  VALUE split;
  VALUE con = Qnil, kw = Qnil, name = Qnil, desc = Qnil;

  kw = ENCODED_STR_NEW(keyword_at, keyword_length);
  con = ENCODED_STR_NEW(at, length);

  unindent(con, start_col);
  
  split = rb_str_split(con, "\n");

  name = rb_funcall(split, rb_intern("shift"), 0);
  desc = rb_ary_join(split, rb_str_new2( "\n" ));

  if( name == Qnil ) 
  {
    name = rb_str_new2("");
  }
  if( rb_funcall(desc, rb_intern("size"), 0) == 0) 
  {
    desc = rb_str_new2("");
  }
  rb_funcall(name, rb_intern("strip!"), 0);
  rb_funcall(desc, rb_intern("rstrip!"), 0);
  rb_funcall(listener, rb_intern(event_name), 4, kw, name, desc, INT2FIX(current_line)); 
}

static void 
store_attr(VALUE listener, const char * attr_type,
           const char * at, size_t length, 
           int line)
{
  VALUE val = ENCODED_STR_NEW(at, length);
  rb_funcall(listener, rb_intern(attr_type), 2, val, INT2FIX(line));
}
static void 
store_docstring_content(VALUE listener, 
          int start_col, 
          const char *type_at, size_t type_length,
          const char *at, size_t length, 
          int current_line)
{
  VALUE re2;
  VALUE unescape_escaped_quotes;
  VALUE con = ENCODED_STR_NEW(at, length);
  VALUE con_type = ENCODED_STR_NEW(type_at, type_length);

  unindent(con, start_col);

  re2 = rb_reg_regcomp(rb_str_new2("\r\\Z"));
  unescape_escaped_quotes = rb_reg_regcomp(rb_str_new2("\\\\\"\\\\\"\\\\\""));
  rb_funcall(con, rb_intern("sub!"), 2, re2, rb_str_new2(""));
  rb_funcall(con_type, rb_intern("strip!"), 0);
  rb_funcall(con, rb_intern("gsub!"), 2, unescape_escaped_quotes, rb_str_new2("\"\"\""));
  rb_funcall(listener, rb_intern("doc_string"), 3, con_type, con, INT2FIX(current_line));
}
static void 
raise_lexer_error(const char * at, int line)
{ 
  rb_raise(rb_eGherkinLexingError, "Lexing error on line %d: '%s'. See http://wiki.github.com/cucumber/gherkin/lexingerror for more information.", line, at);
}

static void lexer_init(lexer_state *lexer) {
  lexer->content_start = 0;
  lexer->content_end = 0;
  lexer->content_len = 0;
  lexer->docstring_content_type_start = 0;
  lexer->docstring_content_type_end = 0;
  lexer->mark = 0;
  lexer->keyword_start = 0;
  lexer->keyword_end = 0;
  lexer->next_keyword_start = 0;
  lexer->line_number = 1;
  lexer->last_newline = 0;
  lexer->final_newline = 0;
  lexer->start_col = 0;
}

static VALUE CLexer_alloc(VALUE klass)
{
  VALUE obj;
  lexer_state *lxr = ALLOC(lexer_state);
  lexer_init(lxr);

  obj = Data_Wrap_Struct(klass, NULL, -1, lxr);

  return obj;
}

static VALUE CLexer_init(VALUE self, VALUE listener)
{
  lexer_state *lxr; 
  rb_iv_set(self, "@listener", listener);
  
  lxr = NULL;
  DATA_GET(self, lexer_state, lxr);
  lexer_init(lxr);
  
  return self;
}

static VALUE CLexer_scan(VALUE self, VALUE input)
{
  VALUE input_copy;
  char *data;
  size_t len;
  VALUE listener = rb_iv_get(self, "@listener");

  lexer_state *lexer;
  lexer = NULL;
  DATA_GET(self, lexer_state, lexer);

  input_copy = rb_str_dup(input);

  rb_str_append(input_copy, rb_str_new2("\n%_FEATURE_END_%"));
  data = RSTRING_PTR(input_copy);
  len = RSTRING_LEN(input_copy);
  
  if (len == 0) { 
    rb_raise(rb_eGherkinLexingError, "No content to lex.");
  } else {

    const char *p, *pe, *eof;
    int cs = 0;
    
    VALUE current_row = Qnil;

    p = data;
    pe = data + len;
    eof = pe;
    
    assert(*pe == '\0' && "pointer does not end on NULL");
    
    
#line 1029 "ext/gherkin_lexer_lv/gherkin_lexer_lv.c"
	{
	cs = lexer_start;
	}

#line 425 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
    
#line 1036 "ext/gherkin_lexer_lv/gherkin_lexer_lv.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _lexer_trans_keys + _lexer_key_offsets[cs];
	_trans = _lexer_index_offsets[cs];

	_klen = _lexer_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _lexer_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _lexer_trans_targs[_trans];

	if ( _lexer_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _lexer_actions + _lexer_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 83 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
		MARK(content_start, p);
    lexer->current_line = lexer->line_number;
    lexer->start_col = lexer->content_start - lexer->last_newline - (lexer->keyword_end - lexer->keyword_start) + 2;
  }
	break;
	case 1:
#line 89 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    MARK(content_start, p);
  }
	break;
	case 2:
#line 93 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    lexer->current_line = lexer->line_number;
    lexer->start_col = p - data - lexer->last_newline;
  }
	break;
	case 3:
#line 98 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    int len = LEN(content_start, PTR_TO(final_newline));
    int type_len = LEN(docstring_content_type_start, PTR_TO(docstring_content_type_end));

    if (len < 0) len = 0;
    if (type_len < 0) len = 0;

    store_docstring_content(listener, lexer->start_col, PTR_TO(docstring_content_type_start), type_len, PTR_TO(content_start), len, lexer->current_line);
  }
	break;
	case 4:
#line 108 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{ 
    MARK(docstring_content_type_start, p);
  }
	break;
	case 5:
#line 112 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{ 
    MARK(docstring_content_type_end, p);
  }
	break;
	case 6:
#line 116 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    STORE_KW_END_CON(feature);
  }
	break;
	case 7:
#line 120 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    STORE_KW_END_CON(background);
  }
	break;
	case 8:
#line 124 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    STORE_KW_END_CON(scenario);
  }
	break;
	case 9:
#line 128 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    STORE_KW_END_CON(scenario_outline);
  }
	break;
	case 10:
#line 132 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    STORE_KW_END_CON(examples);
  }
	break;
	case 11:
#line 136 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    store_kw_con(listener, "step",
      PTR_TO(keyword_start), LEN(keyword_start, PTR_TO(keyword_end)),
      PTR_TO(content_start), LEN(content_start, p), 
      lexer->current_line);
  }
	break;
	case 12:
#line 143 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    STORE_ATTR(comment);
    lexer->mark = 0;
  }
	break;
	case 13:
#line 148 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    STORE_ATTR(tag);
    lexer->mark = 0;
  }
	break;
	case 14:
#line 153 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    lexer->line_number += 1;
    MARK(final_newline, p);
  }
	break;
	case 15:
#line 158 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    MARK(last_newline, p + 1);
  }
	break;
	case 16:
#line 162 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    if (lexer->mark == 0) {
      MARK(mark, p);
    }
  }
	break;
	case 17:
#line 168 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    MARK(keyword_end, p);
    MARK(keyword_start, PTR_TO(mark));
    MARK(content_start, p + 1);
    lexer->mark = 0;
  }
	break;
	case 18:
#line 175 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    MARK(content_end, p);
  }
	break;
	case 19:
#line 179 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    p = p - 1;
    lexer->current_line = lexer->line_number;
    current_row = rb_ary_new();
  }
	break;
	case 20:
#line 185 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
		MARK(content_start, p);
  }
	break;
	case 21:
#line 189 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    VALUE re_pipe, re_newline, re_backslash;
    VALUE con = ENCODED_STR_NEW(PTR_TO(content_start), LEN(content_start, p));
    rb_funcall(con, rb_intern("strip!"), 0);
    re_pipe      = rb_reg_regcomp(rb_str_new2("\\\\\\|"));
    re_newline   = rb_reg_regcomp(rb_str_new2("\\\\n"));
    re_backslash = rb_reg_regcomp(rb_str_new2("\\\\\\\\"));
    rb_funcall(con, rb_intern("gsub!"), 2, re_pipe,      rb_str_new2("|"));
    rb_funcall(con, rb_intern("gsub!"), 2, re_newline,   rb_str_new2("\n"));
    rb_funcall(con, rb_intern("gsub!"), 2, re_backslash, rb_str_new2("\\"));

    rb_ary_push(current_row, con);
  }
	break;
	case 22:
#line 203 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    rb_funcall(listener, rb_intern("row"), 2, current_row, INT2FIX(lexer->current_line));
  }
	break;
	case 23:
#line 207 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    int line;
    if (cs < lexer_first_final) {
      size_t count = 0;
      VALUE newstr_val;
      char *newstr;
      int newstr_count = 0;        
      size_t len;
      const char *buff;
      if (lexer->last_newline != 0) {
        len = LEN(last_newline, eof);
        buff = PTR_TO(last_newline);
      } else {
        len = strlen(data);
        buff = data;
      }

      /* Allocate as a ruby string so that it gets cleaned up by GC */
      newstr_val = rb_str_new(buff, len);
      newstr = RSTRING_PTR(newstr_val);


      for (count = 0; count < len; count++) {
        if(buff[count] == 10) {
          newstr[newstr_count] = '\0'; /* terminate new string at first newline found */
          break;
        } else {
          if (buff[count] == '%') {
            newstr[newstr_count++] = buff[count];
            newstr[newstr_count] = buff[count];
          } else {
            newstr[newstr_count] = buff[count];
          }
        }
        newstr_count++;
      }

      line = lexer->line_number;
      lexer_init(lexer); /* Re-initialize so we can scan again with the same lexer */
      raise_lexer_error(newstr, line);
    } else {
      rb_funcall(listener, rb_intern("eof"), 0);
    }
  }
	break;
#line 1326 "ext/gherkin_lexer_lv/gherkin_lexer_lv.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _lexer_actions + _lexer_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 23:
#line 207 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"
	{
    int line;
    if (cs < lexer_first_final) {
      size_t count = 0;
      VALUE newstr_val;
      char *newstr;
      int newstr_count = 0;        
      size_t len;
      const char *buff;
      if (lexer->last_newline != 0) {
        len = LEN(last_newline, eof);
        buff = PTR_TO(last_newline);
      } else {
        len = strlen(data);
        buff = data;
      }

      /* Allocate as a ruby string so that it gets cleaned up by GC */
      newstr_val = rb_str_new(buff, len);
      newstr = RSTRING_PTR(newstr_val);


      for (count = 0; count < len; count++) {
        if(buff[count] == 10) {
          newstr[newstr_count] = '\0'; /* terminate new string at first newline found */
          break;
        } else {
          if (buff[count] == '%') {
            newstr[newstr_count++] = buff[count];
            newstr[newstr_count] = buff[count];
          } else {
            newstr[newstr_count] = buff[count];
          }
        }
        newstr_count++;
      }

      line = lexer->line_number;
      lexer_init(lexer); /* Re-initialize so we can scan again with the same lexer */
      raise_lexer_error(newstr, line);
    } else {
      rb_funcall(listener, rb_intern("eof"), 0);
    }
  }
	break;
#line 1389 "ext/gherkin_lexer_lv/gherkin_lexer_lv.c"
		}
	}
	}

	_out: {}
	}

#line 426 "/home/son/work/github/cucumber/gherkin/tasks/../ragel/i18n/lv.c.rl"

    assert(p <= pe && "data overflow after parsing execute");
    assert(lexer->content_start <= len && "content starts after data end");
    assert(lexer->mark < len && "mark is after data end");
    
    /* Reset lexer by re-initializing the whole thing */
    lexer_init(lexer);

    if (cs == lexer_error) {
      rb_raise(rb_eGherkinLexingError, "Invalid format, lexing fails.");
    } else {
      return Qtrue;
    }
  }
}

void Init_gherkin_lexer_lv()
{
  mGherkin = rb_define_module("Gherkin");
  mGherkinLexer = rb_define_module_under(mGherkin, "Lexer");
  rb_eGherkinLexingError = rb_const_get(mGherkinLexer, rb_intern("LexingError"));

  mCLexer = rb_define_module_under(mGherkin, "CLexer");
  cI18nLexer = rb_define_class_under(mCLexer, "Lv", rb_cObject);
  rb_define_alloc_func(cI18nLexer, CLexer_alloc);
  rb_define_method(cI18nLexer, "initialize", CLexer_init, 1);
  rb_define_method(cI18nLexer, "scan", CLexer_scan, 1);
}

