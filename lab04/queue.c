#include "utils.h"
#include "queue.h"
#include "queue_node.h"


/**
 * @brief Functie ce aloca dinamic memorie pentru coada,
 *        initializand campurile front si rear
 * 
 * @param queue - pointerul ce trebuie modificat pentru
 *                a tine adresa nou alocata pentru coada
 */
void createQueue(Queue **queue)
{
    //TODO2.1: Functia va fi folosita pentru a initializa structura Queue
    *queue = (Queue*)malloc(sizeof(Queue));
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
}

/**
 * @brief Functie ce va fi folosita pentru a adauga un nod in coada queue
 * 
 * * Hint:
 *         * se va folosi functia createQueueNode pentru crearea unui nou nod
 *         * trebuie actualizati poniterii rear si front sau doar front
 *         * a se citi cursul :)
 * 
 * @param queue - coada in care trebuie adaugat un nou nod cu informatia data
 * @param data - datele noului nod
 */
void en(Queue *queue, char *data)
{
    //TODO2.3: adauga un nou nod in coada, noul nod are informatia data
    queue_node* newQueueNode = createQueueNode(data);
    
    if(isNull(queue->rear)) {
        queue->rear = newQueueNode;
    }
    else {
        queue->rear->next = newQueueNode;
        queue->rear = newQueueNode;
    }

    if(isNull(queue->front)) {
        queue->front = queue->rear;
    }
}

/**
 * @brief Functie ce scoate din coada urmatorul nod si
 *        returneaza datele stocate in nod.
 * * Hint:
 *        * a se citi cursul :)
 * 
 * @param queue - coada din care va fi scos nodul 
 * @return char* - datele din interiorul nodului
 */
char *de(Queue *queue){
    //TODO2.4: scoate urmatorul nod din coada si returneaza informatia acestuia
    queue_node* pDummy;
    char* dataDummy = NULL;

    if(!isEmptyQueue(queue)) {
        pDummy = queue->front;
        dataDummy = strdup(pDummy->data);

        queue->front = queue->front->next;
        deleteQueueNode(pDummy);
    }

    return dataDummy;
}

/**
 * @brief Functie ce va elibera memoria asociata fiecarui nod al cozi
 *  
 *  * Hint:
 *          * se poate folosi functia deleteQueueNode
 * @param queue - coada a carui noduri vor fi sterse
 */
void deleteQueue(Queue *queue){
    // Nice to have
    queue_node* dummy;
    while(!isEmptyQueue(queue)) {
        dummy = queue->front;
        queue->front = queue->front->next;
        deleteQueueNode(dummy);
    }
    free(queue);
}

/**
 * @brief Functie ce testeaza pointerii rear si front pentru 
 *        a determina daca coada este goala
 * 
 * @param queue - coada ce va fi testata
 * @return true/false - rezultatul verificarii
 */
bool isEmptyQueue(Queue *queue)
{
    //TODO2.5: Needed by the tests
    return isNull(queue->front);
}
