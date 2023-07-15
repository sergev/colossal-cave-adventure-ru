/*d* === init === adventure === 07.01.85   version  147 */

/* начальная обработка текстовых файлов данных и создание 3-x файлов */
/* прямого доступа: */
/*      text.adv    - c текстами сообщений */
/*      common.adv  - для инициализации common-блоков */
/*      data.adv    - c записанными данными пещеры */

/* данные описаны в следующих файлах: */
/*      advcave    - описание графа пещеры */
/*      advmessa   - тексты разнообразных сообщений */
/*      advvocab   - словарь */
/*      advobjec   - об'екты, их свойства, нач.положение ... */
/*      advclass   - квалификации игрока */
/*      advactio   - действия в ответ на различные глаголы */
/*      advevent   - начальные и случайные действия */

/* === открывает выходные файлы для tekctob и графа пещеры === */

#include <stdio.h>

#include "adv_ext.h"

int p;
char _line[INPLEN], _word[4]; /* buffer: for input line */
FILE *F3;
FILE *F2;

int main()
{
    printf("\n%s\n", "      adventure database initialising");
    printf("---------------------------------------------\n");
    if ((F2 = fopen("data.adv", "wb")) == NULL)
        fatal("cannot create 'data.adv'");

    /* === обработка входных файлов === */

    ivocab(); /* порядок 1-ых 3-x обязателен ! */
    iobjec();
    iactio();

    iclass(); /* в любом порядке (но после) */
    icave();
    imessa();
    ievent();

    stat();

    /* === create file adv_common === */

    savecm();
    printf("---------------------------------------------\n\n");
    return 0;
}
