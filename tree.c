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


void printCharacter(Character* chr) {
    if (!chr) {
        printf("null\n");
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