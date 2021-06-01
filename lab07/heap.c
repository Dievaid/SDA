#include "heap.h"

/**
 * TODO: Implenentati functia de creare a unui heap de capacitate
 * data 
 * @param  capacitate: capacitatea heap-ului
 * @retval - heap-ul creat
 */
Heap *create(int capacitate)
{
	Heap* heap = (Heap*)malloc(sizeof(Heap));
    if(heap) {
        heap->size = 0;
        heap->capacity = capacitate;
        heap->vec = (int*)calloc(capacitate, sizeof(int));
        
        return heap;
    }
    return NULL;
}
/**
 * TODO: Implementati functia de returnare a index-ului
 * parintelui unui nod din heap
 * @param  *h: heap-ul binar
 * @param  i: index-ul copilului
 * @retval - parintele copilului i
 */
int parent(Heap *h, int i)
{
    if(i <= 0 ||  i >= h->size)
		return -1;
	return (i - 1) / 2;
}

/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului stang al unui nod
 * @param  *h: heap-ul binar
 * @param  i: parintele i
 * @retval - copilul din stanga al parintelui i
 */
int leftChild(Heap *h, int i)
{
	int left = 2 * i + 1;
	if(left > h->size - 1 || i < 0)
		return -1;
	return left;
}

/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului drept al unui nod
 * @param  *h: heap-ul binar
 * @param  i: parintele i
 * @retval - copilul din dreapta al parintelui i
 */
int rightChild(Heap *h, int i)
{
	int right = 2 * (i + 1);
	if(right > h->size - 1 || i < 0)
		return -1;
	return right;
}

/**
 * TODO: Implementati functia de returnare a radacinii
 * unui heap   
 * @param  *h: heap-ul binar 
 * @retval - valoarea stocata in radacina unui heap
 */
int returnRoot(Heap *h)
{
	return h->vec[0];
}

/**
 * TODO: Implementati iterativ functia heapify
 * @param  *h: 
 * @param  i: 
 * @retval None
 */
void heapify(Heap *h, int i)
{
    int left, right, lowest = i, aux;
    while (1)
    {
        lowest = i;
        left = leftChild(h, i);
        right = rightChild(h, i);
        if (left == -1 && right == -1)
            return;
        if (left != -1 && h->vec[left] < h->vec[lowest])
            lowest = left;
        if (right != -1 && h->vec[right] < h->vec[lowest])
            lowest = right;

        if (lowest != i)
        {
            aux = h->vec[i];
            h->vec[i] = h->vec[lowest];
            h->vec[lowest] = aux;
            i = lowest;
        }
        else
            break;
    }
}

/**
 * TODO: Implementati functia de redimensionare a unui heap  
 * @param  *h: heap-ul binar
 * @retval None
 */
void resize(Heap *h)
{
	int *vec = (int*)realloc(h->vec, h->capacity *= 2);
	if(vec) {
		free(h->vec);
		h->vec = vec;
	}
}

/**
 * TODO: Implementati functia de inserare a unui nod in heap
 * @param  *h: heap-ul binar
 * @param  x: valoarea nodului de inseat
 * @retval None
 */
void insert(Heap *h, int x)
{
	if(h->size == h->capacity)
		resize(h);
	
	int i = h->size;
	h->size++;

	while(i >= 0 && x > h->vec[(i - 1) / 2]) {
		h->vec[i] = h->vec[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->vec[i] = x;
}

/**
 * TODO: Implementati functia de distrugere a unui heap
 * @param  **h: - heap-ul binar
 * @retval None
 */
void deleteHeap(Heap **h)
{
    if(*h) {
		free((*h)->vec);
		free(*h);
		*h = NULL;
	}
}

/**
 * TODO: Implementati functia de afisare in consola a 
 * unui heap binar
 * @param  *h: heap-ul binar
 * @retval None
 */
void printHeap(Heap *h)
{
	for(int i = 0; i < h->size; i++) {
		printf("%d ", h->vec[i]);
	}	
}

/**
 * TODO: Implementati functia de afisare in fisier a
 * unui heap binar
 * @param  *h: heap-ul binar
 * @param  *output: fisierul de iesire 
 * @retval None
 */
void printHeapInFile(Heap *h, FILE *output)
{
	for(int i = 0; i < h->size; i++) {
		fprintf(output, "%d ", h->vec[i]);
	}
}

/**
 * TODO: Implementati functia de populare a 
 * unui heap binar
 * @param  *h: heap-ul binar
 * @param  *buffer: datele pentru popularea heap-ului
 * @param dimensiune: dimensiunea datelor pentru popularea heap-ului
 * @retval None
 */
void populateHeap(Heap *h, int *buffer, int dimensiune)
{
	if(h == NULL || buffer == NULL || dimensiune == 0) 
		return;
 
	while(dimensiune > h->capacity)
		resize(h);
 
	for(int i = 0; i < dimensiune; i++)
		h->vec[i] = buffer[i];
	h->size = dimensiune;
 
	for(int i = (dimensiune - 1) / 2; i >= 0; i--)
		heapify(h, i);
}
