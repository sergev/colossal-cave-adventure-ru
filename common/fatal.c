/*
 * фатальная ошибка
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "advexter.h"

void fatal(const char *message)
{
    printf("FATAL ERROR: %s\n", message);
    exit(1);
}
