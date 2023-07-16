/* выдает сообщение 'n' и ждет ответа yes/no */

#include <stdio.h>
#include <stdlib.h>

#include "advexter.h"

int yes(int x)
{
    int c;
    char s[80];

beg:
    rspeak(x);

    for (;;) {
        if (!fgets(s, sizeof(s), stdin))
            exit(0);
        trim(s);

        if (s[0] == 0)
            goto quit;

        c = s[0];
        if (is_utf8(c)) {
            // Get utf8 symbol
            c = get_utf8(c, s[1]);
        }

        if (c == 'y' || c == 'Y' || c == CYRILLIC_SMALL_LETTER_DE ||
            c == CYRILLIC_CAPITAL_LETTER_DE) {
            x = 1;
            break;
        } else if (c == 'n' || c == 'N' || c == CYRILLIC_SMALL_LETTER_EN ||
                   c == CYRILLIC_CAPITAL_LETTER_EN) {
            x = 0;
            break;
        } else {
            rspeak(40);
        }
    }
    return (x);

quit:
    if (x != 22 && yes(22))
        exit(0);
    goto beg;
}
