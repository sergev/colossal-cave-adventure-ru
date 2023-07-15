/*d* === ivocab === read in vocabulary === 13.02.85   version   27 */

/*  format: */
/*     d         direction WORD(s) */
/*     s         special WORD(s).  after it is of message to produce */
/*     m         message */

/*  vocabulary: */
/*     common /vocab/ KTAB(VOCW),      % числа - значения слов */
/*                    ATAB(VOCW)       % слова - по 4 буквы */

#include "adv_ext.h"

extern int outt, mesimp;

void ivocab()
{
    static int direct, kword, mm, mark;

    if ((F3 = fopen("advvocab", "r")) == NULL)
        fatal("cannot open 'advvocab'");
    printf("vocabulary words   :");
    while (getlin()) {
        mark = LINE(1);
        if (mark == 'm') { /* message */
            RTEXT(mm) = putmes();
        } else {
            if (mark == 'd') { /* directional words */
                direct = direct + 1;
                kword = direct;
            } else if (mark == 's') { /* special words */
                mm = RANM - mesimp;
                kword = mm + (SPECWR * 1000);
                mesimp = mesimp + 1;
            } else {
                printf("\n%s%.10s\n", "неверный маркер: ", _line);
                fatal(__func__);
            }
            p = 4 /* read list of words */;
            while (getwrd()) {
                if (vocab(_word) >= 0) {
                    printf("\n%s%.4s\n", "дважды определено: ", _word);
                    fatal(__func__);
                }
                nvoc = nvoc + 1;
                KTAB(nvoc) = kword;
                ATAB(nvoc) = *rword;
                screen(nvoc);
            }
        }
    }
    printf("%8d  %s %6d  %s\n", nvoc, "of", VOCW, "used");
    fclose(F3);
}
