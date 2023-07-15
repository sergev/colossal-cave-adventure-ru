/*d* === motion + action ===           07.01.85   version   13 */
/* передвижения или действия в ответ на слова */
/* inp: verb   - глагол движения или действия */
/*      object - объект (если нет то =0) */

#include "advexter.h"

void action(int verb, int object)
{
    int kk;

    kk = actkey(verb);
    if (kk == 0 && verb != 1)
        fatal("bad action");
    if (!act(kk, object))
        rspeak(12); /* как применить слово? */
}

void motion(int verb)
{
    int kk;

    kk = trvkey(loc);
    if (kk == 0 && loc != 1)
        fatal("bad motion");
    if (!act(kk, verb)) {
        if (pct(50)) {
            rspeak(9); /* пути нет */
        } else {
            rspeak(12); /* как применить это слово здесь? */
        }
    }
}
