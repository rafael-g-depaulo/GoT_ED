#ifndef __FIGHT_H_
#define __FIGHT_H_

#include <stdio.h>
#include <stdlib.h>
#include "characters.h"
#include "lists.h"
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

/**
 * @brief realiza uma luta entre os dois nos filhos de no, e coloca o vencedor em no
 * 
 * @param no        endereço do no cujos filhos lutarão
 * @param p1        endereço do player
 * @param log_list  lista dos logs das lutas
 */
void fight_node(t_node* no, t_player* p1, lList* log_list);

/**
 * @brief realiza um round da guerra
 * 
 * @param tree          endereço da arvore
 * @param p1            endereço do player
 * @param log_list[out] lista dos logs das lutas
 */
void fight_round(t_node* tree, t_player* p1, lList* log_list);

/**
 * @brief realiza a guerra
 * 
 * Enquanto o player esta vivo e não existe um vencedor da guerra, chama fight_round().
 * 
 * @param tree          endereço da arvore
 * @param p1            endereço do player
 * @param log_list[out] lista dos logs das lutas
 */
void war(t_node* tree, t_player* p1, lList* log_list);

/**
 * @brief coloca os personagens que vão jogar no último nivel da árvore
 * 
 * @param charList  lista contendo os 16 personagens que vão jogar
 * @param tree      a arvore de 4 níveis na qual os personagens serão inseridos
 */
void putChars_in_tree(lList* charList, t_node* tree);

//EM DESENVOLVIMENTO
//EM DESENVOLVIMENTO

#endif /* __FIGHT_H_ */