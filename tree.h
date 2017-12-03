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

/**
 * @brief imprime os personagens da arvore em preordem (não usado)
 * 
 * @param tree endereço da arvore
 */
void tree_print_preorder(t_node* tree);

/**
 * @brief descreve (imprime) as características de um personagem
 * 
 * usado como função auxiliar de tree_print_preorder();
 * 
 * @param chr endereço do personagem a ser descrito
 */
void printCharacter(Character* chr);

/**
 * @brief coloca os 16 primeiros personagens da lista nos nós folhas da arvore de forma recursiva
 * 
 * OBS: os 16 personagens da lista são liberados no processo
 * 
 * exemplo de uso:
 * @code
 *  // a lista que contem os personagens é char_list
 *  // e a arvore em que vão ser colocados é char_tree
 *  lList* aux = aloca_list();
 *  listCopy(aux, char_list);
 *  add_characters(char_tree, aux);
 *  libera_list(aux, 2);            
 *  // ^^^^ qualquer modo pode ser usado se char_list tiver
 *  // 16 personagens, mas por garantia usar o modo 2
 * @endcode
 * 
 * 
 * @param tree  endereço da arvore
 * @param chars endereço da lista
 */
void add_characters(t_node* tree, lList* chars);

#endif /* _TREE_H_ */