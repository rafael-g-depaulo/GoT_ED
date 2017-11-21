#include "lists.h"

/*-----------------------------------------------------------------------------*/
cList* aloca_circ_list() {
    cList* list = (cList*) malloc(sizeof(cList));

    if (!list) {
        printf("\nERRO: falha na alocacao de lista circular...");
        exit(-1);
    }

    list->size = 0;
    list->first = NULL;

    return list;
}

/*-----------------------------------------------------------------------------*/
void libera_circ_list(cList* list) {

    while (cPop(list));

    free(list);
}


/*-----------------------------------------------------------------------------*/
Character* cPop(cList* list) {
    t_element* ele = list->first;
    Character* retVal = ele->dado;

    list->first = ele->next;
    ele->prev->next = ele->next;
    ele->next->prev = ele->prev;

    free(ele);

    return retVal;
}

/*-----------------------------------------------------------------------------*/
void cPush(cList* list, Character* pers) {
    t_element
}