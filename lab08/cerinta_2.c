#include "utils.h"

/**
 * TODO:   O functie ce transforma un graf reprezentat prin liste de adiacenta 
 * intr-unul reprezentat cu ajutorul unei matrice de adiacenta
 * @note   Nodurile trebuie indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta
 * @retval - Graful in reprezentarea matrice de adiacenta
 */

graph_matrix* newGraphMatrix(graph_list* graph) {
    graph_matrix* newMatrix = (graph_matrix*)malloc(sizeof(graph_matrix));
    newMatrix->E = graph->E;
    newMatrix->V = graph->V;
    newMatrix->matrix = (int**)malloc(sizeof(int*) * newMatrix->V);
    for(int i = 0; i < newMatrix->V; i++)
        newMatrix->matrix[i] = (int*)calloc(newMatrix->V, sizeof(int));

    return newMatrix;
}

graph_matrix* listToMatrix(graph_list* graph) {
    graph_matrix* newGraph = newGraphMatrix(graph);
    node* root;
    for(int i = 0; i < newGraph->V; i++) {
        root = graph->listHeads[i];
        while(root) {
            newGraph->matrix[i][root->vertexNr] = 1;
            root = root->next;
        }
    }
    // print_graph_matrix(newGraph);
    return newGraph;
}


/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/

void free_graph_list(graph_list** graph) {
    node* root;
    node* dummy;

    for(int i = 0; i < (*graph)->V; i++) {
        root = (*graph)->listHeads[i];
        while(root) {
            dummy = root;
            root = root->next;
            free(dummy);
        }
        (*graph)->listHeads[i] = NULL;
    }
    *graph = NULL;
}


void print_graph_matrix(graph_matrix* graph) {
    // nice to have; functie de afiseaza continutul unui graf reprezentat prin matrice de adiacenta
    for(int i = 0; i < graph->V; i++)
    {
        for(int j = 0; j < graph->V; j++)
            printf("%.2d ", graph->matrix[i][j]);
        printf("\n");
    }
}