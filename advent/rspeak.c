/*d* === rspeak ===       07.01.85   version    6 */
/* print the "random" message #n */

#include "advexter.h"

void rspeak(int n)
{
    unsigned adr = rtext(n);
    if (!adr)
        fatal("missing text");
    mes(adr);
}
