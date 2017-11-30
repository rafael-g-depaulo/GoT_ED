/**
 * @file list.h
 * @author Rafael G. de Paulo
 * @date 27/11/17
 * 
 * @brief implementacao da estrutura auxiliar que guarda
 * a história de uma luta entre dois personagens
 * 
 */

#ifndef _WAR_LOG_H_
#define _WAR_LOG_H_

#include <stdbool.h>
#include <stdio.h>
#include "characters.h"

/**
 * @brief      Registra as batalhas que ocorreram ao longo do torneio.
 * 
 * Cada elemento t_log guarda informações sobre as lutas passadas,
 * como os personagens envolvidos, a fase em que se enfrentaram
 * e o atributo usado na ocasião.
 */
typedef struct {
	Character* player1;
	Character* player2;
	int round;
	Stat used_attr;

} t_log;

/**
 * @brief cria um log, alocado dinamicamente, e retorna seu endereço
 * 
 * @param player1   endereço do primeiro player participando do combate
 * @param player2   endereço do segundo player participando do combate
 * @param round     o numero do round em que a luta ocorreu
 * @param used_attr o atributo usado
 * 
 * @return t_log    o endereço do log criado
 */
t_log* create_log(Character* player1, Character* player2, int round, Stat used_attr);

/**
 * @brief imprime a informação do log informado
 * 
 * @param log           o endereço do log a ser imprimido
 * @param printRound    se é pra imprimir o numero do round ou não
 */
void printLog(t_log* log, bool printRound);

/**
 * @brief libera a memoria alocada para um log
 * 
 * @param log 			o endereço do log a ser liberado
 */
void log_free(t_log* log);

#endif /* _WAR_LOG_H_ */