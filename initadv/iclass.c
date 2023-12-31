/*d* === iclass === read in class messages === 13.02.85   version    5 */

/*  format: */
/*     (number) (message) */

#include <string.h>

#include "adv_ext.h"

void iclass()
{
    static char buf[4];
    static int nmes;

    if ((F3 = fopen("advclass", "r")) == NULL)
        fatal("cannot open 'advclass'");
    printf("class messages     :");
    while (getlin()) {
        nmes = nmes + 1;
        screen(nmes);
        strncpy(buf, _line, 3);
        sscanf(buf, "%d", &CVAL(nmes));
        CTEXT(nmes) = putmes();
    }
    printf("%8d  %s %6d  %s\n", nmes, "of", PLCL, "used");
    fclose(F3);
}
