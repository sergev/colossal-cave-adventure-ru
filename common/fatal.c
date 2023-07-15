/*
 * фатальная ошибка
 */
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "advexter.h"

void fatal(const char *message)
{
    write(1, "FATAL ERROR: ", 13);
    write(1, message, strlen(message));
    write(1, "\n", 1);
    exit(1);
}
