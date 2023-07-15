/*d* === iobjec === read in cave description === 13.02.85   version   11 */

/*  format: */
/*     +  WORD(s) to name object */
/*     i  invent message (for movable objects) */
/*     0,1.. object in various state */
/*     s  initial state (in <>0) */
/*     l  initial location (for movable objects) */
/*     f  initial location(s) for fixed objects */
/*     =  separate treasures */

#include "adv_ext.h"

void iobjec()
{
    static int mark, object, indstt, posit, indfix;

    if ((F3 = fopen("advobjec", "r")) == NULL)
        fatal("cannot open 'advobjec'");
    printf("objects description:");
    while (getlin()) {
        mark = LINE(1);
        p = 4;

        if (mark == '+') { /* имена об"ektob */
            object = object + 1;
            while (getwrd()) {
                if (vocab(_word) >= 0) {
                    printf("\n%s%.4s\n", "дважды определено: ", _word);
                    fatal(__func__);
                }
                nvoc = nvoc + 1;
                KTAB(nvoc) = object + (OBJCWR * 1000);
                ATAB(nvoc) = *rword;
            }
            screen(object);
            if (treasr >= 1) {
                PROP(object) = (char)INIPRO;
                tally = tally + 1;
            }

        } else if (mark == '=') { /* пошли об"екты-сокровища */
            treasr = object + 1;

        } else if (mark == 'i') { /* сообщения o несомых */
            indstt = indstt + 1;
            PTEXT(object) = indstt;
            PSTAT(indstt) = putmes();

        } else if (mark >= '0' && mark <= '9') { /* o состояниях */
            indstt = indstt + 1;
            PSTAT(indstt) = putmes();

        } else if (mark == 's') { /* начальное состояние */
            PROP(object) = getobj();

        } else if (mark == 'l') { /* начальная позиция: */
            PLACE(object) = getobj() /*   подвижного об"ekta */;

        } else if (mark == 'f') { /*   фиксированного */
            PLACE(object) = -(indfix + 1);
            for (;;) {
                posit = getobj();
                if (!(posit >= 1))
                    break;
                indfix = indfix + 1;
                FIXED(indfix) = posit;
            }
            indfix = indfix + 1;
            FIXED(indfix) = 0;

        } else {
            printf("\n%s%.10s\n", "ошибка: ", &LINE(p));
            fatal(__func__);
        }
    }
    printf("%8d  %s %6d  %s\n", object, "of", OBJT, "used");

    printf("fixed objects posit:");
    printf("%8d  %s %6d  %s\n", indfix, "of", FIXT, "used");

    printf("objects states     :");
    printf("%8d  %s %6d  %s\n", indstt, "of", STTT, "used");

    fclose(F3);
}
