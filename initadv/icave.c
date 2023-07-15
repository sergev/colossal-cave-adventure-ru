/*d* === icave === read in cave description === 07.01.85   version    6 */

/*  format: */
/*  +\ (location number) */
/*  s  (short description) */
/*  l  (long description) */
/*  t  (travel conditions) */

#include "adv_ext.h"

char locused[LOCT];

void icave()
{
    static int lc;

    if ((F3 = fopen("advcave", "r")) == NULL)
        fatal("cannot open 'advcave'");
    printf("cave locations     :");
    while (getlin()) {
        if (LINE(1) == '+') {
            p = 3;
            lc = getobj();
            if (lc < 0) {
            L999:
                printf("\n%s%.10s\n", "icave: ошибка: ", &LINE(p));
                fatal(__func__);
            }
            screen(lc);
            if (locused[lc - 1] & LOCDEF) {
                printf("\nпозиция %d уже определена\n", lc);
            }
            locused[lc - 1] |= LOCDEF;
        } else if (LINE(1) == 's') {
            STEXT(lc) = putmes();
        } else if (LINE(1) == 'l') {
            LTEXT(lc) = putmes();
        } else if (LINE(1) == 't') {
            TRVKEY(lc) = putcnd();
        } else {
            goto L999;
        }
    }
    printf("%8d  %s %6d  %s\n", lc, "of", LOCT, "used");
    fclose(F3);
}
