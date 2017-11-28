/**
 * @file characters.h
 * @author Luthiery C. Cavalcante, Rafael G. de Paulo
 * @date 22/11/17
 * 
 * @brief Arquivo contendo as funções e estruturas envolvendo os personagens do jogo.
 */

#ifndef _PERSONAGENSS_
#define _PERSONAGENSS_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// includes aqui, por causa de dependencias com as estruturas
#include "lists.h"

/**
 * @brief      Lê o arquivo dos personagens e os armazena numa lista linear duplamente encadeada.
 * 
 * Depois de armazenar as informações de cada linha em variáveis
 * locais, usa a função character_create para criar elementos do tipo Character
 * enquanto os armazena na lista.
 * 
 * @return     A lista com todos os personagens extraídos.
 */
lList* aloca_personagens();

/**
 * @brief      Cria um elemento de tipo #Character contendo as informações obtidas em cada linha do arquivo.
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

/**
 * @brief      Cria uma lista com 16 personagens sorteados da lista maior.
 *
 * @param      lista_personagens A lista com todos os personagens, da qual serão extraídos 16.
 * @return     Uma lista com os 16 personagens a serem inseridos no torneio.
 */
lList* sorteia_personagens(lList* lista_personagens);

Character* escolhe_personagem(lList* lista_players);

/**
 * @brief      Pega o personagem escolhido pelo jogador e o define como Player1.
 * 
 * Esse "registro", que nos diz ao longo do jogo quem é o usuário,
 * nos fornece informações como o atributo usado na última luta
 * e se ele está vivo.
 *
 * @param      personagem  O personagem escolhido;
 * @return     O endereço da estrutura criada.
 */
t_player* inicializa_player(Character* personagem);

t_log* log_create(Character* _player1, Character* _player2, int _round, Stat _atributo);

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

/**
 * @brief 		imprime na tela o player e seu oponente
 * 
 * @param 		player 		endereço do player
 * @param 		opponent 	endereço do oponente
 */
void print_player(t_player* player, Character* opponent);

#endif /* _PERSONAGENSS_ */