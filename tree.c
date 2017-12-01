#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*-----------------------------------------------------------------------------*/
t_node* node_create() {
    t_node* node = (t_node*) malloc(sizeof(t_node));

    if (!node) {
        printf("\nERRO: erro na alocacao de memoria em node_create()...");
        exit(-1);
    }

    node->character = NULL;
    node->left      = NULL;
    node->right     = NULL;

    return node;
}

/*-----------------------------------------------------------------------------*/
void add_level(t_node* tree) {

    if (!(tree->left || tree->right)) {
        tree->left = node_create();
        tree->right = node_create();
    } else {
        add_level(tree->left);
        add_level(tree->right);
    }
}

/*-----------------------------------------------------------------------------*/
t_node* tree_create() {

    t_node* tree = node_create();

    int i;
    for (i = 0; i < 4; i++) {
        add_level(tree);
    }

    return tree;
}

/*-----------------------------------------------------------------------------*/
void tree_free(t_node* tree) {

    if (tree->left)
        tree_free(tree->left);
    if (tree->right)
        tree_free(tree->right);

    free(tree);

}

/*-----------------------------------------------------------------------------*/
void printCharacter(Character* chr) {
    if (!chr) {
        printf("null\n");
    } else {
        printf("\n%s, da casa %s, de stats %d, %d, %d e %d.", chr->name, chr->house,
            chr->health, chr->strength, chr->intelligence, chr->agility);
    }
}

/*-----------------------------------------------------------------------------*/
void tree_print_preorder(t_node* tree) {
    
    printCharacter(tree->character);

    if (tree->left)
        tree_print_preorder(tree->left);
    if (tree->right)
        tree_print_preorder(tree->right);
}

/*-----------------------------------------------------------------------------*/
void add_characters(t_node* tree, lList* chars) {

    if (!tree)
        return;

    if (tree->left || tree->right) {
        add_characters(tree->left, chars);
        add_characters(tree->right, chars);
    } else if (chars->size != 0) {
        tree->character = lPop(chars);
    } else {
        printf("\nERRO: lista de personagens jogando de tamanho insuficiente...");
    }
}