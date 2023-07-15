/* вывод сообщения по заданному адресу */

#include <fcntl.h>
#include <unistd.h>

#include "advexter.h"

#define blksiz 512
#define mask (~(blksiz - 1l))

#define TEXT_LOCAL_FILENAME "text.adv"
#define TEXT_SHARED_FILENAME "\advent\text.dat"
#define empty '>'

void mes(unsigned iadr)
{
    static int cb = -1;
    static char buf[blksiz + 1];
    register char *ptr, *zeroptr, *p;
    static long block = -1, nblock, adr;

    if (cb == -1) {
        if ((cb = open(TEXT_LOCAL_FILENAME, 0)) == -1) {
            if ((cb = open(TEXT_SHARED_FILENAME, 0)) == -1)
                fatal("cannot open '" TEXT_LOCAL_FILENAME "' or '" TEXT_SHARED_FILENAME "'");
        }
    }

    adr = (long)iadr * 2l;
    nblock = adr & mask;
    if (block != nblock) {
        block = nblock;
        lseek(cb, block, 0);
        read(cb, buf, blksiz);
    }

    ptr = &buf[(unsigned)(adr & (blksiz - 1l))];
    if (!*ptr)
        ++ptr;

    if (*ptr != empty) {
        for (;;) {
            for (zeroptr = ptr; *zeroptr; ++zeroptr)
                ;
            write(1, ptr, zeroptr - ptr);
            if (zeroptr != &buf[blksiz])
                break;
            read(cb, buf, blksiz);
            ++block;
            ptr = buf;
        }
    }
}
