/*
 * Преобразователь больших букв в маленькие.
 */
#include "advexter.h"

void to_lower(char *adr, int lgt)
{
    char c;

    while (lgt--) {
        c = *adr;
        if (c >= 'A' && c <= 'Z')
            *adr |= 040;
        /*      else if( (c&0300)==0300 )  *adr &= ~040; */
        ++adr;
    }
}
