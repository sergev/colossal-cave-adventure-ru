/*d* === getlin === 07.01.85   version    6 */
/* get next line from file #3, skip comments */
/* return: true  - ok,  p=0 */
/*         false - end of file */

#include "adv_ext.h"

long *rword = (long *)_word; /* equivalence (word,rword) */

int getlin()
{
    register int c, _getlin;

    _getlin = 0;
    do {
        for (p = 1; (c = getc(F3)) != EOF && c != '\n'; ++p) {
            if (c == '\t') {
                while (p % 8)
                    LINE(p++) = ' ';
                c = ' ';
            }
            LINE(p) = c;
        }
        if (c == EOF)
            goto L2;
        for (; p <= INPLEN; ++p)
            LINE(p) = ' ';
    } while (LINE(1) == '*' || (LINE(1) == ' ' && LINE(4) == ' '));
    _getlin = 1;
    p = 1;
L2:
    return (_getlin);
}

/* === getwrd === */
/* get next word from line 'line', from position 'p' */
/* return: true  - ok,  word is in 'WORD(4)', p - points to next */
/*         false - end of file */

int getwrd()
{
    register int i, _getwrd, ch, p0;

    _getwrd = 0;
    if (scan()) {
        _getwrd = 1;
        for (i = 4; i--;)
            WORD(i + 1) = ' ';
        p0 = p - 1;
        while (p <= INPLEN) {
            ch = LINE(p);
            if (!(ch != ' ' && ch != '=' && ch != ')'))
                break;
            if (p - p0 <= 4)
                WORD(p - p0) = LINE(p);
            p = p + 1;
        }
    }
    return (_getwrd);
}

/* === scan === */
/* ищет первый пробел в 'line' начиная c позиции 'p' */
/* return: true  - ok,  p - позиция не-пробела */
/*         false - end of file */

int scan()
{
    int _scan;

beg:
    _scan = 0;
    while (p <= INPLEN && LINE(p) == ' ')
        p = p + 1;
    if (p <= INPLEN)
        _scan = 1;
    if (LINE(p) == '\\') {
        if (!getlin())
            return (0);
        goto beg;
    }
    return (_scan);
}
