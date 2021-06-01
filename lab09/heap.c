#include "heap.h"
/**
 * TODO: Implementati functia de creare MinHeap avand o capacitate data
 * @param  capacitate: capacitatea heap-ului
 * @retval - heap-ul creat
 */
MinHeap* create(int capacitate) {
	MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
	heap->capacity = capacitate;
	heap->size = 0;
	heap->arr = (HeapNode**)malloc(capacitate * sizeof(HeapNode*));
	heap->poz = (int*)calloc(capacitate, sizeof(int));
	for(int i = 0; i < heap->capacity; i++)
		heap->poz[i] = -1;
	return heap;
}

/**
 * TODO: Implementati functia de creare HeapNode 
 * @param  v:  varful care trebuie adaugat
 * @param dist: distanta rezultata in urma implementarii algoritmului Dijkstra
 * @retval - HeapNode-ul creat
 */
HeapNode *createHeapNode(int v, int dist) {
	HeapNode* newNode = (HeapNode*)malloc(sizeof(HeapNode));
	newNode->v = v;
	newNode->distanta = dist;
	return newNode;
}

/**
 * TODO: Implementati functia de returnare a index-ului
 * parintelui unui nod din MinHeap
 * @param  heap: MinHeap-ul
 * @param  i: index-ul copilului
 * @retval - parintele copilului i
 */

int parent(MinHeap *heap, int i) {
	if(i <= 0 || i >= heap->size)
		return -1;
	return (i - 1) / 2;
}
/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului stang al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din stanga al parintelui i
 */

int leftChild(MinHeap *heap, int i) {
	int left = 2 * i + 1;
	if(left > heap->size - 1 || i < 0)
		return -1;
	return left;
}

/**
 * TODO:  Implementati functia de returnare a index-ului
 * copilului drept al unui nod
 * @param  heap: MinHeap-ul
 * @param  i: parintele i
 * @retval - copilul din dreapta al parintelui i
 */
int rightChild(MinHeap *heap, int i) {
	int right = 2 * i + 2;
	if(right > heap->size - 1 || i < 0)
		return -1;
	return right;
}

/**
 * TODO: Implementati functia de returnare a radacinii
 * unui heap   
 * @param  heap: MinHeap-ul
 * @retval - HeapNode-ul in care este stocata radacina
 */
HeapNode* returnRoot(MinHeap *heap) {
	return heap->arr[0];
}

/**
 * TODO: Implementati functia heapify
 * @param  heap: MinHeap-ul
 * @param  i: pozitia de pe care se doreste
 * @retval None
 */
void heapify(MinHeap *heap, int i) {
	int lowest, left, right;
	HeapNode* auxiliaryNode;
	lowest = i;
	left = leftChild(heap, i);
	right = rightChild(heap, i);

	if(left == -1 && right == -1) {
		return;
	}

	if(left != -1 && heap->arr[left]->distanta < heap->arr[lowest]->distanta)
		lowest = left;
		
	if(right != -1 && heap->arr[right]->distanta < heap->arr[lowest]->distanta)
		lowest = right;

	if(lowest != i) {
		heap->poz[heap->arr[lowest]->v] = i;
		heap->poz[heap->arr[i]->v] = lowest;
		
		auxiliaryNode = heap->arr[i];
		heap->arr[i] = heap->arr[lowest];
		heap->arr[lowest] = auxiliaryNode;
		heapify(heap, lowest);
	}
}
/**
 * TODO: Implementati functia de redimensionare a MinHeap-ului  
 * @param  heap: MinHeap-ul
 * @retval None
 */
void resize(MinHeap *heap) {
	HeapNode** extendedArr = (HeapNode**)realloc(heap->arr, heap->capacity *= 2);
	if(extendedArr) {
		free(heap->arr);
		heap->arr = extendedArr;
	}
	int* newPoz = (int*)realloc(heap->poz, heap->capacity);
	if(newPoz) {
		free(heap->poz);
		heap->poz = newPoz;
	}
}
/**
 * TODO: Implementati functia de inserare a unui nod in heap
 * @param  heap: MinHeap-ul
 * @param  x: HeapNode-ul care urmeaza a fi inserat
 * @retval None
 */
 
void insert(MinHeap *heap, HeapNode *x) {
	if(heap->poz[x->v] == -1) {
		if(heap->size == heap->capacity)
			resize(heap);
		int i = heap->size;
		heap->size++;
		while(i > 0 && x->distanta < heap->arr[(i - 1) / 2]->distanta) {
			heap->arr[i] = heap->arr[(i - 1) / 2];
			heap->poz[heap->arr[i]->v] = i;
			i = (i - 1) / 2;
		}
		heap->arr[i] = x;
		heap->poz[x->v] = i;
	}
	else {
		heap->arr[heap->poz[x->v]]->distanta = x->distanta;
		heapify(heap, 0);
	}
}

/**
 * TODO: Implementati functia stergere a unui heap
 * @param  h: MinHeap-ul
 * @retval None
 */
void deleteMinHeap(MinHeap **heap){
	if(*heap) {
		for(int i = 0; i < (*heap)->size; i++) {
			free((*heap)->arr[i]);
			(*heap)->arr[i] = NULL;
		}
		free((*heap)->arr);
		free((*heap)->poz);
		(*heap)->arr = NULL;
		(*heap)->poz = NULL;
		*heap = NULL;
	}	
}
/**
 * TODO: Implementati functia de afisare a unui heap
 * @param  heap: MinHeap-ul
 * @note : se va afisa si pozitia HeapNode-urilor, pe langa componentele HeapNode-ului
 * @retval None
 */
void printHeap(MinHeap *heap){
	//nice to have
	for(int i = 0; i < heap->size; i++) {
		printf("%d ", heap->arr[i]->v);
	}
}
/**
 * TODO: Implementati functia de stergere a radacinii
 * @param  heap: MinHeap-ul
 * @retval HeapNode-ul care s-a sters, fosta radacina
 */
HeapNode* deleteNode(MinHeap *heap){
	HeapNode* aux = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size - 1];
	heap->size--;
	heap->poz[heap->arr[0]->v] = heap->poz[aux->v];
	heap->poz[aux->v] = -1;
	heapify(heap, 0);
	return aux;
}
