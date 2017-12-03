#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "log.h"

void show_log(lList* log_list) {

    int i, round = 0;
    t_log* log;

    printf("\nA guerra até aqui:\n");
    for (i = 0; i < log_list->size; i++) {

        log = (t_log*) getDadoAtIndex(log_list, i);

        if (log->round != round) {
            printLog(log, true);            // o booleano aqui diz se devemos imprimir antes em que round estamos ou não
            round = log->round;
        } else {
            printLog(log, false);
        }
    }

    if (round != TREE_MAX_LEVEL) {
        printf("\nÉ uma pena que você não pode ver como isso acaba.\nAdeus...\n");
    }
}

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
        printf("\nROUND %d:\n", log->round);

    int stat1, stat2;
    char* stat = (char*) malloc(20 * sizeof(char));

    switch (log->used_attr) {
        case AGILITY:
            strcpy(stat, "agility");
            stat1 = log->player1->agility;
            stat2 = log->player2->agility;
            break;
        case STRENGTH:
            strcpy(stat, "strength");
            stat1 = log->player1->strength;
            stat2 = log->player2->strength;
            break;
        case INTELLIGENCE:
            strcpy(stat, "intelligence");
            stat1 = log->player1->intelligence;
            stat2 = log->player2->intelligence;
            break;
        case HEALTH:
            strcpy(stat, "health");
            stat1 = log->player1->health;
            stat2 = log->player2->health;
            break;
    }

    printf("%s (%d %s) vs. %s (%d %s)\n", log->player1->name, stat1,
        stat, log->player2->name, stat2, stat);

    free(stat);
}

/*-----------------------------------------------------------------------------*/
void log_free(t_log* fight_log) {
    free(fight_log);
}