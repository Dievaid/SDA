#include "utils.h"

/**
 * TODO:   Implementati o functie ce ce genereaza matricea drumurilor unui graf reprezentat cu 
 * ajutorul matricei de adiacenta
 * @note   
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - o matrice reprezentand matricea drumurilor
 */

int** initNewMatrix(int n) {
    int** newMatrix = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        newMatrix[i] = (int*)calloc(n, sizeof(int));
    return newMatrix;
}

void printMatrix(int** a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int** findPaths(graph_matrix* graph) {
    int** pathMatrix = initNewMatrix(graph->V);
    
    for(int i = 0; i < graph->V; i++) {
        for(int j = 0; j < graph->V; j++)
            pathMatrix[i][j] = graph->matrix[i][j];
    }

    for(int k = 0; k < graph->V; k++) {
        for(int i = 0; i < graph->V; i++) {
            for(int j = 0; j < graph->V; j++) {
                if(i != j) {
                    if(pathMatrix[i][j] == 0)
                        pathMatrix[i][j] = pathMatrix[i][k] * pathMatrix[k][j];
                }
            }
        }
    }
    return pathMatrix; 
}