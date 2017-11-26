#ifndef _TREE_H_
#define _TREE_H_

#include "characters.h"

typedef struct node {
    Character* character;
    struct node* left;
    struct node* right;
} t_node;

/**
 * @brief cria um nó da arvore e retorna ele
 * 
 *  cria um t_node, seta seus membros pra NULL, e retorna.
 * 
 * @return t_node* endereço do nó.
 */
t_node* node_create();

/**
 * @brief adiciona um nivel na arvore
 * 
 *  passa pela arvore, adicionando dois filhos em cada folha.
 * 
 * @param tree endereco da arvore;
 */
void add_level(t_node* tree);

/**
 * @brief cria uma arvore binária vazia completa de 4 níveis
 * 
 * @return t_node* endereco da arvore
 */
t_node* tree_create();

/** EM DESENVOLVIMENTO ***************************/
void tree_free();
void tree_print_preorder();
/** EM DESENVOLVIMENTO ***************************/

#endif /* _TREE_H_ */