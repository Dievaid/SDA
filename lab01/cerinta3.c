#include "student.h"

/**
 * //TODO: Implementarea metodei ,,realocare_memorie" 
 * @param vector  - pointer catre vectorul de studenti 
 * @param dimensiune - dimensiunea vectorului
 */
void realocare_memorie(student **vector, int dimensiune)
{
	*vector = (student *)realloc(*vector, dimensiune * sizeof(student));
}

/**
 * //TODO: Implementarea metodei ,,add_student" (se adauga un nou student pe pozitia poz)
 * Hint:
	- datele pentru noul student sunt citite in aceasta functie, de la tastatura
	- optional: se poate utiliza functia swap implementata la cerinta1
 * @param vector  - pointer catre vectorul de studenti 
 * @param poz - pozitia pe care trebuie adaugat noul student
 * @param dimensiune - dimensiunea vectorului
 */
void adaugare_student(student *vector, int poz, int dimensiune, student stud) 
// de ce in test-cerinta3.cpp se citeste variabila stud daca in functie trebuie sa citesc de la tastatura campurile lui stud
// daca nu citesc de la tastatura campurile variabilei, trec toate testele!!!!
//secventa de mai jos aflata in comentariu multi-linie este cea care citeste de la tastatura
{

	//printf("Pozitia %d\n", poz);
	//printf("\nDimensiune %d\n", dimensiune);

	for (int i = 0; i < dimensiune; i++)
	{
		printf("%s ", vector[i].nume);
	}


	/*char buffer[200];
	printf("Dati datele\n");
	scanf("%s", buffer);
	stud.nume = (char *)malloc(strlen(buffer) * sizeof(char));
	strcpy(stud.nume, buffer);
	scanf("%s", buffer);
	stud.prenume = (char *)malloc(strlen(buffer) * sizeof(char));
	strcpy(stud.prenume, buffer);
	scanf("%s", stud.id);
	for (int i = 0; i < 5; i++)
	{
		scanf("%lf", &stud.note[i]);
	}

	vector[dimensiune - 1].nume = (char *)malloc(strlen(vector[dimensiune - 2].nume) * sizeof(char));
	vector[dimensiune - 1].prenume = (char *)malloc(strlen(vector[dimensiune - 2].nume) * sizeof(char));
	strcpy(vector[dimensiune - 1].nume, vector[dimensiune - 2].nume);
	strcpy(vector[dimensiune - 1].prenume, vector[dimensiune - 2].prenume);
	*/
	for (int i = dimensiune - 2; i >= poz; i--)
	{
		vector[i + 1] = vector[i];
	}
	swap(&vector[poz], &stud);	

	for (int i = 0; i < dimensiune; i++)
	{
		printf("%s ", vector[i].nume);
	}

	/*TODO: Care este complexitatea metodei folosite?*/
	//Complexitatea metodei este O(n)
}
