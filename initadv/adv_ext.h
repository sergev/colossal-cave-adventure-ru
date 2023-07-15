/* INCLUDE-FILE ДЛЯ ГЕНЕРАТОРА БАЗЫ ДАННЫХ "ADVENTURE" */

#include <stdio.h>

#include "../common/advexter.h"

#define inplen 81

extern int p;
extern char _line[inplen], _word[4]; /* buffer: for input line */
extern long *rword;                  /* equivalence (word,rword) */

#define line(x) _line[(x)-1]
#define word(x) _word[(x)-1]

extern FILE *F3;

int scan(void);
int getwrd(void);
int getlin(void);
void screen(int n);
int putcnd(void);
int getobj(void);
int putmes(void);
void ivocab(void);
void iobjec(void);
void iactio(void);
void iclass(void);
void icave(void);
void imessa(void);
void ievent(void);
void stat(void);
