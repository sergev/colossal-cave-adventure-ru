/*d* === adventure === head modul == 07.01.85   version   25 */

#include "advexter.h"

int moves;

int main()
{
    int word1, word2, type1, type2;
    int oldob, oldobj;

    ini(); /* initiate data base */

    for (;;) {
        events(); /* случайные события */
        getans(&word1, &word2, &type1, &type2);
        ++moves;
        oldob = 0;

        if (type1 == SPECWR) { /* спец-слово */
            rspeak(word1);
        } else if (type2 == SPECWR) {
            rspeak(word2);

        } else if (type1 == MOVEWR) { /* передвижения */
            motion(word1);

        } else if (type2 == MOVEWR) {
            motion(word2);
        } else {
            if (type1 == OBJCWR) { /* объекта нет рядом */
                if (!here(word1))
                    goto L10;
            }
            if (type2 == OBJCWR) {
                if (!here(word2)) {
                L10:
                    rspeak(203);
                    goto L20;
                }
            }

            if (type1 == ACTNWR) {     /* действие + */
                if (type2 == OBJCWR) { /* + объект */
                    action(word1, word2);
                } else if (oldobj != 0) { /* + старый объект */
                    action(word1, oldobj);
                } else { /* + нет объекта */
                    action(word1, 255);
                }
            } else if (type2 == ACTNWR) { /* объект + действие */
                action(word2, word1);

            } else if (type1 == OBJCWR) { /* объект */
                rspeak(90);               /* что делать c ? */
                oldob = word1;
            }
        L20:;
        }
        oldobj = oldob;
    }
    return 0;
}
