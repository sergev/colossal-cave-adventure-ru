/* вывод сообщения по заданному адресу */

#include <fcntl.h>
#include <unistd.h>

#include "advexter.h"

#define BLKSIZ 512
#define MASK (~(BLKSIZ - 1l))

#define TEXT_LOCAL_FILENAME "text.adv"
#define TEXT_SHARED_FILENAME "/usr/local/share/advent/text.adv"
#define EMPTY '>'

void mes(unsigned iadr)
{
    static int cb = -1;
    static char buf[BLKSIZ + 1];
    register char *ptr, *zeroptr;
    static long block = -1, nblock, adr;

    if (cb == -1) {
        if ((cb = open(TEXT_LOCAL_FILENAME, 0)) == -1) {
            if ((cb = open(TEXT_SHARED_FILENAME, 0)) == -1)
                fatal("cannot open '" TEXT_LOCAL_FILENAME "' or '" TEXT_SHARED_FILENAME "'");
        }
    }

    adr = (long)iadr * 2l;
    nblock = adr & MASK;
    if (block != nblock) {
        block = nblock;
        lseek(cb, block, 0);
        read(cb, buf, BLKSIZ);
    }

    ptr = &buf[(unsigned)(adr & (BLKSIZ - 1l))];
    if (!*ptr)
        ++ptr;

    if (*ptr != EMPTY) {
        for (;;) {
            for (zeroptr = ptr; *zeroptr; ++zeroptr)
                ;
            write(1, ptr, zeroptr - ptr);
            if (zeroptr != &buf[BLKSIZ])
                break;
            read(cb, buf, BLKSIZ);
            ++block;
            ptr = buf;
        }
    }
}
