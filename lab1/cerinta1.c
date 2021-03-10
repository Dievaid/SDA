#include "student.h"

//----- Prelucrarea informatiilor pentru un student -----

/**
 * //TODO: Implementarea metodei ,,nr_restante"
 * @param stud - studentul a carui numar de restante trebuie aflat
 * @return numarul de restante
 */
int nr_restante (student stud) {
	
	unsigned int restante = 0;
	
	for(int i = 0 ; i < 5 ; i++){
		if(stud.note[i] < 5.0){
			restante++;
		}
	}
	return restante;
}

/**
 * //TODO: Implementarea metodei ,,medie"
 * @param stud - studentul a carei medie trebuie calculata
 * @return valoare mediei aritmetice 
 */
double medie (student stud) {

	double suma_note = 0.0;

	for(int i = 0; i < 5; i++){
		suma_note += stud.note[i];
	}

	return suma_note / 5.0;
}

//----- Instantierea & popularea vectorului de studenti -----

/**
 * //TODO: Implementarea metodei ,,alocare_memorie"
 * Hint: 
	- numele si prenumele se aloca in timpul citirii datelor pentru fiecare student
 * @param vector - pointer catre vectorul de studenti
 * @param dimensiune - dimensiunea vectorului
 */
void alocare_memorie (student **vector, int dimensiune) {
	*vector = (student*)malloc(dimensiune * sizeof(student));
}
/** 
 * //TODO: Implementarea metodei ,,citire_fisier" (se citesc datele din fisier)
 * @param vector - vectorul de studenti
 * @param dimensiune - dimensiunea vectorului
 * @param input - fisierul de date
 */
void citire_fisier(student *vector, int dimensiune, FILE *input) {
	
	char buffer[200];

	for(int i = 0; i < dimensiune; i++){
		fscanf(input, "%s", buffer);
		vector[i].nume = (char*)malloc(strlen(buffer) * sizeof(student));
		strcpy(vector[i].nume, buffer);
		fscanf(input, "%s", buffer);
		vector[i].prenume = (char*)malloc(strlen(buffer) * sizeof(student));
		strcpy(vector[i].prenume, buffer);
		fscanf(input, "%s", vector[i].id);
		for(int j = 0; j < 5; j++){
			fscanf(input, "%lf", &vector[i].note[j]);
		}
	}
}

/**
 * //TODO: Implementarea metodei ,,afisare_fisier"
 * @param vector  - vectorul de studenti
 * @param dimensiune - dimensiunea vectorului
 */
void afisare_fisier(student *vector, int dimensiune) {

	/*Exemplu afisare in fisier:
	Nume: Petrescu
	Prenume: Camil
	Id: 99
	Note: 10 10 10 10 10 
	Nume: Popesescu
	Prenume: Gigel
	Id: 100
	Note: 4 12 12 12 12
	Nr. restante: 1
	Nume: Cineva
	Prenume: Marian
	Id: 101
	Note: 5 5 5 5 5
	*/
	for(int i = 0; i < dimensiune; i++){
		printf("Nume: %s\n", vector[i].nume);
		printf("Prenume: %s\n", vector[i].prenume);
		printf("Id: %s\n", vector[i].id);
		printf("Note: %lf %lf %lf %lf %lf\n", vector[i].note[0],
											  vector[i].note[1],
											  vector[i].note[2],
											  vector[i].note[3],
											  vector[i].note[4]);

	}
}

/**
 * //TODO: Implementarea metodei ,,citire"
 * Hint: 
	- datele sunt citite de la tastatura
 * @param vector - vectorul de studenti ce trebuie populat cu date
 * @param dim - dimensiunea vectorului
 
void populare_vector(student *vector, int dimensiune) {

}

 * //TODO: Implementarea metodei ,,afisare"
 * De afisat: nume, prenume, id, note, nr_restante
 * @param stud - studentul a carui date o sa fie afisate
 
void afisare_student(student stud) {

}
*/
//----- Sortarea vectorului de studenti -----

/**
 * //TODO: Implementarea metodei ,,swap" (interschimba datele a 2 studenti)
 * @param first_stud  - primul student
 * @param second_stud - al 2-lea student
 */
void swap(student *first_stud, student *second_stud) {
	student aux;
	aux = *first_stud;
	*first_stud = *second_stud;
	*second_stud = aux;
}

/**
 * //TODO: Implementarea metodei ,,sortare" (se sorteaza crescator in functie de medie)
 * Hint:
	- pentru sortare se foloseste metoda swap
 * @param vector  - vectorul de studenti 
 * @param dimensiune - dimensiunea vectorului
 */
void sortare_vector(student *vector, int dimensiune) {
	for(int i = 0; i < dimensiune -1; i++){
		for(int j = i + 1; j < dimensiune; j++){
			if(medie(vector[i]) > medie(vector[j])){
				swap(&vector[i], &vector[j]);
			}
		}
	}
}