#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF_MIN INT_MIN
#define INF_MAX INT_MAX >> 2

typedef struct{
    int V;     //nr varfuri
    int E;     //nr muchii
    int **mat; //matrice de adiacenta
}Graph;

typedef struct{
    int *dist; //vectorul de distante minime fata de nodul sursa
    int *pred; //vectorul de predecesori
}DijkstraPath;


Graph* createGraph(FILE *);
void printMat(Graph *);
DijkstraPath* Dijkstra(Graph *, int);
void printPath(int *, int, int *, int, FILE *);
int** Floyd_Warshall(Graph *);
#endif
