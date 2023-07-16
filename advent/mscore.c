/* выдает счет и максимальный счет */

#include <stdio.h>
#include "advexter.h"

extern int moves;

void mscore(int score, int maxscore)
{
    printf("     %s", conv(score, 5, 10, ' '));
    printf("                   %s", conv(maxscore, 5, 10, ' '));
    printf("               %s\n", conv(moves, 5, 10, ' '));
}
