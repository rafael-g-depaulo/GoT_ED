#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lists.h"
#include "characters.h"


cList* aloca_personagens() {

	cList* lista = aloca_circ_list();

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

	while (fscanf(arquivo, "%[^,], ", name) 		+
			fscanf(arquivo, "%[^,], ", house) 		+
			fscanf(arquivo, "%d, ", &agility) 		+
			fscanf(arquivo, "%d, ", &strength) 		+
			fscanf(arquivo, "%d, ", &intelligence) 	+
			fscanf(arquivo, "%d\n", &health)        == 6) {

		cPush(lista, character_create(name, house, agility, strength, intelligence, health));
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
void character_free(Character* character) {

	free(character->name);
	free(character->house);
	free(character);
}

/*****************************************************************************/
void f_character(void* character) {
	character_free( (Character*) character);
}

/*****************************************************************************/
t_player* inicializa_player(Character* personagem) {

	t_player* ponteiro = (t_player*) malloc(sizeof(t_player));

	ponteiro->character = personagem;
	ponteiro->alive = true;
	ponteiro->last_used = 0;

	return ponteiro;
}