/*
 * фатальная ошибка
 */
#include <stdlib.h>
#include <unistd.h>

void fatal()
{
    write(2, "FATAL ERROR\n", 12);
    exit(1);
}
