#ifndef HEAPSORT_H_
#define HEAPSORT_H_
#define NOTVALID -1
#include "map.h"

int leftChild(Map *array, int n, int i)
{
    int left = 2 * i + 1;
    if (i > n || left >= n)
        return NOTVALID;
    return left;
}

int rightChild(Map *array, int n, int i)
{
    int right = 2 * i + 2;
    if (i > n || right >= n)
        return NOTVALID;
    return right;
}

void swap(Map *x, Map *y)
{
    Map aux = *x;
    *x = *y;
    *y = aux;
}

void maxHeapify(Map *array, int n, int i)
{
    int left, right, highest;
    while (1)
    {
        highest = i;
        left = leftChild(array, n, i);
        right = rightChild(array, n, i);

        if(left == NOTVALID && right == NOTVALID)
            break;

        if (left != NOTVALID && getEfficiency(array[left]) < getEfficiency(array[highest]))
            highest = left;

        if (right != NOTVALID && getEfficiency(array[right]) < getEfficiency(array[highest]))
            highest = right;

        if (highest != i)
        {
            swap(&array[highest], &array[i]);
            i = highest;
        }
        else
            break;
    }
}

void heapSort(Map *array, int n)
{
    for(int i = (n - 1) / 2; i >= 0; i--)
        maxHeapify(array, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        maxHeapify(array, i, 0);
    }
}

#endif