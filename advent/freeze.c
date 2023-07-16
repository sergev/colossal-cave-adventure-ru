/*d* === freeze ===             19.01.85   version    9 */
/* freeze game into file 'frozen.adv' */

#include <stdio.h>
#include <unistd.h>

#include "advexter.h"

extern FILE *F1;

static void write_f1(const void *ptr, unsigned size)
{
    if (fwrite(ptr, size, 1, F1) != 1)
        fatal("fwrite failed");
}

static void read_f1(void *ptr, unsigned size)
{
    if (fread(ptr, size, 1, F1) != 1)
        fatal("fread failed");
}

void freeze()
{
    F1 = fopen("frozen.adv", "wb");
    if (!F1)
        fatal("cannot create 'frozen.adv'");
    write_f1(&abb, sizeof abb);
    write_f1(_abrev, sizeof _abrev);
    write_f1(&loc, sizeof loc);
    write_f1(&tally, sizeof tally);
    write_f1(_place, sizeof _place);
    write_f1(_prop, sizeof _prop);
    write_f1(&rndini, sizeof rndini);
    write_f1(&tevent, sizeof tevent);
    write_f1(&tiniti, sizeof tiniti);
    fclose(F1);
}

/* === loadfr === */
/* load frozen game from file 'adv:frozen' */

void loadfr()
{
    read_f1(&abb, sizeof abb);
    read_f1(_abrev, sizeof _abrev);
    read_f1(&loc, sizeof loc);
    read_f1(&tally, sizeof tally);
    read_f1(_place, sizeof _place);
    read_f1(_prop, sizeof _prop);
    read_f1(&rndini, sizeof rndini);
    read_f1(&tevent, sizeof tevent);
    read_f1(&tiniti, sizeof tiniti);
    fclose(F1);
    unlink("frozen.adv");
}
