#include "list.h"
#include "utils.h"


/**
 * @brief Functie ce elimina elementele cu informatii duplicate
 * Hint:
 *      * parcurgeti lista si modificati nodurile a.i sa elimi-
 *        nati duplicatele
 *      * daca capul listei nu se modifica va trebuii 
 *        sa il returnati
 * 
 * @param list - capul listei ce trebuie sa fie procesata
 * @return node* - returneaza capul listei
 */
node *removeDuplicates(node *list)
{
    //TODO2: metoda ce realizeaza eliminarea de noduri duplicate
    node *pList, *qList, *dummy;
    pList = list; 
    while (pList != NULL && pList->next != NULL) //cat timp exista cel putin un element cu care pot compara pozitia curenta in lista
    {
        qList = pList; 
        while (qList->next != NULL) // cat timp nu am ajuns la capatul listei
        {
            if (pList->data == qList->next->data) // comparam pozitia curenta cu cele urmatoare
            {
                //eliminam elementul duplicat
                dummy = qList->next;
                qList->next = qList->next->next;
                free(dummy);
            }
            else
                qList = qList->next; //trecem la urmatorul nod de dupa pozitia curenta
        }
        pList = pList->next; // actualizam pozitia curenta in lista
    }
    return list;
}
