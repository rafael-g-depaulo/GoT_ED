/**
 * @file characters.h
 * @author Luthiery C. Cavalcante
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
	char* name;			/**< o nome do personagem */
	char* house;		/**< a casa a qual o personagem pertence */

	int agility;		/**< o atributo agilidade do personagem */
	int strength;		/**< o atributo forca do personagem */
	int intelligence;	/**< o atributo inteligencia do personagem */
	int health;			/**< o atributo energia(vida) do personagem */

} Character;

/**
 * @brief      Enumeração dos atributos dos personagens.
 */
typedef enum attributes {
	AGILITY = 1,	/**< o atributo agilidade */
	STRENGTH,		/**< o atributo forca */
	INTELLIGENCE,	/**< o atributo inteligencia */
	HEALTH			/**< o atributo energia(vida) */
} Stat;

/**
 * @brief      É a estrutura que representa a carta do jogador (P1) ao longo do torneio.
 */
typedef struct {
	Character* chr;		/**< o personagem que o player controla*/
	bool alive;			/**< se o player esta vivo ou morto*/
	Stat last_used;		/**< o ultimo atributo usado pelo player em uma luta*/

} t_player;

/* includes aqui, por causa de dependencias com as estruturas */
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

/**
 * @brief 		mostra para o player as opções de personagens, e retorna a escolha dele
 * 
 * Somente um atributo de cada personagem disponível (escolhido aleatóriamente) deve ser
 * mostrado ao player.
 * 
 * @param lista_players	lista com os 16 presonagens possíveis 
 * @return Character* 	referencia ao personagem escolhido
 */
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

/**
 * @brief      Libera memória referente a um elemento de tipo #Character.
 *
 * @param      character  O personagem a ser apagado
 * @return     Não há retorno.
 */
void character_free(Character* character);

/**
 * @brief 		imprime na tela o player e seu oponente
 * 
 * @param 		player 		endereço do player
 * @param 		opponent 	endereço do oponente
 */
void print_player(t_player* player, Character* opponent);

#endif /* _PERSONAGENSS_ */