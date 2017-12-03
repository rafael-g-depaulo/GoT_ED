#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "log.h"
#include "lists.h"
#include "characters.h"
#include "tree.h"
#include "fight.h"
#include "arts.h"

int main() {
	
	/* ler arquivo, criar a lista de personagens jogando e inicializar o player */
	lList* all_char_list = aloca_personagens();
	
	int menu;
	do {

		do {
			print_ArtMenu();
			printf("\t[1] Novo jogo\n");
			printf("\t[2] Sair\n");
			scanf("%d", &menu);

			char c;
			while ( (c = getc(stdin)) != '\0' && c != EOF && c != '\n');

		} while (menu != 1 && menu != 2);
		if (menu == 2)
			break;


		lList* playing_list = sorteia_personagens(all_char_list);
		t_player* player1 = inicializa_player(escolhe_personagem(playing_list));

		/* criar e inicializar a arvore */
		t_node* torneio = tree_create();
	    
	    lList* list_aux = aloca_list();
	    listCopy(list_aux, playing_list);		/* fazemos uma cópia da lista de personagens, pois a função add_characters */
		add_characters(torneio, list_aux);		/* remove os elementos da lista enquanto os insere na árvore */
		libera_list(list_aux, 2);				/* e não queremos que a lista original se perca, certo? */

		/* criar a lista de logs (guarda o histórico da guerra) */
		lList* log_list = aloca_list();

		/* chama guerra */
		war(torneio, player1, log_list);

		/* mostra as lutas após a guerra acabar */
		show_log(log_list);

		/* liberando memoria (e com sorte toda ela) */
		free(player1);
		libera_list(playing_list, 1);
		libera_list(log_list, 3);
		tree_free(torneio);

		do {
			printf("\n[1] Voltar ao menu principal\n");
			printf("[2] Sair\n");
			scanf("%d", &menu);

			char c;
			while ( (c = getc(stdin)) != '\0' && c != EOF && c != '\n');
		} while (menu != 1 && menu != 2);

	} while(menu == 1);

	libera_list(all_char_list, 2);

	return 0;
}