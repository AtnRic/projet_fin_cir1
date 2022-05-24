#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


/// <summary>
/// utilitaire liste chainées
/// </summary>
/// <returns></returns>
DoubleLinkedList* newDoubleLinkedList() {
	DoubleLinkedList* tmp;
	tmp = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	if (tmp != NULL) {
		tmp->head = NULL;
		tmp->tail = NULL;
		tmp->size = 0;
	}
	return tmp;
}

DoubleLinkedListElem* NewDoubleLinkedListItem(int value) {
	DoubleLinkedListElem* tmp;
	tmp = (DoubleLinkedListElem*)malloc(sizeof(DoubleLinkedListElem));
	if (tmp != NULL) {
		tmp->data = value;
		tmp->next = NULL;
		tmp->previous = NULL;
	}
	return(tmp);
}



int DisplayDoubleList(DoubleLinkedList* list) {
	if (list == NULL || list->head == NULL || list->tail == NULL) { return 0; }

	DoubleLinkedListElem* courant = list->head;
	while (courant != NULL) {
		printf("%d ", courant->data);
		courant = courant->next;
	}
	return 1;
}



int insertItemAtDoubleLinkedListTail(DoubleLinkedList* list, DoubleLinkedListElem* newItem) {
	if (list == NULL)
		return 0;
	if (newItem == NULL || newItem->next != NULL || newItem->previous != NULL)
		return 0;

	if (list->tail == NULL) {
		list->tail = newItem;
		list->head = newItem;
		list->size = 1;
	}
	else {
		newItem->previous = list->tail;
		list->tail->next = newItem;
		list->tail = newItem;
		list->size++;
	}
	return 1;
}


int getDoubleLinkedListSize(DoubleLinkedList* list) {
	if (list != NULL) {
		return list->size;
	}
	return -1;
}

int DeleteDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* elem) {
	
	// cas d'erreur
	// La liste n'existe pas
	if (list == NULL) return(0);
	// liste vide ou anomalie
	if ((list->head == NULL) || (list->tail == NULL)) return(0);
	// anomalie sur la taille
	if ((list->head == list->tail) && (list->size != 1)) return(0);
	// pas d'élément dans la liste ou elem invalide
	if ((list->size == 0) || (elem == NULL)) return(0);
	// initialisation d'un pointeur sur l'élément courant
	DoubleLinkedListElem* tmp = list->head;
	//tmp->previous = NULL;


	// l'élément est en tête et en queue, il y a donc 1 seul élément dans la liste
	if ((elem == list->head) && (elem == list->tail)) {
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
		free(elem);
		return(1);
	}
	// il est en tête, on supprime la tête
	if (elem == list->head) {
		list->head = elem->next;
		list->size--;
		free(elem);
		return(1);
	}
	// Recherche du maillon dans le reste de la liste chaînée
	while ((tmp != NULL) && (tmp != elem)) {
		//tmp->previous = tmp;
		tmp = tmp->next;
	}
	// s'il est en queue, on supprime la queue
	if ((tmp == elem) && (tmp->next == NULL)) {
		list->tail = elem->previous;
		//tmp = NULL;
		list->size--;
		free(elem);
		return(1);
	}
	// s'il est au milieu, on supprime l'élément
	if ((tmp->previous != NULL) && (tmp == elem) && (tmp->next != NULL)) {
		(elem->next)->previous = elem->previous;
		(elem->previous)->next = elem->next;
		list->size--;
		free(elem);
		return(1);
	}
	// l'élément recherché n'a pas été trouvé
	return(0);

}

DoubleLinkedListElem * getDoubleLinkedListElem(DoubleLinkedList* list, int pos) {
	DoubleLinkedListElem * tmp = list->head;
	for (int i = 1; i <= pos; i++) {
		tmp = tmp->next;
	}
	return tmp;
}



int main() {
	//DoubleLinkedList* List = newDoubleLinkedList();
	recherche_loc_tp(3);
}



/// <summary>
///recherche des endroits ou placer les tp dans le labyrinthe et stocke dans une liste chainée
/// </summary>
/// <returns></returns>
int recherche_loc_tp(nb_paires) {
	/*recherche localisation des tp*/
	int size = 10;
	char* maze = (char*)malloc(sizeof(char) * size);
	DoubleLinkedList* List = newDoubleLinkedList();
	if (nb_paires >= size / 2) return -1;
	if (maze != NULL) {
		for (int i = 0; i < size; i++) {
			(*(maze + i)) = 'm';
		}


		DoubleLinkedList* List = newDoubleLinkedList();

		for (int i = 1; i < size-1; i++) {
			if (*(maze+i) == 'l' || *(maze + i) == 'm' || *(maze + i) == 'n' || *(maze + i) == 'o') {
				DoubleLinkedListElem* elem = NewDoubleLinkedListItem(i);
				insertItemAtDoubleLinkedListTail(List, elem);
			}
		}
		printf("positions trouvees :\n");
		DisplayDoubleList(List);
		


		/*Creation de paires de tp*/
		printf("\nCreation des paires de teleporteurs :\n");
		Teleporteurs_Paire* tab = (Teleporteurs_Paire*)malloc(sizeof(Teleporteurs_Paire) * nb_paires);
		srand(time(NULL));

		int pos;
		if (tab != NULL) {
			for (int i = 0; i < nb_paires; i++) {
				int max_index = getDoubleLinkedListSize(List);

				//tirage d'une entrée
				pos = (rand() * max_index / RAND_MAX)-1;
				DoubleLinkedListElem* elem_entree = getDoubleLinkedListElem(List, pos);
				
				(*(tab + i)).entree = elem_entree->data;
				DeleteDoubleLinkedListItem(List, elem_entree);
				

				//tirage d'une sortie
				pos = (rand() * (max_index - 1) / RAND_MAX)-1;
				DoubleLinkedListElem* elem_sortie = getDoubleLinkedListElem(List, pos);
				(*(tab + i)).sortie = elem_sortie->data;
				DeleteDoubleLinkedListItem(List, elem_sortie);
				
				DisplayDoubleList(List);
				printf("\n\n");
			}
			for (int j = 0; j < nb_paires; j++) {
				printf("Paire %d = [%d, %d]\n", j + 1, (*(tab + j)).entree, (*(tab + j)).sortie);
			}
			return 1;
		}
	}
	else
		return -1;
}