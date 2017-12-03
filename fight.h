/**
 * @file characters.h
 * @author Luthiery C. Cavalcante, Rafael G. de Paulo
 * @date 26/11/17
 * 
 * @brief Arquivo contendo as funções e estruturas envolvendo os personagens do jogo.
 */

#ifndef __FIGHT_H_
#define __FIGHT_H_

#include <stdio.h>
#include <stdlib.h>
#include "characters.h"
#include "lists.h"
#include "tree.h"
#include "log.h"

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
 * @param round     o numero do round atual
 * @param log_list  lista dos logs das lutas
 */
void fight_node(t_node* no, t_player* p1, int round, lList* log_list);

/**
 * @brief realiza um round da guerra
 * 
 * @param tree          endereço da arvore
 * @param p1            endereço do player
 * @param round         o numero do round atual
 * @param log_list[out] lista dos logs das lutas
 */
void fight_round(t_node* tree, t_player* p1, int round, lList* log_list);

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

#endif /* __FIGHT_H_ */