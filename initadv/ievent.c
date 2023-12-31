/*d* === ievent === read in initial actions === 07.01.85   version    9 */

/* format: */
/*    i  initialisation */
/*    e  events */

#include "adv_ext.h"

unsigned dpoint;

void ievent()
{
    if ((F3 = fopen("advevent", "r")) == NULL)
        fatal("cannot open 'advevent'");
    printf("initial + events   :");
    while (getlin()) {
        if (LINE(1) == 'i') {
            tiniti = putcnd();
        } else if (LINE(1) == 'e') {
            tevent = putcnd();
            eevent = dpoint;
        } else {
            printf("\n%s%.10s\n", "ошибка: ", &LINE(p));
            fatal(__func__);
        }
    }
    printf("%8d   + %6d bytes\n", tevent - tiniti, dpoint - tevent);
    fclose(F3);
}
