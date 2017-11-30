#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "log.h"

/*-----------------------------------------------------------------------------*/
t_log* create_log(Character* player1, Character* player2, int round, Stat used_attr) {

    t_log* log = (t_log*) malloc(sizeof(t_log));

    if (!log) {
        printf("\nERRO: falha na alocacao de memoria em create_log()...");
        exit(-1);
    }

    log->player1 = player1;
    log->player2 = player2;
    log->round = round;
    log->used_attr = used_attr;

    return log;
}

/*-----------------------------------------------------------------------------*/
void printLog(t_log* log, bool printRound) {

    if (printRound)
        printf("\nROUND %d:");

    int stat1, stat2;
    char* stat = (char*) malloc(20 * sizeof(char));

    switch (log->used_attr) {
        case AGILITY:
            strcpy(stat, "agility");
            stat1 = log->player1->agility;
            stat2 = log->player2->agility;
            break;
        case STRENGTH:
            strcpy(stat, "strenght");
            stat1 = log->player1->strength;
            stat2 = log->player2->strength;
            break;
        case INTELLIGENCE:
            strcpy(stat, "inteligence");
            stat1 = log->player1->intelligence;
            stat2 = log->player2->intelligence;
            break;
        case HEALTH:
            strcpy(stat, "health");
            stat1 = log->player1->health;
            stat2 = log->player2->health;
            break;
    }

    
    printf("\n%s (%d %s) x %s (%d %s)", log->player1->name, stat1,
        stat, log->player1->name, stat2, stat);
}