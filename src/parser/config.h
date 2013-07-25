
#ifndef CONFIG_H
#define CONFIG_H

/**************************************************************************/

#define EXTERN  extern

/**************************************************************************/
/*
    The following macro helps define argument lists for fns: the arg lists are
    eaten up when not allowed (as in C).  e.g. extern int foo ARGS((int, int));
*/

#if defined(__STDC__) || defined(__cplusplus)
#    define ARGS(args) args
#else
#    define ARGS(args) ()
#endif

#ifndef	__PRETTY_FUNCTION__
#	define	__PRETTY_FUNCTION__		"<Pretty Function Name (gcc only)>"
#endif

/**************************************************************************/

// For the gcc extension \e in strings.
#define    ESC_VAL    ('\033')

/**************************************************************************/

// Define this if your compilation system already defines: uchar, ushort, ulong for you
//#define	 HAVE_UNSIGNED_TYPES

/**************************************************************************/

#endif /* CONFIG_H */
