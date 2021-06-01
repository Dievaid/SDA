#include "utils.h"
#define COUNT 10
void print2DUtil(BST* root, int space)
{
    // Base case
    if (root == NULL)
        return;
  
    // Increase distance between levels
    space += COUNT;
  
    // Process right child first
    print2DUtil(root->right, space);
  
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
  
    // Process left child
    print2DUtil(root->left, space);
}
void print2D(BST *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

int main()
{
    FILE* f = fopen("../data/test2-data.txt", READ_MODE);
    int n;
    fscanf(f, "%d", &n);
    BST* root = createBalanced(n, f);
    // printf("%d\n", findSuccesor(root)->data);
    // printf("%d\n", findPredecessor(root)->data);
    // printf("\n\n\n");
    print2D(root);
}
