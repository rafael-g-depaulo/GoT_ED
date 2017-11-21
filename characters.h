#ifndef _PERSONAGENSS_
#define _PERSONAGENSS_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lists.h"

#define STR_SIZE 50

/**
 * @brief      A principal estrutura do jogo, que guarda as informações de cada carta.
 */
typedef struct {
	char* name;
	char* house;
	int agility;
	int strength;
	int intelligence;
	int health;
} Character;

/**
 * @brief      Enumeração dos atributos dos personagens.
 */
typedef enum attributes {
	AGILITY = 1,
	STRENGTH,
	INTELLIGENCE,
	HEALTH
} Stat;

/**
 * @brief      É a estrutura que representa a carta do jogador (P1) ao longo do torneio.
 */
typedef struct {
	Character* chr;
	bool alive;
	Stat last_used;

} t_player;


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
 * @brief      Lê o arquivo dos personagens e os armazena numa lista circular duplamente encadeada.
 * 
 * Depois de armazenar as informações de cada linha em variáveis
 * locais, usa a função character_create para criar elementos do tipo Character
 * enquanto os armazena na lista.
 * 
 * @return     A lista com todos os personagens extraídos.
 */
cList* aloca_personagens();

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
 * @return     O endereço do elemento criado.
 */
Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health);

lList* sorteia_personagens(cList* lista_personagens);

/**
 * @brief      Pega o personagem escolhido pelo jogador e o define como Player1.
 * 
 * Esse "registro", que nos diz ao longo do jogo quem é o usuário,
 * nos fornece informações como o atributo usado na última luta.
 *
 * @param      personagem  O personagem escolhido;
 * @return     O endereço da estrutura criada.
 */
t_player* inicializa_player(Character* personagem);

/**
 * @brief      Libera memória referente a um elemento de tipo #Character.
 *
 * @param      character  O personagem a ser apagado
 * @return     Não há retorno.
 */
void character_free(Character* character);

/**
 * @brief 		Libera memória referente a um elemento de tipo #Character. (chamando character_free())
 * 
 * essa funcao é usada em libera_list()
 * 
 * @param character endereco do personagem a ser apagado
 */
void libera_character(void* character);

/**
 * @brief      Libera memória referente a um elemento de tipo #t_log.
 *
 * @param      log   Registro a ser apagado
 * @return     Não há retorno.
 */
void libera_log(void* log);


#endif /* _PERSONAGENSS_ */