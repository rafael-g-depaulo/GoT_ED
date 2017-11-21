#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "lists.h"
#include "characters.h"
#include "tree.h"
#include "fight.h"


Character* fight(Character* fighter_one, Character* fighter_two, int atribute) {

	Character* winner;
	Stat atr = atribute;

	switch(atr) {

		case AGILITY:
			if (fighter_one->agility >= fighter_two->agility)
				winner = fighter_one;
			else
				winner = fighter_two;
			break;

		case STRENGTH:
			if (fighter_one->strength >= fighter_two->strength)
				winner = fighter_one;
			else
				winner = fighter_two;
			break;
		
		case INTELLIGENCE:
			if (fighter_one->intelligence >= fighter_two->intelligence)
				winner = fighter_one;
			else
				winner = fighter_two;
			break;

		case HEALTH:
			if (fighter_one->health >= fighter_two->health)
				winner = fighter_one;
			else
				winner = fighter_two;
			break;
	}
	
	return winner;
}

/*****************************************************************************/
void print_player(t_player* player, Character* opponent) {

	printf("Seu personagem: %s da casa %s\n", player->chr->name, player->chr->house);

	if (player->last_used == AGILITY)
		printf("X) X\t: XX\n");
	else
		printf("1: Agility\t: %d", player->chr->agility);

	if (player->last_used == STRENGTH)
		printf("X) X\t: XX\n");
	else
		printf("2: Strength\t: %d", player->chr->strenth);

	if (player->last_used == INTELLIGENCE)
		printf("X) X\t: XX\n");
	else
		printf("3: Intelligence\t: %d", player->chr->intelligence);

	if (player->last_used == HEALTH)
		printf("X) X\t: XX\n");
	else
		printf("4: Health\t: %d", player->chr->health);

	printf("O adversário: %s da casa %s\n", opponent->name, opponent->house);

}
