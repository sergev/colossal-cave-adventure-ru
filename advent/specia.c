/*d* === specia ===           07.01.85   version   13 */
/* обработка спецслучая #n */

#include <stdlib.h>

#include "advexter.h"

extern int drkfla;
extern int darkflag1;

void specia(int n)
{
    int flag, obj;

    switch (n) {
    case (2 - 1):
        goto L1;
    case (3 - 1):
        goto L2;
    case (4 - 1):
        goto L3;
    case (5 - 1):
        goto L4;
    case (6 - 1):
        goto L5;
    case (7 - 1):
        goto L6;
    case (8 - 1):
        goto L7;
    case (9 - 1):
        goto L8;
    case (10 - 1):
        goto L9;
    }
    fatal("bad special");

L1:
    exit(0); /* конец игры */

L2:
    score(); /* выдача счета игры */
    goto L100;

L3:
    score(); /* счет + конец */
    exit(0);

L4:
    abb = 1 /* только сокращения */;
    goto L100;

L5:
    flag = 0 /* invent */;
    for (obj = 1; obj <= OBJT; ++obj) {
        if (PLACE(obj) == CARIED) {
            if (flag == 0) {
                rspeak(99);
                flag = 1;
            }
            mes(PSTAT(PTEXT(obj)));
        }
    }
    if (flag == 0)
        rspeak(98);
    goto L100;

L6:
    drkfla = 0 /* look */;
    if (ABREV(loc) == 1)
        rspeak(15);
    descr2();
    ABREV(loc) = 1;
    goto L100;

L7:
    if (dark()) {
        darkflag1++;
        descr2(); /*@VG*/
    }             /* lamp on */
    goto L100;

L8:
    if (dark())
        rspeak(16); /* lamp off */
    goto L100;

L9:
    freeze(); /* freeze game */
    exit(0);

L100:;
}
