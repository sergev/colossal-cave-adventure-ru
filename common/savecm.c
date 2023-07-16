/*d* === savecm ===             07.01.85   version    2 */
/* load/store common data for adventure into file 'adv:data' */

#include <stdio.h>

#include "advexter.h"

FILE *F1;

static void write_f1(const void *ptr, unsigned size)
{
    if (fwrite(ptr, size, 1, F1) != 1)
        fatal("fwrite failed");
}

static void read_f1(void *ptr, unsigned size)
{
    if (fread(ptr, size, 1, F1) != 1)
        fatal("fread failed");
}

void savecm()
{
    if ((F1 = fopen("common.adv", "wb")) == NULL)
        fatal("cannot create 'common.adv'");
    write_f1(_rtext, sizeof _rtext);
    write_f1(_ltext, sizeof _ltext);
    write_f1(_stext, sizeof _stext);
    write_f1(_ctext, sizeof _ctext);
    write_f1(_cval, sizeof _cval);
    write_f1(_ptext, sizeof _ptext);
    write_f1(_pstat, sizeof _pstat);
    write_f1(_trvkey, sizeof _trvkey);
    write_f1(_actkey, sizeof _actkey);
    write_f1(&nvoc, sizeof nvoc);
    write_f1(_ktab, sizeof _ktab);
    write_f1(_atab, sizeof _atab);
    write_f1(&tally, sizeof tally);
    write_f1(&treasr, sizeof treasr);
    write_f1(_place, sizeof _place);
    write_f1(_fixed, sizeof _fixed);
    write_f1(_prop, sizeof _prop);
    write_f1(&rndini, sizeof rndini);
    write_f1(&tevent, sizeof tevent);
    write_f1(&eevent, sizeof eevent);
    write_f1(&tiniti, sizeof tiniti);
    fclose(F1);
}

void loadcm()
{
    if ((F1 = fopen("common.adv", "rb")) == NULL) {
        if ((F1 = fopen("/usr/local/share/advent/common.adv", "rb")) == NULL)
            fatal("cannot open 'common.adv' or '/usr/local/share/advent/common.adv'");
    }
    read_f1(_rtext, sizeof _rtext);
    read_f1(_ltext, sizeof _ltext);
    read_f1(_stext, sizeof _stext);
    read_f1(_ctext, sizeof _ctext);
    read_f1(_cval, sizeof _cval);
    read_f1(_ptext, sizeof _ptext);
    read_f1(_pstat, sizeof _pstat);
    read_f1(_trvkey, sizeof _trvkey);
    read_f1(_actkey, sizeof _actkey);
    read_f1(&nvoc, sizeof nvoc);
    read_f1(_ktab, sizeof _ktab);
    read_f1(_atab, sizeof _atab);
    read_f1(&tally, sizeof tally);
    read_f1(&treasr, sizeof treasr);
    read_f1(_place, sizeof _place);
    read_f1(_fixed, sizeof _fixed);
    read_f1(_prop, sizeof _prop);
    read_f1(&rndini, sizeof rndini);
    read_f1(&tevent, sizeof tevent);
    read_f1(&eevent, sizeof eevent);
    read_f1(&tiniti, sizeof tiniti);
    fclose(F1);
}

int abb;               /* флаг: нужно ли полное описание */
unsigned _rtext[RANM]; /* адреса разных сообщений */
unsigned _ltext[LOCT]; /* - " -  длинных описаний позиции */
unsigned _stext[LOCT]; /* - " -  коротких описаний позиции */
unsigned _ctext[PLCL]; /* - " -  квалификаций игрока */
unsigned _cval[PLCL];  /* пороги квалификации игрока */
unsigned _ptext[OBJT]; /* индексы сообщений o свойствах объектов */
unsigned _pstat[STTT]; /* индексы сообщений o свойствах объектов */
char _abrev[LOCT];     /* флаги: надо сокращенное описание */
unsigned _trvkey[LOCT]; /* таблица начала графа данной позиции */
unsigned _actkey[ACTW]; /*  -"-    -"-  реакции нa действие */
int nvoc;               /* число слов в словаре */
int _ktab[VOCW];        /* числа - значение слов */
long _atab[VOCW];       /* слова - по 4 буквы */
int rndini;
int loc;           /* текущая позиция */
int tally;         /* число еще не обнаруженных сокровищ */
int treasr;        /* номер 1-ого объекта-сокровища */
int rndini;        /* случайное число данной партии */
unsigned tevent;   /* указатель таблицы случайных событий */
unsigned eevent;   /* конец таблицы случайных событий */
unsigned tiniti;   /* -"-  -"- инициализации */
int _place[LOCT];  /* позиция объекта или -[индекс] */
char _fixed[FIXT]; /* для фиксированных объектов */
char _prop[OBJT];  /* свойство объекта */
