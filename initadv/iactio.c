/* === iactio === read actions description === 13.02.85   version   10 */

/*  format: */
/*  +\ (action names-synonyms) */
/*  a  (actions conditions) */

#include "adv_ext.h"

void iactio()
{
    static int aw;

    if ((F3 = fopen("advactio", "r")) == NULL)
        fatal("cannot open 'advactio'");
    printf("actions words      :");
    while (getlin()) {
        if (LINE(1) == '+') {
            aw = aw + 1;
            p = 4 /* read list of words */;
            while (getwrd()) {
                if (vocab(_word) >= 0) {
                    printf("\n%s%.4s\n", "дважды определено: ", _word);
                    fatal(__func__);
                }
                nvoc = nvoc + 1;
                KTAB(nvoc) = aw + (ACTNWR * 1000);
                ATAB(nvoc) = *rword;
            }
            screen(aw);

        } else if (LINE(1) == 'a') {
            ACTKEY(aw) = putcnd();

        } else {
            printf("\n%s%.10s\n", "ошибка: ", &LINE(p));
            fatal(__func__);
        }
    }
    printf("%8d  %s %6d  %s\n", aw, "of", ACTW, "used");

    fclose(F3);
}
