#ifndef _TREE_H_
#define _TREE_H_

#include "characters.h"

typedef struct node {
    Character* character;
    struct node* left;
    struct node* right;
} t_node;

/** EM DESENVOLVIMENTO ***************************/
t_node* node_create();
t_node* tree_create();
void tree_free();
void tree_print_preorder();
/** EM DESENVOLVIMENTO ***************************/

#endif /* _TREE_H_ */