/*d* === score === выдача счета игры        07.01.85   version    9 */

#include "advexter.h"

void score()
{
    int scor, maxsco, obj, i;

    scor = maxsco = 0;
    for (obj = treasr; obj <= OBJT; ++obj) {
        if (PLACE(obj) > 0) {
            maxsco = maxsco + 20;
            if (PLACE(obj) == 3 && PROP(obj) == 0) { /* сокровище в доме */
                scor = scor + 20;
            } else if ((PROP(obj) & 0377) != INIPRO) { /* сокровище видел */
                scor = scor + 5;
            }
        }
    }
    rspeak(32);
    mscore(scor, maxsco);

    obj = 1;
    for (i = 1; i <= PLCL; ++i)
        if (CVAL(i) && scor >= CVAL(i))
            obj = i;
    mes(CTEXT(obj));
}
