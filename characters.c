#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "characters.h"
//#include "lists.h"


void aloca_personagens() {

	//cList lista = (char*) malloc(sizeof(char) * STR_SIZE);

	FILE* arquivo = fopen("personagens.txt", "r");
	if (arquivo == NULL) {
		printf("Erro na leitura do arquivo!\n");
		exit(-1);
	}

	char* name = (char*) malloc(sizeof(char) * STR_SIZE);
	char* house = (char*) malloc(sizeof(char) * STR_SIZE);

	int agility, strength, intelligence, health;
	int i = 0;

	while (fscanf(arquivo, "%[^,], ", name) 		+
			fscanf(arquivo, "%[^,], ", house) 		+
			fscanf(arquivo, "%d, ", &agility) 		+
			fscanf(arquivo, "%d, ", &strength) 		+
			fscanf(arquivo, "%d, ", &intelligence) 	+
			fscanf(arquivo, "%d\n", &health)        == 6) {

		//cPush(lista, character_create(name, house, agility, strength, intelligence, health));
	}

	fclose(arquivo);
	free(name);
	free(house);

	//return lista;
}


Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health) {

	Character* personagem = (Character*) malloc(sizeof(Character));

	personagem->name = (char*) malloc(sizeof(char) * STR_SIZE);
	personagem->house = (char*) malloc(sizeof(char) * STR_SIZE);

	strcpy(personagem->name, _name);
	strcpy(personagem->house, _house);
	personagem->agility = _agility;
	personagem->strength = _strength;
	personagem->intelligence = _intelligence;
	personagem->health = _health;

	return personagem;
}


void character_free(Character* character) {

	free(character->name);
	free(character->house);
	free(character);
}

Character* fight(Character* fighter_one, Character* fighter_two, int atribute) {

	Character* winner;

	switch(atribute) {

		case 1:
			if (fighter_one->agility >= fighter_two->agility)
				winner = fighter_one;
			else
				winner = fighter_two;
			break;

		case 2:
			if (fighter_one->strength >= fighter_two->strength)
				winner = fighter_one;
			else
				winner = fighter_two;
			break;
		
		case 3:
			if (fighter_one->intelligence >= fighter_two->intelligence)
				winner = fighter_one;
			else
				winner = fighter_two;
			break;

		case 4:
			if (fighter_one->health >= fighter_two->health)
				winner = fighter_one;
			else
				winner = fighter_two;
			break;
	}
	
	return winner;
}