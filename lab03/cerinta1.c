#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param data - informatia nodului respectiv
 * @param next - adresa urmatorului nod
 * @return node* nou nod creat
 */
node *makeNode(int data, node *next)
{
    node* newNode = NULL;
    newNode = (node*)malloc(sizeof(node)); //alocam memorie pentru nodul listei

    //Punem datele primite ca parametri ai functiei in memoria alocata pentru nod
    newNode->data = data; 
    newNode->next = next;

    return newNode;
}


/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return node* 
 */

node *makeList(FILE *file)
{
    int data;

    node* linked_list = NULL;
    node* aux;

    fscanf(file, "%d", &data);
    linked_list = makeNode(data, NULL); //memoram adresa de inceput a primului nod din lista
    aux = linked_list;

    while(fscanf(file, "%d", &data) != EOF) {
        if(aux->data < data) {
            aux = makeNode(data, linked_list); //adaugam un nod inaintea capului listei
            linked_list = aux; // actualizam capul listei
        }
    }
    return linked_list;
}


/**
 * @brief Functie ce afiseaza toate elementele unei liste
 *  
 * @param head - capul listei de afisat
 */
void print(node *head)
{
    node* node = head;
    while(node) {
        printf("%d ", node->data);
        node = node->next;
    }
}