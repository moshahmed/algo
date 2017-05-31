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

typedef union Datum {	/* interpreter stack type */
	double	val;
	Symbol	*sym;
} Datum;
extern	Datum pop();

typedef int (*Inst)();	/* machine instruction */
#define	STOP	(Inst) 0

extern	Inst prog[], *progp, *code();
extern	eval(), add(), sub(), mul(), divi(), negate(), power();
extern	assign(), bltin(), varpush(), constpush(), print();
extern	prexpr();
extern	gt(), lt(), eq(), ge(), le(), ne(), and(), or(), not();
extern	ifcode(), whilecode();

typedef void (*sighandler_t)(int);
