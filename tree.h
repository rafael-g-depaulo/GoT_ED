/**
 * @file tree.h
 * @author Rafael G. de Paulo
 * @date 23/11/17
 * 
 * @brief implementacao da arvore binária
 * 
 */

#ifndef _TREE_H_
#define _TREE_H_

#include "characters.h"

/**
 * @brief estrutura dos nós da arvore, e da árvore em si
 * 
 */
typedef struct node {
    Character* character;       /**< ponteiro para o personagem*/
    struct node* left;          /**< ponteiro para o filho esquerdo*/
    struct node* right;         /**< ponteiro para o filho direito*/
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

/**
 * @brief libera a memoria de uma arvore binaria
 * 
 * OBS: NÃO libera a memoria dos Character's dentro da arvore!
 * 
 * @param tree endereço da arvore
 */
void tree_free(t_node* tree);
/** EM DESENVOLVIMENTO ***************************/
void tree_print_preorder(t_node* tree);
/** EM DESENVOLVIMENTO ***************************/

#endif /* _TREE_H_ */