#include "lists.h"

/*-----------------------------------------------------------------------------*/
cList* aloca_circ_list() {
    cList* list = (cList*) malloc(sizeof(cList));

    if (!list) {
        printf("\nERRO: falha na alocacao de memoria em aloca_circ_list()...");
        exit(-1);
    }

    list->size = 0;
    list->last = NULL;

    return list;
}

/*-----------------------------------------------------------------------------*/
void libera_circ_list(cList* list) {

    while (cPop(list));

    free(list);
}


/*-----------------------------------------------------------------------------*/

// incompleto
Character* cPop(cList* list) {
    t_element* ele = list->last;
    Character* retVal = (Character*) ele->dado;

    list->last = ele->next;
    ele->prev->next = ele->next;
    ele->next->prev = ele->prev;

    free(ele);

    list->size--;
    return retVal;
}

/*-----------------------------------------------------------------------------*/

// incompleto
void cPush(cList* list, Character* pers) {
    t_element* ele = (t_element*) malloc(sizeof(t_element));

    if (!ele) {
        printf("\nERRO: falha na alocacao de memoria em cPush()...");
        exit(-1);
    }
    
    ele->dado = pers;

    list->last->next->prev = ele;
    ele->next = list->last->next;
    ele->prev = list->last;
    list->last->next = ele;
    list->last = ele;

    list->size++;
}