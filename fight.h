#ifndef __FIGHT_H_
#define __FIGHT_H_

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "characters.h"
#include "tree.h"

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

void fight_node(t_node* no, t_player* p1, lList* log_list);
void fight_round(t_node* tree, t_player* p1, lList* log_list);
void war(t_node* tree, t_player* p1, lList* log_list);
void putChars_in_tree(lList* charList, t_node* tree);

void print_player(t_player* player, Character* opponent);

//EM DESENVOLVIMENTO

#endif /* __FIGHT_H_ */