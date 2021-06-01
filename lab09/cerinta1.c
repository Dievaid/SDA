#include "graph.h"
#include "heap.h"
/**
 * TODO:   Implementati o functie care citeste dintr-un fisier de intrare
 * nr-ul de varfuri, muchii, iar pe urmatoarele linii
 * nod u, nod v si distanta[u][v], pentru a putea reprezenta ulterior matricea de adiacenta
 * @param  input: fisierul de intrare
 * @note   -Atentie! Nu redeschideti fisierul de intrare
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
Graph* createGraph(FILE *input) {
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    fscanf(input, "%d", &newGraph->V);
    fscanf(input, "%d", &newGraph->E);

    newGraph->mat = (int**)malloc(newGraph->V * sizeof(int*));
    for(int i = 0; i < newGraph->V; i++)
        newGraph->mat[i] = (int*)calloc(newGraph->V, sizeof(int));
    int u, v;
    for(int i = 1 ; i <= newGraph->E; i++) {
        fscanf(input, "%d %d", &u, &v);
        fscanf(input, "%d", &newGraph->mat[u][v]);
        newGraph->mat[v][u] = newGraph->mat[u][v];
    }
    printMat(newGraph);
    printf("\n\n");
    return newGraph;
}
/**
 * TODO: Implementati functia de afisare a matricei de adiacenta
 * @param  g: graful creat anterior
 * @note : Nice to have
 * @retval - None
 */
void printMat(Graph *g) {
   for(int i = 0; i < g->V; i++) {
        for(int j = 0; j < g->V; j++)
            printf("%.2d ", g->mat[i][j]);
        printf("\n");
   }
}