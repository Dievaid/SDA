#include "graph.h"
#include "heap.h"


/**
 * TODO:   Implementati Algoritmul Dijkstra folosindu-va de MinHeap-ul creat in fisierul heap.c
 * @param  g: graful dat
 * @param source : varful sursa pentru care se aplica algoritmul
 * @retval None
 */

void memsetDijkstra(DijkstraPath* dijkstraPath, int n)
{
    for(int i = 0; i < n; i++) {
        dijkstraPath->dist[i] = INF_MAX;
        dijkstraPath->pred[i] = -1;
    }
}

DijkstraPath* Dijkstra(Graph *g, int source){
    MinHeap* PriorityQueue = create(g->V);
    HeapNode* pop;
    DijkstraPath* dijkstraPath = (DijkstraPath*)malloc(sizeof(DijkstraPath));
    dijkstraPath->dist = (int*)calloc(g->V, sizeof(int));
    dijkstraPath->pred = (int*)calloc(g->V, sizeof(int));
    int v;

    memsetDijkstra(dijkstraPath, g->V);

    dijkstraPath->dist[source] = 0;
    for(int i = 0; i < g->V; i++)
        insert(PriorityQueue, createHeapNode(i, INF_MAX));
    insert(PriorityQueue, createHeapNode(source, 0));

    while(PriorityQueue->size) {
        pop = deleteNode(PriorityQueue);
        v = pop->v;
        for(int i = 0; i < g->V; i++) {
            if(g->mat[v][i]) {
                if(dijkstraPath->dist[v] + g->mat[v][i] < dijkstraPath->dist[i]) {
                    dijkstraPath->dist[i] = dijkstraPath->dist[v] + g->mat[v][i];
                    dijkstraPath->pred[i] = v;
                    insert(PriorityQueue, createHeapNode(i, dijkstraPath->dist[i]));
                } 
            }
        }
    }
    return dijkstraPath;
}

/**
 * TODO:   Implementati Algoritmul Dijkstra folosindu-va de MinHeap-ul creat in fisierul heap.c
 * @param vectorPath : vectorul cailor
 * @param index : [optional pentru recursivitate]
 * @param vector_precedesori : vectorul de predecesori 
 * @param destinatie : varful destinatie pentru care se cauta path-ul
 * @param output : fisierul in care se face scrierea vectorului de predecesori (path.txt)
 * @note : se poate implementa atat recursiv, cat si iterativ
 *         nu mai trebuie facute alocari pentru vectorPath, vector_predecesori
 *         fisierul de output este deschis 
 * @retval None
 */
void printPath(int *vectorPath, int index, int *vector_precedesori, int destinatie, FILE *output) {
    if(index > -1) {
        vectorPath[index] = destinatie;
        printPath(vectorPath, index - 1, vector_precedesori, vector_precedesori[destinatie], output);
    }
    fprintf(output, "%d", destinatie);
}
