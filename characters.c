#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "lists.h"
#include "characters.h"


lList* aloca_personagens() {

	lList* lista = aloca_list();

	FILE* arquivo = fopen("personagens.txt", "r");
	if (arquivo == NULL) {
		printf("Erro na leitura do arquivo!\n");
		exit(-1);
	}

	char* name = (char*) malloc(sizeof(char) * STR_SIZE);
	char* house = (char*) malloc(sizeof(char) * STR_SIZE);
	if (name == NULL || house == NULL) {
		printf("Erro de alocação em aloca_personagens()!\n");
		exit(-1);
	}

	int agility, strength, intelligence, health;

	while ( fscanf(arquivo, "%[^,], ", name) 		+
			fscanf(arquivo, "%[^,], ", house) 		+
			fscanf(arquivo, "%d, ", &agility) 		+
			fscanf(arquivo, "%d, ", &strength) 		+
			fscanf(arquivo, "%d, ", &intelligence) 	+
			fscanf(arquivo, "%d\n", &health)        == 6) {

		lPush(lista, character_create(name, house, agility, strength, intelligence, health));
	}

	fclose(arquivo);
	free(name);
	free(house);

	return lista;
}

/*****************************************************************************/
Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health) {

	Character* personagem = (Character*) malloc(sizeof(Character));

	personagem->name = (char*) malloc(sizeof(char) * STR_SIZE);
	personagem->house = (char*) malloc(sizeof(char) * STR_SIZE);
	if (personagem->name == NULL ||
		personagem->house == NULL  ) {
		printf("Erro de alocação em character_create()!\n");
		exit(-1);
	}

	strcpy(personagem->name, _name);
	strcpy(personagem->house, _house);
	personagem->agility = _agility;
	personagem->strength = _strength;
	personagem->intelligence = _intelligence;
	personagem->health = _health;

	return personagem;
}

/*****************************************************************************/
lList* sorteia_personagens(lList* lista_personagens) {

	srand(time(NULL));

	lList* lista_players = aloca_list();
	Character* atual;

	while (lista_players->size < 16) {
		
		atual = getDadoAtIndex(lista_personagens, rand() % lista_personagens->size);
		if (!hasDado(lista_players, atual)) {
			lPush(lista_players, atual);
		}
	}

	return lista_players;
}

/*****************************************************************************/
Character* escolhe_personagem(lList* lista_players) {

	Character* atual;

	printf("\t\tEscolha seu personagem\n\n");
	
	int i, index_escolhido, show_attr;
	for (i = 0; i < lista_players->size; i++) {

		atual = getDadoAtIndex(lista_players, i);
		show_attr = 1+(rand()%4);

		printf("Personagem %d:\n", i+1);

		if (show_attr == 1)
			printf("Agility: %d\t", atual->agility);
		else
			printf("Agility: ??\t");
	
		if (show_attr == 2)
			printf("Strength: %d\t", atual->strength);
		else
			printf("Strength: ??\t");
		
		if (show_attr == 3)
			printf("Intelligence: %d\t", atual->intelligence);
		else
			printf("Intelligence: ??\t");

		if (show_attr == 4)
			printf("Health: %d\n\n", atual->health);
		else
			printf("Health: ??\n\n");	
	}

	do {
		printf("Sua escolha: ");
		scanf("%d", &index_escolhido);
	} while (index_escolhido <= 0 || index_escolhido > 16);

	return getDadoAtIndex(lista_players, index_escolhido-1);

}

/*****************************************************************************/
t_player* inicializa_player(Character* personagem) {

	t_player* ponteiro = (t_player*) malloc(sizeof(t_player));
	if (ponteiro == NULL) {
		printf("Erro de alocação em inicializa_player()!\n");
		exit(-1);
	}

	ponteiro->chr = personagem;
	ponteiro->alive = true;
	ponteiro->last_used = 0;

	return ponteiro;
}

/*****************************************************************************/
void character_free(Character* character) {

	free(character->name);
	free(character->house);
	free(character);
}

/*****************************************************************************/
void print_player(t_player* player, Character* opponent) {

	printf("\nSeu personagem: %s da casa %s.\n", player->chr->name, player->chr->house);

	if (player->last_used == AGILITY)
		printf("\nX) X\t\t: XX");
	else
		printf("\n1: Agility\t: %d", player->chr->agility);

	if (player->last_used == STRENGTH)
		printf("\nX) X\t\t: XX");
	else
		printf("\n2: Strength\t: %d", player->chr->strength);

	if (player->last_used == INTELLIGENCE)
		printf("\nX) X\t\t: XX");
	else
		printf("\n3: Intelligence\t: %d", player->chr->intelligence);

	if (player->last_used == HEALTH)
		printf("\nX) X\t\t: XX\n");
	else
		printf("\n4: Health\t: %d\n", player->chr->health);

	printf("\nO adversário: %s da casa %s.\n", opponent->name, opponent->house);

}