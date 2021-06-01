#ifndef MAP_H_
#define MAP_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Map
{
    int weight;
    int profit;
}Map;

Map* createMappedArray_FromFile(FILE* input, int *n, int *kSize) {
    int size, weight, profit, s;
    fscanf(input, "%d", &size);
    *n = size;
    fscanf(input, "%d", &s);
    *kSize = s;
    Map* newMap = (Map*)malloc(sizeof(Map) * size);
    for(int i = 0; i < size; i++) {
        fscanf(input, "%d %d", &profit, &weight);
        newMap[i].weight = weight;
        newMap[i].profit = profit;
    }
    return newMap;
}

double getEfficiency(Map var) {return (double)var.profit / var.weight;}

#endif