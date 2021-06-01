#include "heap.h"
#define ROOT 0

/**
 * TODO: Sortati eficient un vector k-sortat folosind un heap.
 * HINT: Se poate utiliza un heap de dimensiune mai mica decat
 * numarul de elemente din buffer
 * @param  *buffer: - vectorul k sortat
 * @param  dimensiune: numarul de elemente
 * @param  k: indicele de sortare a vectorului k-sortat
 * @retval - vectorul sortat
 */


int isNotEmpty(Heap* h)
{
    return h->size > 0;
}

int *kSortedArray(int *buffer, int dimensiune, int k)
{
    Heap* heap = create(k + 1);
    populateHeap(heap, buffer, k + 1);

    int* answer = (int*)calloc(dimensiune, sizeof(int));
    int index = 0;

    for(int i = k + 1; i < dimensiune; i++) {
        answer[index++] = returnRoot(heap);
        heap->vec[ROOT] = buffer[i];
        heapify(heap, ROOT);
    }

    while(isNotEmpty(heap)) {
        answer[index++] = returnRoot(heap);
        deleteNode(heap, ROOT);
    }
    deleteHeap(&heap);
    return answer;
}
