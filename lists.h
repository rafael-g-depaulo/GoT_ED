/**
 * @file list.h
 * @author Rafael G. de Paulo
 * @date 21/11/17
 * 
 * @brief implementacao da lista duplamente encadeada linear e lista duplamente encadeada circular
 * 
 */

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
    t_element* last;     /**< ponteiro para o ultimo elemento da fila*/
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
    t_element* first;       /**< ponteiro para o primeiro elemento*/
    t_element* last;        /**< ponteiro para o ultimo elemento*/
} list;

/**
 * @brief funcao que aloca dinamicamente uma lista circular
 * 
 * "explicação mais profunda"
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
 * @brief remove um elemento da lista circular e rotorna o seu elemento
 * 
 * o elemento apontado por list->last->prev é removido da lista.
 * o elemento list->last aponta como seu next o do elemento removido,
 * e o anterior do elemento removido aponta para list->last.
 * depois disso list->size é atualizado, é liberada a memoria do elemento removido e e seu dado é retornado 
 * 
 * @param list endereco da lista
 * @return Character* o endereco do dado do elemento removido da lista 
 */
Character* cPop(cList* list);

/**
 * @brief insere um personagem na lista circular
 * 
 * é criado um elemento contendo pers, e esse elemento é inserido na lista, na posição last. (list->last)
 * o antigo list->last agora aponta para o novo elemento como seu next. e o novo elemento aponta para o antigo
 * list->last como seu anterior
 * 
 * @param list endereco da lista 
 * @param pers endereco do personagem a ser inserido
 */
void cPush(cList* list, Character* pers);