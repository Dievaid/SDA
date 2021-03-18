#include "list.h"
#include "utils.h"

#define L_MAX 20
/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param number - numarul pe care il are copilul
 * @param name - numele copilului
 * @param next  - adresa urmatorului nod
 * @return childNode* - nou nod creat
 */

childNode *makeChildNode(int number, const char *name, childNode *next)
{
    //TODO3.1: primul pas in implementarea cerintei 3
    childNode *newNode = NULL;
    newNode = (childNode *)malloc(sizeof(childNode));
    newNode->number = number;
    newNode->name = strdup(name);
    newNode->next = next;

    return newNode;
}

/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeChildNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return childNode* 
 */

void printList(childNode *list)
{
    childNode *head = list;
    do
    {
        printf("%s ", head->name);
        head = head->next;
    } while (head != list);
    printf("\n");
}

childNode *makeCircularList(FILE *file)
{
    //TODO2.2: al doilea pas in implementarea cerintei 3
    int number;
    char name[L_MAX];
    childNode *head = NULL;
    childNode *point;

    fscanf(file, "%d", &number);
    fscanf(file, "%s", name);
    head = makeChildNode(number, name, NULL);
    point = head;

    while (fscanf(file, "%d", &number) != EOF && fscanf(file, "%s", name) != EOF)
    {
        point->next = makeChildNode(number, name, NULL);
        point = point->next;
    }

    point->next = head;
    return head;
}

/**
 * @brief Functie ce 
 * 
 * @param head - capul listei ce reprezinta cercul de copii
 * @param p - pasul ce va fi luat pentru eliminarea copiilor
 * @return childNode* 
 */
childNode *playJosephGame(childNode *head, int p)
{
    // TODO3.3: se va return o lista creata prin adaugarea
    // cu complexitatea O(1) a copiilor in ordinea in care
    // sunt eliminati
    childNode *kick_order = NULL, *kick_head = NULL;
    childNode *dummy, *list = head;

    while (list->next != list) { //cat timp lista nu a ramas cu un singur element lista
        for (int i = 1; i < p; i++) {
            list = list->next;
        }//ne deplasam catre elementul dinaintea celuia pe care vrem sa il eliminam

        if(!kick_head) {
            kick_head = makeChildNode(list->next->number, list->next->name, NULL);
            kick_order = kick_head;
        }//daca lista e goala, capul listei va fi primul copil eliminat
        else {
            kick_order->next = makeChildNode(list->next->number, list->next->name, NULL);
            kick_order = kick_order->next;
        }//altfel se va alipi urmatorul copil selectat pentru eliminare listei

        //eliminam din lista copilul care a fost ales 
        dummy = list->next;
        list->next = list->next->next;
        free(dummy);

        list = list->next; // trecem la urmatorul copil
    }
    //adaugam ultimul copil ramas din lista
    kick_order->next = makeChildNode(list->next->number, list->next->name, NULL);
    kick_order = kick_order->next;
    
    //eliminam din lista ultimul copil
    free(list);
    return kick_head;
}
