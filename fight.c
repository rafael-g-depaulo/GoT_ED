#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "log.h"
#include "lists.h"
#include "characters.h"
#include "tree.h"
#include "fight.h"
#include "arts.h"


/*-----------------------------------------------------------------------------*/
Character* fight(Character* fighter_one, Character* fighter_two, int atribute) {

	Character* winner;
	Stat atr = (Stat) atribute;

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

/*-----------------------------------------------------------------------------*/
void fight_node(t_node* no, t_player* p1, int round, lList* log_list) {

	/* caso o PC esteja nessa luta */
	if (p1->chr == no->left->character || p1->chr == no->right->character) {

		/* pegando o personagem do player e o NPC */
		Character* NPC;

		if (p1->chr == no->left->character)
			NPC = no->right->character;
		else
			NPC = no->left->character;

		/* printar personagem e receber escolha de atributo */
		if (round == 3) {
			printf("SEMIFINAL:\n");
		} else if (round == 4) {
			printf("FINAL:\n");
		} else {
			printf("ROUND %d:\n", round);
		}
		print_player(p1, NPC);

		/* escolha de atributo */
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

			char c;
			while ( (c = getc(stdin)) != '\0' && c != EOF && c != '\n');

			printf("\nEscolha invalida. Escolha de novo...");
		}

		/* realize a luta */
		Character* winner = fight(no->left->character, no->right->character, atrib);

		/* crie o log a guarde na lista */
		t_log* log = create_log(no->left->character, no->right->character, round, atrib);
		lPush(log_list, log);

		/* anuncie o resultado na tela */
		if (round == 3) {
			printf("\nSEMIFINAL:\n\n");
		} else if (round == 4) {
			printf("\nFINAL:\n\n");
		} else {
			printf("\nROUND %d:\n\n", round);
		}

		p1->last_used = (Stat) atrib;
		no->character = winner;

		if (winner != p1->chr) {
			p1->alive = false;
			print_ArtLose();
			printf("\nYou died...\n");
			printLog(log, false);
			printf("%s da casa %s foi vitorioso\n\n", NPC->name, NPC->house);

		} else {
			print_ArtWin();
		
			switch (round) {
				case 1:
					printf("\nVoce derrotou o inimigo, porém o inverno se aproxima, e a guerra também...\n");
					break;
				case 2:
					printf("\nA arte da guerra é sutil, e o caminho do aspirante ao trono é traiçoeiro.");
					printf("Hoje a vitoria é sua, mas poderá dizer isso de amanhã?\n");
					break;
				case 3:
					printf("\nNada mal... mas lembre-se que a pior queda vem do degrau mais alto.\n");
					break;
				case TREE_MAX_LEVEL:
					printf("\nVocê derrotou o inimigo, Vossa Majestade.\n");
					break;
				default:
					printf("Parabéns pela vitoria, mas ainda ha muita dificuldade pela frente");
					break;
			}

			printLog(log, false);
			
			if (round != 4) {
				printf("Pressione qualqer tecla pra continuar...");
				char c;
				while ( (c = getc(stdin)) != '\0' && c != EOF && c != '\n');
				scanf("%*c");
				system("clear");
			}
		}

	/* caso seja uma luta de NPC's */
	} else {
		int atrib = (rand() % 4)+1;
		no->character = fight(no->left->character, no->right->character, atrib);

		t_log* log = create_log(no->left->character, no->right->character, round, atrib);
		lPush(log_list, log);
	}
}

/*-----------------------------------------------------------------------------*/
void fight_round(t_node* tree, t_player* p1, int round, lList* log_list) {
	
	/* se exitem dois personagens que precisam lutar (condição de parada) */
	if (tree->left && tree->right && tree->left->character && tree->right->character) {
		fight_node(tree, p1, round, log_list);
		return;
	}

	/* se o no da esquerda existe e esta vazio, percorra ele */
	if (tree->left && !(tree->left->character))
		fight_round(tree->left, p1, round, log_list);

	/* se o no da direita existe e esta vazio, percorra ele */
	if (tree->right && !(tree->right->character))
		fight_round(tree->right, p1, round, log_list);
}

/*-----------------------------------------------------------------------------*/
void war(t_node* tree, t_player* p1, lList* log_list) {
	
	int round = 1;
	while (p1->alive && !(tree->character))
		fight_round(tree, p1, round++, log_list);

	if (p1->alive)
		printf("%s da casa %s foi vitorioso e agora é o novo rei dos 7 reinos!\n",
			   p1->chr->name, p1->chr->house);
}