/*d* === savecm ===             07.01.85   version    2 */
/* load/store common data for adventure into file 'adv:data' */

#include <stdio.h>

#include "advexter.h"

FILE *F1;

void savecm()
{
    if ((F1 = fopen("common.adv", "wb")) == NULL)
        fatal();
    fwrite(_rtext, sizeof _rtext, 1, F1);
    fwrite(_ltext, sizeof _ltext, 1, F1);
    fwrite(_stext, sizeof _stext, 1, F1);
    fwrite(_ctext, sizeof _ctext, 1, F1);
    fwrite(_cval, sizeof _cval, 1, F1);
    fwrite(_ptext, sizeof _ptext, 1, F1);
    fwrite(_pstat, sizeof _pstat, 1, F1);
    fwrite(_trvkey, sizeof _trvkey, 1, F1);
    fwrite(_actkey, sizeof _actkey, 1, F1);
    fwrite(&nvoc, sizeof nvoc, 1, F1);
    fwrite(_ktab, sizeof _ktab, 1, F1);
    fwrite(_atab, sizeof _atab, 1, F1);
    fwrite(&tally, sizeof tally, 1, F1);
    fwrite(&treasr, sizeof treasr, 1, F1);
    fwrite(_place, sizeof _place, 1, F1);
    fwrite(_fixed, sizeof _fixed, 1, F1);
    fwrite(_prop, sizeof _prop, 1, F1);
    fwrite(&rndini, sizeof rndini, 1, F1);
    fwrite(&tevent, sizeof tevent, 1, F1);
    fwrite(&eevent, sizeof eevent, 1, F1);
    fwrite(&tiniti, sizeof tiniti, 1, F1);
    fclose(F1);
}

void loadcm()
{
    if ((F1 = fopen("common.adv", "rb")) == NULL) {
        if ((F1 = fopen("/usr/local/share/advent/common.adv", "rb")) == NULL)
            fatal();
    }
    fread(_rtext, sizeof _rtext, 1, F1);
    fread(_ltext, sizeof _ltext, 1, F1);
    fread(_stext, sizeof _stext, 1, F1);
    fread(_ctext, sizeof _ctext, 1, F1);
    fread(_cval, sizeof _cval, 1, F1);
    fread(_ptext, sizeof _ptext, 1, F1);
    fread(_pstat, sizeof _pstat, 1, F1);
    fread(_trvkey, sizeof _trvkey, 1, F1);
    fread(_actkey, sizeof _actkey, 1, F1);
    fread(&nvoc, sizeof nvoc, 1, F1);
    fread(_ktab, sizeof _ktab, 1, F1);
    fread(_atab, sizeof _atab, 1, F1);
    fread(&tally, sizeof tally, 1, F1);
    fread(&treasr, sizeof treasr, 1, F1);
    fread(_place, sizeof _place, 1, F1);
    fread(_fixed, sizeof _fixed, 1, F1);
    fread(_prop, sizeof _prop, 1, F1);
    fread(&rndini, sizeof rndini, 1, F1);
    fread(&tevent, sizeof tevent, 1, F1);
    fread(&eevent, sizeof eevent, 1, F1);
    fread(&tiniti, sizeof tiniti, 1, F1);
    fclose(F1);
}

int abb;               /* флаг: нужно ли полное описание */
unsigned _rtext[ranm]; /* адреса разных сообщений */
unsigned _ltext[loct]; /* - " -  длинных описаний позиции */
unsigned _stext[loct]; /* - " -  коротких описаний позиции */
unsigned _ctext[plcl]; /* - " -  квалификаций игрока */
unsigned _cval[plcl];  /* пороги квалификации игрока */
unsigned _ptext[objt]; /* индексы сообщений o свойствах объектов */
unsigned _pstat[sttt]; /* индексы сообщений o свойствах объектов */
char _abrev[loct];     /* флаги: надо сокращенное описание */
unsigned _trvkey[loct]; /* таблица начала графа данной позиции */
unsigned _actkey[actw]; /*  -"-    -"-  реакции нa действие */
int nvoc;               /* число слов в словаре */
int _ktab[vocw];        /* числа - значение слов */
long _atab[vocw];       /* слова - по 4 буквы */
int rndini;
int loc;           /* текущая позиция */
int tally;         /* число еще не обнаруженных сокровищ */
int treasr;        /* номер 1-ого объекта-сокровища */
int rndini;        /* случайное число данной партии */
unsigned tevent;   /* указатель таблицы случайных событий */
unsigned eevent;   /* конец таблицы случайных событий */
unsigned tiniti;   /* -"-  -"- инициализации */
int _place[loct];  /* позиция объекта или -[индекс] */
char _fixed[fixt]; /* для фиксированных объектов */
char _prop[objt];  /* свойство объекта */
