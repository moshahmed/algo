#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

typedef struct Symbol {	/* symbol table entry */
	char	*name;
	short	type;	/* VAR, BLTIN, UNDEF */
	union {
		double	val;		/* if VAR */
		double	(*ptr)();	/* if BLTIN */
	} u;
	struct Symbol	*next;	/* to link to another */
} Symbol;
Symbol	*install(), *lookup();

typedef void (*sighandler_t)(int);
