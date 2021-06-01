#include "utils.h"

/**
 * TODO: Implementati o functie ce creaza un arbore balansat din datele
 * 	din fisierul f. Arborele nu trebuie sa respecte alta proprietate decat
 *  cea mentionala anterior 
 * @note   
 * @param  N: Numarul de noduri ale arborelui
 * @param  *f: Fisierul din care sunt citite datele de intrare 
 * @retval	Nodul radacina al arborelui creat 
 */
BST* createBalanced(int N, FILE *f) 
{
    if(!N)
        return NULL;
    int data;
    fscanf(f ,"%d", &data);
    BST* root = createBSTNode(data);
    root->left = createBalanced(N/2, f);
    root->right = createBalanced(N - 1 - N/2, f);
    return root;
}


/**
 * TODO:   Implementati o functie ce testeaza daca un arbore binar este
 * 	un arbore binar de cautare.
 * @note   
 * @param  root: Radacina arborelui
 * @param  max_value: Valoarea maxima intalnita pana la nodul curent
 * @param  min_value: Valoarea minima intalnita pana la nodul curent
 * @retval - true daca arborele este un BST, false in caz contrar
 */
bool checkBST(BST* root, int max_value, int min_value)
{
	if(isNull(root))
        return true;

    if(root->data < min_value)
        return false;

    if(root->data > max_value)
        return false;

    return checkBST(root->left, root->data - 1, min_value) && checkBST(root->right, max_value, root->data + 1);
}

/**
 * TODO:  Implementati o functie ce aloca memorie pentru un nod 
 * 	si salveaza datele in acesta
 * @note   
 * @param  data: Datele ce trebuie stocate in nod
 * @retval Nodul creat
 */

BST* createBSTNode(int data)
{
	BST* newNode = (BST*)malloc(sizeof(BST));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}
/**
 * TODO: Implementati o functie ce insereaza un nod nou intr-un BST cu
 * 	pastrarea proprietatiilor acestui tip de arbore binar
 * @note   
 * @param  root: Nodul radacina
 * @param  data: Valoarea ce trebuie inserata in arbore
 * @retval Radacina arborelui modificat anterior
 */
BST* insertInBST(BST* root, int data)
{
    if(isNull(root))
        return createBSTNode(data);
    else {
        if(root->data > data) {
            root->left = insertInBST(root->left, data);
            root->left->parent = root;
        }
        else
            if(root->data < data) {
                root->right = insertInBST(root->right, data);
                root->right->parent = root;
            }
    }
    return root;
}