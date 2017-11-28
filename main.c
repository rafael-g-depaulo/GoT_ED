#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lists.h"
#include "characters.h"
#include "tree.h"
#include "fight.h"


int main() {
	
	lList* all_char_list = aloca_personagens();

	lList* playing_list = sorteia_personagens(all_char_list);

	t_player* player1 = inicializa_player(escolhe_personagem(playing_list));

	return 0;
}