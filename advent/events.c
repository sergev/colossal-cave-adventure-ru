/*d* === treat events ===       19.01.85   version   10 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "advexter.h"

extern int actfla;
extern FILE *F1;

void events() {
    int actres;
    actfla=1;
    actres=act(tevent,0);
    actfla=0;
}

void ini() {
    int actres;
    time_t now;

    loadcm();

    if( (F1=fopen("frozen.adv","rb")) != NULL ) {
        loadfr();

    } else {
        time( &now );
        srand( now );
        loc=1;
        rndini=rand();
        actfla=1;
        actres=act(tiniti,0);
        actfla=0;
    }
    descr();
}
