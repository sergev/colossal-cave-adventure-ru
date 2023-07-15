/*d* === функции sostoяния ===        07.01.85   version   19 */

/* dark()       - в данной точке темно */
/* at(object)   - здесь находится этот объект */

#include "advexter.h"

int darkflag1 = 0;

int dark()
{
    static int lamp, light;

    if (lamp == 0) { /* инициализация */
        lamp = (vocab("lamp") % 1000);
        light = (vocab("!light") % 1000);
    }
    if (darkflag1) /*@VG*/
        return (darkflag1 = 0);
    return (!at(light) && (!here(lamp) || PROP(lamp) == 0));
}

int at(int object)
{
    int _at, p;
    p = PLACE(object);
    _at = 0;
    if (p == loc) {
        _at = 1;
    } else if (p < 0) {
        p = -p;
        while (FIXED(p) != 0) {
            if ((FIXED(p) & 0377) == loc) {
                _at = 1;
                return (_at);
            }
            p = p + 1;
        }
    }
    return (_at);
}

int here(int object)
{
    return (PLACE(object) == CARIED || at(object));
}
