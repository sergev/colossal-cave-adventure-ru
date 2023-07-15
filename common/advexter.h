/* = common blocks for adventure === include file === */
#include <stdbool.h>

/* - parameters --- current limits: */

/*
 * размеры массивов
 */
#define VOCW 550        /* размер словаря */
#define LOCT 254        /* locations */
#define OBJT 127        /* objects */
#define FIXT 200        /* locations for fixed objects */
#define STTT (OBJT * 2) /* different states of objects */
#define ACTW 60         /* "action" verbs */
#define RANM 400        /* random messages */
#define PLCL 12         /* different player classifications */

/*
 * типы слов
 */
#define MOVEWR 0 /* направление движения */
#define OBJCWR 1 /* объект */
#define ACTNWR 2 /* действие с объектом */
#define SPECWR 3 /* спец-слово */

/* there are also limits which cannot be exceeded due to the structure */
/* of the database. these upper limits are: */
/*      1000 non-synonymous vocabulary words */
/*       255 locations */
/*       127 objects */
/*       511 random messages */
/*       255 states of objects */

/*
 * messages
 */
extern int abb;               /* флаг: нужно ли полное описание */

extern unsigned _rtext[RANM]; /* адреса разных сообщений */
#define RTEXT(x) _rtext[(x)-1]

extern unsigned _ltext[LOCT]; /* - " -  длинных описаний позиции */
#define LTEXT(x) _ltext[(x)-1]

extern unsigned _stext[LOCT]; /* - " -  коротких описаний позиции */
#define STEXT(x) _stext[(x)-1]

extern unsigned _ctext[PLCL]; /* - " -  квалификаций игрока */
#define CTEXT(x) _ctext[(x)-1]

extern unsigned _cval[PLCL]; /* пороги квалификации игрока */
#define CVAL(x) _cval[(x)-1]

extern unsigned _ptext[OBJT]; /* индексы сообщений o свойствах объектов */
#define PTEXT(x) _ptext[(x)-1]

extern unsigned _pstat[STTT]; /* индексы сообщений o свойствах объектов */
#define PSTAT(x) _pstat[(x)-1]

extern char _abrev[LOCT]; /* флаги: надо сокращенное описание */
#define ABREV(x) _abrev[(x)-1]

/*
 * travels + actions
 */
extern unsigned _trvkey[LOCT]; /* таблица начала графа данной позиции */
#define TRVKEY(x) _trvkey[(x)-1]

extern unsigned _actkey[ACTW]; /*  -"-    -"-  реакции нa действие */
#define ACTKEY(x) _actkey[(x)-1]

/*
 * vocabulary
 */
extern int nvoc;        /* число слов в словаре */

extern int _ktab[VOCW]; /* числа - значение слов */
#define KTAB(x) _ktab[(x)-1]

extern long _atab[VOCW]; /* слова - по 4 буквы */
#define ATAB(x) _atab[(x)-1]

/*
 * state
 */
#define INIPRO 255  /* начальное состояние для сокровищ или отсутствующий объект */
#define CARIED 1000 /* маркер - объект несут */

extern int rndini;
extern int loc;         /* текущая позиция */
extern int tally;       /* число еще не обнаруженных сокровищ */
extern int treasr;      /* номер 1-ого объекта-сокровища */
extern int rndini;      /* случайное число данной партии */
extern unsigned tevent; /* указатель таблицы случайных событий */
extern unsigned eevent; /* конец таблицы случайных событий */
extern unsigned tiniti; /* -"-  -"- инициализации */

extern int _place[LOCT]; /* позиция объекта или -[индекс] */
#define PLACE(x) _place[(x)-1]

extern char _fixed[FIXT]; /* для фиксированных объектов */
#define FIXED(x) _fixed[(x)-1]

extern char _prop[OBJT]; /* свойство объекта */
#define PROP(x) _prop[(x)-1]

/*
 * Cyrillic letters in internal encoding.
 */
#define CYRILLIC_CAPITAL_LETTER_DE  0x94    /* Д */
#define CYRILLIC_SMALL_LETTER_DE    0xb4    /* д */
#define CYRILLIC_CAPITAL_LETTER_EN  0x9d    /* Н */
#define CYRILLIC_SMALL_LETTER_EN    0xbd    /* н */

/*
 * From common directory.
 */
void fatal(const char *message);
int vocab(char *word);
void savecm(void);
void loadcm(void);
bool is_utf8(int ch);
int get_utf8(int c1, int c2);
const char *word_utf8(const char w[4]);

/*
 * From advent directory.
 */
void iniget(unsigned adr);
int get(void);
int at(int object);
int pct(int n);
int yes(int x);
void rspeak(int n);
void chnloc(int newloc);
void specia(int n);
void indobj(void);
int dark(void);
void mes(unsigned iadr);
int here(int object);
void to_lower(char *adr, int lgt);
void ini(void);
void events(void);
void getans(int *word1, int *word2, int *type1, int *type2);
void motion(int verb);
void action(int verb, int object);
void descr(void);
void descr2(void);
void trim(char *s);
void score(void);
int act(int indx, int object);
void loadfr(void);
void inpans(char *wrd1, char *wrd2);
void mscore(int score, int maxscore);
char *conv (unsigned value, int length, int radix, char begins);
void freeze(void);
