/*  === descr === describe current location */

#include "advexter.h"

static void ds(int n);

void descr()
{
    ds(0);
}

void descr2()
{
    ds(1);
}

void ds(int n)
{
    register int kk;

    if (n)
        goto L100;
    if (dark()) {
        rspeak(16);
    } else {
        kk = 0;
        if (ABREV(loc) != 0) {
            kk = STEXT(loc);
        } else {
        L100:
            kk = LTEXT(loc);
        }
        if (kk == 0)
            kk = LTEXT(loc);
        mes(kk);
        if (abb != 0) {
            ABREV(loc) = 2;
        } else {
            ABREV(loc) = (ABREV(loc) + 1) % 4;
        }
        indobj();
    }
}
