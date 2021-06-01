#include "utils.h"

/**
 * TODO: Implementati o functie de cautare a unui nod in
 * 	functie de valoarea din acesta
 * @note   
 * @param  root: Radacina arborelui
 * @param  data: Valoarea de cautat
 * @retval Nodul cautat, daca nu este gasit se returneaza NULL
 */
BST* findNode(BST* root, int data)
{
	while(root)
    {
        if(root->data == data)
            return root;
        
        if(data > root->data)
            root = root->right;
        
        if(data < root->data)
            root = root->left;
    }
    return NULL;
}
/**
 * TODO: Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea maxima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea maxima din arbore/subarbore
 */
BST* findMax(BST* root)
{
    while(isNotNull(root->right)) {
        root = root->right;
    }
    return root;
}

/**
 * TODO: Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea minima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea minima din arbore/subarbore
 */
BST* findMin(BST* root)
{
    while(isNotNull(root->left)) {
        root = root->left;
    }
    return root;
}

/**
 * TODO: Implementati o functie ce returneaza succesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui succesor trebuie gasit
 * @retval Succesorul nodului root
 */
BST* findSuccesor(BST* root)
{
    BST* node = root;
    while(isNotNull(root->parent)) {
        root = root->parent;
    }

    if(isNotNull(node->right))
        return findMin(node->right);

    BST* predecessor = node;
    while(isNotNull(root)) {
        if(root->data > node->data) {
            predecessor = root;
            root = root->left;
        }
        else if(root->data < node->data)
            root = root->right;
            else
                break;
    }
    return predecessor;
}

/**
 * TODO: Implementati o functie ce returneaza predecesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui predecesor trebuie gasit
 * @retval Predecesorul nodului root
 */
BST* findPredecessor(BST* root)
{
	BST* node = root;
    while(isNotNull(root->parent)) {
        root = root->parent;
    }

    if(isNotNull(node->left))
        return findMax(node->left);
    
    BST* predecessor = node;
    while(isNotNull(root)) {
        if(root->data < node->data) {
            predecessor = root;
            root = root->right;
        }
        else if(root->data > node->data)
            root = root->left;
            else
                break;
    }
    return predecessor;
}
