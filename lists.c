#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "characters.h"
#include "log.h"

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
        printf("\nERRO: falha na alocacao de memoria em lPush()...");
        exit(-1);
    }

    ele->dado = dado;

    if (!(list->first))
        list->first = ele;
    if (list->last)
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

    if (!ele) {
        printf("\nERRO: lPop() em lista vazia...");
        return NULL;
    }

    void* dado     = list->first->dado;

    if (list->size > 1) {
        ele->next->prev = NULL;
        list->first = ele->next;
    
    } else {
        ele->next = NULL;
        ele->prev = NULL;
        list->first = NULL;
        list->last = NULL;
    }

    free(ele);

    list->size--;
    return dado;
}

/*-----------------------------------------------------------------------------*/
void libera_list(lList* list, int modo) {
    void* dado = NULL;
    while ( (dado = lPop(list)) ) {
        
        if (modo == 2) {
            dado = (Character*) dado;
            character_free(dado);
        
        } else if (modo == 3) {
            dado = (t_log*) dado;
            log_free(dado);
        }
    }

    free(list);
}

/*-----------------------------------------------------------------------------*/
Character* getDadoAtIndex(lList* list, int index) {
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

    for (i = 0; i < list->size; i++) {
        if ((Character*) ele->dado == (Character*) dado) {
            retVal = true;
            break;
        }
        ele = ele->next;
    }
    
    return retVal;
}

/*-----------------------------------------------------------------------------*/
void listCopy(lList* dest, lList* src) {

    t_element* ele = src->first;

    while (dest->size < src->size) {
        lPush(dest, ele->dado);
        ele = ele->next;
    }
}