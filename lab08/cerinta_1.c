#include "utils.h"


/**
 * TODO:   O functie ce transforma un graf reprezentat de o matrice de adiacenta 
 * intr-unul reprezentat cu ajutorul listelor de adiacenta
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - Graful in reprezentarea liste de adiacenta
 */

void printGraphMatrix(graph_matrix* graph) {
    for(int i = 0; i < graph->V; i++)
    {
        for(int j = 0; j < graph->V; j++)
            printf("%.2d ", graph->matrix[i][j]);
        printf("\n");
    }
}

graph_list* newGraphList(graph_matrix* graph) {
    graph_list* newList = (graph_list*)malloc(sizeof(graph_list));
    newList->V = graph->V;
    newList->E = graph->E;
    newList->listHeads = (node**)malloc(newList->V * sizeof(node*));
    return newList;
}

graph_list* matrixToList(graph_matrix* graph) {

    node *root;
    node* newNode;
    graph_list* graphList = newGraphList(graph);

    // printGraphMatrix(graph);
    for(int i = 0; i < graphList->V; i++) {
        graphList->listHeads[i] = NULL;

        for(int j = 0; j < graphList->V; j++) {
            if(graph->matrix[i][j] > 0) {
                if(graphList->listHeads[i] == NULL) {
                    graphList->listHeads[i] = push_values(NULL, j);
                    root = graphList->listHeads[i];
                }
                else {
                    newNode = push_values(NULL, j);
                    root->next = newNode;
                    root = root->next;
                }
            }
        }
    }
    // print_graph_list(graphList);
    return graphList;
}

/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_matrix(graph_matrix** graph) {
    for(int i = 0; i < (*graph)->V; i++)
        free((*graph)->matrix[i]);
    free(*graph);
    *graph = NULL;
}


node* push_values(node* root, int val) {
    // nice to have; functie de adauga o valoare intr-o lista
    node* newNode = (node*)malloc(sizeof(node));
    newNode->vertexNr = val;
    newNode->next = root;
    return newNode;
}


void print_graph_list(graph_list* graph) {
    // nice to have; functie care afiseaza continutul unui graf reprezentat prin liste de adiacenta
    node* root;
    for(int i = 0; i < graph->V; i++)
    {
        root = graph->listHeads[i];
        while(root) {
            printf("%d -> ", root->vertexNr);
            root = root->next;
        }
        printf("NULL\n");  
    }
}



