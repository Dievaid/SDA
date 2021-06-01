#include "heap.h"

/**
 * TODO: Returnati un vector ce contine cele mai mari k elemente din vector.
 * HINT: Nu trebuie sa sortati tot vectorul, se poate utiliza un heap de
 * dimensiune mai mica. Pentru sortarea intregului vector se pot aplica penalizari
 * @param  *buffer: vectorul initial
 * @param  dimensiune: dimensiunea vectorului
 * @param  k: numarul de elemente returnate
 * @retval - vectorul cu cele mai mari k elemente din buffer
 */
int *kMaxElem(int *buffer, int dimensiune, int k)
{
    Heap *h = create(dimensiune);
    for(int i = 0; i < dimensiune; i++) {
        buffer[i] = (-1) * buffer[i];
    }
    populateHeap(h, buffer, dimensiune);
    int *newVector = (int*)calloc(k, sizeof(int));
    for(int i = 0; i < k; i++) {
        newVector[i] = (-1) * returnRoot(h);
        deleteNode(h, 0);
    }
    deleteHeap(&h);
    return newVector;
}
