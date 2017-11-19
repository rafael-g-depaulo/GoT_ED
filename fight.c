#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lists.h"
#include "characters.h"


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
t_log* log_create(Character* _player1, Character* _player2, int _round, Stat _atributo) {

	t_log* elemento = (t_log*) malloc(sizeof(t_log));

	elemento->player1 = _player1;
	elemento->player2 = _player2;
	elemento->round = _round;
	elemento->used_attr = _atributo;

	return elemento;
}