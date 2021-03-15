#include "merge.h"
#include "quick.h"
#include "utils.h"

//----- MergeSort -----

/**
 * //TODO: Implementarea metodei "merge" din cadrul algoritmului Merge Sort
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param middle - pozitia din mijloc
 * @param right - pozitia finala
 */
void merge(int *arr, int left, int middle, int right)
{
    int arr1_size = middle - left + 1;
    int arr2_size = right - middle;

    int *arr1, *arr2;
    arr1 = (int*)malloc(arr1_size * sizeof(int));
    arr2 = (int*)malloc(arr2_size * sizeof(int));

    for(int iterator = 0; iterator < arr1_size; iterator++)
        arr1[iterator] = arr[left + iterator];
    for(int iterator = 0; iterator < arr2_size; iterator++)
        arr2[iterator] = arr[middle + 1 + iterator];

    int i = 0, j = 0, k = left;
    
    while(i < arr1_size && j < arr2_size) {
        if(arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < arr1_size) {
        arr[k++] = arr1[i++];
    }

    while(j < arr2_size) {
        arr[k++] = arr2[j++];
    }
}

/**
 * //TODO: Implementarea metodei "mergesort" din cadrul algoritmului Merge Sort
 * @param arr - vectorul care trebuie sortat
 * @param left - pozitia initiala
 * @param right - pozitia finala
 */
void mergesort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    mergesort(arr, left, (left + right) / 2);
    mergesort(arr, ((left + right) / 2 + 1), right);
    merge(arr, left, (left + right) / 2, right);
}

//----- Quick Sort -----

/**
 * //TODO: Implementarea metodei de interschimbare a doua elemente
 * @param x - primul element
 * @param y - al doilea element
 */
void swap(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

/**
 * //TODO: Implementarea metodei de partitionare din cadrul algoritmului Quick Sort
 * Consideram pivotul a fi ultimul element din vector
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; 
    int i = low - 1; 
 
    for (int j = low; j < high; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &pivot); 
    return i + 1;
}

/**
 * //TODO: Implementarea metodei "quicksort" din cadrul algoritmului Quick Sort
 * @param arr - vectorul care trebuie sortat
 * @param low - pozitia initiala
 * @param high - pozitia finala
 */
void quicksort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int pi = partition(arr, low, high); 
    quicksort(arr, low, pi - 1); 
    quicksort(arr, pi + 1, high);
}

//----- Analiza functiilor -----

/**
 * //TODO: Care dintre metodele anterior implementate reprezinta metode de sortare stabile
 * si care reprezinta metode de sortare instabile? Argumentati.
 * Merge sort este o metoda de sortare stabila deaorece atunci cand cei doi vectori care impart vectorul initial in doua parti sunt interclasati se tine cont de ordinea lor initiala
 * Quick sort este o metoda de sortare instabila deoarece la fiecare alegere a pivotului, se vor realiza interschimbari si intre valori identice, insa poate fi transformat intr-un algoritm stabil
 */