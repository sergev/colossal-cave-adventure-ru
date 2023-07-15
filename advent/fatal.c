/*
 * фатальная ошибка
 */
#include <stdlib.h>
#include <unistd.h>
#include "advexter.h"

void fatal(/*n*/)
{
    write(1, "FATAL ERROR: ", 13);
    //write(1, conv(n, 3, 10, ' '), 3);
    write(1, "\n", 1);
    exit(1);
}
