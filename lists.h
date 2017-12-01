/**
 * @file list.h
 * @author Rafael G. de Paulo
 * @date 21/11/17
 * 
 * @brief implementacao da lista duplamente encadeada
 * 
 */

 #ifndef _LISTS_H_
 #define _LISTS_H_

 #include <stdlib.h>
 #include <stdbool.h>

/**
 * @brief elemento da lista duplamente encadeada
 * 
 */
typedef struct element {
    void* dado;             /**< o dado guardado*/
    struct element* next;   /**< ponteiro para o proximo elemento na lista*/
    struct element* prev;   /**< ponteiro para o elemento anterior na lista*/
} t_element;

/**
 * @brief lista duplamente encadeada
 * 
 * a lista é usada para armazenar todos os personagens selecionáveis, o log das lutas,
 * e guardar a lista de personagens jogando, por isso o dado é um (void*)
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
 #include "characters.h"
 #include "log.h"

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
 * OBS: os elementos da lista são liberados, mas se os dados referenciados por eles serão liberados
 * depende do modo usado.
 * 1 para não liberar os dados
 * 2 para liberar elementos #Character
 * 3 para liberar elementos #t_log
 * 
 * @param list o endereco da lista
 * @param freeDado a funcao a ser usada para 
 */
void libera_list(lList* list, int modo);

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
Character* getDadoAtIndex(lList* list, int index);

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

/**
 * @brief copia os dados de src, colocando eles em dest
 * 
 * não altera src. dest aponta para os mesmos dados de src, não para copias.
 * 
 * @param dest  lista que recebera a copia
 * @param src   lista que sera copiada
 */
void listCopy(lList* dest, lList* src);

#endif /* _LISTS_H_ */