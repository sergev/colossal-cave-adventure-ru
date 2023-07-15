/* ВЫДАЧА СТАТИСТИКИ ПО ИСПОЛЬЗОВАНИЮ СЛОВАРЯ И ДР. */

#include "adv_ext.h"

extern char mesused[];
extern int mesimp;

static char stand_mes[] = { 9, 12, 13, 15, 16, 23, 32, 40, 60, 90, 98, 99, 203, 0 };

void stat()
{
    register int i, nm;
    register char *p;

    printf("vocabulary words   :");
    printf("%8d  %s %6d  %s\n", nvoc, "of", VOCW, "used");

    for (nm = 1, i = RANM; i--;)
        if (_rtext[i])
            ++nm;
    printf("messages           :");
    printf("%8d  %s %6d  %s\n", nm, "of", RANM, "used");

    for (i = LOCT; i--;) {
        switch (locused[i]) {
        case LOCGO:
            printf("позиция %d не описана\n", i + 1);
            break;
        case LOCDEF:
            printf("позиция %d недоступна\n", i + 1);
            break;
        }
    }

    for (p = stand_mes; *p; ++p) {
        if (!RTEXT((*p) & 0377)) {
            printf("стандартное сообщение %d не определено\n", i + 1);
        }
    }

    for (i = 1; i <= RANM - mesimp; ++i) {
        for (p = stand_mes; *p; ++p) {
            if (((*p) & 0377) == i + 1)
                goto st;
        }
        if (mesused[i] && !_rtext[i]) {
            printf("сообщение %d не определено\n", i + 1);
        }
        if (!mesused[i] && _rtext[i]) {
            printf("сообщение %d не используется\n", i + 1);
        }
    st:;
    }
}
