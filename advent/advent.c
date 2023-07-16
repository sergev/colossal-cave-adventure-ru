/*d* === adventure === head modul == 07.01.85   version   25 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "advexter.h"

int moves;

static void play()
{
    int word1, word2, type1, type2;
    int oldob, oldobj = 0;

    for (;;) {
        events(); /* случайные события */
        getans(&word1, &word2, &type1, &type2);
        ++moves;
        oldob = 0;

        if (type1 == SPECWR) { /* спец-слово */
            rspeak(word1);
        } else if (type2 == SPECWR) {
            rspeak(word2);

        } else if (type1 == MOVEWR) { /* передвижения */
            motion(word1);

        } else if (type2 == MOVEWR) {
            motion(word2);
        } else {
            if (type1 == OBJCWR) { /* объекта нет рядом */
                if (!here(word1))
                    goto L10;
            }
            if (type2 == OBJCWR) {
                if (!here(word2)) {
                L10:
                    rspeak(203);
                    goto L20;
                }
            }

            if (type1 == ACTNWR) {     /* действие + */
                if (type2 == OBJCWR) { /* + объект */
                    action(word1, word2);
                } else if (oldobj != 0) { /* + старый объект */
                    action(word1, oldobj);
                } else { /* + нет объекта */
                    action(word1, 255);
                }
            } else if (type2 == ACTNWR) { /* объект + действие */
                action(word2, word1);

            } else if (type1 == OBJCWR) { /* объект */
                rspeak(90);               /* что делать c ? */
                oldob = word1;
            }
        L20:;
        }
        oldobj = oldob;
    }
}

/*
 * Command line options.
 */
static struct option long_options[] = {
    // clang-format off
    /* option       has arg             flag    integer code */
    { "help",       no_argument,        0,      'h' },
    { "version",    no_argument,        0,      'V' },
    { "seed",       required_argument,  0,      's' },
    { 0 },
    // clang-format on
};

void usage(int status)
{
    printf("The Colossal Cave Adventure, Version %s\n", GAME_VERSION);
    printf("\n");
    printf("Usage:\n");
    printf("    advent [options]\n");
    printf("Options:\n");
    printf("    -h, --help             This message\n");
    printf("    -V, --version          Show version and exit\n");
    printf("    -s NUM, --seed=NUM     Fixed seed for the random generator\n");
    printf("\n");
    exit(status);
}

int main(int argc, char **argv)
{
    unsigned long seed = 0;

    /* Parse command line options. */
    for (;;) {
        switch (getopt_long(argc, argv, "-hVs:", long_options, 0)) {
        case EOF:
            break;
        case 0:
            continue;
        case 1:
            // No regular arguments expected.
            fprintf(stderr, "Unknown argument: %s\n", optarg);
            usage(EXIT_FAILURE);
        case 'h':
            // Show usage message and exit.
            usage(EXIT_SUCCESS);
        case 'V':
            // Show version and exit.
            printf("The Colossal Cave Adventure, Version %s\n", GAME_VERSION);
            exit(EXIT_SUCCESS);
        case 's':
            // Seed.
            seed = strtoul(optarg, 0, 0);
            continue;
        default:
            usage(EXIT_FAILURE);
        }
        break;
    }

    ini(seed); /* initiate data base */
    play();
    return 0;
}
