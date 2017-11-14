#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "characters.h"
#include "lists.h"


void aloca_personagens(cList* list) {

	FILE* arquivo = fopen(personagens.txt, "r");

	char* name = (char*) malloc(sizeof(char) * STR_SIZE);
	char* house = (char*) malloc(sizeof(char) * STR_SIZE);

	int agility, strength, intelligence, health;
	int i = 0;

	while (fscanf(arquivo, "%[^,], ", name) 		+
		fscanf(arquivo, "%[^,], ", house) 		+
		fscanf(arquivo, "%d, ", &agility) 		+
		fscanf(arquivo, "%d, ", &strength) 		+
		fscanf(arquivo, "%d, ", &intelligence) 	+
		fscanf(arquivo, "%d", &health) 		   == 6) {

		printf("ELEMENTO %d\n", i);
		printf("%s\n%s\n");
		}
			/*
			fclose(arquivo);
			printf("\nERRO: erro na leitura de personagens.txt");
			exit(-2);
			*/
	fclose(arquivo);

}

Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health) {

	Character* personagem = (Character*) malloc(sizeof(Character));

	personagem->name = (char*) malloc(sizeof(char) * STR_SIZE);
	personagem->house = (char*) malloc(sizeof(char) * STR_SIZE);

	strcpy(personagem->name, _name);
	strcpy(personagem->house, _house);
	personagem->agility = _agility;
	personagem->strength = _strength;
	personagem->intelligente = _intelligence;
	personagem->health = _health;

	return personagem;
}