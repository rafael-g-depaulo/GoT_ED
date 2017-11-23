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
void cPush(cList* list, Character* dado) {
    t_element* ele = (t_element*) malloc(sizeof(t_element));

    if (!ele) {
        printf("\nERRO: falha na alocacao de memoria em cPush()...");
        exit(-1);
    }

    ele->dado = (Character*) dado;

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

/*-----------------------------------------------------------------------------*/
lList* aloca_list() {
    
    lList* list = (lList*) malloc(sizeof(list));
    if (!list) {
        printf("\nERRO: falha na alocacao de memoria em aloca_list()...");
        exit(-1);
    }

    list->size = 0;
    list->first = NULL;
    list->last = NULL;

    return list;
}

/*-----------------------------------------------------------------------------*/
void lPush(lList* list, void* dado) {
    t_element* ele = (t_element*) malloc(sizeof(t_element));

    if (!ele) {
        priintf("\nERRO: falha na alocacao de memoria em lPush()...");
        exit(-1);
    }

    ele->dado = dado;

    list->last->next = ele;
    ele->prev = list->last;
    list->last = ele;

    list->size++;
}

/*-----------------------------------------------------------------------------*/
void* lPop(lList* list) {

    if (list->size == 0)
        return NULL;

    t_element* ele = list->first;
    void* dado     = list->first->dado;

    if (ele->next)
        ele->next->prev = NULL;
    
    list->first = ele->next;
    free(ele);

    return dado;
}

/*-----------------------------------------------------------------------------*/
void libera_list(lList* list) {

    while(lPop(list));
    free(list);
}

/*-----------------------------------------------------------------------------*/
Character* getDadoAtIndex(cList* list, int index) {
    if (!list || list->size == 0)
        return NULL;

    t_element* ele = list->first;

    int i = 0;
    while (i++ < index) 
        ele = ele->next;

    return (Character*) ele->dado;
}

/*-----------------------------------------------------------------------------*/
bool hasDado(lList* list, void* dado) {
    t_element* ele = list->first;
    bool retVal = false;
    int i;

    for (i = 1; i < list->size; i++)
        if (ele->dado == dado) {
            retVal = true;
            break;
        }
    
    return retVal;
}