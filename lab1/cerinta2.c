#include "student.h"

/**
 * //TODO: Implementarea metodei ,,eliminare_restantieri" (se elimina fiecare student restantier)
 * Hint:
	- dimensiunea se schimba
	- se creeaza un vector auxiliar
 * @param vector  - vectorul de studenti 
 * @param dimensiune - dimensiunea vectorului
 * @return vectorul de studenti fara restanta
 */
student* eliminare_restantieri(student *vector, int *dimensiune) {

	student* studenti;
	int nr_stud = 0;


	for(int i = 0; i < (*dimensiune); i++) {
		if(nr_restante(vector[i]) == 0) { //aflam cati studenti sunt integralisti
			nr_stud++;
		}
	}

	if(nr_stud == (*dimensiune)) //daca toti elevii sunt integralisti returnam vectorul initial intrucat nu avem restantieri
		return vector;

	if(nr_stud == 0) {// daca sunt 0 integralisti => toti elevii sunt restantieri
		*dimensiune = 0;
		return NULL;
	}

	studenti = (student*)malloc(nr_stud * sizeof(student));
	nr_stud = 0;
	for(int i = 0; i < (*dimensiune); i++) {
		if(nr_restante(vector[i]) == 0) {
			studenti[nr_stud++] = vector[i];
		}
	}
	free(vector);
	*dimensiune = nr_stud;

	/*for(int i = 0; i < (*dimensiune); i++){
		if(nr_restante(vector[i]) > 0){
			for(int j = i; j < (*dimensiune) - 1; j++){
				vector[j] = vector[j+1];
			}
			(*dimensiune)--;
		}
	}*/
	return studenti;
	/*TODO: Care este complexitatea pentru secventa de stergere a elementelor din vector cu realocare de memorie?*/
}