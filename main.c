#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "log.h"
#include "lists.h"
#include "characters.h"
#include "tree.h"
#include "fight.h"

int main() {
	
	// ler arquivo, criar a lista de personagens jogando e inicializar o player
	lList* all_char_list = aloca_personagens();
	lList* playing_list = sorteia_personagens(all_char_list);
	t_player* player1 = inicializa_player(escolhe_personagem(playing_list));

	// criar e inicializar a arvore
	t_node* tree = tree_create();
    lList* list_aux = aloca_list();
    listCopy(list_aux, playing_list);
	add_characters(tree, list_aux);
	libera_list(list_aux, 2);

	// criar a lista de logs (guarda o histórico da guerra)
	lList* log_list = aloca_list();

	// guerra
	war(tree, player1, log_list);

	// liberando memoria (e com sorte toda ela)
	free(player1);
	libera_list(playing_list, 1);
	libera_list(all_char_list, 2);
	tree_free(tree);

	return 0;
}