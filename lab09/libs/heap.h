#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int v;//nod
    int distanta; // distanta pana la nodul v de la un nod dat
}HeapNode;

typedef struct{
    int size;
    int capacity;
    int *poz;//vectorul de pozitii ale elementelor din MinHeap
    HeapNode **arr;//vectorul cu distantele minime pana in mom respectiv
}MinHeap;

MinHeap* create(int );
HeapNode* createHeapNode(int , int );
int parent(MinHeap *, int );
int leftChild(MinHeap *, int );
int rightChild(MinHeap *, int );
HeapNode* returnRoot(MinHeap *);
void heapify(MinHeap *, int);
void insert(MinHeap *, HeapNode *);
void resize(MinHeap *);
void deleteMinHeap(MinHeap **);
void printHeap(MinHeap *);
HeapNode* deleteNode(MinHeap *);

#endif
