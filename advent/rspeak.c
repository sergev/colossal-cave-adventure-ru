/*d* === rspeak ===       07.01.85   version    6 */
/* print the "random" message #n */

#include "advexter.h"

void rspeak(int n)
{
    register unsigned adr;
    if (!(adr = rtext(n)))
        fatal(/*3*/);
    mes(adr);
}
