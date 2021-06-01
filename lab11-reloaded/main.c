#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "heapsort.h"

double knapsack(Map* array, int n, int knapsackCapacity) {
    heapSort(array, n);

    int weight = 0;
    double answer = 0.0;

    for(int i = 0; i < n; i++) {
        if(weight + array[i].weight <= knapsackCapacity) {
            weight += array[i].weight;
            answer += array[i].profit;
        }
        else {
            int rest = knapsackCapacity - weight;
            answer += array[i].profit * ((double)rest / array[i].weight);
            break;
        }
    }
    return answer;
}

int main()
{
    char fileName[] = "./testfiles/testX";
    int n, kSize;
    FILE* input;
    Map* arr;
    for(char i = '1'; i <= '8'; i++) {
        fileName[strlen(fileName) - 1] = i;
        input = fopen(fileName, "r");
        arr = createMappedArray_FromFile(input, &n, &kSize);
        printf("ANSWER FOR TEST FILE %c IS %lf\n", i, knapsack(arr, n, kSize));
        fclose(input);
        free(arr);
    }
    return 0;
}