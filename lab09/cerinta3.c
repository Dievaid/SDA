#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati algoritmul Floyd-Warshall pentru un graf cu matricea de adiacenta data
 * @param  g: graful dat
 * @retval - Matricea costurilor pentru toate nodurile
 */
int **Floyd_Warshall(Graph *g){

    int** newMatrix = (int**)malloc(g->V * sizeof(int*));
    for(int i = 0; i < g->V; i++)
        newMatrix[i] = (int*)calloc(g->V, sizeof(int));
    
    for(int i = 0; i < g->V; i++)
        for(int j = 0; j < g->V; j++) {
            if(i == j)
                newMatrix[i][j] = 0;
            else {
                if(g->mat[i][j] == 0)
                    newMatrix[i][j] = INF_MAX;
                else
                    newMatrix[i][j] = g->mat[i][j];
             }
        }

    for(int k = 0; k < g->V; k++) {
        for(int i = 0; i < g->V; i++) {
            for(int j = 0; j < g->V; j++) {
                if(newMatrix[i][k] + newMatrix[k][j] < newMatrix[i][j] && newMatrix[i][k] != INF_MAX && newMatrix[k][j] != INF_MAX) 
                    newMatrix[i][j] = newMatrix[i][k] + newMatrix[k][j];
            }
        }
    }
    return newMatrix;
}