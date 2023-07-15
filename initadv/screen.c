/*
 * мигалка на экране
 */
#include <unistd.h>

#include "adv_ext.h"

void screen(int n)
{
    if (isatty(1)) {
        printf("%8d\b\b\b\b\b\b\b\b", n);
        //printf("%8d", n);
    }
}
