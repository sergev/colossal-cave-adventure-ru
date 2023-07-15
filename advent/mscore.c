/* выдает счет и максимальный счет */

#include <unistd.h>

#include "advexter.h"

extern int moves;

void mscore(int score, int maxscore)
{
    write(1, "     ", 5);
    write(1, conv(score, 5, 10, ' '), 5);
    write(1, "                   ", 19);
    write(1, conv(maxscore, 5, 10, ' '), 5);
    write(1, "               ", 15);
    write(1, conv(moves, 5, 10, ' '), 5);
    write(1, "\n", 1);
}
