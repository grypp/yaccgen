/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C

 Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
 part or all of the Bison parser skeleton and distribute that work
 under terms of your choice, so long as that work isn't itself a
 parser generator using the skeleton or a modified version thereof
 as a parser skeleton.  Alternatively, if you modify or redistribute
 the parser skeleton itself, you may (at your option) remove this
 special exception, which will cause the skeleton and the resulting
 Bison output files to be licensed under the GNU General Public
 License without this special exception.

 This special exception was added by the Free Software Foundation in
 version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
 simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
 infringing on user name space.  This should be done even for local
 variables, as they might otherwise be expanded by user macros.
 There are some unavoidable exceptions within include files to
 define necessary library symbols; they are noted "INFRINGES ON
 USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "gram.y"

/*
 ======================================================================

 CTool Library
 Copyright (C) 1995-2001	Shaun Flisakowski

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 1, or (at your option)
 any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 ======================================================================
 */

/* grammar File for C - Shaun Flisakowski and Patrick Baudin */
/* Grammar was constructed with the assistance of:
 "C - A Reference Manual" (Fourth Edition),
 by Samuel P Harbison, and Guy L Steele Jr. */

#ifdef    NO_ALLOCA
#define   alloca  __builtin_alloca
#endif

#include <stdio.h>
#include <errno.h>
#include <setjmp.h>

#include "lexer.h"
#include "symbol.h"
#include "token.h"
#include "stemnt.h"
#include "location.h"
#include "project.h"

extern int errno;
int yylex(YYSTYPE *lvalp);

/* Cause the `yydebug' variable to be defined.  */
#define YYDEBUG 1

#undef HERE
#define HERE Location(gProject->Parse_TOS->yylineno, \
                      gProject->Parse_TOS->yycolno, \
                      gProject->Parse_TOS->filename)

/*  int  yydebug = 1;  */

/* ###################################################### */

/* Line 268 of yacc.c  */
#line 216 "gram.y"

/* 1 if we explained undeclared var errors.  */
/*  static int undeclared_variable_notice = 0;  */

/* Line 268 of yacc.c  */
#line 138 "gram.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
/* Put the tokens into the symbol table, so that GDB and other debuggers
 know about them.  */
enum yytokentype {
	IDENT = 258,
	TAG_NAME = 259,
	LABEL_NAME = 260,
	TYPEDEF_NAME = 261,
	STRING = 262,
	LSTRING = 263,
	CHAR_CONST = 264,
	LCHAR_CONST = 265,
	INUM = 266,
	RNUM = 267,
	PP_LINE = 268,
	INVALID = 269,
	CONST = 270,
	VOLATILE = 271,
	AUTO = 272,
	EXTRN = 273,
	REGISTR = 274,
	STATIC = 275,
	TYPEDEF = 276,
	VOID = 277,
	BOOL = 278,
	CHAR = 279,
	SHORT = 280,
	INT = 281,
	INT8 = 282,
	INT16 = 283,
	INT32 = 284,
	INT64 = 285,
	LONG = 286,
	FLOAT = 287,
	DOUBLE = 288,
	SGNED = 289,
	UNSGNED = 290,
	ENUM = 291,
	STRUCT = 292,
	UNION = 293,
	BREAK = 294,
	CASE = 295,
	CONT = 296,
	DEFLT = 297,
	DO = 298,
	ELSE = 299,
	IF = 300,
	FOR = 301,
	GOTO = 302,
	RETURN = 303,
	SWITCH = 304,
	WHILE = 305,
	PLUS_EQ = 306,
	MINUS_EQ = 307,
	STAR_EQ = 308,
	DIV_EQ = 309,
	MOD_EQ = 310,
	B_AND_EQ = 311,
	B_OR_EQ = 312,
	B_XOR_EQ = 313,
	L_SHIFT_EQ = 314,
	R_SHIFT_EQ = 315,
	EQUAL = 316,
	LESS_EQ = 317,
	GRTR_EQ = 318,
	NOT_EQ = 319,
	RPAREN = 320,
	RBRCKT = 321,
	LBRACE = 322,
	RBRACE = 323,
	SEMICOLON = 324,
	COMMA = 325,
	ELLIPSIS = 326,
	LB_SIGN = 327,
	DOUB_LB_SIGN = 328,
	BACKQUOTE = 329,
	AT = 330,
	ATTRIBUTE = 331,
	ALIGNED = 332,
	PACKED = 333,
	CDECL = 334,
	MODE = 335,
	FORMAT = 336,
	NORETURN = 337,
	MALLOC = 338,
	COMMA_OP = 339,
	ASSIGN = 340,
	EQ = 341,
	COMMA_SEP = 342,
	COLON = 343,
	QUESTMARK = 344,
	OR = 345,
	AND = 346,
	B_OR = 347,
	B_XOR = 348,
	B_AND = 349,
	COMP_EQ = 350,
	GRTR = 351,
	LESS = 352,
	COMP_ARITH = 353,
	R_SHIFT = 354,
	L_SHIFT = 355,
	MINUS = 356,
	PLUS = 357,
	MOD = 358,
	DIV = 359,
	STAR = 360,
	CAST = 361,
	DECR = 362,
	INCR = 363,
	SIZEOF = 364,
	B_NOT = 365,
	NOT = 366,
	UNARY = 367,
	HYPERUNARY = 368,
	LBRCKT = 369,
	LPAREN = 370,
	DOT = 371,
	ARROW = 372
};
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

/* Copy the second part of user declarations.  */

/* Line 343 of yacc.c  */
#line 296 "gram.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
int yyi;
#endif
{
	return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
/* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
/* The OS might guarantee only one guard page at the bottom of the stack,
 and a page size can be as small as 4096 bytes.  So we cannot safely
 invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
 to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
	yytype_int16 yyss_alloc;
	YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
 N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
 local variables YYSIZE and YYSTACKSIZE give the old and new number of
 elements in the stack, and YYPTR gives the new location of the
 stack.  Advance YYPTR to a properly aligned location for the next
 stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
 not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1094

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  191
/* YYNRULES -- Number of rules.  */
#define YYNRULES  357
/* YYNRULES -- Number of states.  */
#define YYNSTATES  510

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   372

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] = { 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 2, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
		97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117 };

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
 YYRHS.  */
static const yytype_uint16 yyprhs[] = { 0, 0, 3, 4, 6, 8, 11, 15, 16, 18, 20, 22, 25, 29, 32, 36, 40, 41, 47, 50, 51, 53, 55, 58, 61, 63, 68, 71, 72, 74, 76, 79, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 107, 110, 114, 116, 118, 120, 122, 124, 130, 133, 136, 140, 144, 146, 152, 160, 168, 174, 184, 186, 188, 190, 192, 195, 200, 202, 204, 210, 212, 216, 217, 219, 221, 222, 224, 226, 228,
		232, 234, 238, 241, 243, 247, 249, 253, 255, 259, 262, 264, 269, 271, 275, 277, 281, 283, 287, 289, 293, 295, 299, 301, 303, 305, 307, 309, 311, 313, 315, 317, 319, 324, 327, 330, 333, 336, 339, 342, 345, 347, 351, 353, 355, 357, 361, 365, 367, 369, 371, 373, 375, 377, 382, 384, 386, 389, 392, 394, 398, 402, 407, 408, 410, 412, 416, 418, 420, 422, 424, 426, 428, 430, 432, 434, 436, 438,
		440, 442, 444, 446, 448, 450, 451, 453, 454, 455, 459, 460, 462, 463, 464, 468, 471, 475, 478, 481, 484, 487, 488, 490, 492, 493, 496, 498, 501, 503, 505, 507, 509, 511, 513, 515, 517, 519, 520, 522, 525, 526, 530, 533, 534, 536, 537, 541, 544, 546, 547, 551, 553, 557, 558, 560, 562, 564, 568, 570, 572, 576, 578, 583, 584, 586, 588, 590, 592, 594, 597, 598, 600, 602, 604, 606, 608, 610,
		612, 614, 616, 618, 620, 622, 624, 626, 628, 630, 632, 634, 636, 638, 640, 642, 644, 646, 649, 652, 655, 658, 663, 668, 671, 676, 681, 684, 689, 694, 695, 697, 698, 701, 702, 704, 706, 708, 712, 714, 718, 720, 721, 722, 726, 729, 732, 736, 739, 741, 743, 744, 748, 749, 755, 757, 759, 761, 762, 767, 769, 770, 772, 774, 776, 779, 781, 783, 785, 789, 791, 796, 801, 805, 810, 813, 815, 818,
		820, 821, 824, 826, 830, 832, 834, 836, 838, 839, 840, 843, 844, 847, 849, 853, 855, 859, 860, 863, 866, 869, 871, 873, 875, 878, 880, 884, 888, 893, 897, 902, 903, 905, 912, 913, 915, 917, 919, 921, 926, 931, 940 };

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] = { 119, 0, -1, -1, 120, -1, 1, -1, 122, 121, -1, 120, 122, 121, -1, -1, 210, -1, 123, -1, 13, -1, 1, 69, -1, 1, 68, 121, -1, 124, 125, -1, 214, 280, 201, -1, 213, 279, 201, -1, -1, 67, 126, 205, 127, 68, -1, 1, 68, -1, -1, 128, -1, 129, -1, 128, 129, -1, 128, 13, -1, 133, -1, 67, 205, 131, 68, -1, 1, 68, -1, -1, 132, -1, 133, -1, 132, 133, -1, 132, 13, -1, 134,
		-1, 135, -1, 130, -1, 136, -1, 137, -1, 138, -1, 139, -1, 140, -1, 141, -1, 142, -1, 143, -1, 1, 69, -1, 158, 69, -1, 149, 88, 133, -1, 144, -1, 145, -1, 146, -1, 147, -1, 148, -1, 49, 115, 158, 65, 133, -1, 39, 69, -1, 41, 69, -1, 48, 157, 69, -1, 47, 5, 69, -1, 69, -1, 45, 115, 158, 65, 133, -1, 45, 115, 158, 65, 133, 44, 133, -1, 43, 133, 50, 115, 158, 65, 69, -1, 50, 115, 158, 65, 133,
		-1, 46, 115, 157, 69, 157, 69, 157, 65, 133, -1, 150, -1, 151, -1, 152, -1, 291, -1, 40, 156, -1, 40, 156, 71, 156, -1, 42, -1, 159, -1, 159, 89, 158, 88, 153, -1, 153, -1, 172, 199, 154, -1, -1, 156, -1, 158, -1, -1, 158, -1, 180, -1, 160, -1, 159, 90, 160, -1, 162, -1, 160, 91, 162, -1, 111, 166, -1, 163, -1, 162, 92, 163, -1, 164, -1, 163, 93, 164, -1, 167, -1, 164, 94, 167, -1, 110,
		166, -1, 172, -1, 115, 216, 65, 166, -1, 168, -1, 167, 196, 168, -1, 169, -1, 168, 197, 169, -1, 170, -1, 169, 198, 170, -1, 171, -1, 170, 194, 171, -1, 166, -1, 171, 195, 166, -1, 183, -1, 173, -1, 174, -1, 175, -1, 161, -1, 165, -1, 176, -1, 177, -1, 178, -1, 179, -1, 109, 115, 216, 65, -1, 109, 172, -1, 101, 166, -1, 102, 166, -1, 94, 166, -1, 105, 166, -1, 108, 172, -1, 107, 172, -1,
		154, -1, 180, 70, 154, -1, 291, -1, 182, -1, 200, -1, 115, 158, 65, -1, 115, 1, 65, -1, 181, -1, 184, -1, 185, -1, 191, -1, 186, -1, 187, -1, 183, 114, 158, 66, -1, 189, -1, 190, -1, 183, 108, -1, 183, 107, -1, 293, -1, 183, 116, 188, -1, 183, 117, 188, -1, 183, 115, 192, 65, -1, -1, 193, -1, 154, -1, 193, 70, 154, -1, 102, -1, 101, -1, 105, -1, 104, -1, 103, -1, 95, -1, 98, -1, 100, -1,
		99, -1, 86, -1, 85, -1, 11, -1, 12, -1, 9, -1, 10, -1, 7, -1, 8, -1, -1, 202, -1, -1, -1, 203, 204, 209, -1, -1, 206, -1, -1, -1, 207, 208, 209, -1, 212, 69, -1, 212, 69, 209, -1, 211, 69, -1, 212, 69, -1, 213, 234, -1, 214, 234, -1, -1, 219, -1, 303, -1, -1, 217, 218, -1, 219, -1, 219, 215, -1, 225, -1, 18, -1, 20, -1, 21, -1, 17, -1, 19, -1, 220, -1, 221, -1, 245, -1, -1, 225, -1, 222,
		224, -1, -1, 223, 226, 224, -1, 241, 224, -1, -1, 228, -1, -1, 245, 229, 227, -1, 241, 227, -1, 228, -1, -1, 279, 232, 306, -1, 231, -1, 231, 86, 237, -1, -1, 235, -1, 236, -1, 233, -1, 236, 70, 233, -1, 239, -1, 239, -1, 238, 70, 239, -1, 154, -1, 67, 238, 240, 68, -1, -1, 70, -1, 242, -1, 15, -1, 16, -1, 242, -1, 243, 242, -1, -1, 243, -1, 256, -1, 252, -1, 254, -1, 250, -1, 248, -1,
		249, -1, 246, -1, 22, -1, 23, -1, 24, -1, 25, -1, 26, -1, 27, -1, 28, -1, 29, -1, 30, -1, 31, -1, 32, -1, 33, -1, 34, -1, 35, -1, 6, -1, 4, -1, 37, 247, -1, 38, 247, -1, 36, 247, -1, 37, 247, -1, 37, 67, 257, 68, -1, 251, 67, 257, 68, -1, 38, 247, -1, 38, 67, 257, 68, -1, 253, 67, 257, 68, -1, 36, 247, -1, 36, 67, 258, 68, -1, 255, 67, 258, 68, -1, -1, 264, -1, -1, 260, 259, -1, -1, 70,
		-1, 261, -1, 262, -1, 260, 70, 262, -1, 263, -1, 263, 86, 154, -1, 293, -1, -1, -1, 265, 266, 267, -1, 268, 69, -1, 267, 69, -1, 267, 268, 69, -1, 230, 269, -1, 230, -1, 270, -1, -1, 271, 273, 306, -1, -1, 270, 70, 272, 273, 306, -1, 274, -1, 275, -1, 279, -1, -1, 278, 88, 276, 277, -1, 153, -1, -1, 279, -1, 281, -1, 281, -1, 287, 282, -1, 282, -1, 283, -1, 291, -1, 115, 281, 65, -1, 284,
		-1, 283, 115, 296, 65, -1, 283, 115, 288, 65, -1, 283, 115, 65, -1, 283, 114, 155, 66, -1, 105, 244, -1, 285, -1, 286, 285, -1, 286, -1, -1, 289, 290, -1, 291, -1, 290, 70, 291, -1, 3, -1, 6, -1, 291, -1, 292, -1, -1, -1, 295, 298, -1, -1, 297, 298, -1, 299, -1, 299, 70, 71, -1, 300, -1, 299, 70, 300, -1, -1, 301, 302, -1, 219, 279, -1, 219, 303, -1, 219, -1, 287, -1, 304, -1, 287, 304,
		-1, 305, -1, 115, 303, 65, -1, 114, 155, 66, -1, 305, 114, 155, 66, -1, 115, 294, 65, -1, 305, 115, 294, 65, -1, -1, 307, -1, 76, 115, 115, 308, 65, 65, -1, -1, 78, -1, 79, -1, 15, -1, 82, -1, 77, 115, 11, 65, -1, 80, 115, 291, 65, -1, 81, 115, 291, 70, 11, 70, 11, 65, -1, 83, -1 };

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] = { 0, 228, 228, 235, 246, 254, 259, 266, 274, 278, 282, 286, 290, 296, 324, 353, 387, 386, 404, 411, 414, 417, 418, 427, 442, 445, 455, 462, 465, 468, 469, 478, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 507, 514, 530, 531, 534, 535, 536, 539, 548, 556, 564, 572, 580, 587, 596, 606, 617, 626, 638, 639, 640, 643, 651, 656, 664, 680, 681, 689,
		690, 697, 700, 703, 707, 710, 713, 716, 717, 724, 725, 732, 739, 740, 747, 748, 755, 756, 763, 770, 771, 779, 780, 786, 787, 793, 794, 800, 801, 807, 808, 814, 815, 816, 817, 818, 819, 820, 821, 822, 823, 826, 833, 840, 846, 853, 860, 866, 873, 880, 881, 888, 897, 898, 904, 910, 918, 919, 920, 921, 922, 923, 926, 934, 935, 938, 945, 952, 955, 978, 1001, 1015, 1018, 1021, 1022, 1031, 1032,
		1035, 1036, 1037, 1040, 1043, 1046, 1047, 1050, 1051, 1054, 1055, 1056, 1057, 1058, 1059, 1068, 1068, 1079, 1084, 1079, 1100, 1100, 1110, 1115, 1110, 1123, 1128, 1141, 1148, 1156, 1174, 1195, 1201, 1210, 1214, 1214, 1225, 1235, 1263, 1269, 1270, 1271, 1274, 1275, 1278, 1279, 1289, 1293, 1296, 1299, 1318, 1318, 1350, 1371, 1374, 1377, 1377, 1387, 1402, 1412, 1411, 1422, 1423, 1431, 1434,
		1437, 1440, 1444, 1460, 1462, 1467, 1475, 1476, 1485, 1488, 1500, 1503, 1504, 1507, 1508, 1517, 1520, 1527, 1528, 1529, 1530, 1531, 1532, 1533, 1534, 1535, 1536, 1537, 1538, 1539, 1540, 1541, 1542, 1543, 1544, 1545, 1546, 1547, 1550, 1557, 1565, 1575, 1585, 1595, 1605, 1612, 1636, 1646, 1654, 1679, 1689, 1696, 1720, 1723, 1727, 1730, 1736, 1739, 1749, 1752, 1757, 1765, 1780, 1797, 1804,
		1809, 1804, 1823, 1829, 1837, 1845, 1850, 1861, 1865, 1865, 1873, 1872, 1884, 1902, 1919, 1923, 1922, 1942, 1946, 1949, 1956, 1962, 1968, 1973, 1976, 1979, 1984, 1990, 1991, 2008, 2025, 2050, 2068, 2074, 2075, 2082, 2089, 2089, 2104, 2109, 2121, 2125, 2137, 2138, 2147, 2151, 2151, 2160, 2160, 2173, 2174, 2183, 2184, 2192, 2192, 2202, 2224, 2247, 2261, 2265, 2269, 2276, 2279, 2283, 2287,
		2298, 2302, 2320, 2323, 2326, 2337, 2341, 2345, 2349, 2353, 2357, 2371, 2380, 2403 };
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
 First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char * const yytname[] = { "$end", "error", "$undefined", "IDENT", "TAG_NAME", "LABEL_NAME", "TYPEDEF_NAME", "STRING", "LSTRING", "CHAR_CONST", "LCHAR_CONST", "INUM", "RNUM", "PP_LINE", "INVALID", "CONST", "VOLATILE", "AUTO", "EXTRN", "REGISTR", "STATIC", "TYPEDEF", "VOID", "BOOL", "CHAR", "SHORT", "INT", "INT8", "INT16", "INT32", "INT64", "LONG", "FLOAT", "DOUBLE", "SGNED",
		"UNSGNED", "ENUM", "STRUCT", "UNION", "BREAK", "CASE", "CONT", "DEFLT", "DO", "ELSE", "IF", "FOR", "GOTO", "RETURN", "SWITCH", "WHILE", "PLUS_EQ", "MINUS_EQ", "STAR_EQ", "DIV_EQ", "MOD_EQ", "B_AND_EQ", "B_OR_EQ", "B_XOR_EQ", "L_SHIFT_EQ", "R_SHIFT_EQ", "EQUAL", "LESS_EQ", "GRTR_EQ", "NOT_EQ", "RPAREN", "RBRCKT", "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "ELLIPSIS", "LB_SIGN",
		"DOUB_LB_SIGN", "BACKQUOTE", "AT", "ATTRIBUTE", "ALIGNED", "PACKED", "CDECL", "MODE", "FORMAT", "NORETURN", "MALLOC", "COMMA_OP", "ASSIGN", "EQ", "COMMA_SEP", "COLON", "QUESTMARK", "OR", "AND", "B_OR", "B_XOR", "B_AND", "COMP_EQ", "GRTR", "LESS", "COMP_ARITH", "R_SHIFT", "L_SHIFT", "MINUS", "PLUS", "MOD", "DIV", "STAR", "CAST", "DECR", "INCR", "SIZEOF", "B_NOT", "NOT", "UNARY",
		"HYPERUNARY", "LBRCKT", "LPAREN", "DOT", "ARROW", "$accept", "program", "trans_unit", "top_level_exit", "top_level_decl", "func_def", "func_spec", "cmpnd_stemnt", "$@1", "opt_stemnt_list", "stemnt_list", "stemnt", "cmpnd_stemnt_reentrance", "opt_stemnt_list_reentrance", "stemnt_list_reentrance", "stemnt_reentrance", "expr_stemnt", "labeled_stemnt", "cond_stemnt", "iter_stemnt",
		"switch_stemnt", "break_stemnt", "continue_stemnt", "return_stemnt", "goto_stemnt", "null_stemnt", "if_stemnt", "if_else_stemnt", "do_stemnt", "while_stemnt", "for_stemnt", "label", "named_label", "case_label", "deflt_label", "cond_expr", "assign_expr", "opt_const_expr", "const_expr", "opt_expr", "expr", "log_or_expr", "log_and_expr", "log_neg_expr", "bitwise_or_expr", "bitwise_xor_expr",
		"bitwise_and_expr", "bitwise_neg_expr", "cast_expr", "equality_expr", "relational_expr", "shift_expr", "additive_expr", "mult_expr", "unary_expr", "sizeof_expr", "unary_minus_expr", "unary_plus_expr", "addr_expr", "indirection_expr", "preinc_expr", "predec_expr", "comma_expr", "prim_expr", "paren_expr", "postfix_expr", "subscript_expr", "comp_select_expr", "postinc_expr", "postdec_expr",
		"field_ident", "direct_comp_select", "indirect_comp_select", "func_call", "opt_expr_list", "expr_list", "add_op", "mult_op", "equality_op", "relation_op", "shift_op", "assign_op", "constant", "opt_KnR_declaration_list", "$@2", "$@3", "$@4", "opt_declaration_list", "$@5", "$@6", "$@7", "declaration_list", "decl_stemnt", "old_style_declaration", "declaration", "no_decl_specs", "decl_specs",
		"abs_decl", "type_name", "$@8", "type_name_bis", "decl_specs_reentrance_bis", "local_or_global_storage_class", "local_storage_class", "storage_class", "type_spec", "opt_decl_specs_reentrance", "decl_specs_reentrance", "$@9", "opt_comp_decl_specs", "comp_decl_specs_reentrance", "$@10", "comp_decl_specs", "decl", "$@11", "init_decl", "opt_init_decl_list", "init_decl_list",
		"init_decl_list_reentrance", "initializer", "initializer_list", "initializer_reentrance", "opt_comma", "type_qual", "type_qual_token", "type_qual_list", "opt_type_qual_list", "type_spec_reentrance", "typedef_name", "tag_ref", "struct_tag_ref", "union_tag_ref", "enum_tag_ref", "struct_tag_def", "struct_type_define", "union_tag_def", "union_type_define", "enum_tag_def", "enum_type_define",
		"struct_or_union_definition", "enum_definition", "opt_trailing_comma", "enum_def_list", "enum_def_list_reentrance", "enum_const_def", "enum_constant", "field_list", "$@12", "$@13", "field_list_reentrance", "comp_decl", "comp_decl_list", "comp_decl_list_reentrance", "$@14", "$@15", "comp_declarator", "simple_comp", "bit_field", "$@16", "width", "opt_declarator", "declarator",
		"func_declarator", "declarator_reentrance_bis", "direct_declarator_reentrance_bis", "direct_declarator_reentrance", "array_decl", "pointer_start", "pointer_reentrance", "pointer", "ident_list", "$@17", "ident_list_reentrance", "ident", "typename_as_ident", "any_ident", "opt_param_type_list", "$@18", "param_type_list", "$@19", "param_type_list_bis", "param_list", "param_decl", "$@20",
		"param_decl_bis", "abs_decl_reentrance", "direct_abs_decl_reentrance_bis", "direct_abs_decl_reentrance", "opt_gcc_attrib", "gcc_attrib", "gcc_inner", 0 };
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
 token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
	0, 256, 257, 258, 259, 260, 261, 262, 263, 264,
	265, 266, 267, 268, 269, 270, 271, 272, 273, 274,
	275, 276, 277, 278, 279, 280, 281, 282, 283, 284,
	285, 286, 287, 288, 289, 290, 291, 292, 293, 294,
	295, 296, 297, 298, 299, 300, 301, 302, 303, 304,
	305, 306, 307, 308, 309, 310, 311, 312, 313, 314,
	315, 316, 317, 318, 319, 320, 321, 322, 323, 324,
	325, 326, 327, 328, 329, 330, 331, 332, 333, 334,
	335, 336, 337, 338, 339, 340, 341, 342, 343, 344,
	345, 346, 347, 348, 349, 350, 351, 352, 353, 354,
	355, 356, 357, 358, 359, 360, 361, 362, 363, 364,
	365, 366, 367, 368, 369, 370, 371, 372
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] = { 0, 118, 119, 119, 119, 120, 120, 121, 122, 122, 122, 122, 122, 123, 124, 124, 126, 125, 125, 127, 127, 128, 128, 128, 129, 130, 130, 131, 131, 132, 132, 132, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 134, 135, 136, 136, 137, 137, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 149, 149, 150, 151, 151, 152, 153, 153, 154, 154,
		155, 155, 156, 157, 157, 158, 159, 159, 160, 160, 161, 162, 162, 163, 163, 164, 164, 165, 166, 166, 167, 167, 168, 168, 169, 169, 170, 170, 171, 171, 172, 172, 172, 172, 172, 172, 172, 172, 172, 172, 173, 173, 174, 175, 176, 177, 178, 179, 180, 180, 181, 181, 181, 182, 182, 183, 183, 183, 183, 183, 183, 184, 185, 185, 186, 187, 188, 189, 190, 191, 192, 192, 193, 193, 194, 194, 195, 195,
		195, 196, 197, 198, 198, 199, 199, 200, 200, 200, 200, 200, 200, 202, 201, 203, 204, 201, 206, 205, 207, 208, 205, 209, 209, 210, 210, 211, 212, 213, 214, 215, 217, 216, 218, 218, 219, 220, 220, 220, 221, 221, 222, 222, 223, 224, 224, 225, 226, 225, 225, 227, 227, 229, 228, 228, 230, 232, 231, 233, 233, 234, 234, 235, 236, 236, 237, 238, 238, 239, 239, 240, 240, 241, 242, 242, 243, 243,
		244, 244, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 246, 247, 248, 249, 250, 251, 252, 252, 253, 254, 254, 255, 256, 256, 257, 257, 258, 258, 259, 259, 260, 261, 261, 262, 262, 263, 265, 266, 264, 267, 267, 267, 268, 268, 269, 271, 270, 272, 270, 273, 273, 274, 276, 275, 277, 278, 278, 279, 280, 281, 281, 282, 283, 283, 283,
		283, 283, 283, 284, 285, 286, 286, 287, 289, 288, 290, 290, 291, 292, 293, 293, 294, 295, 294, 297, 296, 298, 298, 299, 299, 301, 300, 302, 302, 302, 303, 303, 303, 304, 305, 305, 305, 305, 305, 306, 306, 307, 308, 308, 308, 308, 308, 308, 308, 308, 308 };

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] = { 0, 2, 0, 1, 1, 2, 3, 0, 1, 1, 1, 2, 3, 2, 3, 3, 0, 5, 2, 0, 1, 1, 2, 2, 1, 4, 2, 0, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 1, 1, 1, 1, 1, 5, 2, 2, 3, 3, 1, 5, 7, 7, 5, 9, 1, 1, 1, 1, 2, 4, 1, 1, 5, 1, 3, 0, 1, 1, 0, 1, 1, 1, 3, 1, 3, 2, 1, 3, 1, 3, 1, 3, 2, 1, 4, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 2, 2, 2, 2, 2, 2, 2,
		1, 3, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 4, 1, 1, 2, 2, 1, 3, 3, 4, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 3, 0, 1, 0, 0, 3, 2, 3, 2, 2, 2, 2, 0, 1, 1, 0, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 2, 0, 3, 2, 0, 1, 0, 3, 2, 1, 0, 3, 1, 3, 0, 1, 1, 1, 3, 1, 1, 3, 1, 4, 0, 1, 1, 1, 1, 1, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 2, 2, 2, 4, 4, 2, 4, 4, 2, 4, 4, 0, 1, 0, 2, 0, 1, 1, 1, 3, 1, 3, 1, 0, 0, 3, 2, 2, 3, 2, 1, 1, 0, 3, 0, 5, 1, 1, 1, 0, 4, 1, 0, 1, 1, 1, 2, 1, 1, 1, 3, 1, 4, 4, 3, 4, 2, 1, 2, 1, 0, 2, 1, 3, 1, 1, 1, 1, 0, 0, 2, 0, 2, 1, 3, 1, 3, 0, 2, 2, 2, 1, 1, 1, 2, 1, 3, 3, 4, 3, 4, 0, 1, 6, 0, 1, 1, 1, 1, 4, 4, 8, 1 };

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
 Performed when YYTABLE doesn't specify something else to do.  Zero
 means the default is an error.  */
static const yytype_uint16 yydefact[] = { 0, 4, 252, 10, 225, 226, 191, 188, 192, 189, 190, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 0, 0, 0, 0, 0, 7, 9, 0, 8, 0, 0, 212, 212, 181, 193, 194, 196, 199, 187, 196, 224, 195, 237, 235, 236, 234, 0, 232, 0, 233, 0, 231, 7, 11, 253, 268, 256, 278, 254, 278, 255, 1, 0, 7, 5, 0, 16, 13, 176, 177, 319, 229, 0, 210, 215, 178,
		213, 214, 166, 299, 302, 303, 306, 312, 314, 0, 304, 179, 208, 166, 300, 198, 197, 196, 201, 278, 278, 268, 12, 320, 0, 270, 272, 273, 275, 321, 322, 277, 0, 267, 279, 0, 6, 18, 169, 227, 230, 311, 0, 0, 0, 15, 165, 167, 346, 73, 326, 313, 301, 14, 200, 0, 0, 0, 264, 271, 269, 0, 258, 0, 261, 0, 170, 172, 228, 305, 162, 163, 160, 161, 158, 159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 71, 220, 69,
		79, 107, 81, 84, 86, 108, 101, 88, 93, 95, 97, 99, 91, 104, 105, 106, 109, 110, 111, 112, 128, 124, 103, 129, 130, 132, 133, 135, 136, 131, 125, 211, 217, 123, 216, 0, 0, 209, 347, 121, 0, 74, 75, 78, 309, 0, 0, 0, 332, 259, 262, 265, 274, 276, 207, 287, 202, 204, 280, 0, 0, 0, 0, 0, 68, 0, 0, 0, 0, 76, 0, 0, 169, 56, 0, 0, 21, 34, 24, 32, 33, 35, 36, 37, 38, 39, 40, 41, 42, 46, 47, 48,
		49, 50, 0, 62, 63, 64, 0, 123, 0, 222, 218, 117, 91, 115, 116, 118, 0, 120, 119, 0, 114, 90, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152, 0, 153, 0, 155, 154, 0, 148, 147, 0, 151, 150, 149, 0, 157, 156, 0, 138, 137, 0, 143, 0, 0, 168, 0, 212, 0, 310, 0, 308, 316, 317, 307, 327, 328, 330, 0, 284, 286, 297, 206, 203, 202, 282, 0, 281, 26, 43, 52, 66, 53, 0, 0, 76, 0, 0, 77, 0, 0, 0, 17, 23, 22, 0,
		44, 173, 223, 0, 0, 127, 126, 0, 184, 185, 0, 80, 82, 85, 87, 89, 94, 96, 98, 100, 102, 72, 0, 145, 0, 144, 140, 139, 141, 174, 349, 122, 0, 332, 336, 333, 289, 346, 291, 292, 0, 293, 205, 283, 0, 0, 0, 0, 55, 54, 0, 0, 0, 0, 29, 45, 219, 221, 113, 92, 73, 324, 186, 337, 182, 338, 340, 0, 134, 142, 0, 175, 352, 0, 350, 351, 0, 0, 353, 357, 0, 318, 329, 331, 324, 334, 337, 335, 297, 288,
		294, 67, 0, 0, 76, 0, 0, 25, 31, 30, 0, 0, 332, 0, 339, 73, 324, 70, 146, 0, 0, 0, 0, 346, 0, 0, 57, 0, 51, 60, 342, 344, 325, 341, 0, 0, 0, 0, 0, 348, 290, 296, 295, 0, 0, 76, 343, 345, 354, 355, 0, 59, 58, 0, 0, 0, 0, 61, 0, 356 };

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] = { -1, 28, 29, 69, 30, 31, 32, 72, 119, 245, 246, 247, 248, 412, 413, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 168, 210, 211, 212, 351, 269, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 214, 191, 192, 193, 194, 195, 196, 197, 386, 198, 199,
		200, 384, 385, 305, 309, 297, 299, 302, 312, 201, 126, 127, 128, 206, 146, 147, 148, 271, 319, 33, 34, 320, 36, 321, 422, 288, 289, 368, 38, 39, 40, 41, 42, 96, 43, 98, 336, 225, 338, 226, 78, 129, 79, 92, 81, 82, 202, 272, 203, 363, 44, 45, 121, 122, 46, 47, 61, 48, 49, 50, 51, 52, 53, 54, 55, 56, 113, 105, 141, 106, 107, 108, 109, 114, 115, 144, 229, 230, 333, 334, 335, 448, 397, 398,
		399, 474, 492, 400, 93, 94, 84, 85, 86, 87, 88, 89, 90, 216, 217, 326, 204, 111, 112, 461, 462, 218, 219, 329, 330, 331, 332, 395, 463, 425, 426, 208, 209, 440 };

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
 STATE-NUM.  */
#define YYPACT_NINF -395
static const yytype_int16 yypact[] = { 363, 3, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, 48, 51, 52, 64, 464, -395, -395, 35, -395, -9, -2, 22, 22, -395, -395, -395, 1023, -395, -395, 1023, -395, -395, -395, -395, -395, -395, 10, -395, 50, -395, 62, -395, -395, -395, -395, 119, 79, 58, 87, 58, 89, -395,
		3, -395, -395, 94, -395, -395, -395, -395, -395, 155, 22, 78, -395, -395, -395, 109, 25, -395, -395, 60, -395, -395, 86, 29, -395, -395, -395, 41, -7, -395, -395, 1023, -395, 58, 58, 119, -395, -395, 129, 131, -395, -395, 113, -395, -395, -395, 141, -395, -395, 143, -395, -395, 1056, -395, 155, -395, 154, 195, 22, -395, -395, -395, 148, 234, 47, -395, -395, -395, -395, 165, 172, 193, -395,
		119, -395, 234, -395, 415, -395, 723, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, 195, 234, 234, 234, 234, 898, 898, 917, 234, 234, 519, -395, -395, 104, 173, -395, 171, 177, 178, -395, -395, 170, 176, 96, 112, 63, 132, -395, -395, -395, -395, -395, -395, -395, -395, -395, 152, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, 1023, 156, -395, -395,
		-395, 210, -395, -395, 208, -395, 214, 277, 218, -395, -395, -395, -395, -395, -395, -395, 217, 415, -395, 947, 219, 160, 222, 234, 223, -395, 850, 175, 179, 282, 234, 180, 183, 1056, -395, 239, 596, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, 220, -395, -395, -395, 240, 224, 1023, 241, -395, -395, -395, -395, -395, -395, 75,
		-395, -395, 519, -395, -395, -395, 248, 249, 250, 1023, 234, 234, 234, 234, 234, 234, -395, 234, -395, 234, -395, -395, 234, -395, -395, 234, -395, -395, -395, 234, -395, -395, 234, -395, -395, 234, 234, 119, 119, -395, 247, 22, 202, -395, 234, -395, 251, -395, -395, -395, 254, -395, 1023, -395, 259, 22, -395, -395, 415, -395, 261, -395, -395, -395, -395, 260, -395, 268, 234, 234, 263,
		264, -395, 234, 234, 773, -395, -395, -395, 850, -395, -395, 195, 252, 269, -395, -395, 234, -395, -40, 258, 173, 171, 177, 178, 170, 176, 96, 112, 63, -395, -395, 271, -395, 275, 278, -395, -395, -395, 1023, 174, -395, 277, 276, 18, -395, -395, 148, -395, -395, 262, 265, -395, -395, 234, 236, 287, 285, -395, -395, 290, 292, 291, 646, -395, -395, -395, -395, -395, -395, 234, 16, -395, 116,
		-395, -395, 124, 234, -395, -395, 234, -395, -395, 255, -395, -395, 256, 257, -395, -395, 297, -395, -395, -395, 44, -395, 46, -395, 22, -395, -395, -395, 234, 850, 234, 850, 850, -395, -395, -395, 299, 302, -395, 308, -395, 234, 309, -395, -395, 364, 277, 277, 337, 148, 234, 338, 360, 336, -395, -395, -395, -395, -395, -395, 340, 342, 344, 348, 345, -395, -395, -395, -395, 347, 850, 234,
		-395, -395, -395, -395, 407, -395, -395, 357, 353, 850, 413, -395, 361, -395 };

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] = { -395, -395, -395, 0, 396, -395, -395, -395, -395, -395, -395, 181, -395, -395, -395, -221, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -394, -104, -369, -217, -330, -127, -395, 137, -395, 144, 136, 139, -395, -131, 159, 158, 157, 161, 166, -152, -395, -395, -395, -395, -395, -395, -395,
		-395, -395, -395, -395, -395, -395, -395, -395, 142, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, -395, 365, -395, -395, -395, 229, -395, -395, -395, -254, -395, -395, 59, -395, 61, -395, 184, -395, -395, -241, -395, -395, -395, -395, -5, 2, -395, 123, -190, -395, -395, -395, -395, 332, 426, -395, -395, -395, -395, -139, -395, -122, -18, -395, -395, -113, -395, 221,
		-395, -395, -395, -395, -395, -395, -395, -395, -395, 72, 371, -395, -395, -395, 334, -395, -395, -395, -395, -395, 246, -395, -395, -395, -395, 28, -395, -395, -395, -395, -395, -34, -395, -33, -85, -395, -395, 414, -395, -324, -395, -395, -395, -36, -395, -68, 38, -395, -395, -395, 43, -395, 114, -395, -395, -296, -295, -395, -374, -395, -395 };

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
 positive, shift that token.  If negative, reduce the rule which
 number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -324
static const yytype_int16 yytable[] = { 91, 91, 83, 213, 95, 133, 275, 275, 275, 275, 280, 281, 283, 275, 275, 347, 345, 361, 273, 407, 169, 75, 227, 449, 110, 75, -164, 274, 276, 277, 278, 228, 75, 467, 284, 285, 70, 337, 224, 99, 287, 91, -164, 97, 123, 423, 97, 75, 369, 75, -315, 460, 59, 169, 91, 59, 59, 103, 120, 35, 73, 37, -299, -299, 66, 76, 110, 74, 117, -299, 446, 57, 58, 424, 420, 421,
		286, 100, 75, -299, 491, -323, 151, 152, 153, 154, 155, 156, 35, 91, 37, 394, -164, 135, -208, -208, 484, 423, 447, 490, 97, -208, 71, 149, 110, 227, 213, 227, -164, -323, 270, -208, 215, 352, 228, 60, 228, 101, 62, 64, 446, 76, 75, 76, 477, 104, -266, 76, 464, 102, 420, 421, 420, 444, 414, 431, 116, 77, 415, 275, 275, 275, 275, 275, 77, 275, -263, 275, 337, 76, 275, 464, 287, 275, -257,
		287, -260, 275, 420, 444, 420, 444, 118, 370, 124, 503, 306, 307, 308, 158, 4, 5, 136, 137, 130, 131, 159, 160, 380, 125, 161, 327, 162, 163, 164, 165, 166, 451, 382, 432, 167, 76, 459, 290, 291, 300, 301, 139, 75, 142, 270, 140, 151, 152, 153, 154, 155, 156, 381, 143, 270, 145, 383, 303, 304, 275, 227, 310, 311, 150, 391, 406, 352, 416, 207, 228, 410, 411, 342, 343, 420, 421, 476, 220,
		478, 479, 419, 75, 465, 466, 221, 151, 152, 153, 154, 155, 156, 63, 65, 387, 387, 433, 434, 435, 436, 437, 438, 439, 169, 313, 314, 222, 157, 293, 292, 296, 315, 316, 317, 318, 294, 322, 295, 502, 298, 275, 323, 213, 324, 325, 75, 110, 110, 328, 507, 91, -285, 350, 341, 158, 348, 344, 346, 213, 349, 353, 159, 160, 354, 91, 161, 401, 162, 163, 164, 165, 166, 356, 359, 360, 167, 362, -65,
		365, 366, 367, 389, 390, 405, 270, 417, 392, 275, 270, 393, 475, 468, 352, 158, 396, 403, 404, 408, 409, 418, 159, 160, 428, 213, 161, 429, 162, 163, 164, 165, 166, 427, 442, 430, 167, 450, 452, 453, -298, 454, 455, 441, 456, 91, 457, 445, 133, 472, -2, 1, 480, -180, 481, 352, 2, 469, 470, 471, 483, -323, 486, 3, 270, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
		23, 24, 25, 26, 27, 489, 493, 494, 495, 496, 497, 91, 498, 91, 123, 91, 499, 401, 500, 501, 270, 504, 270, 270, 2, 505, 506, 508, 68, 509, 358, 371, 373, 4, 5, -180, 374, 487, 488, 372, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 375, 376, 377, 205, 270, 134, 388, 402, 80, 378, -3, 67, 364, -180, -180, 270, 2, 379, 355, 138, 223, 340, 473, 3, -180, 4, 5, 6, 7, 8, 9,
		10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 132, 485, 482, 0, 443, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 286, 0, 75, 0, 0, -183, 151, 152, 153, 154, 155, 156, 0, -180, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, -183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -180, 0, 0, 0, 0, 0,
		0, 0, 0, 0, -180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 231, 0, 75, 0, 0, 0, 151, 152, 153, 154, 155, 156, 357, 0, 0, 0, 158, 0, 0, 0, 0, 0, 0, 159, 160, 0, 0, 161, 0, 162, 163, 164, 165, 166, 0, 0, 0, 167, 232, 233, 234, 235, 236, 0, 237, 238, 239, 240, 241, 242, 231, 0, 75, 0, 0, 0, 151, 152, 153, 154, 155, 156, 458, 0, 0, 0, 243, -20, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 232, 233, 234, 235, 236, 158, 237, 238, 239, 240, 241, 242, 159, 160, 0, 0, 161, 0, 162, 163, 164, 165, 166, 0, 0, 0, 167, 0, 243, -28, 244, 0, 0, 0, 0, 0, 0, 0, 0, 231, 0, 75, 0, 0, 0, 151, 152, 153, 154, 155, 156, 0, 0, 0, 0, 158, 0, 0, 0, 0, 0, 0, 159, 160, 0, 0, 161, 0, 162, 163, 164, 165, 166, 0, 0, 0, 167, 232, 233, 234, 235, 236, 0, 237, 238, 239, 240, 241,
		242, 231, 0, 75, 0, 0, 0, 151, 152, 153, 154, 155, 156, 0, 0, 0, 0, 243, -19, 244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 232, 233, 234, 235, 236, 158, 237, 238, 239, 240, 241, 242, 159, 160, 0, 0, 161, 0, 162, 163, 164, 165, 166, 0, 0, 0, 167, 0, 243, -27, 244, 0, 0, 0, 0, 0, 0, 0, 0, 231, 0, 75, 0, 0, 0, 151, 152, 153, 154, 155, 156, 0, 0, 0, 0, 158, 0, 0, 0, 0, 0, 0,
		159, 160, 0, 0, 161, 0, 162, 163, 164, 165, 166, 0, 0, 0, 167, 232, 233, 234, 235, 236, 0, 237, 238, 239, 240, 241, 242, 75, 0, 0, 0, 151, 152, 153, 154, 155, 156, 0, 0, 0, 0, 0, 0, 243, 0, 244, 75, 0, 0, 0, 151, 152, 153, 154, 155, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158, 0, 0, 0, 0, 0, 0, 159, 160, 2, 0, 161, 0, 162, 163, 164, 165, 166, 4, 5, 0, 167, 0, 0, 0, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0, 0, 0, 158, 0, 0, 0, 0, 0, 0, 159, 160, 0, 0, 161, 0, 162, 163, 164, 165, 166, 0, 158, 0, 279, 0, 0, 339, 0, 159, 160, 0, 0, 161, 0, 162, 163, 164, 165, 166, 2, 0, 0, 282, 0, 0, 0, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, -171, 0, 0, 0, 0, 0, 0, 0, 0, -171, -171, -171,
		-171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171, -171 };

#define yypact_value_is_default(yystate) \
  ((yystate) == (-395))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] = { 36, 37, 36, 130, 37, 90, 158, 159, 160, 161, 162, 163, 164, 165, 166, 236, 233, 271, 157, 349, 124, 3, 144, 397, 60, 3, 1, 158, 159, 160, 161, 144, 3, 427, 165, 166, 1, 227, 142, 44, 167, 77, 1, 41, 77, 369, 44, 3, 289, 3, 3, 420, 4, 157, 90, 4, 4, 57, 76, 0, 69, 0, 69, 70, 0, 105, 102, 69, 68, 76, 394, 68, 69, 369, 114, 115, 1, 67, 3, 86, 474, 65, 7, 8, 9,
		10, 11, 12, 29, 125, 29, 332, 67, 98, 69, 70, 465, 421, 394, 473, 98, 76, 67, 121, 140, 227, 233, 229, 67, 65, 146, 86, 65, 240, 227, 67, 229, 67, 67, 67, 444, 105, 3, 105, 454, 6, 68, 105, 423, 67, 114, 115, 114, 115, 355, 389, 64, 115, 359, 291, 292, 293, 294, 295, 115, 297, 67, 299, 338, 105, 302, 446, 279, 305, 67, 282, 67, 309, 114, 115, 114, 115, 68, 290, 86, 495, 103, 104, 105, 94,
		15, 16, 100, 101, 114, 115, 101, 102, 309, 70, 105, 217, 107, 108, 109, 110, 111, 404, 315, 15, 115, 105, 413, 89, 90, 99, 100, 68, 3, 86, 236, 70, 7, 8, 9, 10, 11, 12, 312, 68, 246, 68, 316, 101, 102, 367, 338, 85, 86, 65, 324, 348, 349, 362, 76, 338, 353, 354, 68, 69, 114, 115, 453, 68, 455, 456, 367, 3, 114, 115, 68, 7, 8, 9, 10, 11, 12, 26, 27, 317, 318, 77, 78, 79, 80, 81, 82, 83,
		362, 107, 108, 68, 67, 92, 91, 95, 114, 115, 116, 117, 93, 115, 94, 494, 98, 427, 66, 404, 70, 65, 3, 317, 318, 65, 505, 321, 69, 5, 69, 94, 115, 69, 69, 420, 115, 115, 101, 102, 115, 335, 105, 335, 107, 108, 109, 110, 111, 68, 88, 69, 115, 70, 88, 65, 65, 65, 69, 115, 50, 355, 68, 70, 474, 359, 70, 452, 430, 454, 94, 70, 69, 71, 69, 69, 65, 101, 102, 66, 465, 105, 65, 107, 108, 109, 110,
		111, 88, 71, 70, 115, 88, 115, 65, 88, 69, 65, 392, 65, 394, 68, 394, 446, 65, 0, 1, 66, 3, 65, 495, 6, 115, 115, 115, 65, 65, 11, 13, 413, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 65, 65, 44, 69, 66, 65, 444, 65, 446, 444, 448, 65, 448, 70, 69, 453, 11, 455, 456, 6, 65, 70, 11, 29, 65, 246, 291, 293, 15, 16, 69, 294, 470, 471, 292,
		22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 295, 297, 299, 125, 494, 94, 318, 338, 36, 302, 0, 1, 282, 3, 105, 505, 6, 305, 243, 102, 140, 229, 448, 13, 115, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 89, 466, 462, -1, 393, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 3, -1, -1, 6, 7, 8, 9, 10, 11, 12,
		-1, 69, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 105, -1, -1, -1, -1, -1, -1, -1, -1, -1, 115, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 3, -1, -1, -1, 7, 8, 9, 10, 11, 12, 13, -1, -1, -1, 94, -1, -1, -1, -1, -1, -1, 101, 102, -1, -1, 105, -1, 107, 108, 109,
		110, 111, -1, -1, -1, 115, 39, 40, 41, 42, 43, -1, 45, 46, 47, 48, 49, 50, 1, -1, 3, -1, -1, -1, 7, 8, 9, 10, 11, 12, 13, -1, -1, -1, 67, 68, 69, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 39, 40, 41, 42, 43, 94, 45, 46, 47, 48, 49, 50, 101, 102, -1, -1, 105, -1, 107, 108, 109, 110, 111, -1, -1, -1, 115, -1, 67, 68, 69, -1, -1, -1, -1, -1, -1, -1, -1, 1,
		-1, 3, -1, -1, -1, 7, 8, 9, 10, 11, 12, -1, -1, -1, -1, 94, -1, -1, -1, -1, -1, -1, 101, 102, -1, -1, 105, -1, 107, 108, 109, 110, 111, -1, -1, -1, 115, 39, 40, 41, 42, 43, -1, 45, 46, 47, 48, 49, 50, 1, -1, 3, -1, -1, -1, 7, 8, 9, 10, 11, 12, -1, -1, -1, -1, 67, 68, 69, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 39, 40, 41, 42, 43, 94, 45, 46, 47, 48, 49,
		50, 101, 102, -1, -1, 105, -1, 107, 108, 109, 110, 111, -1, -1, -1, 115, -1, 67, 68, 69, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 3, -1, -1, -1, 7, 8, 9, 10, 11, 12, -1, -1, -1, -1, 94, -1, -1, -1, -1, -1, -1, 101, 102, -1, -1, 105, -1, 107, 108, 109, 110, 111, -1, -1, -1, 115, 39, 40, 41, 42, 43, -1, 45, 46, 47, 48, 49, 50, 3, -1, -1, -1, 7, 8, 9, 10, 11, 12, -1, -1, -1, -1, -1, -1, 67, -1,
		69, 3, -1, -1, -1, 7, 8, 9, 10, 11, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 94, -1, -1, -1, -1, -1, -1, 101, 102, 6, -1, 105, -1, 107, 108, 109, 110, 111, 15, 16, -1, 115, -1, -1, -1, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, -1, -1, -1, -1, -1, -1, 94, -1, -1, -1, -1, -1, -1, 101, 102, -1, -1, 105, -1, 107, 108, 109, 110, 111, -1, 94, -1, 115,
		-1, -1, 69, -1, 101, 102, -1, -1, 105, -1, 107, 108, 109, 110, 111, 6, -1, -1, 115, -1, -1, -1, -1, -1, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 6, -1, -1, -1, -1, -1, -1, -1, -1, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38 };

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
 symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] = { 0, 1, 6, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 119, 120, 122, 123, 124, 210, 211, 212, 213, 214, 219, 220, 221, 222, 223, 225, 241, 242, 245, 246, 248, 249, 250, 251, 252, 253, 254, 255, 256, 68, 69, 4, 67, 247, 67, 247, 67, 247, 0, 1, 122, 121, 1, 67, 125, 69, 69, 3, 105, 115, 231, 233, 234, 235,
		236, 279, 281, 282, 283, 284, 285, 286, 287, 291, 234, 279, 280, 281, 224, 225, 226, 224, 67, 67, 67, 121, 6, 258, 260, 261, 262, 263, 291, 292, 293, 257, 264, 265, 257, 121, 68, 126, 242, 243, 244, 281, 86, 70, 201, 202, 203, 232, 114, 115, 285, 282, 201, 224, 257, 257, 258, 68, 70, 259, 86, 68, 266, 68, 205, 206, 207, 242, 65, 7, 8, 9, 10, 11, 12, 67, 94, 101, 102, 105, 107, 108, 109,
		110, 111, 115, 153, 154, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 181, 182, 183, 184, 185, 186, 187, 189, 190, 191, 200, 237, 239, 291, 233, 204, 76, 306, 307, 154, 155, 156, 158, 180, 65, 288, 289, 296, 297, 68, 68, 68, 262, 154, 228, 230, 241, 245, 267, 268, 1, 39, 40, 41, 42, 43, 45, 46, 47, 48, 49, 50, 67, 69, 127, 128,
		129, 130, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 158, 291, 208, 238, 239, 166, 172, 166, 166, 166, 115, 172, 172, 115, 172, 166, 166, 1, 158, 216, 217, 89, 90, 91, 92, 93, 94, 95, 196, 98, 197, 99, 100, 198, 101, 102, 194, 103, 104, 105, 195, 85, 86, 199, 107, 108, 114, 115, 116, 117, 209, 212, 214, 115, 66, 70, 65, 290, 291, 65,
		298, 299, 300, 301, 269, 270, 271, 227, 228, 229, 69, 268, 69, 68, 69, 69, 156, 69, 133, 115, 115, 5, 157, 158, 115, 115, 205, 68, 13, 129, 88, 69, 209, 70, 240, 216, 65, 65, 65, 218, 219, 158, 160, 162, 163, 164, 167, 168, 169, 170, 171, 166, 154, 158, 154, 192, 193, 188, 293, 188, 69, 115, 154, 70, 70, 219, 302, 70, 273, 274, 275, 278, 279, 227, 69, 71, 50, 158, 157, 69, 69, 158, 158,
		131, 132, 133, 133, 239, 68, 65, 166, 114, 115, 215, 287, 303, 304, 305, 88, 66, 65, 70, 209, 15, 77, 78, 79, 80, 81, 82, 83, 308, 291, 71, 300, 115, 279, 287, 303, 272, 306, 88, 156, 115, 65, 69, 65, 65, 68, 13, 133, 155, 294, 295, 303, 304, 114, 115, 153, 154, 115, 115, 115, 65, 273, 276, 158, 133, 157, 133, 133, 66, 65, 298, 65, 155, 294, 11, 291, 291, 65, 306, 153, 277, 65, 44, 69, 66,
		65, 65, 65, 70, 69, 133, 157, 11, 65, 70, 133, 11, 65 };

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

/* Like YYERROR except do call yyerror.  This remains here temporarily
 to ease the transition to the new meaning of YYERROR, for GCC.
 Once GCC version 2 has supplanted version 1, this can go.  However,
 YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
 in Bison 2.4.2's NEWS entry, where a plan to phase it out is
 discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
/* This is here to suppress warnings from the GCC cpp's
 -Wunused-macros.  Normally we don't worry about that warning, but
 some users do, and we want to make it easy for users to remove
 YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
 If N is 0, then set CURRENT to the empty location which ends
 the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif

/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))

/*--------------------------------.
 | Print this symbol on YYOUTPUT.  |
 `--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void yy_symbol_value_print(FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
		static void
		yy_symbol_value_print (yyoutput, yytype, yyvaluep)
		FILE *yyoutput;
		int yytype;
		YYSTYPE const * const yyvaluep;
#endif
		{
	if (!yyvaluep) return;
# ifdef YYPRINT
	if (yytype < YYNTOKENS)
	YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
	YYUSE(yyoutput);
# endif
	switch (yytype) {
		default:
			break;
	}
}

/*--------------------------------.
 | Print this symbol on YYOUTPUT.  |
 `--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void yy_symbol_print(FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
		static void
		yy_symbol_print (yyoutput, yytype, yyvaluep)
		FILE *yyoutput;
		int yytype;
		YYSTYPE const * const yyvaluep;
#endif
		{
	if (yytype < YYNTOKENS)
	YYFPRINTF(yyoutput, "token %s (", yytname[yytype]);
	else
	YYFPRINTF(yyoutput, "nterm %s (", yytname[yytype]);

	yy_symbol_value_print(yyoutput, yytype, yyvaluep);
	YYFPRINTF(yyoutput, ")");
}

/*------------------------------------------------------------------.
 | yy_stack_print -- Print the state stack from its BOTTOM up to its |
 | TOP (included).                                                   |
 `------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void yy_stack_print(yytype_int16 *yybottom, yytype_int16 *yytop)
#else
		static void
		yy_stack_print (yybottom, yytop)
		yytype_int16 *yybottom;
		yytype_int16 *yytop;
#endif
		{
	YYFPRINTF(stderr, "Stack now");
	for (; yybottom <= yytop; yybottom++) {
		int yybot = *yybottom;
		YYFPRINTF(stderr, " %d", yybot);
	}
	YYFPRINTF(stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))

/*------------------------------------------------.
 | Report that the YYRULE is going to be reduced.  |
 `------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void yy_reduce_print(YYSTYPE *yyvsp, int yyrule)
#else
		static void
		yy_reduce_print (yyvsp, yyrule)
		YYSTYPE *yyvsp;
		int yyrule;
#endif
		{
	int yynrhs = yyr2[yyrule];
	int yyi;
	unsigned long int yylno = yyrline[yyrule];
	YYFPRINTF(stderr, "Reducing stack by rule %d (line %lu):\n", yyrule - 1, yylno);
	/* The symbols being reduced.  */
	for (yyi = 0; yyi < yynrhs; yyi++) {
		YYFPRINTF(stderr, "   $%d = ", yyi + 1);
		yy_symbol_print(stderr, yyrhs[yyprhs[yyrule] + yyi], &(yyvsp[(yyi + 1) - (yynrhs)]));
		YYFPRINTF(stderr, "\n");
	}
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
 multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
 if the built-in stack extension method is used).

 Do not make this value too large; the results are undefined if
 YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
 evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
const char *yystr;
#endif
{
	YYSIZE_T yylen;
	for (yylen = 0; yystr[yylen]; yylen++)
	continue;
	return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
 YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
char *yydest;
const char *yysrc;
#endif
{
	char *yyd = yydest;
	const char *yys = yysrc;

	while ((*yyd++ = *yys++) != '\0')
	continue;

	return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
 quotes and backslashes, so that it's suitable for yyerror.  The
 heuristic is that double-quoting is unnecessary unless the string
 contains an apostrophe, a comma, or backslash (other than
 backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
 null, do not copy; instead, return the length of what the result
 would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
	if (*yystr == '"')
	{
		YYSIZE_T yyn = 0;
		char const *yyp = yystr;

		for (;;)
		switch (*++yyp)
		{
			case '\'':
			case ',':
			goto do_not_strip_quotes;

			case '\\':
			if (*++yyp != '\\')
			goto do_not_strip_quotes;
			/* Fall through.  */
			default:
			if (yyres)
			yyres[yyn] = *yyp;
			yyn++;
			break;

			case '"':
			if (yyres)
			yyres[yyn] = '\0';
			return yyn;
		}
		do_not_strip_quotes:;
	}

	if (! yyres)
	return yystrlen (yystr);

	return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
 about the unexpected token YYTOKEN for the state stack whose top is
 YYSSP.

 Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
 not large enough to hold the message.  In that case, also set
 *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
 required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
		yytype_int16 *yyssp, int yytoken)
{
	YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
	YYSIZE_T yysize = yysize0;
	YYSIZE_T yysize1;
	enum {YYERROR_VERBOSE_ARGS_MAXIMUM = 5};
	/* Internationalized format string. */
	const char *yyformat = 0;
	/* Arguments of yyformat. */
	char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	/* Number of reported tokens (one for the "unexpected", one per
	 "expected"). */
	int yycount = 0;

	/* There are many possibilities here to consider:
	 - Assume YYFAIL is not used.  It's too flawed to consider.  See
	 <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
	 for details.  YYERROR is fine as it does not invoke this
	 function.
	 - If this state is a consistent state with a default action, then
	 the only way this function was invoked is if the default action
	 is an error action.  In that case, don't check for expected
	 tokens because there are none.
	 - The only way there can be no lookahead present (in yychar) is if
	 this state is a consistent state with a default action.  Thus,
	 detecting the absence of a lookahead is sufficient to determine
	 that there is no unexpected or expected token to report.  In that
	 case, just report a simple "syntax error".
	 - Don't assume there isn't a lookahead just because this state is a
	 consistent state with a default action.  There might have been a
	 previous inconsistent state, consistent state with a non-default
	 action, or user semantic action that manipulated yychar.
	 - Of course, the expected token list depends on states to have
	 correct lookahead information, and it depends on the parser not
	 to perform extra reductions after fetching a lookahead from the
	 scanner and before detecting a syntax error.  Thus, state merging
	 (from LALR or IELR) and default reductions corrupt the expected
	 token list.  However, the list is correct for canonical LR with
	 one exception: it will still contain any token that will not be
	 accepted due to an error action in a later state.
	 */
	if (yytoken != YYEMPTY)
	{
		int yyn = yypact[*yyssp];
		yyarg[yycount++] = yytname[yytoken];
		if (!yypact_value_is_default (yyn))
		{
			/* Start YYX at -YYN if negative to avoid negative indexes in
			 YYCHECK.  In other words, skip the first -YYN actions for
			 this state because they are default actions.  */
			int yyxbegin = yyn < 0 ? -yyn : 0;
			/* Stay within bounds of both yycheck and yytname.  */
			int yychecklim = YYLAST - yyn + 1;
			int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
			int yyx;

			for (yyx = yyxbegin; yyx < yyxend; ++yyx)
			if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
					&& !yytable_value_is_error (yytable[yyx + yyn]))
			{
				if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
				{
					yycount = 1;
					yysize = yysize0;
					break;
				}
				yyarg[yycount++] = yytname[yyx];
				yysize1 = yysize + yytnamerr (0, yytname[yyx]);
				if (! (yysize <= yysize1
								&& yysize1 <= YYSTACK_ALLOC_MAXIMUM))
				return 2;
				yysize = yysize1;
			}
		}
	}

	switch (yycount)
	{
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
		YYCASE_(0, YY_("syntax error"));
		YYCASE_(1, YY_("syntax error, unexpected %s"));
		YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
		YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
		YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
		YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
	}

	yysize1 = yysize + yystrlen (yyformat);
	if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
	return 2;
	yysize = yysize1;

	if (*yymsg_alloc < yysize)
	{
		*yymsg_alloc = 2 * yysize;
		if (! (yysize <= *yymsg_alloc
						&& *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
		*yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
		return 1;
	}

	/* Avoid sprintf, as that infringes on the user's name space.
	 Don't have undefined behavior even if the translation
	 produced a string with the wrong number of "%s"s.  */
	{
		char *yyp = *yymsg;
		int yyi = 0;
		while ((*yyp = *yyformat) != '\0')
		if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
		{
			yyp += yytnamerr (yyp, yyarg[yyi++]);
			yyformat += 2;
		}
		else
		{
			yyp++;
			yyformat++;
		}
	}
	return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
		static void
		yydestruct (yymsg, yytype, yyvaluep)
		const char *yymsg;
		int yytype;
		YYSTYPE *yyvaluep;
#endif
		{
	YYUSE(yyvaluep);

	if (!yymsg) yymsg = "Deleting";
	YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

	switch (yytype) {

		default:
			break;
	}
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse(void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

/*----------.
 | yyparse.  |
 `----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int yyparse(void)
#else
		int
		yyparse ()

#endif
#endif
		{
	/* The lookahead symbol.  */
	int yychar;

	/* The semantic value of the lookahead symbol.  */YYSTYPE yylval;

	/* Number of syntax errors so far.  */
	int yynerrs;

	int yystate;
	/* Number of tokens to shift before error messages enabled.  */
	int yyerrstatus;

	/* The stacks and their tools:
	 `yyss': related to states.
	 `yyvs': related to semantic values.

	 Refer to the stacks thru separate pointers, to allow yyoverflow
	 to reallocate them elsewhere.  */

	/* The state stack.  */
	yytype_int16 yyssa[YYINITDEPTH];
	yytype_int16 *yyss;
	yytype_int16 *yyssp;

	/* The semantic value stack.  */YYSTYPE yyvsa[YYINITDEPTH];
	YYSTYPE *yyvs;
	YYSTYPE *yyvsp;

	YYSIZE_T yystacksize;

	int yyn;
	int yyresult;
	/* Lookahead token as an internal (translated) token number.  */
	int yytoken;
	/* The variables used to return semantic value and location from the
	 action routines.  */YYSTYPE yyval;

#if YYERROR_VERBOSE
	/* Buffer for error messages, and its allocated size.  */
	char yymsgbuf[128];
	char *yymsg = yymsgbuf;
	YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

	/* The number of symbols on the RHS of the reduced rule.
	 Keep to zero when no symbol should be popped.  */
	int yylen = 0;

	yytoken = 0;
	yyss = yyssa;
	yyvs = yyvsa;
	yystacksize = YYINITDEPTH;

	YYDPRINTF((stderr, "Starting parse\n"));

	yystate = 0;
	yyerrstatus = 0;
	yynerrs = 0;
	yychar = YYEMPTY; /* Cause a token to be read.  */

	/* Initialize stack pointers.
	 Waste one element of value and location stack
	 so that they stay on the same level as the state stack.
	 The wasted elements are never initialized.  */
	yyssp = yyss;
	yyvsp = yyvs;

	goto yysetstate;

	/*------------------------------------------------------------.
	 | yynewstate -- Push a new state, which is found in yystate.  |
	 `------------------------------------------------------------*/
	yynewstate:
	/* In all cases, when you get here, the value and location stacks
	 have just been pushed.  So pushing a state here evens the stacks.  */
	yyssp++;

	yysetstate: *yyssp = yystate;

	if (yyss + yystacksize - 1 <= yyssp) {
		/* Get the current used size of the three stacks, in elements.  */
		YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
		{
			/* Give user a chance to reallocate the stack.  Use copies of
			 these so that the &'s don't force the real ones into
			 memory.  */
			YYSTYPE *yyvs1 = yyvs;
			yytype_int16 *yyss1 = yyss;

			/* Each stack pointer address is followed by the size of the
			 data in use in that stack, in bytes.  This used to be a
			 conditional around just the two extra args, but that might
			 be undefined if yyoverflow is a macro.  */
			yyoverflow (YY_("memory exhausted"),
					&yyss1, yysize * sizeof (*yyssp),
					&yyvs1, yysize * sizeof (*yyvsp),
					&yystacksize);

			yyss = yyss1;
			yyvs = yyvs1;
		}
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
		goto yyexhaustedlab;
# else
		/* Extend the stack our own way.  */
		if (YYMAXDEPTH <= yystacksize)
		goto yyexhaustedlab;
		yystacksize *= 2;
		if (YYMAXDEPTH < yystacksize)
		yystacksize = YYMAXDEPTH;

		{
			yytype_int16 *yyss1 = yyss;
			union yyalloc *yyptr =
			(union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
			if (! yyptr)
			goto yyexhaustedlab;
			YYSTACK_RELOCATE (yyss_alloc, yyss);
			YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
			if (yyss1 != yyssa)
			YYSTACK_FREE (yyss1);
		}
# endif
#endif /* no yyoverflow */

		yyssp = yyss + yysize - 1;
		yyvsp = yyvs + yysize - 1;

		YYDPRINTF((stderr, "Stack size increased to %lu\n", (unsigned long int) yystacksize));

		if (yyss + yystacksize - 1 <= yyssp)
		YYABORT;
	}

	YYDPRINTF((stderr, "Entering state %d\n", yystate));

	if (yystate == YYFINAL)
	YYACCEPT;

	goto yybackup;

	/*-----------.
	 | yybackup.  |
	 `-----------*/
	yybackup:

	/* Do appropriate processing given the current state.  Read a
	 lookahead token if we need one and don't already have one.  */

	/* First try to decide what to do without reference to lookahead token.  */
	yyn = yypact[yystate];
	if (yypact_value_is_default (yyn)) goto yydefault;

	/* Not known => get a lookahead token if don't already have one.  */

	/* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
	if (yychar == YYEMPTY) {
		YYDPRINTF((stderr, "Reading a token: "));
		yychar = YYLEX;
	}

	if (yychar <= YYEOF) {
		yychar = yytoken = YYEOF;
		YYDPRINTF((stderr, "Now at end of input.\n"));
	} else {
		yytoken = YYTRANSLATE (yychar);
		YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
	}

	/* If the proper action on seeing token YYTOKEN is to reduce or to
	 detect an error, take that action.  */
	yyn += yytoken;
	if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken) goto yydefault;
	yyn = yytable[yyn];
	if (yyn <= 0) {
		if (yytable_value_is_error (yyn)) goto yyerrlab;
		yyn = -yyn;
		goto yyreduce;
	}

	/* Count tokens shifted since error; after three, turn off error
	 status.  */
	if (yyerrstatus) yyerrstatus--;

	/* Shift the lookahead token.  */
	YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);

	/* Discard the shifted token.  */
	yychar = YYEMPTY;

	yystate = yyn;
	*++yyvsp = yylval;

	goto yynewstate;

	/*-----------------------------------------------------------.
	 | yydefault -- do the default action for the current state.  |
	 `-----------------------------------------------------------*/
	yydefault: yyn = yydefact[yystate];
	if (yyn == 0) goto yyerrlab;
	goto yyreduce;

	/*-----------------------------.
	 | yyreduce -- Do a reduction.  |
	 `-----------------------------*/
	yyreduce:
	/* yyn is the number of a rule to reduce with.  */
	yylen = yyr2[yyn];

	/* If YYLEN is nonzero, implement the default value of the action:
	 `$$ = $1'.

	 Otherwise, the following line sets YYVAL to garbage.
	 This behavior is undocumented and Bison
	 users should not rely upon it.  Assigning to YYVAL
	 unconditionally makes the parser a bit smaller, and it avoids a
	 GCC warning that YYVAL may be used uninitialized.  */
	yyval = yyvsp[1 - yylen];

	YY_REDUCE_PRINT(yyn);
	switch (yyn) {
		case 2:

			/* Line 1806 of yacc.c  */
#line 228 "gram.y"
		{
			if (gProject->Parse_TOS->err_cnt == 0) *gProject->Parse_TOS->yyerrstream << "Warning: ANSI/ISO C forbids an empty source file.\n";
			gProject->Parse_TOS->transUnit = (TransUnit*) NULL;
			(yyval.transunit) = (TransUnit*) NULL;
		}
			break;

		case 3:

			/* Line 1806 of yacc.c  */
#line 236 "gram.y"
		{
			if (gProject->Parse_TOS->err_cnt) {
				*gProject->Parse_TOS->yyerrstream << gProject->Parse_TOS->err_cnt << " errors found.\n";
				gProject->Parse_TOS->transUnit = (TransUnit*) NULL;
			} else {
				gProject->Parse_TOS->transUnit = (yyval.transunit);
			}
		}
			break;

		case 4:

			/* Line 1806 of yacc.c  */
#line 247 "gram.y"
		{
			*gProject->Parse_TOS->yyerrstream << "Errors - Aborting parse.\n";
			gProject->Parse_TOS->transUnit = (TransUnit*) NULL;
			YYACCEPT;
		}
			break;

		case 5:

			/* Line 1806 of yacc.c  */
#line 255 "gram.y"
		{
			(yyval.transunit) = gProject->Parse_TOS->transUnit;
			(yyval.transunit)->add((yyvsp[(1) - (2)].stemnt));
		}
			break;

		case 6:

			/* Line 1806 of yacc.c  */
#line 260 "gram.y"
		{
			(yyval.transunit)->add((yyvsp[(2) - (3)].stemnt));
		}
			break;

		case 7:

			/* Line 1806 of yacc.c  */
#line 266 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->ReinitializeCtxt();
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ExitScopes(FILE_SCOPE);
			gProject->Parse_TOS->err_top_level = 0;
		}
			break;

		case 8:

			/* Line 1806 of yacc.c  */
#line 275 "gram.y"
		{
			(yyval.stemnt) = (yyvsp[(1) - (1)].declStemnt);
		}
			break;

		case 9:

			/* Line 1806 of yacc.c  */
#line 279 "gram.y"
		{
			(yyval.stemnt) = (yyvsp[(1) - (1)].functionDef);
		}
			break;

		case 10:

			/* Line 1806 of yacc.c  */
#line 283 "gram.y"
		{
			(yyval.stemnt) = (yyvsp[(1) - (1)].stemnt);
		}
			break;

		case 11:

			/* Line 1806 of yacc.c  */
#line 287 "gram.y"
		{
			(yyval.stemnt) = (Statement*) NULL;
		}
			break;

		case 12:

			/* Line 1806 of yacc.c  */
#line 291 "gram.y"
		{
			(yyval.stemnt) = (Statement*) NULL;
		}
			break;

		case 13:

			/* Line 1806 of yacc.c  */
#line 297 "gram.y"
		{
			if ((yyvsp[(2) - (2)].stemnt) != NULL) {
				(yyval.functionDef) = new FunctionDef((yyvsp[(2) - (2)].stemnt)->location);
				Block *blk = (Block*) (yyvsp[(2) - (2)].stemnt);

				(yyval.functionDef)->decl = (yyvsp[(1) - (2)].decl);

				if ((yyvsp[(1) - (2)].decl)->name && (yyvsp[(1) - (2)].decl)->name->entry) (yyvsp[(1) - (2)].decl)->name->entry->u2FunctionDef = (yyval.functionDef);

				// Steal internals of the compound statement
				(yyval.functionDef)->head = blk->head;
				(yyval.functionDef)->tail = blk->tail;

				blk->head = blk->tail = (Statement*) NULL;
				delete (yyvsp[(2) - (2)].stemnt);
			} else {
				delete (yyvsp[(1) - (2)].decl);
				(yyval.functionDef) = (FunctionDef*) NULL;
			}
		}
			break;

		case 14:

			/* Line 1806 of yacc.c  */
#line 325 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->ResetDeclCtxt();

			gProject->Parse_TOS->possibleType = true;
			(yyval.decl) = (yyvsp[(2) - (3)].decl);

			if ((yyval.decl)->form != NULL) {
				assert(gProject->Parse_TOS->err_top_level || (yyval.decl)->form->type == TT_Function);

				(yyval.decl)->extend((yyvsp[(1) - (3)].base));

				/* This is adding K&R-style declarations if $3 exists */
				if ((yyvsp[(3) - (3)].decl) != NULL) {
					FunctionType *fnc = (FunctionType*) ((yyval.decl)->form);
					fnc->KnR_decl = true;
					Decl *param = (yyvsp[(3) - (3)].decl);
					while (param != NULL) {
						Decl *next = param->next;
						delete param;
						param = next;
					}
				}
			}
		}
			break;

		case 15:

			/* Line 1806 of yacc.c  */
#line 354 "gram.y"
		{

			gProject->Parse_TOS->parseCtxt->ResetDeclCtxt();

			(yyval.decl) = (yyvsp[(2) - (3)].decl);

			if ((yyval.decl)->form != NULL) {
				assert(gProject->Parse_TOS->err_top_level || (yyval.decl)->form->type == TT_Function);
				(yyval.decl)->extend((yyvsp[(1) - (3)].base));

				/* This is adding K&R-style declarations if $3 exists */
				if ((yyvsp[(3) - (3)].decl) != NULL) {
					FunctionType *fnc = (FunctionType*) ((yyval.decl)->form);
					fnc->KnR_decl = true;
					Decl *param = (yyvsp[(3) - (3)].decl);
					while (param != NULL) {
						Decl *next = param->next;
						delete param;
						param = next;
					}
				}
			}
		}
			break;

		case 16:

			/* Line 1806 of yacc.c  */
#line 387 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ReEnterScope();
		}
			break;

		case 17:

			/* Line 1806 of yacc.c  */
#line 392 "gram.y"
		{
			Block* block = new Block(*(yyvsp[(1) - (5)].loc));
			(yyval.stemnt) = block;
			block->addDecls((yyvsp[(3) - (5)].decl));
			block->addStatements(ReverseList((yyvsp[(4) - (5)].stemnt)));
			if (gProject->Parse_TOS->transUnit) {
				yyCheckLabelsDefinition(gProject->Parse_TOS->transUnit->contxt.labels);
				gProject->Parse_TOS->transUnit->contxt.ExitScope();
				gProject->Parse_TOS->transUnit->contxt.ExitScope();
			}
		}
			break;

		case 18:

			/* Line 1806 of yacc.c  */
#line 405 "gram.y"
		{
			(yyval.stemnt) = (Statement*) NULL;
		}
			break;

		case 19:

			/* Line 1806 of yacc.c  */
#line 411 "gram.y"
		{
			(yyval.stemnt) = (Statement*) NULL;
		}
			break;

		case 22:

			/* Line 1806 of yacc.c  */
#line 419 "gram.y"
		{
			/* Hook them up backwards, we'll reverse them later. */
			if ((yyvsp[(2) - (2)].stemnt)) {
				(yyvsp[(2) - (2)].stemnt)->next = (yyvsp[(1) - (2)].stemnt);
				(yyval.stemnt) = (yyvsp[(2) - (2)].stemnt);
			}
		}
			break;

		case 23:

			/* Line 1806 of yacc.c  */
#line 428 "gram.y"
		{ /* preprocessor #line directive */
			/* Hook them up backwards, we'll reverse them later. */
			if ((yyvsp[(2) - (2)].stemnt)) {
				(yyvsp[(2) - (2)].stemnt)->next = (yyvsp[(1) - (2)].stemnt);
				(yyval.stemnt) = (yyvsp[(2) - (2)].stemnt);
			}
		}
			break;

		case 25:

			/* Line 1806 of yacc.c  */
#line 446 "gram.y"
		{
			Block* block = new Block(*(yyvsp[(1) - (4)].loc));
			(yyval.stemnt) = block;
			block->addDecls((yyvsp[(2) - (4)].decl));
			block->addStatements(ReverseList((yyvsp[(3) - (4)].stemnt)));

			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ExitScope();
		}
			break;

		case 26:

			/* Line 1806 of yacc.c  */
#line 456 "gram.y"
		{
			(yyval.stemnt) = (Statement*) NULL;
		}
			break;

		case 27:

			/* Line 1806 of yacc.c  */
#line 462 "gram.y"
		{
			(yyval.stemnt) = (Statement*) NULL;
		}
			break;

		case 30:

			/* Line 1806 of yacc.c  */
#line 470 "gram.y"
		{
			/* Hook them up backwards, we'll reverse them later. */
			if ((yyvsp[(2) - (2)].stemnt)) {
				(yyvsp[(2) - (2)].stemnt)->next = (yyvsp[(1) - (2)].stemnt);
				(yyval.stemnt) = (yyvsp[(2) - (2)].stemnt);
			}
		}
			break;

		case 31:

			/* Line 1806 of yacc.c  */
#line 479 "gram.y"
		{ /* preprocessor #line directive */
			/* Hook them up backwards, we'll reverse them later. */
			if ((yyvsp[(2) - (2)].stemnt)) {
				(yyvsp[(2) - (2)].stemnt)->next = (yyvsp[(1) - (2)].stemnt);
				(yyval.stemnt) = (yyvsp[(2) - (2)].stemnt);
			}
		}
			break;

		case 43:

			/* Line 1806 of yacc.c  */
#line 501 "gram.y"
		{
			delete (yyvsp[(2) - (2)].loc);
			(yyval.stemnt) = (Statement*) NULL;
		}
			break;

		case 44:

			/* Line 1806 of yacc.c  */
#line 508 "gram.y"
		{
			(yyval.stemnt) = new ExpressionStemnt((yyvsp[(1) - (2)].value), *(yyvsp[(2) - (2)].loc));
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 45:

			/* Line 1806 of yacc.c  */
#line 515 "gram.y"
		{
			(yyval.stemnt) = (yyvsp[(3) - (3)].stemnt);
			if ((yyval.stemnt) == NULL) {
				/* Sorry, we must have a statement here. */
				if (yyerr("Can't have a label at the end of a block! "))
				YYERROR;

				(yyval.stemnt) = new Statement(ST_NullStemnt, *(yyvsp[(2) - (3)].loc));
			}
			(yyval.stemnt)->addHeadLabel((yyvsp[(1) - (3)].label));
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 51:

			/* Line 1806 of yacc.c  */
#line 540 "gram.y"
		{
			(yyval.stemnt) = new SwitchStemnt((yyvsp[(3) - (5)].value), (yyvsp[(5) - (5)].stemnt), *(yyvsp[(1) - (5)].loc));
			delete (yyvsp[(1) - (5)].loc);
			delete (yyvsp[(2) - (5)].loc);
			delete (yyvsp[(4) - (5)].loc);
		}
			break;

		case 52:

			/* Line 1806 of yacc.c  */
#line 549 "gram.y"
		{
			(yyval.stemnt) = new Statement(ST_BreakStemnt, *(yyvsp[(1) - (2)].loc));
			delete (yyvsp[(1) - (2)].loc);
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 53:

			/* Line 1806 of yacc.c  */
#line 557 "gram.y"
		{
			(yyval.stemnt) = new Statement(ST_ContinueStemnt, *(yyvsp[(1) - (2)].loc));
			delete (yyvsp[(1) - (2)].loc);
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 54:

			/* Line 1806 of yacc.c  */
#line 565 "gram.y"
		{
			(yyval.stemnt) = new ReturnStemnt((yyvsp[(2) - (3)].value), *(yyvsp[(1) - (3)].loc));
			delete (yyvsp[(1) - (3)].loc);
			delete (yyvsp[(3) - (3)].loc);
		}
			break;

		case 55:

			/* Line 1806 of yacc.c  */
#line 573 "gram.y"
		{
			(yyval.stemnt) = new GotoStemnt((yyvsp[(2) - (3)].symbol), *(yyvsp[(1) - (3)].loc));
			delete (yyvsp[(1) - (3)].loc);
			delete (yyvsp[(3) - (3)].loc);
		}
			break;

		case 56:

			/* Line 1806 of yacc.c  */
#line 581 "gram.y"
		{
			(yyval.stemnt) = new Statement(ST_NullStemnt, *(yyvsp[(1) - (1)].loc));
			delete (yyvsp[(1) - (1)].loc);
		}
			break;

		case 57:

			/* Line 1806 of yacc.c  */
#line 588 "gram.y"
		{
			(yyval.stemnt) = new IfStemnt((yyvsp[(3) - (5)].value), (yyvsp[(5) - (5)].stemnt), *(yyvsp[(1) - (5)].loc));
			delete (yyvsp[(1) - (5)].loc);
			delete (yyvsp[(2) - (5)].loc);
			delete (yyvsp[(4) - (5)].loc);
		}
			break;

		case 58:

			/* Line 1806 of yacc.c  */
#line 597 "gram.y"
		{
			(yyval.stemnt) = new IfStemnt((yyvsp[(3) - (7)].value), (yyvsp[(5) - (7)].stemnt), *(yyvsp[(1) - (7)].loc), (yyvsp[(7) - (7)].stemnt));
			delete (yyvsp[(1) - (7)].loc);
			delete (yyvsp[(2) - (7)].loc);
			delete (yyvsp[(4) - (7)].loc);
			delete (yyvsp[(6) - (7)].loc);
		}
			break;

		case 59:

			/* Line 1806 of yacc.c  */
#line 607 "gram.y"
		{
			(yyval.stemnt) = new DoWhileStemnt((yyvsp[(5) - (7)].value), (yyvsp[(2) - (7)].stemnt), *(yyvsp[(1) - (7)].loc));
			delete (yyvsp[(1) - (7)].loc);
			delete (yyvsp[(3) - (7)].loc);
			delete (yyvsp[(4) - (7)].loc);
			delete (yyvsp[(6) - (7)].loc);
			delete (yyvsp[(7) - (7)].loc);
		}
			break;

		case 60:

			/* Line 1806 of yacc.c  */
#line 618 "gram.y"
		{
			(yyval.stemnt) = new WhileStemnt((yyvsp[(3) - (5)].value), (yyvsp[(5) - (5)].stemnt), *(yyvsp[(1) - (5)].loc));
			delete (yyvsp[(1) - (5)].loc);
			delete (yyvsp[(2) - (5)].loc);
			delete (yyvsp[(4) - (5)].loc);
		}
			break;

		case 61:

			/* Line 1806 of yacc.c  */
#line 628 "gram.y"
		{
			(yyval.stemnt) = new ForStemnt((yyvsp[(3) - (9)].value), (yyvsp[(5) - (9)].value), (yyvsp[(7) - (9)].value), *(yyvsp[(1) - (9)].loc), (yyvsp[(9) - (9)].stemnt));
			delete (yyvsp[(1) - (9)].loc);
			delete (yyvsp[(2) - (9)].loc);
			delete (yyvsp[(4) - (9)].loc);
			delete (yyvsp[(6) - (9)].loc);
			delete (yyvsp[(8) - (9)].loc);
		}
			break;

		case 65:

			/* Line 1806 of yacc.c  */
#line 644 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) (yyval.label) = gProject->Parse_TOS->parseCtxt->Mk_named_label((yyvsp[(1) - (1)].symbol), gProject->Parse_TOS->transUnit->contxt.labels);
		}
			break;

		case 66:

			/* Line 1806 of yacc.c  */
#line 652 "gram.y"
		{
			(yyval.label) = new Label((yyvsp[(2) - (2)].value));
			delete (yyvsp[(1) - (2)].loc);
		}
			break;

		case 67:

			/* Line 1806 of yacc.c  */
#line 657 "gram.y"
		{
			(yyval.label) = new Label((yyvsp[(2) - (4)].value), (yyvsp[(4) - (4)].value));
			delete (yyvsp[(1) - (4)].loc);
			delete (yyvsp[(3) - (4)].loc);
		}
			break;

		case 68:

			/* Line 1806 of yacc.c  */
#line 665 "gram.y"
		{
			(yyval.label) = new Label(LT_Default);
			delete (yyvsp[(1) - (1)].loc);
		}
			break;

		case 70:

			/* Line 1806 of yacc.c  */
#line 682 "gram.y"
		{
			(yyval.value) = new TrinaryExpr((yyvsp[(1) - (5)].value), (yyvsp[(3) - (5)].value), (yyvsp[(5) - (5)].value), *(yyvsp[(2) - (5)].loc));
			delete (yyvsp[(2) - (5)].loc);
			delete (yyvsp[(4) - (5)].loc);
		}
			break;

		case 72:

			/* Line 1806 of yacc.c  */
#line 691 "gram.y"
		{
			(yyval.value) = new AssignExpr((yyvsp[(2) - (3)].assignOp), (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), (yyvsp[(1) - (3)].value)->location);
		}
			break;

		case 73:

			/* Line 1806 of yacc.c  */
#line 697 "gram.y"
		{
			(yyval.value) = (Expression*) NULL;
		}
			break;

		case 76:

			/* Line 1806 of yacc.c  */
#line 707 "gram.y"
		{
			(yyval.value) = (Expression*) NULL;
		}
			break;

		case 80:

			/* Line 1806 of yacc.c  */
#line 718 "gram.y"
		{
			(yyval.value) = new BinaryExpr(BO_Or, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), *(yyvsp[(2) - (3)].loc));
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 82:

			/* Line 1806 of yacc.c  */
#line 726 "gram.y"
		{
			(yyval.value) = new BinaryExpr(BO_And, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), *(yyvsp[(2) - (3)].loc));
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 83:

			/* Line 1806 of yacc.c  */
#line 733 "gram.y"
		{
			(yyval.value) = new UnaryExpr(UO_Not, (yyvsp[(2) - (2)].value), *(yyvsp[(1) - (2)].loc));
			delete (yyvsp[(1) - (2)].loc);
		}
			break;

		case 85:

			/* Line 1806 of yacc.c  */
#line 741 "gram.y"
		{
			(yyval.value) = new BinaryExpr(BO_BitOr, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), *(yyvsp[(2) - (3)].loc));
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 87:

			/* Line 1806 of yacc.c  */
#line 749 "gram.y"
		{
			(yyval.value) = new BinaryExpr(BO_BitXor, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), *(yyvsp[(2) - (3)].loc));
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 89:

			/* Line 1806 of yacc.c  */
#line 757 "gram.y"
		{
			(yyval.value) = new BinaryExpr(BO_BitAnd, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), *(yyvsp[(2) - (3)].loc));
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 90:

			/* Line 1806 of yacc.c  */
#line 764 "gram.y"
		{
			(yyval.value) = new UnaryExpr(UO_BitNot, (yyvsp[(2) - (2)].value), *(yyvsp[(1) - (2)].loc));
			delete (yyvsp[(1) - (2)].loc);
		}
			break;

		case 92:

			/* Line 1806 of yacc.c  */
#line 772 "gram.y"
		{
			(yyval.value) = new CastExpr((yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].value), *(yyvsp[(1) - (4)].loc));
			delete (yyvsp[(1) - (4)].loc);
			delete (yyvsp[(3) - (4)].loc);
		}
			break;

		case 94:

			/* Line 1806 of yacc.c  */
#line 781 "gram.y"
		{
			(yyval.value) = new RelExpr((yyvsp[(2) - (3)].relOp), (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), (yyvsp[(1) - (3)].value)->location);
		}
			break;

		case 96:

			/* Line 1806 of yacc.c  */
#line 788 "gram.y"
		{
			(yyval.value) = new RelExpr((yyvsp[(2) - (3)].relOp), (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), (yyvsp[(1) - (3)].value)->location);
		}
			break;

		case 98:

			/* Line 1806 of yacc.c  */
#line 795 "gram.y"
		{
			(yyval.value) = new BinaryExpr((yyvsp[(2) - (3)].binOp), (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), (yyvsp[(1) - (3)].value)->location);
		}
			break;

		case 100:

			/* Line 1806 of yacc.c  */
#line 802 "gram.y"
		{
			(yyval.value) = new BinaryExpr((yyvsp[(2) - (3)].binOp), (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), (yyvsp[(1) - (3)].value)->location);
		}
			break;

		case 102:

			/* Line 1806 of yacc.c  */
#line 809 "gram.y"
		{
			(yyval.value) = new BinaryExpr((yyvsp[(2) - (3)].binOp), (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), (yyvsp[(1) - (3)].value)->location);
		}
			break;

		case 113:

			/* Line 1806 of yacc.c  */
#line 827 "gram.y"
		{
			(yyval.value) = new SizeofExpr((yyvsp[(3) - (4)].type), *(yyvsp[(1) - (4)].loc));
			delete (yyvsp[(1) - (4)].loc);
			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 114:

			/* Line 1806 of yacc.c  */
#line 834 "gram.y"
		{
			(yyval.value) = new SizeofExpr((yyvsp[(2) - (2)].value), *(yyvsp[(1) - (2)].loc));
			delete (yyvsp[(1) - (2)].loc);
		}
			break;

		case 115:

			/* Line 1806 of yacc.c  */
#line 841 "gram.y"
		{
			(yyval.value) = new UnaryExpr(UO_Minus, (yyvsp[(2) - (2)].value), HERE);
		}
			break;

		case 116:

			/* Line 1806 of yacc.c  */
#line 847 "gram.y"
		{
			/* Unary plus is an ISO addition (for symmetry) - ignore it */
			(yyval.value) = (yyvsp[(2) - (2)].value);
		}
			break;

		case 117:

			/* Line 1806 of yacc.c  */
#line 854 "gram.y"
		{
			(yyval.value) = new UnaryExpr(UO_AddrOf, (yyvsp[(2) - (2)].value), *(yyvsp[(1) - (2)].loc));
			delete (yyvsp[(1) - (2)].loc);
		}
			break;

		case 118:

			/* Line 1806 of yacc.c  */
#line 861 "gram.y"
		{
			(yyval.value) = new UnaryExpr(UO_Deref, (yyvsp[(2) - (2)].value), HERE);
		}
			break;

		case 119:

			/* Line 1806 of yacc.c  */
#line 867 "gram.y"
		{
			(yyval.value) = new UnaryExpr(UO_PreInc, (yyvsp[(2) - (2)].value), *(yyvsp[(1) - (2)].loc));
			delete (yyvsp[(1) - (2)].loc);
		}
			break;

		case 120:

			/* Line 1806 of yacc.c  */
#line 874 "gram.y"
		{
			(yyval.value) = new UnaryExpr(UO_PreDec, (yyvsp[(2) - (2)].value), *(yyvsp[(1) - (2)].loc));
			delete (yyvsp[(1) - (2)].loc);
		}
			break;

		case 122:

			/* Line 1806 of yacc.c  */
#line 882 "gram.y"
		{
			(yyval.value) = new BinaryExpr(BO_Comma, (yyvsp[(1) - (3)].value), (yyvsp[(3) - (3)].value), *(yyvsp[(2) - (3)].loc));
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 123:

			/* Line 1806 of yacc.c  */
#line 889 "gram.y"
		{
			//TODO look it after
			//if ((yyvsp[(1) - (1)].symbol)->entry == NULL && gProject->warn_variable) {
			//	yywarn("Undeclared variable");
			//}

			(yyval.value) = new Variable((yyvsp[(1) - (1)].symbol), HERE);
		}
			break;

		case 125:

			/* Line 1806 of yacc.c  */
#line 899 "gram.y"
		{
			(yyval.value) = (yyvsp[(1) - (1)].consValue);
		}
			break;

		case 126:

			/* Line 1806 of yacc.c  */
#line 905 "gram.y"
		{
			(yyval.value) = (yyvsp[(2) - (3)].value);
			delete (yyvsp[(1) - (3)].loc);
			delete (yyvsp[(3) - (3)].loc);
		}
			break;

		case 127:

			/* Line 1806 of yacc.c  */
#line 911 "gram.y"
		{
			(yyval.value) = (Expression*) NULL;
			delete (yyvsp[(1) - (3)].loc);
			delete (yyvsp[(3) - (3)].loc);
		}
			break;

		case 134:

			/* Line 1806 of yacc.c  */
#line 927 "gram.y"
		{
			(yyval.value) = new IndexExpr((yyvsp[(1) - (4)].value), (yyvsp[(3) - (4)].value), *(yyvsp[(2) - (4)].loc));
			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 137:

			/* Line 1806 of yacc.c  */
#line 939 "gram.y"
		{
			(yyval.value) = new UnaryExpr(UO_PostInc, (yyvsp[(1) - (2)].value), *(yyvsp[(2) - (2)].loc));
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 138:

			/* Line 1806 of yacc.c  */
#line 946 "gram.y"
		{
			(yyval.value) = new UnaryExpr(UO_PostDec, (yyvsp[(1) - (2)].value), *(yyvsp[(2) - (2)].loc));
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 140:

			/* Line 1806 of yacc.c  */
#line 956 "gram.y"
		{
			Variable *var = new Variable((yyvsp[(3) - (3)].symbol), *(yyvsp[(2) - (3)].loc));
			BinaryExpr *be = new BinaryExpr(BO_Member, (yyvsp[(1) - (3)].value), var, *(yyvsp[(2) - (3)].loc));
			delete (yyvsp[(2) - (3)].loc);
			(yyval.value) = be;

			// Lookup the component in its struct
			// if possible.
			if ((yyvsp[(1) - (3)].value)->etype == ET_Variable) {
				Variable *var = (Variable*) (yyvsp[(1) - (3)].value);
				Symbol *varName = var->name;
				SymEntry *entry = varName->entry;

				if (entry && entry->uVarDecl) {
					entry->uVarDecl->lookup((yyvsp[(3) - (3)].symbol), gProject->Parse_TOS->transUnit->contxt);
				}
			}
		}
			break;

		case 141:

			/* Line 1806 of yacc.c  */
#line 979 "gram.y"
		{
			Variable *var = new Variable((yyvsp[(3) - (3)].symbol), *(yyvsp[(2) - (3)].loc));
			BinaryExpr *be = new BinaryExpr(BO_PtrMember, (yyvsp[(1) - (3)].value), var, *(yyvsp[(2) - (3)].loc));
			delete (yyvsp[(2) - (3)].loc);
			(yyval.value) = be;

			// Lookup the component in its struct
			// if possible.
			if ((yyvsp[(1) - (3)].value)->etype == ET_Variable) {
				Variable *var = (Variable*) (yyvsp[(1) - (3)].value);
				Symbol *varName = var->name;
				SymEntry *entry = varName->entry;

				if (entry && entry->uVarDecl) {
					entry->uVarDecl->lookup((yyvsp[(3) - (3)].symbol), gProject->Parse_TOS->transUnit->contxt);
				}
			}
		}
			break;

		case 142:

			/* Line 1806 of yacc.c  */
#line 1002 "gram.y"
		{
			FunctionCall* fc = new FunctionCall((yyvsp[(1) - (4)].value), *(yyvsp[(2) - (4)].loc));

			/* add function args */
			fc->addArgs(ReverseList((yyvsp[(3) - (4)].value)));

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
			(yyval.value) = fc;
		}
			break;

		case 143:

			/* Line 1806 of yacc.c  */
#line 1015 "gram.y"
		{
			(yyval.value) = (Expression*) NULL;
		}
			break;

		case 146:

			/* Line 1806 of yacc.c  */
#line 1023 "gram.y"
		{
			(yyval.value) = (yyvsp[(3) - (3)].value);
			(yyval.value)->next = (yyvsp[(1) - (3)].value);

			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 164:

			/* Line 1806 of yacc.c  */
#line 1068 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ReEnterScope();
		}
			break;

		case 165:

			/* Line 1806 of yacc.c  */
#line 1073 "gram.y"
		{
			(yyval.decl) = (Decl*) NULL;
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ExitScope();
		}
			break;

		case 166:

			/* Line 1806 of yacc.c  */
#line 1079 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ReEnterScope();
			gProject->Parse_TOS->parseCtxt->ResetDeclCtxt();
		}
			break;

		case 167:

			/* Line 1806 of yacc.c  */
#line 1084 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->SetVarParam(1, !gProject->Parse_TOS->err_top_level, 0);
			gProject->Parse_TOS->parseCtxt->SetIsKnR(true);
		}
			break;

		case 168:

			/* Line 1806 of yacc.c  */
#line 1088 "gram.y"
		{
			(yyval.decl) = (yyvsp[(3) - (3)].decl);
			gProject->Parse_TOS->parseCtxt->SetIsKnR(false);
			gProject->Parse_TOS->parseCtxt->SetVarParam(0, !gProject->Parse_TOS->err_top_level, 1);

			// Exit, but will allow re-enter for a function.
			// Hack, to handle parameters being in the function's scope.
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ExitScope(true);
		}
			break;

		case 169:

			/* Line 1806 of yacc.c  */
#line 1100 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.EnterScope();
			gProject->Parse_TOS->parseCtxt->ResetDeclCtxt();
		}
			break;

		case 170:

			/* Line 1806 of yacc.c  */
#line 1106 "gram.y"
		{
			(yyval.decl) = (Decl*) NULL;
		}
			break;

		case 171:

			/* Line 1806 of yacc.c  */
#line 1110 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.EnterScope();
			gProject->Parse_TOS->parseCtxt->ResetDeclCtxt();
		}
			break;

		case 172:

			/* Line 1806 of yacc.c  */
#line 1115 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->SetVarParam(0, !gProject->Parse_TOS->err_top_level, 0);
		}
			break;

		case 173:

			/* Line 1806 of yacc.c  */
#line 1118 "gram.y"
		{
			(yyval.decl) = (yyvsp[(3) - (3)].decl);
			gProject->Parse_TOS->parseCtxt->SetVarParam(0, !gProject->Parse_TOS->err_top_level, 0);
		}
			break;

		case 174:

			/* Line 1806 of yacc.c  */
#line 1124 "gram.y"
		{
			(yyval.decl) = (yyvsp[(1) - (2)].decl);
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 175:

			/* Line 1806 of yacc.c  */
#line 1129 "gram.y"
		{
			(yyval.decl) = (yyvsp[(1) - (3)].decl);

			Decl* appendDecl = (yyvsp[(1) - (3)].decl);
			while (appendDecl->next != NULL)
				appendDecl = appendDecl->next;

			appendDecl->next = (yyvsp[(3) - (3)].decl);
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 176:

			/* Line 1806 of yacc.c  */
#line 1142 "gram.y"
		{
			(yyval.declStemnt) = new DeclStemnt(*(yyvsp[(2) - (2)].loc));
			(yyval.declStemnt)->addDecls(ReverseList((yyvsp[(1) - (2)].decl)));
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 177:

			/* Line 1806 of yacc.c  */
#line 1149 "gram.y"
		{
			(yyval.declStemnt) = new DeclStemnt(*(yyvsp[(2) - (2)].loc));
			(yyval.declStemnt)->addDecls(ReverseList((yyvsp[(1) - (2)].decl)));
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 178:

			/* Line 1806 of yacc.c  */
#line 1157 "gram.y"
		{
			assert(gProject->Parse_TOS->err_top_level || (yyvsp[(1) - (2)].base) == gProject->Parse_TOS->parseCtxt->curCtxt->decl_specs);
			gProject->Parse_TOS->parseCtxt->ResetDeclCtxt();

			yywarn("old-style declaration or incorrect type");

			gProject->Parse_TOS->possibleType = true;
			(yyval.decl) = (yyvsp[(2) - (2)].decl);

			if ((yyval.decl) == NULL) {
				(yyval.decl) = new Decl((yyvsp[(1) - (2)].base));
			}
		}
			break;

		case 179:

			/* Line 1806 of yacc.c  */
#line 1175 "gram.y"
		{
			assert(gProject->Parse_TOS->err_top_level || (yyvsp[(1) - (2)].base) == gProject->Parse_TOS->parseCtxt->curCtxt->decl_specs);
			gProject->Parse_TOS->parseCtxt->ResetDeclCtxt();

			gProject->Parse_TOS->possibleType = true;
			(yyval.decl) = (yyvsp[(2) - (2)].decl);

			if ((yyval.decl) == NULL) {
				(yyval.decl) = new Decl((yyvsp[(1) - (2)].base));
			}
		}
			break;

		case 180:

			/* Line 1806 of yacc.c  */
#line 1195 "gram.y"
		{
			(yyval.base) = new BaseType(BT_Int);
			gProject->Parse_TOS->parseCtxt->SetDeclCtxt((yyval.base));
		}
			break;

		case 183:

			/* Line 1806 of yacc.c  */
#line 1214 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->PushCtxt();
			gProject->Parse_TOS->parseCtxt->ResetVarParam();
		}
			break;

		case 184:

			/* Line 1806 of yacc.c  */
#line 1219 "gram.y"
		{
			(yyval.type) = (yyvsp[(2) - (2)].type);
			gProject->Parse_TOS->parseCtxt->PopCtxt(false);
		}
			break;

		case 185:

			/* Line 1806 of yacc.c  */
#line 1226 "gram.y"
		{
			assert((yyvsp[(1) - (1)].base) == gProject->Parse_TOS->parseCtxt->curCtxt->decl_specs);

			gProject->Parse_TOS->possibleType = true;
			(yyval.type) = (yyvsp[(1) - (1)].base);
			if ((yyval.type)->isFunction()) if (yyerr("Function type not allowed as type name"))
			YYERROR;
		}
			break;

		case 186:

			/* Line 1806 of yacc.c  */
#line 1236 "gram.y"
		{
			assert((yyvsp[(1) - (2)].base) == gProject->Parse_TOS->parseCtxt->curCtxt->decl_specs);

			gProject->Parse_TOS->possibleType = true;
			(yyval.type) = (yyvsp[(2) - (2)].type);

			Type * extended = (yyval.type)->extend((yyvsp[(1) - (2)].base));
			if ((yyval.type)->isFunction()) {
				if (yyerr("Function type not allowed as type name"))
				YYERROR;
			} else if (extended && (yyvsp[(1) - (2)].base) && (yyvsp[(1) - (2)].base)->isFunction() && !extended->isPointer()) {
				if (yyerr("Wrong type combination"))
				YYERROR;
			}
		}
			break;

		case 187:

			/* Line 1806 of yacc.c  */
#line 1264 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->SetDeclCtxt((yyval.base));
		}
			break;

		case 194:

			/* Line 1806 of yacc.c  */
#line 1280 "gram.y"
		{
			if (!gProject->Parse_TOS->transUnit || gProject->Parse_TOS->transUnit->contxt.syms->current->level >= FUNCTION_SCOPE) (yyval.storage) = (yyvsp[(1) - (1)].storage);
			else (yyval.storage) = ST_None;
		}
			break;

		case 196:

			/* Line 1806 of yacc.c  */
#line 1293 "gram.y"
		{
			(yyval.base) = (BaseType*) NULL;
		}
			break;

		case 198:

			/* Line 1806 of yacc.c  */
#line 1300 "gram.y"
		{
			(yyval.base) = (yyvsp[(2) - (2)].base);

			if (!(yyval.base)) {
				(yyval.base) = new BaseType();
			}

			if ((yyvsp[(1) - (2)].storage) == ST_None) {
				if (yyerr("Invalid use of local storage type"))
				YYERROR;
			} else if ((yyval.base)->storage != ST_None) yywarn("Overloading previous storage type specification");
			else (yyval.base)->storage = (yyvsp[(1) - (2)].storage);
		}
			break;

		case 199:

			/* Line 1806 of yacc.c  */
#line 1318 "gram.y"
		{
			gProject->Parse_TOS->possibleType = false;
		}
			break;

		case 200:

			/* Line 1806 of yacc.c  */
#line 1319 "gram.y"
		{
			(yyval.base) = (yyvsp[(1) - (3)].base);

			if ((yyvsp[(3) - (3)].base)) {
				if (((yyvsp[(3) - (3)].base)->typemask & BT_Long) && ((yyval.base)->typemask & BT_Long)) {
					// long long : A likely C9X addition
					(yyval.base)->typemask &= ~BT_Long;
					(yyvsp[(3) - (3)].base)->typemask &= ~BT_Long;
					(yyval.base)->typemask |= (yyvsp[(3) - (3)].base)->typemask;
					(yyval.base)->typemask |= BT_LongLong;
				} else (yyval.base)->typemask |= (yyvsp[(3) - (3)].base)->typemask;

				if ((yyvsp[(3) - (3)].base)->storage != ST_None) (yyval.base)->storage = (yyvsp[(3) - (3)].base)->storage;

				// delete $3;
			}

			/*
			 std::cout << "In decl_spec: ";
			 $$->printBase(std::cout,0);
			 if ($$->storage == ST_Typedef)
			 std::cout << "(is a typedef)";
			 std::cout << std::endl;
			 */
		}
			break;

		case 201:

			/* Line 1806 of yacc.c  */
#line 1351 "gram.y"
		{
			(yyval.base) = (yyvsp[(2) - (2)].base);

			if (!(yyval.base)) {
				(yyval.base) = new BaseType();
			}

			if (((yyval.base)->qualifier & (yyvsp[(1) - (2)].typeQual)) != TQ_None) yywarn("qualifier already specified");

			(yyval.base)->qualifier |= (yyvsp[(1) - (2)].typeQual);

		}
			break;

		case 202:

			/* Line 1806 of yacc.c  */
#line 1371 "gram.y"
		{
			(yyval.base) = (BaseType*) NULL;
		}
			break;

		case 204:

			/* Line 1806 of yacc.c  */
#line 1377 "gram.y"
		{
			gProject->Parse_TOS->possibleType = false;
		}
			break;

		case 205:

			/* Line 1806 of yacc.c  */
#line 1378 "gram.y"
		{
			(yyval.base) = (yyvsp[(1) - (3)].base);

			if ((yyvsp[(3) - (3)].base)) {
				(yyval.base)->typemask |= (yyvsp[(3) - (3)].base)->typemask;
				// delete $3;
			}
		}
			break;

		case 206:

			/* Line 1806 of yacc.c  */
#line 1388 "gram.y"
		{
			(yyval.base) = (yyvsp[(2) - (2)].base);

			if (!(yyval.base)) {
				(yyval.base) = new BaseType();
			}

			if (((yyval.base)->qualifier & (yyvsp[(1) - (2)].typeQual)) != TQ_None) yywarn("qualifier already specified");
			(yyval.base)->qualifier |= (yyvsp[(1) - (2)].typeQual);
		}
			break;

		case 207:

			/* Line 1806 of yacc.c  */
#line 1403 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->SetDeclCtxt((yyval.base));
		}
			break;

		case 208:

			/* Line 1806 of yacc.c  */
#line 1412 "gram.y"
		{
			(yyvsp[(1) - (1)].decl)->extend(gProject->Parse_TOS->parseCtxt->UseDeclCtxt());
		}
			break;

		case 209:

			/* Line 1806 of yacc.c  */
#line 1416 "gram.y"
		{
			(yyvsp[(1) - (3)].decl)->attrib = (yyvsp[(3) - (3)].gccAttrib);
			(yyval.decl) = (yyvsp[(1) - (3)].decl);
		}
			break;

		case 211:

			/* Line 1806 of yacc.c  */
#line 1424 "gram.y"
		{
			(yyvsp[(1) - (3)].decl)->initializer = (yyvsp[(3) - (3)].value);
			(yyval.decl) = (yyvsp[(1) - (3)].decl);
		}
			break;

		case 212:

			/* Line 1806 of yacc.c  */
#line 1431 "gram.y"
		{
			(yyval.decl) = (Decl*) NULL;
		}
			break;

		case 215:

			/* Line 1806 of yacc.c  */
#line 1441 "gram.y"
		{
			(yyval.decl) = (yyvsp[(1) - (1)].decl);
		}
			break;

		case 216:

			/* Line 1806 of yacc.c  */
#line 1445 "gram.y"
		{
			(yyval.decl) = (yyvsp[(1) - (3)].decl);

			Decl* appendDecl = (yyvsp[(1) - (3)].decl);
			while (appendDecl->next != NULL)
				appendDecl = appendDecl->next;

			appendDecl->next = (yyvsp[(3) - (3)].decl);
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 218:

			/* Line 1806 of yacc.c  */
#line 1463 "gram.y"
		{
			(yyval.arrayConst) = new ArrayConstant(NoLocation);
			(yyval.arrayConst)->addElement((yyvsp[(1) - (1)].value));
		}
			break;

		case 219:

			/* Line 1806 of yacc.c  */
#line 1468 "gram.y"
		{
			(yyval.arrayConst) = (yyvsp[(1) - (3)].arrayConst);
			(yyval.arrayConst)->addElement((yyvsp[(3) - (3)].value));
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 221:

			/* Line 1806 of yacc.c  */
#line 1477 "gram.y"
		{
			(yyval.value) = (yyvsp[(2) - (4)].arrayConst);
			delete (yyvsp[(1) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 222:

			/* Line 1806 of yacc.c  */
#line 1485 "gram.y"
		{
			(yyval.loc) = (Location*) NULL;
		}
			break;

		case 223:

			/* Line 1806 of yacc.c  */
#line 1489 "gram.y"
		{
			delete (yyvsp[(1) - (1)].loc);
			(yyval.loc) = (Location*) NULL;
		}
			break;

		case 228:

			/* Line 1806 of yacc.c  */
#line 1509 "gram.y"
		{
			(yyval.typeQual) = (yyvsp[(1) - (2)].typeQual) | (yyvsp[(2) - (2)].typeQual);
			if (((yyvsp[(2) - (2)].typeQual) & (yyvsp[(1) - (2)].typeQual)) != TQ_None) yywarn("qualifier already specified");
		}
			break;

		case 229:

			/* Line 1806 of yacc.c  */
#line 1517 "gram.y"
		{
			(yyval.typeQual) = TQ_None;
		}
			break;

		case 252:

			/* Line 1806 of yacc.c  */
#line 1551 "gram.y"
		{
			(yyval.base) = new BaseType(BT_UserType);
			(yyval.base)->typeName = (yyvsp[(1) - (1)].symbol);
		}
			break;

		case 253:

			/* Line 1806 of yacc.c  */
#line 1558 "gram.y"
		{
			assert ((! (yyval.symbol)->entry) ||
					(yyval.symbol)->entry->IsTagDecl());
		}
			break;

		case 254:

			/* Line 1806 of yacc.c  */
#line 1566 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) (yyval.base) = gProject->Parse_TOS->parseCtxt->Mk_tag_ref((yyvsp[(1) - (2)].typeSpec), (yyvsp[(2) - (2)].symbol), gProject->Parse_TOS->transUnit->contxt.tags);
			else (yyval.base) = NULL;
		}
			break;

		case 255:

			/* Line 1806 of yacc.c  */
#line 1576 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) (yyval.base) = gProject->Parse_TOS->parseCtxt->Mk_tag_ref((yyvsp[(1) - (2)].typeSpec), (yyvsp[(2) - (2)].symbol), gProject->Parse_TOS->transUnit->contxt.tags);
			else (yyval.base) = NULL;
		}
			break;

		case 256:

			/* Line 1806 of yacc.c  */
#line 1586 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) (yyval.base) = gProject->Parse_TOS->parseCtxt->Mk_tag_ref((yyvsp[(1) - (2)].typeSpec), (yyvsp[(2) - (2)].symbol), gProject->Parse_TOS->transUnit->contxt.tags);
			else (yyval.base) = NULL;
		}
			break;

		case 257:

			/* Line 1806 of yacc.c  */
#line 1596 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) (yyval.base) = gProject->Parse_TOS->parseCtxt->Mk_tag_def((yyvsp[(1) - (2)].typeSpec), (yyvsp[(2) - (2)].symbol), gProject->Parse_TOS->transUnit->contxt.tags);
			else (yyval.base) = NULL;
		}
			break;

		case 258:

			/* Line 1806 of yacc.c  */
#line 1606 "gram.y"
		{
			(yyval.base) = new BaseType((yyvsp[(3) - (4)].strDef));
			(yyvsp[(3) - (4)].strDef)->_isUnion = false;
			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 259:

			/* Line 1806 of yacc.c  */
#line 1613 "gram.y"
		{
			(yyval.base) = (yyvsp[(1) - (4)].base);
			assert(! (yyval.base)->stDefn);
			(yyval.base)->stDefn = (yyvsp[(3) - (4)].strDef);
			(yyvsp[(3) - (4)].strDef)->tag = (yyvsp[(1) - (4)].base)->tag->dup();
			(yyvsp[(3) - (4)].strDef)->_isUnion = false;

			// Overload the incomplete definition
			(yyval.base)->tag->entry->uStructDef = (yyval.base);

//             std::cout << "struct/union/enum_type_define:"
//                          "The definition of:"
//                       << "(uStructDef:" << $1->tag->entry->uStructDef << ")"
//                       << "(uStructDef->stDefn:" << $1->tag->entry->uStructDef->stDefn << ")"
//                       << "(" << $1->tag->entry << ")" << $1->tag->name  << "$" ;
//             $1->tag->entry->scope->ShowScopeId(std::cout);
//             std::cout << " has been completed" << endl; 

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 260:

			/* Line 1806 of yacc.c  */
#line 1637 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) (yyval.base) = gProject->Parse_TOS->parseCtxt->Mk_tag_def((yyvsp[(1) - (2)].typeSpec), (yyvsp[(2) - (2)].symbol), gProject->Parse_TOS->transUnit->contxt.tags);
			else (yyval.base) = NULL;
		}
			break;

		case 261:

			/* Line 1806 of yacc.c  */
#line 1647 "gram.y"
		{
			(yyval.base) = new BaseType((yyvsp[(3) - (4)].strDef));
			(yyvsp[(3) - (4)].strDef)->_isUnion = true;

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 262:

			/* Line 1806 of yacc.c  */
#line 1655 "gram.y"
		{
			(yyval.base) = (yyvsp[(1) - (4)].base);
			assert(! (yyval.base)->stDefn);
			(yyval.base)->stDefn = (yyvsp[(3) - (4)].strDef);
			(yyvsp[(3) - (4)].strDef)->tag = (yyvsp[(1) - (4)].base)->tag->dup();
			(yyvsp[(3) - (4)].strDef)->_isUnion = true;

			// Overload the incomplete definition
			(yyval.base)->tag->entry->uStructDef = (yyval.base);

//             std::cout << "struct/union/enum_type_define:"
//                          "The definition of:"
//                       << "(uStructDef:" << $1->tag->entry->uStructDef << ")"
//                       << "(uStructDef->stDefn:" << $1->tag->entry->uStructDef->stDefn << ")"
//                       << "(" << $1->tag->entry << ")" << $1->tag->name  << "$" ;
//             $1->tag->entry->scope->ShowScopeId(std::cout);
//             std::cout << " has been completed" << endl; 

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);

		}
			break;

		case 263:

			/* Line 1806 of yacc.c  */
#line 1680 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) (yyval.base) = gProject->Parse_TOS->parseCtxt->Mk_tag_def((yyvsp[(1) - (2)].typeSpec), (yyvsp[(2) - (2)].symbol), gProject->Parse_TOS->transUnit->contxt.tags);
			else (yyval.base) = NULL;
		}
			break;

		case 264:

			/* Line 1806 of yacc.c  */
#line 1690 "gram.y"
		{
			(yyval.base) = new BaseType((yyvsp[(3) - (4)].enDef));

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 265:

			/* Line 1806 of yacc.c  */
#line 1697 "gram.y"
		{
			(yyval.base) = (yyvsp[(1) - (4)].base);
			assert(! (yyval.base)->enDefn);
			(yyval.base)->enDefn = (yyvsp[(3) - (4)].enDef);
			(yyvsp[(3) - (4)].enDef)->tag = (yyvsp[(1) - (4)].base)->tag->dup();

			// Overload the incomplete definition
			(yyval.base)->tag->entry->uStructDef = (yyval.base);

//             std::cout << "struct/union/enum_type_define:"
//                          "The definition of:"
//                       << "(uStructDef:" << $1->tag->entry->uStructDef << ")"
//                       << "(uStructDef->stDefn:" << $1->tag->entry->uStructDef->stDefn << ")"
//                       << "(" << $1->tag->entry << ")" << $1->tag->name  << "$" ;
//             $1->tag->entry->scope->ShowScopeId(std::cout);
//             std::cout << " has been completed" << endl; 

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 266:

			/* Line 1806 of yacc.c  */
#line 1720 "gram.y"
		{
			(yyval.strDef) = new StructDef();
			yywarn("ANSI/ISO C prohibits empty struct/union");
		}
			break;

		case 268:

			/* Line 1806 of yacc.c  */
#line 1727 "gram.y"
		{
			(yyval.enDef) = new EnumDef();
			yywarn("ANSI/ISO C prohibits empty enum");
		}
			break;

		case 269:

			/* Line 1806 of yacc.c  */
#line 1731 "gram.y"
		{
			(yyval.enDef) = (yyvsp[(1) - (2)].enDef);
		}
			break;

		case 270:

			/* Line 1806 of yacc.c  */
#line 1736 "gram.y"
		{
			(yyval.loc) = NULL;
		}
			break;

		case 271:

			/* Line 1806 of yacc.c  */
#line 1740 "gram.y"
		{
			yywarn("Trailing comma in enum type definition");
		}
			break;

		case 273:

			/* Line 1806 of yacc.c  */
#line 1753 "gram.y"
		{
			(yyval.enDef) = new EnumDef();
			(yyval.enDef)->addElement((yyvsp[(1) - (1)].enConst));
		}
			break;

		case 274:

			/* Line 1806 of yacc.c  */
#line 1758 "gram.y"
		{
			(yyval.enDef) = (yyvsp[(1) - (3)].enDef);
			(yyval.enDef)->addElement((yyvsp[(3) - (3)].enConst));
			delete (yyvsp[(2) - (3)].loc);
		}
			break;

		case 275:

			/* Line 1806 of yacc.c  */
#line 1766 "gram.y"
		{
			(yyval.enConst) = new EnumConstant((yyvsp[(1) - (1)].symbol), NULL, HERE);
			if (gProject->Parse_TOS->transUnit) {
				if (gProject->Parse_TOS->transUnit->contxt.syms->IsDefined((yyvsp[(1) - (1)].symbol)->name)) {
					if (yyerr("Duplicate enumeration constant"))
					YYERROR;
				}

				(yyvsp[(1) - (1)].symbol)->entry = gProject->Parse_TOS->transUnit->contxt.syms->Insert(mk_enum_const((yyvsp[(1) - (1)].symbol)->name, (yyval.enConst)));
			}
		}
			break;

		case 276:

			/* Line 1806 of yacc.c  */
#line 1781 "gram.y"
		{
			(yyval.enConst) = new EnumConstant((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].value), HERE);
			if (gProject->Parse_TOS->transUnit) {
				if (gProject->Parse_TOS->transUnit->contxt.syms->IsDefined((yyvsp[(1) - (3)].symbol)->name)) {
					if (yyerr("Duplicate enumeration constant"))
					YYERROR;
				}

				(yyvsp[(1) - (3)].symbol)->entry = gProject->Parse_TOS->transUnit->contxt.syms->Insert(mk_enum_const((yyvsp[(1) - (3)].symbol)->name, (yyval.enConst)));
			}
		}
			break;

		case 278:

			/* Line 1806 of yacc.c  */
#line 1804 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.EnterScope();
			gProject->Parse_TOS->parseCtxt->PushCtxt();
		}
			break;

		case 279:

			/* Line 1806 of yacc.c  */
#line 1809 "gram.y"
		{
			assert(!gProject->Parse_TOS->err_top_level || gProject->Parse_TOS->possibleType);
			/* Safety precaution! */
			gProject->Parse_TOS->possibleType = true;
		}
			break;

		case 280:

			/* Line 1806 of yacc.c  */
#line 1815 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->PopCtxt(false);
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ExitScope();
			(yyval.strDef) = (yyvsp[(3) - (3)].strDef);
		}
			break;

		case 281:

			/* Line 1806 of yacc.c  */
#line 1824 "gram.y"
		{
			(yyval.strDef) = new StructDef();
			(yyval.strDef)->addComponent(ReverseList((yyvsp[(1) - (2)].decl)));
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 282:

			/* Line 1806 of yacc.c  */
#line 1830 "gram.y"
		{
			// A useful gcc extension:
			//   naked semicolons in struct/union definitions.
			(yyval.strDef) = (yyvsp[(1) - (2)].strDef);
			yywarn("Empty declaration");
			delete (yyvsp[(2) - (2)].loc);
		}
			break;

		case 283:

			/* Line 1806 of yacc.c  */
#line 1838 "gram.y"
		{
			(yyval.strDef) = (yyvsp[(1) - (3)].strDef);
			(yyval.strDef)->addComponent(ReverseList((yyvsp[(2) - (3)].decl)));
			delete (yyvsp[(3) - (3)].loc);
		}
			break;

		case 284:

			/* Line 1806 of yacc.c  */
#line 1846 "gram.y"
		{
			gProject->Parse_TOS->possibleType = true;
			(yyval.decl) = (yyvsp[(2) - (2)].decl);
		}
			break;

		case 285:

			/* Line 1806 of yacc.c  */
#line 1851 "gram.y"
		{
			gProject->Parse_TOS->possibleType = true;
			(yyval.decl) = new Decl((yyvsp[(1) - (1)].base));
			yywarn("No field declarator");
		}
			break;

		case 287:

			/* Line 1806 of yacc.c  */
#line 1865 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->SetIsFieldId(true);
		}
			break;

		case 288:

			/* Line 1806 of yacc.c  */
#line 1868 "gram.y"
		{
			(yyval.decl) = (yyvsp[(2) - (3)].decl);
			(yyval.decl)->attrib = (yyvsp[(3) - (3)].gccAttrib);
		}
			break;

		case 289:

			/* Line 1806 of yacc.c  */
#line 1873 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->SetIsFieldId(true);
		}
			break;

		case 290:

			/* Line 1806 of yacc.c  */
#line 1876 "gram.y"
		{
			(yyval.decl) = (yyvsp[(4) - (5)].decl);
			(yyval.decl)->attrib = (yyvsp[(5) - (5)].gccAttrib);
			(yyval.decl)->next = (yyvsp[(1) - (5)].decl);
			delete (yyvsp[(2) - (5)].loc);
		}
			break;

		case 291:

			/* Line 1806 of yacc.c  */
#line 1885 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->SetIsFieldId(false);
			Type * decl = gProject->Parse_TOS->parseCtxt->UseDeclCtxt();
			Type * extended = (yyval.decl)->extend(decl);
			if ((yyval.decl)->form && (yyval.decl)->form->isFunction()) {
				if (yyerr("Function type not allowed as field"))
				YYERROR;
			} else if (extended && decl && decl->isFunction() && !extended->isPointer()) if (yyerr("Wrong type combination"))
			YYERROR;

		}
			break;

		case 292:

			/* Line 1806 of yacc.c  */
#line 1903 "gram.y"
		{
			Type * decl = gProject->Parse_TOS->parseCtxt->UseDeclCtxt();
			(yyval.decl)->extend(decl);
			if (!decl) {
				if (yyerr("No type specifier for bit field"))
				YYERROR;
			} else if (!(yyval.decl)->form) {
				if (yyerr("Wrong type combination"))
				YYERROR;
			}
		}
			break;

		case 294:

			/* Line 1806 of yacc.c  */
#line 1923 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->SetIsFieldId(false);
		}
			break;

		case 295:

			/* Line 1806 of yacc.c  */
#line 1926 "gram.y"
		{
			BitFieldType *bf = new BitFieldType((yyvsp[(4) - (4)].value));
			(yyval.decl) = (yyvsp[(1) - (4)].decl);

			if ((yyval.decl) == NULL) {
				(yyval.decl) = new Decl(bf);
			} else {
				bf->subType = (yyval.decl)->form;
				(yyval.decl)->form = bf;
			}
		}
			break;

		case 297:

			/* Line 1806 of yacc.c  */
#line 1946 "gram.y"
		{
			(yyval.decl) = (Decl*) NULL;
		}
			break;

		case 299:

			/* Line 1806 of yacc.c  */
#line 1957 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->Mk_declarator((yyval.decl));
		}
			break;

		case 300:

			/* Line 1806 of yacc.c  */
#line 1963 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->Mk_func_declarator((yyval.decl));
		}
			break;

		case 301:

			/* Line 1806 of yacc.c  */
#line 1969 "gram.y"
		{
			(yyval.decl) = (yyvsp[(2) - (2)].decl);
			(yyval.decl)->extend((yyvsp[(1) - (2)].ptr));
		}
			break;

		case 304:

			/* Line 1806 of yacc.c  */
#line 1980 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) (yyval.decl) = gProject->Parse_TOS->parseCtxt->Mk_direct_declarator_reentrance((yyvsp[(1) - (1)].symbol), gProject->Parse_TOS->transUnit->contxt.syms);
		}
			break;

		case 305:

			/* Line 1806 of yacc.c  */
#line 1985 "gram.y"
		{
			(yyval.decl) = (yyvsp[(2) - (3)].decl);
			delete (yyvsp[(1) - (3)].loc);
			delete (yyvsp[(3) - (3)].loc);
		}
			break;

		case 307:

			/* Line 1806 of yacc.c  */
#line 1992 "gram.y"
		{
			(yyval.decl) = (yyvsp[(1) - (4)].decl);
			FunctionType * ft = new FunctionType(ReverseList((yyvsp[(3) - (4)].decl)));
			Type * extended = (yyval.decl)->extend(ft);
			if (extended && !extended->isPointer()) if (yyerr("Wrong type combination"))
			YYERROR;

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
			// Exit, but will allow re-enter for a function.
			// Hack, to handle parameters being in the function's scope.
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ExitScope(true);

		}
			break;

		case 308:

			/* Line 1806 of yacc.c  */
#line 2009 "gram.y"
		{
			(yyval.decl) = (yyvsp[(1) - (4)].decl);
			FunctionType * ft = new FunctionType(ReverseList((yyvsp[(3) - (4)].decl)));
			Type * extended = (yyval.decl)->extend(ft);
			if (extended && !extended->isPointer()) if (yyerr("Wrong type combination"))
			YYERROR;

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
			// Exit, but will allow re-enter for a function.
			// Hack, to handle parameters being in the function's scope.
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.ExitScope(true);

		}
			break;

		case 309:

			/* Line 1806 of yacc.c  */
#line 2026 "gram.y"
		{
			(yyval.decl) = (yyvsp[(1) - (3)].decl);

			if ((yyval.decl) != NULL) {
				FunctionType* ft = new FunctionType();
				Type* extended = (yyval.decl)->extend(ft);
				if (extended && !extended->isPointer()) if (yyerr("Wrong type combination"))
				YYERROR;
			}

			delete (yyvsp[(2) - (3)].loc);
			delete (yyvsp[(3) - (3)].loc);
			if (gProject->Parse_TOS->transUnit) {
				gProject->Parse_TOS->transUnit->contxt.EnterScope();
				// Exit, but will allow re-enter for a function.
				// Hack, to handle parameters being in the function's scope.
				gProject->Parse_TOS->transUnit->contxt.ExitScope(true);
			}
		}
			break;

		case 310:

			/* Line 1806 of yacc.c  */
#line 2051 "gram.y"
		{
			(yyval.decl) = (yyvsp[(1) - (4)].decl);
			ArrayType * at = new ArrayType((yyvsp[(3) - (4)].value));
			Type * extended = (yyval.decl)->extend(at);
			if (extended && extended->isFunction()) if (yyerr("Wrong type combination"))
			YYERROR;

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 311:

			/* Line 1806 of yacc.c  */
#line 2069 "gram.y"
		{
			(yyval.ptr) = new PtrType((yyvsp[(2) - (2)].typeQual));
		}
			break;

		case 313:

			/* Line 1806 of yacc.c  */
#line 2076 "gram.y"
		{
			(yyval.ptr) = (yyvsp[(2) - (2)].ptr);
			(yyval.ptr)->subType = (yyvsp[(1) - (2)].ptr);
		}
			break;

		case 315:

			/* Line 1806 of yacc.c  */
#line 2089 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->IncrVarParam(1);
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.EnterScope();
			gProject->Parse_TOS->parseCtxt->PushCtxt();
		}
			break;

		case 316:

			/* Line 1806 of yacc.c  */
#line 2095 "gram.y"
		{
			// Exit, but will allow re-enter for a function.
			// Hack, to handle parameters being in the function's scope.
			gProject->Parse_TOS->parseCtxt->PopCtxt(true);
			gProject->Parse_TOS->parseCtxt->IncrVarParam(-1);
			(yyval.decl) = (yyvsp[(2) - (2)].decl);
		}
			break;

		case 317:

			/* Line 1806 of yacc.c  */
#line 2105 "gram.y"
		{
			if (gProject->Parse_TOS->transUnit) (yyval.decl) = gProject->Parse_TOS->parseCtxt->Mk_direct_declarator_reentrance((yyvsp[(1) - (1)].symbol), gProject->Parse_TOS->transUnit->contxt.syms);
		}
			break;

		case 318:

			/* Line 1806 of yacc.c  */
#line 2110 "gram.y"
		{
			(yyval.decl) = (yyvsp[(1) - (3)].decl);
			if (gProject->Parse_TOS->transUnit) {
				(yyval.decl) = gProject->Parse_TOS->parseCtxt->Mk_direct_declarator_reentrance((yyvsp[(3) - (3)].symbol), gProject->Parse_TOS->transUnit->contxt.syms);
				(yyval.decl)->next = (yyvsp[(1) - (3)].decl);
			}
		}
			break;

		case 320:

			/* Line 1806 of yacc.c  */
#line 2126 "gram.y"
		{
			/* Convert a TYPEDEF_NAME back into a normal IDENT */
			(yyval.symbol) = (yyvsp[(1) - (1)].symbol);
			(yyval.symbol)->entry = (SymEntry*) NULL;
		}
			break;

		case 323:

			/* Line 1806 of yacc.c  */
#line 2147 "gram.y"
		{
			(yyval.decl) = (Decl*) NULL;
		}
			break;

		case 324:

			/* Line 1806 of yacc.c  */
#line 2151 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->IncrVarParam(1);
		}
			break;

		case 325:

			/* Line 1806 of yacc.c  */
#line 2154 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->IncrVarParam(-1);
			(yyval.decl) = (yyvsp[(2) - (2)].decl);
		}
			break;

		case 326:

			/* Line 1806 of yacc.c  */
#line 2160 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->IncrVarParam(1);
			if (gProject->Parse_TOS->transUnit) gProject->Parse_TOS->transUnit->contxt.EnterScope();
			gProject->Parse_TOS->parseCtxt->PushCtxt();
		}
			break;

		case 327:

			/* Line 1806 of yacc.c  */
#line 2166 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->PopCtxt(true);
			gProject->Parse_TOS->parseCtxt->IncrVarParam(-1);
			(yyval.decl) = (yyvsp[(2) - (2)].decl);
		}
			break;

		case 329:

			/* Line 1806 of yacc.c  */
#line 2175 "gram.y"
		{
			BaseType *bt = new BaseType(BT_Ellipsis);

			(yyval.decl) = new Decl(bt);
			(yyval.decl)->next = (yyvsp[(1) - (3)].decl);
		}
			break;

		case 331:

			/* Line 1806 of yacc.c  */
#line 2185 "gram.y"
		{
			(yyval.decl) = (yyvsp[(3) - (3)].decl);
			(yyval.decl)->next = (yyvsp[(1) - (3)].decl);
		}
			break;

		case 332:

			/* Line 1806 of yacc.c  */
#line 2192 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->PushCtxt();
		}
			break;

		case 333:

			/* Line 1806 of yacc.c  */
#line 2196 "gram.y"
		{
			gProject->Parse_TOS->parseCtxt->PopCtxt(true);
			(yyval.decl) = (yyvsp[(2) - (2)].decl);
		}
			break;

		case 334:

			/* Line 1806 of yacc.c  */
#line 2203 "gram.y"
		{
			assert(gProject->Parse_TOS->err_top_level || (yyvsp[(1) - (2)].base) == gProject->Parse_TOS->parseCtxt->curCtxt->decl_specs);
			gProject->Parse_TOS->possibleType = true;
			(yyval.decl) = (yyvsp[(2) - (2)].decl);
			Type * decl = gProject->Parse_TOS->parseCtxt->UseDeclCtxt();
			Type * extended = (yyval.decl)->extend(decl);
			if ((yyval.decl)->form && (yyval.decl)->form->isFunction()) {
				if (yyerr("Function type not allowed"))
				YYERROR;
			} else if (extended && decl && decl->isFunction() && !extended->isPointer()) {
				if (yyerr("Wrong type combination"))
				YYERROR;
			}
		}
			break;

		case 335:

			/* Line 1806 of yacc.c  */
#line 2225 "gram.y"
		{
			assert(gProject->Parse_TOS->err_top_level || (yyvsp[(1) - (2)].base) == gProject->Parse_TOS->parseCtxt->curCtxt->decl_specs);
			gProject->Parse_TOS->possibleType = true;
			(yyval.decl) = new Decl((yyvsp[(2) - (2)].type));

			Type * decl = gProject->Parse_TOS->parseCtxt->UseDeclCtxt();
			Type * extended = (yyval.decl)->extend(decl);
			if ((yyval.decl)->form && (yyval.decl)->form->isFunction()) {
				if (yyerr("Function type not allowed for parameter"))
				YYERROR;
			} else if (extended && decl && decl->isFunction() && !extended->isPointer()) {
				if (yyerr("Wrong type combination"))
				YYERROR;
			}
		}
			break;

		case 336:

			/* Line 1806 of yacc.c  */
#line 2248 "gram.y"
		{
			gProject->Parse_TOS->possibleType = true;
			(yyval.decl) = new Decl((yyvsp[(1) - (1)].base));
			if ((yyval.decl)->form && (yyval.decl)->form->isFunction()) if (yyerr("Function type not allowed for parameter"))
			YYERROR;
		}
			break;

		case 337:

			/* Line 1806 of yacc.c  */
#line 2262 "gram.y"
		{
			(yyval.type) = (yyvsp[(1) - (1)].ptr);
		}
			break;

		case 338:

			/* Line 1806 of yacc.c  */
#line 2266 "gram.y"
		{
			(yyval.type) = (yyvsp[(1) - (1)].type);
		}
			break;

		case 339:

			/* Line 1806 of yacc.c  */
#line 2270 "gram.y"
		{
			(yyval.type) = (yyvsp[(2) - (2)].type);
			(yyval.type)->extend((yyvsp[(1) - (2)].ptr));
		}
			break;

		case 341:

			/* Line 1806 of yacc.c  */
#line 2280 "gram.y"
		{
			(yyval.type) = (yyvsp[(2) - (3)].type);
		}
			break;

		case 342:

			/* Line 1806 of yacc.c  */
#line 2284 "gram.y"
		{
			(yyval.type) = new ArrayType((yyvsp[(2) - (3)].value));
		}
			break;

		case 343:

			/* Line 1806 of yacc.c  */
#line 2288 "gram.y"
		{
			ArrayType *at = new ArrayType((yyvsp[(3) - (4)].value));
			(yyval.type) = (yyvsp[(1) - (4)].type);
			(yyval.type)->extend(at);
			Type * extended = (yyval.type)->extend(at);
			if (extended && extended->isFunction()) if (yyerr("Wrong type combination"))
			YYERROR;
		}
			break;

		case 344:

			/* Line 1806 of yacc.c  */
#line 2299 "gram.y"
		{
			(yyval.type) = new FunctionType(ReverseList((yyvsp[(2) - (3)].decl)));
		}
			break;

		case 345:

			/* Line 1806 of yacc.c  */
#line 2303 "gram.y"
		{
			FunctionType * ft = new FunctionType(ReverseList((yyvsp[(3) - (4)].decl)));
			(yyval.type) = (yyvsp[(1) - (4)].type);
			Type * extended = (yyval.type)->extend(ft);
			if (extended && !extended->isPointer()) if (yyerr("Wrong type combination"))
			YYERROR;

		}
			break;

		case 346:

			/* Line 1806 of yacc.c  */
#line 2320 "gram.y"
		{
			(yyval.gccAttrib) = (GccAttrib*) NULL;
		}
			break;

		case 348:

			/* Line 1806 of yacc.c  */
#line 2327 "gram.y"
		{
			(yyval.gccAttrib) = (yyvsp[(4) - (6)].gccAttrib);
			delete (yyvsp[(2) - (6)].loc);
			delete (yyvsp[(3) - (6)].loc);
			delete (yyvsp[(5) - (6)].loc);
			delete (yyvsp[(6) - (6)].loc);
		}
			break;

		case 349:

			/* Line 1806 of yacc.c  */
#line 2337 "gram.y"
		{
			/* The lexer ate some unsupported option. */
			(yyval.gccAttrib) = new GccAttrib(GCC_Unsupported);
		}
			break;

		case 350:

			/* Line 1806 of yacc.c  */
#line 2342 "gram.y"
		{
			(yyval.gccAttrib) = new GccAttrib(GCC_Packed);
		}
			break;

		case 351:

			/* Line 1806 of yacc.c  */
#line 2346 "gram.y"
		{
			(yyval.gccAttrib) = new GccAttrib(GCC_CDecl);
		}
			break;

		case 352:

			/* Line 1806 of yacc.c  */
#line 2350 "gram.y"
		{
			(yyval.gccAttrib) = new GccAttrib(GCC_Const);
		}
			break;

		case 353:

			/* Line 1806 of yacc.c  */
#line 2354 "gram.y"
		{
			(yyval.gccAttrib) = new GccAttrib(GCC_NoReturn);
		}
			break;

		case 354:

			/* Line 1806 of yacc.c  */
#line 2358 "gram.y"
		{
			(yyval.gccAttrib) = new GccAttrib(GCC_Aligned);

			if ((yyvsp[(3) - (4)].consValue)->ctype == CT_Int) {
				IntConstant *iCons = (IntConstant*) (yyvsp[(3) - (4)].consValue);

				(yyval.gccAttrib)->value = iCons->lng;
			}

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 355:

			/* Line 1806 of yacc.c  */
#line 2372 "gram.y"
		{
			(yyval.gccAttrib) = new GccAttrib(GCC_Mode);

			(yyval.gccAttrib)->mode = (yyvsp[(3) - (4)].symbol);

			delete (yyvsp[(2) - (4)].loc);
			delete (yyvsp[(4) - (4)].loc);
		}
			break;

		case 356:

			/* Line 1806 of yacc.c  */
#line 2381 "gram.y"
		{
			(yyval.gccAttrib) = new GccAttrib(GCC_Format);

			(yyval.gccAttrib)->mode = (yyvsp[(3) - (8)].symbol);

			if ((yyvsp[(5) - (8)].consValue)->ctype == CT_Int) {
				IntConstant *iCons = (IntConstant*) (yyvsp[(5) - (8)].consValue);

				(yyval.gccAttrib)->strIdx = iCons->lng;
			}

			if ((yyvsp[(7) - (8)].consValue)->ctype == CT_Int) {
				IntConstant *iCons = (IntConstant*) (yyvsp[(7) - (8)].consValue);

				(yyval.gccAttrib)->first = iCons->lng;
			}

			delete (yyvsp[(2) - (8)].loc);
			delete (yyvsp[(8) - (8)].loc);
		}
			break;

		case 357:

			/* Line 1806 of yacc.c  */
#line 2404 "gram.y"
		{
			(yyval.gccAttrib) = new GccAttrib(GCC_Malloc);
		}
			break;

			/* Line 1806 of yacc.c  */
#line 4915 "gram.cpp"
		default:
			break;
	}
	/* User semantic actions sometimes alter yychar, and that requires
	 that yytoken be updated with the new translation.  We take the
	 approach of translating immediately before every use of yytoken.
	 One alternative is translating here after every semantic action,
	 but that translation would be missed if the semantic action invokes
	 YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
	 if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
	 incorrect destructor might then be invoked immediately.  In the
	 case of YYERROR or YYBACKUP, subsequent parser actions might lead
	 to an incorrect destructor call or verbose syntax error message
	 before the lookahead is translated.  */
	YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

	YYPOPSTACK(yylen);
	yylen = 0;
	YY_STACK_PRINT(yyss, yyssp);

	*++yyvsp = yyval;

	/* Now `shift' the result of the reduction.  Determine what state
	 that goes to, based on the state we popped back to and the rule
	 number reduced by.  */

	yyn = yyr1[yyn];

	yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
	if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp) yystate = yytable[yystate];
	else yystate = yydefgoto[yyn - YYNTOKENS];

	goto yynewstate;

	/*------------------------------------.
	 | yyerrlab -- here on detecting error |
	 `------------------------------------*/
	yyerrlab:
	/* Make sure we have latest lookahead translation.  See comments at
	 user semantic actions for why this is necessary.  */
	yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

	/* If not already recovering from an error, report this error.  */
	if (!yyerrstatus) {
		++yynerrs;
#if ! YYERROR_VERBOSE
		yyerror(YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
		{
			char const *yymsgp = YY_("syntax error");
			int yysyntax_error_status;
			yysyntax_error_status = YYSYNTAX_ERROR;
			if (yysyntax_error_status == 0)
			yymsgp = yymsg;
			else if (yysyntax_error_status == 1)
			{
				if (yymsg != yymsgbuf)
				YYSTACK_FREE (yymsg);
				yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
				if (!yymsg)
				{
					yymsg = yymsgbuf;
					yymsg_alloc = sizeof yymsgbuf;
					yysyntax_error_status = 2;
				}
				else
				{
					yysyntax_error_status = YYSYNTAX_ERROR;
					yymsgp = yymsg;
				}
			}
			yyerror (yymsgp);
			if (yysyntax_error_status == 2)
			goto yyexhaustedlab;
		}
# undef YYSYNTAX_ERROR
#endif
	}

	if (yyerrstatus == 3) {
		/* If just tried and failed to reuse lookahead token after an
		 error, discard it.  */

		if (yychar <= YYEOF) {
			/* Return failure if at end of input.  */
			if (yychar == YYEOF)
			YYABORT;
		} else {
			yydestruct("Error: discarding", yytoken, &yylval);
			yychar = YYEMPTY;
		}
	}

	/* Else will try to reuse lookahead token after shifting the error
	 token.  */
	goto yyerrlab1;

	/*---------------------------------------------------.
	 | yyerrorlab -- error raised explicitly by YYERROR.  |
	 `---------------------------------------------------*/
	yyerrorlab:

	/* Pacify compilers like GCC when the user code never invokes
	 YYERROR and the label yyerrorlab therefore never appears in user
	 code.  */
	if (/*CONSTCOND*/0) goto yyerrorlab;

	/* Do not reclaim the symbols of the rule which action triggered
	 this YYERROR.  */
	YYPOPSTACK(yylen);
	yylen = 0;
	YY_STACK_PRINT(yyss, yyssp);
	yystate = *yyssp;
	goto yyerrlab1;

	/*-------------------------------------------------------------.
	 | yyerrlab1 -- common code for both syntax error and YYERROR.  |
	 `-------------------------------------------------------------*/
	yyerrlab1: yyerrstatus = 3; /* Each real token shifted decrements this.  */

	for (;;) {
		yyn = yypact[yystate];
		if (!yypact_value_is_default (yyn)) {
			yyn += YYTERROR;
			if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR) {
				yyn = yytable[yyn];
				if (0 < yyn) break;
			}
		}

		/* Pop the current state because it cannot handle the error token.  */
		if (yyssp == yyss)
		YYABORT;

		yydestruct("Error: popping", yystos[yystate], yyvsp);
		YYPOPSTACK(1);
		yystate = *yyssp;
		YY_STACK_PRINT(yyss, yyssp);
	}

	*++yyvsp = yylval;

	/* Shift the error token.  */
	YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

	yystate = yyn;
	goto yynewstate;

	/*-------------------------------------.
	 | yyacceptlab -- YYACCEPT comes here.  |
	 `-------------------------------------*/
	yyacceptlab: yyresult = 0;
	goto yyreturn;

	/*-----------------------------------.
	 | yyabortlab -- YYABORT comes here.  |
	 `-----------------------------------*/
	yyabortlab: yyresult = 1;
	goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
	/*-------------------------------------------------.
	 | yyexhaustedlab -- memory exhaustion comes here.  |
	 `-------------------------------------------------*/
	yyexhaustedlab: yyerror(YY_("memory exhausted"));
	yyresult = 2;
	/* Fall through.  */
#endif

	yyreturn: if (yychar != YYEMPTY) {
		/* Make sure we have latest lookahead translation.  See comments at
		 user semantic actions for why this is necessary.  */
		yytoken = YYTRANSLATE (yychar);
		yydestruct("Cleanup: discarding lookahead", yytoken, &yylval);
	}
	/* Do not reclaim the symbols of the rule which action triggered
	 this YYABORT or YYACCEPT.  */
	YYPOPSTACK(yylen);
	YY_STACK_PRINT(yyss, yyssp);
	while (yyssp != yyss) {
		yydestruct("Cleanup: popping", yystos[*yyssp], yyvsp);
		YYPOPSTACK(1);
	}
#ifndef yyoverflow
	if (yyss != yyssa)
	YYSTACK_FREE(yyss);
#endif
#if YYERROR_VERBOSE
	if (yymsg != yymsgbuf)
	YYSTACK_FREE (yymsg);
#endif
	/* Make sure YYID is used.  */
	return YYID (yyresult);
}

/* Line 2067 of yacc.c  */
#line 2409 "gram.y"

/*******************************************************/

