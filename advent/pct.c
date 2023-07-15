/*d* === probability = n% ===        07.01.85   version    2 */

#include <stdlib.h>

int pct(int n)
{
    int r;

    r = (rand() >> 2) & 037777;
    return ((r % 100) < n);
}
