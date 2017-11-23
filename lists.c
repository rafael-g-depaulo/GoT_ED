#include "lists.h"

/*-----------------------------------------------------------------------------*/
cList* aloca_circ_list() {
    cList* list = (cList*) malloc(sizeof(cList));

    if (!list) {
        printf("\nERRO: falha na alocacao de memoria em aloca_circ_list()...");
        exit(-1);
    }

    list->size = 0;
    list->first = NULL;

    return list;
}

/*-----------------------------------------------------------------------------*/
void libera_circ_list(cList* list) {

    Character* chr;
    while (chr = cPop(list))
        character_free(chr);

    free(list);
}


/*-----------------------------------------------------------------------------*/
Character* cPop(cList* list) {

    if (list->size == 0) 
        return NULL;

    t_element* ele = list->first;
    Character* retVal = (Character*) ele->dado;

    if (list->size == 1) {
        list->first = NULL;
    } else {
        list->first->next->prev = list->first->prev;
        list->first->prev->next = list->first->next;
        list->first = list->first->next;
    }
    
    free(ele);
    list->size--;
    return retVal;
}

/*-----------------------------------------------------------------------------*/
void cPush(cList* list, Character* pers) {
    t_element* ele = (t_element*) malloc(sizeof(t_element));

    if (!ele) {
        printf("\nERRO: falha na alocacao de memoria em cPush()...");
        exit(-1);
    }

    if (list->size == 0) {
        list->first = ele;
        ele->next = ele;
        ele->prev = ele;
    } else {
        ele->next = list->first;
        ele->prev = list->first->prev;
        list->first->prev->next = ele;
        list->first->prev = ele;
    }

    list->size++;
}