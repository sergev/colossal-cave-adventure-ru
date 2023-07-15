/* ввод следующего байта из файла данных  a=get() */
/* установ начального адреса чтения   iniget(adr) */

#include <stdio.h>
#include <stdlib.h>

#include "advexter.h"

#define DATA_LOCAL_FILENAME "data.adv"
#define DATA_SHARED_FILENAME "/usr/local/share/advent/data.adv"

static FILE *cb;
static char *bevents, *pevents;

void iniget(unsigned adr)
{
    if (cb == NULL) {
        if ((cb = fopen(DATA_LOCAL_FILENAME, "rb")) == NULL) {
            if ((cb = fopen(DATA_SHARED_FILENAME, "rb")) == NULL)
                fatal("cannot open '" DATA_LOCAL_FILENAME "' or '" DATA_SHARED_FILENAME "'");
        }
        bevents = (char *)malloc(eevent - tevent + 2);
        fseek(cb, (long)tevent, 0);
        fread(bevents, eevent - tevent, 1, cb);
    }

    if (tevent <= adr && adr < eevent) {
        pevents = bevents + (adr - tevent);
    } else {
        pevents = NULL;
        fseek(cb, (long)adr, 0);
    }
}

int get()
{
    char c;
    if (pevents == NULL) {
        fread(&c, 1, 1, cb);
    } else {
        c = *pevents++;
    }
    return (c & 0377);
}
