#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 70

typedef struct {
	char* name;
	char* house;
	int agility;
	int strength;
	int intelligence;
	int health;
} Character;

//EU VOU DOXYGERAR ISSO LOGO LOGO PERAI
void aloca_personagens();

Character* character_create(char* _name, char* _house, int _agility, int _strength, int _intelligence, int _health);
