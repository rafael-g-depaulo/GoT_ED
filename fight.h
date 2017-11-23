#ifndef __FIGHT_H_
#define __FIGHT_H_

#include <stdio.h>
#include <stdlib.h>
#include "characters.h"
#include "lists.h"
#include "tree.h"


void fight_round(t_node* tree, t_player* player, int current_round, lList* log_list);

int choose_stat(t_player* player);

/**
 * @brief      Compara um mesmo atributo entre duas cartas e determina o vencedor da batalha.
 *
 * @param      fighter_one  O lutador da esquerda
 * @param      fighter_two  O lutador da direita
 * @param[in]  atribute     O atributo usado no confronto
 *
 * @return     O endereço do personagem vencedor.
 * @see #Character
 * @see #Stat
 */
Character* fight(Character* fighter_one, Character* fighter_two, int atribute);

void print_player(t_player* player, Character* opponent);

//EM DESENVOLVIMENTO

#endif /* __FIGHT_H_ */