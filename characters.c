#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "characters.h"
#include "lists.h"


void aloca_personagens(cList* list) {

	FILE* arquivo = fopen(personagens.txt, "r");

	char* name, house;
	int agility, strength, intelligence, health;

	while (arquivo != EOF) { 	//essa condição tá certa?

		fscanf(arquivo, "%[^,], ", name);
		fscanf(arquivo, "%[^,], ", house);
		fscanf(arquivo, "%d, ", &agility);
		fscanf(arquivo, "%d, ", &strength);
		fscanf(arquivo, "%d, ", &intelligence);
		fscanf(arquivo, "%d", &health);
		
		cPush(list, character_create(name, house, agility, strength, intelligence, health));
	}

	fclose(arquivo);

}

Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health) {

	Character* personagem = (Character*) malloc(sizeof(Character));

	strcpy(personagem->name, _name);
	strcpy(personagem->house, _house);
	personagem->agility = _agility;
	personagem->strength = _strength;
	personagem->intelligente = _intelligence;
	personagem->health = _health;

	return personagem;
}