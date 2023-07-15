#include <string.h>
#include "advexter.h"

void trim(char *s)
{
    int i=0;
    while((s[i]==' ')||(s[i]=='\t'))
        i++;
    strcpy(s,s+i);
}
