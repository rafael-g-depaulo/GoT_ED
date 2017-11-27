/**
 * @file list.h
 * @author Rafael G. de Paulo
 * @date 21/11/17
 * 
 * @brief implementacao da lista duplamente encadeada linear e lista duplamente encadeada circular
 * 
 */

 #ifndef _LISTS_H_
 #define _LISTS_H_

 #include <stdlib.h>
 #include <stdbool.h>

/**
 * @brief elemento da lista duplamente encadeada, circular e linear
 * 
 */
typedef struct element {
    void* dado;             /**< o dado guardado*/
    struct element* next;   /**< ponteiro para o proximo elemento na lista*/
    struct element* prev;   /**< ponteiro para o elemento anterior na lista*/
} t_element;

/**
 * @brief lista circular duplamente encadeada.
 * 
 * a lista circular é usada somente para guardar a lista de todos os personagens que existem em personagens.txt, 
 * a natureza circular da lista vai tornar um pouco mais simples a seleção de 16 personagens aletórios.
 * 
 * a lista aponta para um dos elementos, e cada um dos elementos aponta para o anterior elemento e o anterior, de forma
 * que a lista possa dar um "loop" em si mesma, conectando o final ao inicio
 */
typedef struct {
    int size;            /**< a quantidade de elementos na lista*/
    t_element* first;    /**< ponteiro para o primeiro elemento da fila*/
} cList;

/**
 * @brief lista linear duplamente encadeada
 * 
 * a lista linear é usada para guardar o log das lutas, e guardar a lista de personages jogando, por isso
 * dado é um (void*)
 * 
 * a lista aponta para o primeiro elemento, que aponta para NULL e para o próximo elemento.
 * todos os elementos a partir daí apontam para o elemento aterior e o próximo, com excessão do
 * último, que aponta para o anterior e para NULL. 
 * 
 */
typedef struct {
    int size;            /**< a quantidade de elementos na lista*/
    t_element* first;    /**< ponteiro para o primeiro elemento*/
    t_element* last;     /**< ponteiro para o ultimo elemento*/
} lList;


// includes aqui, por causa de dependencias com as estruturas
 #include <stdlib.h>
 #include <stdbool.h>
 #include "characters.h"

/**
 * @brief funcao que aloca dinamicamente uma lista circular
 * 
 * aloca uma lista circular vazia, com list->size = 0 e list->first = NULL.
 * exemplo de uso:
 * 
 * @code
 * cList* list = aloca_circ_list();
 * @endcode
 * 
 * @return cList* retorna o endereço para a lista alocada dinamicamente
 */
cList* aloca_circ_list();

/**
 * @brief funcao que libera uma lista circular alocada dinamicamente.
 * 
 * todos os elementos e Character* são liberados com cPop() e character_free()
 * antes da lista ser liberada, para garantir que não haja vazamento.
 * 
 * @param list endereco da lista a ser liberada
 */
void libera_circ_list(cList* list);

/**
 * @brief remove um elemento da lista circular e retorna o seu dado
 * 
 * remove list->first, e muda o elemento anterior e posterior a list->first
 * para apontarem um para o outro e manter a "circularidade" da lista.
 * muda o elemento apontado por list->first para ser o elemento posterior ao
 * anterior list->first
 * também diminui list->size em 1;
 * 
 * @param list endereco da lista
 * @return Character* o endereco do dado do elemento removido da lista, ou NULL se a lista estiver vazia 
 */
Character* cPop(cList* list);

/**
 * @brief insere um personagem na lista circular duplamente encadeada
 * 
 * insere um novo elemento na lista, em uma posição anterior à list->first.
 * list->first continua apontando para o mersmo elemento. list->first e seu anterior
 * mudam para apontar para o novo elemento, que aponta para pers
 * 
 * @param list endereco da lista 
 * @param dado endereco do personagem a ser inserido
 */
void cPush(cList* list, Character* dado);

/**
 * @brief funcao que aloca dinamicamente uma lista linear
 * 
 * aloca uma lista circular vazia, com list->size = 0, list->first = NULL
 * e list->last = NULL. exemplo de uso:
 * 
 * @code
 * lList* list = aloca_list();
 * @endcode
 * 
 * @return lList* retorna o endereço para a lista alocada dinamicamente
 */
lList* aloca_list();

/**
 * @brief insere um dado na lista linear duplamente encadeada
 * 
 * insere um novo dado, em um elemenento alocado dinamicamente,
 * no final da lista "list", mudando list->size e list->last apropriadamente.
 * 
 * @param list endereco da lista
 * @param dado endereco do dado a ser adicionado
 */
void lPush(lList* list, void* dado);

/**
 * @brief remove um elemento da lista linear e retorna seu dado
 * 
 * remove list->first da lista, mas e libera a sua memoria.
 * muda list->size, list->first e list->first->next->prev, adequadamente.
 * 
 * @param list endereco da lista
 * @return void* endereco do dado retirado da lista
 */
void* lPop(lList* list);

/**
 * @brief libera a lista linear alocada dinamicamente
 * 
 * todos os elementos são liberados com lPop() antes da lista ser liberada.
 * OBS: os elementos são liberados, mas os dados dentro deles só são liberados
 * (com a função freeDado) se freeDado != NULL. se freeDado == NULL, então os dados são ignorados.
 * 
 * @param list o endereco da lista
 * @param freeDado a funcao a ser usada para 
 */
void libera_list(lList* list, void (*freeDado)(void*));

/**
 * @brief retorna o dado no i-ésimo elemento a partir de list->first
 * 
 * realisa uma busca na lista, retornando o dado do i-ésimo próximo
 * elemento a partir de list->first
 * 
 * @param list  endereo da lista
 * @param i     indice do dado a ser recuperado
 * 
 * @return Character* dado recuperado
 */
Character* getDadoAtIndex(cList* list, int index);

/**
 * @brief checa se um dado esta presente na lista ou nao
 * 
 * checa todos os elementos da lista para ver se algum deles
 * aponta para dado. se sim, retorna true
 * 
 * @param list o endereco da lista
 * @param dado o endereco do dado
 * @return true  a variavel apontada por dado ja esta presente na lista
 * @return false a variavel apontada por dado não esta presente na lista
 */
bool hasDado(lList* list, void* dado);

// EM ANDAMENTO ***************************************
// EM ANDAMENTO ***************************************

#endif /* _LISTS_H_ */