#include "utils.h"

/**
 * TODO: Returnati prin intermediul parametrului arr un vector ce contine toate
 * 	nodurile din arborele binar de cautare cu valori aflate in intervalul [min_value, max_value]  
 * @note   
 * @param  root: Radacina arborelui/subarborelui 
 * @param  arr: Vectorul cu valorile cerute
 * @param  *size: Pozitia pe care inseram la etapa curenta
 * @param  max_value: Pragul superior
 * @param  min_value: Pragul inferior
 * @retval None
 */
void bstToArray(BST* root, BST** arr, int *size, int max_value, int min_value)
{
	if(isNull(root))
        return;
    bstToArray(root->left, arr, size, max_value, min_value);
    arr[(*size)++] = root;
    bstToArray(root->right, arr, size, max_value, min_value);
}


/**
 * TODO: Implementati o functie ce returneaza numarul de noduri ce stocheaza
 * 	valori din intervalul [min_value, max_value]
 * @note   
 * @param  root: Radacina arborelui/subarborelui 
 * @param  max_value: Pragul superior
 * @param  min_value: Pragul inferior
 * @retval Numarul de noduri cu valori in [min_value, max_value] 
 *  din arbore/subarbore
 */

int getNumberOfNodes(BST* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + getNumberOfNodes(root->left) + getNumberOfNodes(root->right);
    }
}// functie ce numara nodurile dintr-un arbore binar

int numberOfNodesInBetween(BST* root, int max_value, int min_value)
{
    int TreeNodeArraySize = getNumberOfNodes(root);
    BST** TreeNodeArray = (BST**)malloc(sizeof(BST*) * TreeNodeArraySize);

    for(int i = 0; i < TreeNodeArraySize; i++)
        TreeNodeArray[i] = (BST*)malloc(sizeof(BST));
    
    int size = 0;
    bstToArray(root, TreeNodeArray, &size, max_value, min_value);
    return size;
}

