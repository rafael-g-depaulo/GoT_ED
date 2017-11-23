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

 typedef int Character;

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
 * @brief lista circular simplesmente encadeada
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
} list;

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
 * todos os elementos da lista são liberados com cPop() antes da lista
 * ser liberada, para garantir que não haja vazamento.
 * 
 * @param list endereco da lista a ser liberada
 */
void libera_circ_list(cList* list);

/**
 * @brief remove um elemento da lista circular e retorna o seu elemento
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
 * @brief insere um personagem na lista circular
 * 
 * insere um novo elemento na lista, em uma posição anterior à list->first.
 * list->first continua apontando para o mersmo elemento. list->first e seu anterior
 * mudam para apontar para o novo elemento, que aponta para pers
 * 
 * @param list endereco da lista 
 * @param pers endereco do personagem a ser inserido
 */
void cPush(cList* list, Character* pers);


// EM ANDAMENTO ***************************************
list* aloca_list();
void lPush(list* list, void* dado);
void* lPop(list* list);
void libera_list(list* list);
// EM ANDAMENTO ***************************************

#endif /* _LISTS_H_ */