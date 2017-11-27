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
		printf("2: Strength\t: %d", player->chr->strength);

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

/*-----------------------------------------------------------------------------*/
void fight_node(t_node* no, t_player* p1, lList* log_list) {

	srand(time(NULL));

	// caso o PC esteja nessa luta
	if (p1->chr == no->left->character || p1->chr == no->right->character) {

		// pegando o personagem do player e o NPC
		Character* NPC;

		if (p1->chr == no->left->character)
			NPC = no->right->character;
		else
			NPC = no->left->character;

		// printar personagem e receber escolha de atributo
		print_player(p1, NPC);

		// escolha de atributo
		int atrib = 0;
		while (true) {
			printf("\nEscolha um atributo: ");
			scanf("%d", &atrib);
			
			if (atrib == 1 && p1->last_used != AGILITY)
				break;
			if (atrib == 2 && p1->last_used != STRENGTH)
				break;
			if (atrib == 3 && p1->last_used != INTELLIGENCE)
				break;
			if (atrib == 4 && p1->last_used != HEALTH)
				break;

			printf("\nEscolha invalida. Escolha de novo...");
		}

		// realize a luta
		Character* winner = fight(no->left->character, no->right->character, atrib);

		if (winner != p1->chr)
			p1->alive = false;

		no->character = winner;

	// caso seja uma luta de NPC's
	} else {
		int atrib = rand() % 4;
		no->character = fight(no->left->character, no->right->character, atrib);
	}
}

/*-----------------------------------------------------------------------------*/
void fight_round(t_node* tree, t_player* p1, lList* log_list) {
	
	// se exitem dois personagens que precisam lutar (condição de parada) 
	if (tree->left && tree->right && tree->left->character && tree->right->character) {
		fight_node(tree, p1, log_list);
		return;
	}

	// se o no da esquerda existe e esta vazio, percorra ele
	if (tree->left && !(tree->left->character))
		fight_round(tree->left, p1, log_list);

	// se o no da direita existe e esta vazio, percorra ele
	if (tree->right && !(tree->right->character))
		fight_round(tree->right, p1, log_list);
}

/*-----------------------------------------------------------------------------*/
void war(t_node* tree, t_player* p1, lList* log_list) {
	
	while (p1->alive && !(tree->character))
		fight_round(tree, p1, log_list);
}

/*-----------------------------------------------------------------------------*/
void putChars_in_tree(lList* charList, t_node* tree) {

	if (charList->size == 0)
		return;

	// se é folha
	if (!(tree->left || tree->right)) {
		tree->character = lPop(charList);
	// se não é folha	
	} else {
		putChars_in_tree(charList, tree->left);
		putChars_in_tree(charList, tree->right);
	}
}