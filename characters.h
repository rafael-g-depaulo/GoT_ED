#ifndef _PERSONAGENSSKK_
#define _PERSONAGENSSKK_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STR_SIZE 70

typedef struct {
	char* name;
	char* house;
	int agility;
	int strength;
	int intelligence;
	int health;

} Character;


/**
 * @brief      É o ID do jogador (P1) ao longo do torneio.
 */
typedef struct {
	Character* player;
	bool alive;

} t_player;


/**
 * @brief      É o registro das lutas que ocorreram no torneio.
 * 
 * Cada elemento t_log guarda informações sobre as lutas passadas,
 * como os personagens envolvidos, a fase em que se enfrentaram
 * e o atributo usado.
 */
typedef struct {
	Character* player1;
	Character* player2;
	int round;
	//stat atributo;

} t_log;

/**
 * @brief      Lê o arquivo dos personagens e os armazena numa lista duplamente encadeada.
 * 
 * Depois de armazenar as informações de cada personagem em variáveis
 * locais, usa a função character_create para criar elementos do tipo Character
 * enquanto os armazena na lista.
 * 
 * @return     A lista com todos os personagens extraídos.
 */
void aloca_personagens();

/**
 * @brief      Cria um elemento de tipo Character contendo as informações obtidas no arquivo.
 *
 * @param      _name          O nome do personagem
 * @param      _house         A casa do personagem
 * @param[in]  _agility       Sua agilidade
 * @param[in]  _strength      Sua strength
 * @param[in]  _intelligence  Sua inteligência
 * @param[in]  _health        Sua saúde
 *
 * @return     Um ponteiro do elemento criado.
 */
Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health);


#endif