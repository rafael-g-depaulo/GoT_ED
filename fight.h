#ifndef __FIGHT_H_
#define __FIGHT_H_

#include <stdio.h>
#include <stdlib.h>

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

t_log* log_create(Character* _player1, Character* _player2, int _round, Stat _atributo);

//EM DESENVOLVIMENTO

#endif /* __FIGHT_H_ */