#include "utils.h"
#include "counting.h"

//----- Counting Sort -----

/**
 * //TODO: Implementarea algoritmului counting sort
 * Restrictii: 0 <= arr[i] < 50
 * Dimensiunea vectorului de frecventa va fi 50
 * @param arr - vectorul care trebuie sortat
 * @param dim - dimensiunea vectorului
 * @return vectorul de frecventa utilizat in algoritm
 */
int* countingSort(int *arr, int dim)
{
    int *frequency_arr = NULL;
    int check = 0;
    int iterator = 0;
    frequency_arr = (int*)calloc(50, sizeof(int));

    for(int i = 0; i < dim; i++) {
        frequency_arr[arr[i]]++;
    }

    for(int i = 0; i < 50; i++) {
        check = 0;
        while(check != frequency_arr[i]) {
            check++;
            arr[iterator++] = i;
        }
    }
    return frequency_arr;
}

/**
 * //TODO: Care este complexitatea spatiala si cea temporala?
 * Complexitatea temporala este O(n) , iar cea spatiala este O(n)
 * De ce nu este mai folosit?
 * Aceasta metoda de sortare nu este folosita deoarece elementele pot avea valori foarte mari care necesita alocarea unei cantitati foarte mari de spatiu, prin urmare metoda devenind ineficienta.
 * Totodata, algoritmul nu poate fi folosit decat pentru a compara caractere si numere naturale, nici vorba de double sau float
 */