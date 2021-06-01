#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int *vec; 
    int size, capacity;
    
    int type; // Optional
}Heap;


Heap* create(int );
int parent(Heap *, int );
int leftChild(Heap *, int );
int rightChild(Heap *, int );
int returnRoot(Heap *);
void heapify(Heap *, int );
void resize(Heap *);
void insert(Heap *, int );
void deleteHeap(Heap **);
void printHeap(Heap *);
void printHeapInFile(Heap *, FILE *);
void populateHeap(Heap *, int *, int );


void readVector(int **, int , FILE* );
void deleteNode(Heap *, int );
void heapsort(Heap *, int *, int );
int* kMaxElem(int *, int , int );
int* kSortedArray(int *, int , int );