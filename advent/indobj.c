/*d* === indobj ===        07.01.85   version   16 */
/* indicate objects at this location */

#include "advexter.h"

void indobj()
{
    int obj, kk, p;
    if (!dark()) {
        for (obj = 1; obj <= OBJT; ++obj) {
            if (PTEXT(obj) != 0) {
                kk = PROP(obj) & 0377;
                if (kk == INIPRO)
                    kk = 0;
                kk = PSTAT(PTEXT(obj) + kk + 1);
                p = PLACE(obj);

                if (p == loc) {                         /* подвижный объект */
                    if ((PROP(obj) & 0377) == INIPRO) { /* впервые увидел */
                        PROP(obj) = 0 /* сокровище */;
                        tally = tally - 1;
                    }
                    mes(kk);

                } else if (p < 0) { /* не -"- -"- */
                    p = -p;
                    while (FIXED(p) != 0) {
                        if ((FIXED(p) & 0377) == loc)
                            mes(kk);
                        p = p + 1;
                    }
                }
            }
        }
    }
}
