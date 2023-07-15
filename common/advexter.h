/* = common blocks for adventure === include file === */

/* - parameters --- current limits: */

                        /* === размеры массивов === */
#define vocw 550        /* размер словаря */
#define loct 254        /* locations */
#define objt 127        /* objects */
#define fixt 200        /* locations for fixed objects */
#define sttt (objt*2)   /* different states of objects */
#define actw 60         /* "action" verbs */
#define ranm 400        /* random messages */
#define plcl 12         /* different player classifications. */

                        /* === типы слов === */
#define movewr 0        /* направление движения */
#define objcwr 1        /* объект */
#define actnwr 2        /* действие с объектом */
#define specwr 3        /* спец-слово */


/* there are also limits which cannot be exceeded due to the structure */
/* of the database. these upper limits are: */
/*      1000 non-synonymous vocabulary words */
/*       255 locations */
/*       127 objects */
/*       511 random messages */
/*       255 states of objects */


/* --- messages --- */
extern int  abb;                      /* флаг: нужно ли полное описание */
extern unsigned  _rtext[ranm];        /* адреса разных сообщений */
#define    rtext(x) _rtext[(x)-1]
extern unsigned  _ltext[loct];        /* - " -  длинных описаний позиции */
#define    ltext(x) _ltext[(x)-1]
extern unsigned  _stext[loct];        /* - " -  коротких описаний позиции */
#define    stext(x) _stext[(x)-1]
extern unsigned  _ctext[plcl];        /* - " -  квалификаций игрока */
#define    ctext(x) _ctext[(x)-1]
extern unsigned  _cval[plcl];         /* пороги квалификации игрока */
#define    cval(x) _cval[(x)-1]
extern unsigned  _ptext[objt];        /* индексы сообщений o свойствах объектов */
#define    ptext(x) _ptext[(x)-1]
extern unsigned  _pstat[sttt];        /* индексы сообщений o свойствах объектов */
#define    pstat(x) _pstat[(x)-1]
extern char _abrev[loct];             /* флаги: надо сокращенное описание */
#define    abrev(x) _abrev[(x)-1]


/* --- travels + actions --- */
extern unsigned  _trvkey[loct];       /* таблица начала графа данной позиции */
#define    trvkey(x) _trvkey[(x)-1]
extern unsigned  _actkey[actw];       /*  -"-    -"-  реакции нa действие */
#define    actkey(x) _actkey[(x)-1]


/* --- vocabulary --- */
extern int  nvoc;                     /* число слов в словаре */
extern int  _ktab[vocw];              /* числа - значение слов */
#define    ktab(x) _ktab[(x)-1]
extern long _atab[vocw];              /* слова - по 4 буквы */
#define    atab(x) _atab[(x)-1]

/* --- state --- */
#define inipro  255           /* начальное состояние для сокровищ */
#define nulobj  255           /* отсутствующий объект */
#define caried  1000          /* маркер - объект несут */

extern int  rndini;
extern int  loc;                      /* текущая позиция */
extern int  tally;                    /* число еще не обнаруженных сокровищ */
extern int  treasr;                   /* номер 1-ого объекта-сокровища */
extern int  rndini;                   /* случайное число данной партии */
extern unsigned  tevent;              /* указатель таблицы случайных событий */
extern unsigned  eevent;              /* конец таблицы случайных событий */
extern unsigned  tiniti;              /* -"-  -"- инициализации */

extern int  _place[loct];             /* позиция объекта или -[индекс] */
#define    place(x) _place[(x)-1]

extern char _fixed[fixt];             /* для фиксированных объектов */
#define    fixed(x) _fixed[(x)-1]

extern char _prop[objt];              /* свойство объекта */
#define    prop(x) _prop[(x)-1]

void fatal(void);
int vocab(char *word);
void savecm(void);
