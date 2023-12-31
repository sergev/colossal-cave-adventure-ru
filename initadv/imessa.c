/*d* === imessa === read in messages === 07.01.85   version   13 */

/*  format: */
/*     (number) (message) */

#include <string.h>

#include "adv_ext.h"

void imessa()
{
    static char buf[4];
    static int nmes;

    if ((F3 = fopen("advmessa", "r")) == NULL)
        fatal("cannot open 'advmessa'");
    printf("random messages    :");
    while (getlin()) {
        strncpy(buf, _line, 3);
        sscanf(buf, "%d", &nmes);
        screen(nmes);
        if (RTEXT(nmes) != 0)
            printf("\nсообщение %d уже определено\n", nmes);
        RTEXT(nmes) = putmes();
    }
    printf("%8d  %s %6d  %s\n", nmes, "of", RANM, "used");
    fclose(F3);
}
