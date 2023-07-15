/*d* === putcnd ===   07.01.85   version   23 */
/* store conditions into "adv:data" direct access file */
/* первая строка уже загружена в 'line' */
/* return: address of first record */

#include "adv_ext.h"

extern FILE *F2;
extern unsigned dpoint;

static void condit(void);
static void outd(char bt);

int putcnd()
{
    unsigned _putcnd;
    static char mrk, mrk0;
    long f3pos;

    _putcnd = dpoint;
    mrk0 = LINE(1);
    do {
        mrk = LINE(1);
        if (mrk != mrk0)
            break;
        p = 2;
        condit();
        f3pos = ftell(F3);
    } while (getlin());
    fseek(F3, f3pos, 0);
    outd(0);
    return (_putcnd);
}

/* === outd === */
/* output of one byte into file  "data.adv" */

void outd(char bt)
{
    fwrite(&bt, 1, 1, F2);
    dpoint = dpoint + 1;
}

/* === condit ===                              . */
/* analise condition & action line (line is 'lines' from 'lines(p)') */
/* format of line: (conditions items) = (actions items) */
/* put items into 'array' from 'array(ind+1)' */

/* format of condition:   marker (+/-) [object] [= number] */
/*   ==> o+bird  t-rod   p+cage=1  t- */
/*                  or:   w (+/-) (set of words) */
/*   ==> w+(up stream enter) */
/* internal format: kod+(+/-.bit)+(object.exist.bit) [object] [number] */
/*              or: kod+(+/_.bit)+(number.of.words) (list.of.words) */

/* format of action:      marker . [object] [= number] */
/*   ==> d.bird  t.  p.cage=0  m.98 */
/* internal format is the same exept (+/-.bit) */

int mesimp;
char mesused[RANM];

void condit()
{
    static int mark, lp, nwords, kod, i, obj, number;
    static int _words[30];
#define WORDS(x) _words[(x)-1]

#define NOT 128
#define ISOBJ 64

#define NCND (sizeof _cndcod)
#define NACT (sizeof _actcod)

#define CNDCOD(x) _cndcod[(x)-1]
    static char _cndcod[] = {
        /* === маркеры условий === */
        'o', /* об"ekt=заданному */
        'a', /* we are at object */
        'h', /* here is object */
        't', /* is toting object */
        '%', /* with probability=obj% */
        'p', /* PROP(obj)=n */
        'f', /* object is fixed */
        '+', /* .true. */
        'y', /* reply is "yes" */
        'l', /* location = obj */
        '>', /* carry > obj objects */
        '$', /* initial probability = obj% */
        'w'  /* one of next words - последний маркер !! */
    };

#define ACTCOD(x) _actcod[(x)-1]
    static char _actcod[] = {
        /* === маркеры действий === */
        'd', /* drop object */
        '*', /* destroy object */
        'c', /* carry object */
        'm', /* messane #n (  1 <= n < 256 ) */
        'm', /*    ...     (256 <= n < 512 ) */
        'p', /* let PROP(obj)=n */
        'l', /* change location to #n */
        '#', /* special case #n */
        't', /* throw object to location #n */
        'a', /* add 1 to PROP(obj) */
        'i', /* indicate objects at location */
        'n', /* смена объекта и повторный анализ */
        '"', /* message with address - послендний маркер !! */
    };

    while (scan() && LINE(p) != '=') { /* анализ условий */
        mark = LINE(p);
        p = p + 1; /* ... mapkep */
        for (kod = 1; kod <= NCND; ++kod) {
            if (mark == CNDCOD(kod))
                goto L10;
        }
        goto L999;
    L10:

        lp = LINE(p);
        p = p + 1 /* ... + / - */;
        if (lp == '-') {
            kod = kod + NOT ;
        } else if (lp != '+') {
        L999:
            printf("\n%s%.10s\n", "ошибка в условии: ", &LINE(p));
            return;
        }

        if (LINE(p) == '(') { /* many words (spec.case) */
            p = p + 1;
            nwords = 0;
            for (;;) {
                if (!scan())
                    goto L999;
                if (LINE(p) == ')')
                    break;
                nwords = nwords + 1;
                WORDS(nwords) = getobj();
            }
            p = p + 1;
            outd(kod + nwords);
            for (i = 1; i <= nwords; ++i)
                outd(WORDS(i));

        } else { /* стандартное условие */
            obj = 0 /* ... об"ekt (если есть) */;
            if (LINE(p) != ' ' && LINE(p) != '=') {
                obj = getobj();
                kod = kod + ISOBJ;
            }

            number = 0 /* ... число (если есть) */;
            if (LINE(p) == '=') {
                p = p + 1;
                number = getobj() + 1;
            }

            outd(kod);
            if (obj > 0)
                outd(obj);
            if (number > 0)
                outd(number);
        }
        if (mark == 'y')
            mesused[obj - 1] = 1;
    }
    outd(0);

    p = p + 1;
    while (scan()) { /* анализ действий */
        mark = LINE(p);
        p = p + 2 /* ... mapkep */;
        for (kod = 1; kod <= NACT; ++kod) {
            if (mark == ACTCOD(kod))
                goto L20;
        }
        goto L999;
    L20:
        obj = number = 0;
        if (mark == '"') { /* ... сообщение b след.ctp */
            if (!getlin())
                goto L999;
            obj = RANM - mesimp;
            kod = 4 + ISOBJ;
            mark = 'm';
            RTEXT(obj) = putmes();
            mesimp = mesimp + 1;
            p = INPLEN + 1;

        } else {
            if (LINE(p) != ' ' && LINE(p) != '=') { /* об"ekt */
                obj = getobj();
                kod = kod + ISOBJ;
            }

            if (LINE(p) == '=') { /* число */
                p = p + 1;
                number = getobj() + 1;
            }
        }

        if (mark == 'm')
            mesused[obj - 1] = 1;
        if (mark == 'l')
            locused[obj - 1] |= LOCGO;

        if (mark == 'm' && obj >= 256) { /* спецслучай */
            ++kod;
            obj -= 255;
        }

        outd(kod);
        if (obj > 0)
            outd(obj);
        if (number > 0)
            outd(number);
    }
    outd(0);
}
