#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "structures.h"



//Ce qui doit être obtenu
/*var labyrinthe = [
		["k", "f", "b", "f", "f", "f", "b", "f", "f", "o"],
		["e", "h", "g", "m", "b", "h", "g", "m", "f", "h"],
		["l", "g", "j", "f", "d", "g", "g", "k", "f", "i"],
		["n", "j", "f", "h", "k", "d", "a", "a", "f", "c"],
		["e", "f", "h", "j", "i", "a", "i", "g", "k", "i"],
		["g", "n", "j", "f", "b", "f", "f", "i", "j", "o"],
		["g", "j", "f", "f", "i", "k", "h", "k", "f", "h"],
		["j", "f", "f", "f", "f", "i", "j", "d", "o", "l"],
];
var correspondance = {
  //   h  d  b  g
  a : [0, 0, 0, 0] ,
  b : [1, 0, 0, 0] ,
  c : [0, 1, 0, 0] ,
  d : [0, 0, 1, 0] ,
  e : [0, 0, 0, 1] ,
  f : [1, 0, 1, 0] ,
  g : [0, 1, 0, 1] ,
  h : [1, 1, 0, 0] ,
  i : [0, 1, 1, 0] ,
  j : [0, 0, 1, 1] ,
  k : [1, 0, 0, 1] ,
  l : [0, 1, 1, 1] ,
  m : [1, 0, 1, 1] ,
  n : [1, 1, 0, 1] ,
  o : [1, 1, 1, 0] ,
  p : [1, 1, 1, 1] ,
};
console.log(labyrinthe[3][1]);*/

/*Liste chainée double*/
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
	if (tmp != NULL) {
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
	return 0;
}

DoubleLinkedListElem* getDoubleLinkedListElem(DoubleLinkedList* list, int pos) {
	DoubleLinkedListElem* tmp = list->head;
	for (int i = 1; i <= pos; i++) {
		tmp = tmp->next;
	}
	return tmp;
}
/*Fin Liste chainée double*/

/*Tri Fusion*/
void triFusion(int i, int j, int tab[], int tmp[]) {
	if (j <= i) { return; }

	int m = (i + j) / 2;

	triFusion(i, m, tab, tmp);     //trier la moiti� gauche r�cursivement
	triFusion(m + 1, j, tab, tmp); //trier la moiti� droite r�cursivement
	int pg = i;     //pg pointe au d�but du sous-tableau de gauche
	int pd = m + 1; //pd pointe au d�but du sous-tableau de droite
	int c;          //compteur
// on boucle de i � j pour remplir chaque �l�ment du tableau final fusionn�
	for (c = i; c <= j; c++) {
		if (pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
			tmp[c] = tab[pd];
			pd++;
		}
		else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
			tmp[c] = tab[pg];
			pg++;
		}
		else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un �l�ment plus petit
			tmp[c] = tab[pg];
			pg++;
		}
		else {  //le pointeur du sous-tableau de droite pointe vers un �l�ment plus petit
			tmp[c] = tab[pd];
			pd++;
		}
	}
	for (c = i; c <= j; c++) {  //copier les �l�ments de tmp � tab
		tab[c] = tmp[c];
	}
}
/*Fin tri Fusion*/

/*Fichier*/
int readFile(char* filename, int tableau[]) {
	FILE* stream;
	errno_t err;
	//int tableau[2] = { 0 };

	err = fopen_s(&stream, filename, "r");
	if (err == 0)
		printf("Le fichier 'file.txt' est ouvert\n");
	else
		printf("Le fichier 'file.txt' n'est pas ouvert\n");
	if (stream == NULL) {
		printf("\nstream pas OK");
		return -1;
	}
	else printf("\nstream ok");

	fseek(stream, 0, SEEK_SET);

	/*char* value;
	value = fgetc(stream);
	printf("%c", value);*/
	if (stream != NULL) {
		for (int i = 0; i < 2; i++) {
			fscanf_s(stream, "%d", &tableau[i]);
			printf("\ntableau %d : %d", i, tableau[i]);
		}
	}

	if (stream) {
		err = fclose(stream);
		if (err == 0) {
			printf("\nLe fichier 'file.txt' est ferme\n");
			return 1;
		}
			
		else {
			printf("\nLe fichier 'file.txt' n'est pas ferme\n");
			return -1;
		}
	}
	return 1;
}
/*Fin fichier*/

/*Conversion position renvoyée par le fichier csv en lettre*/
char RechercheLettre(char* letter, int LaPosition) {
	char LaPositionLettre;
	LaPositionLettre = *(letter + LaPosition);
	return LaPositionLettre;
}
/*Fin Conversion position renvoyée par le fichier csv en lettre*/

/*Algo labyrinthe*/
int NearCase(Lab* L, int index) {
	printf("INDEX %d - L:%d R:%d T:%d D:%d\n", index, Left(L, index), Right(L, index), Top(L, index), Down(L, index));
	return 0;
}

Free* NewFree(int max) {
	Free* F = (Free*)malloc(sizeof(Free));
	if (F != NULL) {
		F->List = (int*)malloc(sizeof(int*) * max);
		F->Size = 0;
	}
	return F;
}

Lab* NewLab(int size) {
	Lab* N = (Lab*)malloc(sizeof(Lab));
	if (N != NULL) {
		(N->tab) = (Cell*)malloc(sizeof(Cell) * size * size);
		if (N->tab == NULL) {
			printf("Erreur d'initialisation du labyrinthe. {1}");
		}
		else {
			for (int i = 0; i < size * size; i++) {
				(N->tab + i)->d = true;
				(N->tab + i)->l = true;
				(N->tab + i)->r = true;
				(N->tab + i)->t = true;
				(N->tab + i)->used = false;
			}
		}
		N->size = size;
		return N;
	}
	else {
		printf("Erreur d'initialisation du labyrinthe. {2}");
	}
	return N;
}

int Launch(Lab* L) {
	if (L == NULL) {
		printf("Labyrinthe vide.");
		return 0;
	}
	Cell* origin = L->tab;
	return EXIT_SUCCESS;
}
int tryPath(Lab* L, int index, Free* F) {
	char wall = r_CaseNear(L, index);
	//printf("%d(%c)-", index, (L->tab+index)->used ? 'y' : 'n');
	if (!Isolate(L, index)) {
		printf("%d ", index);
		(*(F->List + F->Size)) = index;
		F->Size++;
	}
	switch (wall) {
	case 'l':
		(L->tab + index)->used = true;
		DelWall(L, index, 'l');
		if (Left(L, index) != -1) {
			//printf("\nNext(%c)\n", (L->tab + Left(L, index))->used ? 'y' : 'n');
			return tryPath(L, Left(L, index), F);
		}
	case 'r':
		(L->tab + index)->used = true;
		DelWall(L, index, 'r');
		if (Right(L, index) != -1) {
			//printf("\nNext(%c)\n", (L->tab + Right(L, index))->used ? 'y' : 'n');
			return tryPath(L, Right(L, index), F);
		}
	case 't':
		(L->tab + index)->used = true;
		DelWall(L, index, 't');
		if (Top(L, index) != -1) {
			//printf("\nNext(%c)\n", (L->tab + Top(L, index))->used ? 'y' : 'n');
			return tryPath(L, Top(L, index), F);
		}
	case 'd':
		(L->tab + index)->used = true;
		DelWall(L, index, 'd');
		if (Down(L, index) != -1) {
			//printf("\nNext(%c)\n", (L->tab + Down(L, index))->used ? 'y' : 'n');
			return tryPath(L, Down(L, index), F);
		}
	case 'n':
		(L->tab + index)->used = true;
	}
	if (F->Size != 0) {

		printf("\033[1m\033[32m");
		printf("END\n");
		printf("\033[0m");
	}
	for (int i = 0; i < F->Size; i++) {
		Free* G = NewFree(1000);
		tryPath(L, (*(F->List + i)), G);
	}
	free(F);
	return 0;
}
char r_CaseNear(Lab* L, int index) {
	int R = ceilf(((float)rand() / (float)RAND_MAX) * 4.0);
	switch (R) {

	case 1:
		if (Right(L, index) != -1)
		{
			return 'r';
		}
		else
		{
			if (!Isolate(L, index))
			{
				return r_CaseNear(L, index);
			}
			else
			{
				break;
			}
		}
		break;
	case 2:
		if (Top(L, index) != -1)
		{
			return 't';
		}
		else
		{
			if (!Isolate(L, index))
			{
				return r_CaseNear(L, index);
			}
			else
			{
				break;
			}
		}
		break;
	case 3:
		if (Down(L, index) != -1)
		{
			return 'd';
		}
		else
		{
			if (!Isolate(L, index))
			{
				return r_CaseNear(L, index);
			}
			else
			{
				break;
			}
		}
		break;
	case 4:
		if (Left(L, index) != -1)
		{
			return 'l';
		}
		else
		{
			if (!Isolate(L, index))
			{
				return r_CaseNear(L, index);
			}
			else
			{
				break;
			}
		}
		break;
	}
	return 'n';
}
bool Isolate(Lab* L, int index) {
	if (Right(L, index) == -1 && Left(L, index) == -1 && Top(L, index) == -1 && Down(L, index) == -1) {
		//printf("%d Isolated %d %d %d %d\n", index, Right(L, index), Left(L, index), Top(L, index), Down(L, index));
		return true;
	}
	else {
		//printf("%d Not isolated%d %d %d %d\n", index, Right(L, index), Left(L, index), Top(L, index), Down(L, index));
		return false;
	}
}
int Left(Lab* L, int index) {
	printf("\033[1m\033[31m");
	int size = L->size;
	Cell* origin = L->tab;
	if ((index % size) == 0) {
		//printf("Left %d : NULL\n", index);
		return -1;
	}
	if (((origin + index - 1)->used)) {
		//printf("Left %d : USED\n", index);
		return -1;
	}
	else {
		if (index - 1 > L->size * L->size) {
			//printf("\nIndex problem %d\n", index - 1);
		}
		return (index - 1);
	}	printf("\033[0m");
}
int Right(Lab* L, int index) {
	printf("\033[1m\033[31m");
	int size = L->size;
	Cell* origin = L->tab;
	if ((index + 1) % size == 0) {
		//printf("Right %d : NULL\n", index);
		return -1;
	}

	if (((origin + index + 1)->used)) {
		//printf("Right %d : %c : USED\n", index+1, ((origin + index + 1)->used) ? 'y':'n');
		return -1;
	}
	else {
		if (index + 1 > L->size * L->size) {
			//printf("\nIndex problem %d\n", index + 1);
		}
		return (index + 1);
	}	printf("\033[0m");
}
int Top(Lab* L, int index) {
	printf("\033[1m\033[31m");
	int size = L->size;
	Cell* origin = L->tab;
	if (index < size) {
		//printf("Top %d : NULL\n", index);
		return -1;
	}
	if (((origin + index - size)->used)) {
		//printf("Top %d : USED\n", index);
		return -1;
	}
	else {
		if (index - size > L->size * L->size) {
			//printf("\nIndex problem %d\n", index - size);
		}
		return (index - size);
	}	printf("\033[0m");
}
int Down(Lab* L, int index) {
	printf("\033[1m\033[31m");
	int size = L->size;
	Cell* origin = L->tab;

	if (index >= ((size * size) - size)) {
		//printf("Bottom %d : NULL\n", index);
		return -1;
	}
	if (((origin + index + size)->used)) {
		return -1;
	}
	else {
		if (index + size > L->size * L->size) {
			//printf("\nIndex problem %d\n", index + size);
		}
		return (index + size);
	}
	printf("\033[0m");
}

// wall = t, d, l, r
int DelWall(Lab* L, int index, char wall) {


	if (L == NULL || index == -1 || index >= (L->size * L->size)) {
		printf("Error");
		return -1;
	}
	if ((L->tab + index) == NULL) {
		printf("Error");
		return -1;
	}

	switch (wall)
	{
	case 'l':
		(L->tab + index)->l = false;
		if (Left(L, index) != -1)
		{
			(L->tab + Left(L, index))->r = false;
		}
		else {
			printf("null1");
		}
		break;
	case 'r':
		(L->tab + index)->r = false;
		if (Right(L, index) != -1)
		{
			(L->tab + Right(L, index))->l = false;
		}
		else {
			printf("null2");
		}
		break;
	case 't':
		(L->tab + index)->t = false;
		if (Top(L, index) != -1)
		{
			(L->tab + Top(L, index))->d = false;;
		}
		else {
			printf("null3");
		}
		break;
	case 'd':
		(L->tab + index)->d = false;
		if (Down(L, index) != -1)
		{
			(L->tab + Down(L, index))->t = false;
		}
		else {
			printf("null4");
		}
		break;
	}
	return 1;
}
int show(Lab* L, Path* P) {
	printf("\nLabyrinthe * Taille : %d : \n", L->size);
	//for (int i = 0; i < L->size * L->size; i++)
	//{
	//	if ((L->tab + i)->t == 0 || (L->tab + i)->r == 0 || (L->tab + i)->l == 0 || (L->tab + i)->d == 0) {
	//		printf("\033[31m");
	//	}
	//	else {
	//		printf("\033[32m");
	//	}
	//	//printf("Cell %d : t%d, d%d, l%d, r%d\n", i, (L->tab + i)->t, (L->tab + i)->d, (L->tab + i)->l, (L->tab + i)->r);
	//}

	printf("\033[0m");
	for (int w = 0; w < L->size; w++) {
		for (int i = 0; i < L->size; i++) {
			int index = (L->size * w + i);
			if (Contains(P, index)) {
				printf("\033[1m\033[32m");
			}
			else {
				printf("\033[0m");
			}
			if ((L->tab + index)->t == 1) {
				printf("-----");
			}
			if ((L->tab + index)->t == 0) {

				printf("     ");
			}
		}
		printf("\n");
		for (int i = 0; i < L->size; i++) {
			int index = (L->size * w + i);
			char p = ' ';
			if (Contains(P, index)) {
				printf("\033[1m\033[32m");
				p = 'x';
			}
			else {
				printf("\033[0m");
				p = ' ';
			}
			if ((L->tab + index)->l == 1 && (L->tab + index)->r == 1) {
				printf("| %c |", p);
			}
			else if ((L->tab + index)->l == 0 && (L->tab + index)->r == 1) {
				printf("  %c |", p);
			}
			else if ((L->tab + index)->l == 1 && (L->tab + index)->r == 0) {
				printf("| %c  ", p);
			}
			else if ((L->tab + index)->l == 0 && (L->tab + index)->r == 0) {
				printf("  %c  ", p);
			}
		}
		printf("\n");
		if (w == L->size - 1) {
			for (int i = 0; i < L->size; i++) {
				int index = (L->size * w + i);
				if (Contains(P, index)) {
					printf("\033[1m\033[32m");
				}
				else {
					printf("\033[0m");
				}
				if ((L->tab + index)->d == 1) {
					printf("-----");
				}
				else {
					printf("     ");
				}
			}
		}
	}
	return EXIT_SUCCESS;
}

char* letter(Lab* L) {
	char* c = (char*)malloc(sizeof(char) * L->size * L->size);
	if (c != NULL) {
		for (int i = 0; i < L->size * L->size; i++) {
			if ((i % L->size) == 0 && i != 0 && i != L->size) {
				printf("\n");
			}
			if (!(*(L->tab + i)).t && !(*(L->tab + i)).r && !(*(L->tab + i)).d && !(*(L->tab + i)).l) {
				(*(c + i)) = 'a';
				printf("a");
			}
			if ((*(L->tab + i)).t && !(*(L->tab + i)).r && !(*(L->tab + i)).d && !(*(L->tab + i)).l) {
				(*(c + i)) = 'b';
				printf("b");
			}
			if (!(*(L->tab + i)).t && (*(L->tab + i)).r && !(*(L->tab + i)).d && !(*(L->tab + i)).l) {
				(*(c + i)) = 'c';
				printf("c");
			}
			if (!(*(L->tab + i)).t && !(*(L->tab + i)).r && (*(L->tab + i)).d && !(*(L->tab + i)).l) {
				(*(c + i)) = 'd';
				printf("d");
			}
			if (!(*(L->tab + i)).t && !(*(L->tab + i)).r && !(*(L->tab + i)).d && (*(L->tab + i)).l) {
				(*(c + i)) = 'e';
				printf("e");
			}
			if ((*(L->tab + i)).t && !(*(L->tab + i)).r && (*(L->tab + i)).d && !(*(L->tab + i)).l) {
				(*(c + i)) = 'f';
				printf("f");
			}
			if (!(*(L->tab + i)).t && (*(L->tab + i)).r && !(*(L->tab + i)).d && (*(L->tab + i)).l) {
				(*(c + i)) = 'g';
				printf("g");
			}
			if ((*(L->tab + i)).t && (*(L->tab + i)).r && !(*(L->tab + i)).d && !(*(L->tab + i)).l) {
				(*(c + i)) = 'h';
				printf("h");
			}
			if (!(*(L->tab + i)).t && (*(L->tab + i)).r && (*(L->tab + i)).d && !(*(L->tab + i)).l) {
				(*(c + i)) = 'i';
				printf("i");
			}
			if (!(*(L->tab + i)).t && !(*(L->tab + i)).r && (*(L->tab + i)).d && (*(L->tab + i)).l) {
				(*(c + i)) = 'j';
				printf("j");
			}
			if ((*(L->tab + i)).t && !(*(L->tab + i)).r && !(*(L->tab + i)).d && (*(L->tab + i)).l) {
				(*(c + i)) = 'k';
				printf("k");
			}
			if (!(*(L->tab + i)).t && (*(L->tab + i)).r && (*(L->tab + i)).d && (*(L->tab + i)).l) {
				(*(c + i)) = 'l';
				printf("l");
			}
			if ((*(L->tab + i)).t && !(*(L->tab + i)).r && (*(L->tab + i)).d && (*(L->tab + i)).l) {
				(*(c + i)) = 'm';
				printf("m");
			}
			if ((*(L->tab + i)).t && (*(L->tab + i)).r && !(*(L->tab + i)).d && (*(L->tab + i)).l) {
				(*(c + i)) = 'n';
				printf("n");
			}
			if ((*(L->tab + i)).t && (*(L->tab + i)).r && (*(L->tab + i)).d && !(*(L->tab + i)).l) {
				(*(c + i)) = 'o';
				printf("o");
			}
		}
	}
	return c;
}
/*Fin algo labyrinthe*/

/*Gardes*/
void ApparitionGardes(char* maze, int cote, int Quantite_Garde) {
	srand(time(NULL));
	Garde* garde = (Garde*)malloc(Quantite_Garde*sizeof(Garde));
	if (garde == NULL) return;
	DoubleLinkedList* List = newDoubleLinkedList();
	DoubleLinkedList* LaDirection = newDoubleLinkedList();

	for (int i = 0; i < pow(cote, 2); i++) {
		int count = 0;
		int sortie = 0;
		if (*(maze + i) == 'e' || *(maze + i) == 'j' || *(maze + i) == 'k' || *(maze + i) == 'm') {
			for (int j = 1; j <= 5; j++) {
				if (*(maze + (i + j)) == 'a' || *(maze + (i + j)) == 'b' || *(maze + (i + j)) == 'd') {
					count++;
					sortie++;
				}
				else if (*(maze + (i + j)) == 'f') {
					count++;
				}
				else break;
			}
			if (count >= 3 && sortie >= 1) {
				//ajout i à la liste chainée
				DoubleLinkedListElem* elem = NewDoubleLinkedListItem(i);
				DoubleLinkedListElem* elemDirection = NewDoubleLinkedListItem(1);
				insertItemAtDoubleLinkedListTail(List, elem);
				insertItemAtDoubleLinkedListTail(LaDirection, elemDirection);
			}
		}
		count = 0;
		sortie = 0;
		if (*(maze + i) == 'b' || *(maze + i) == 'h' || *(maze + i) == 'k' || *(maze + i) == 'n') {
			for (int j = 1; j <= 5; j++) {
				if (*(maze + (i + (j * cote))) == 'a' || *(maze + (i + (j * cote))) == 'c' || *(maze + (i + (j * cote))) == 'e') {
					count++;
					sortie++;
				}
				else if (*(maze + (i + (j * cote))) == 'g') {
					count++;
				}
				else break;
			}
			if (count >= 3 && sortie >= 1) {
				//ajout i à la liste chainée
				DoubleLinkedListElem* elem = NewDoubleLinkedListItem(i);
				DoubleLinkedListElem* elemDirection = NewDoubleLinkedListItem(2);
				insertItemAtDoubleLinkedListTail(List, elem);
				insertItemAtDoubleLinkedListTail(LaDirection, elemDirection);
			}
		}
	}
	printf("\n;");
	for (int i = 0; i < Quantite_Garde; i++) {
		int r = rand() % getDoubleLinkedListSize(List);
		(garde + i)->Id = i + 1;
		(garde + i)->position = getDoubleLinkedListElem(List, r)->data;
		(garde + i)->move = getDoubleLinkedListElem(LaDirection, r)->data;
		DeleteDoubleLinkedListItem(List, (garde + i)->position);
		DeleteDoubleLinkedListItem(LaDirection, (garde + i)->move);
		printf("%d:%d,", (garde + i)->position, (garde+i)->move); //;index:direction,
	}
	return;
}

//void top(char* maze, int cote, Garde* garde, int i) {
//	if (maze[(garde + i)->position] != 'b' && maze[(garde + i)->position] != 'f' && maze[(garde + i)->position] != 'h' && maze[(garde + i)->position] != 'k' && maze[(garde + i)->position] != 'm' && maze[(garde + i)->position] != 'n' && maze[(garde + i)->position] != 'o') {
//		(garde + i)->position -= cote;
//		printf("\nNew Garde %d : %d", (garde + i)->Id, (garde + i)->position);
//		(garde+i)->choix = 1;
//	}
//	else {
//		bottom(maze, cote, garde, i);
//	}
//	return;
//}
//
//void bottom(char* maze, int cote, Garde* garde, int i) {
//	if (maze[(garde + i)->position] != 'd' && maze[(garde + i)->position] != 'f' && maze[(garde + i)->position] != 'i' && maze[(garde + i)->position] != 'j' && maze[(garde + i)->position] != 'l' && maze[(garde + i)->position] != 'm' && maze[(garde + i)->position] != 'o') {
//		(garde + i)->position += cote;
//		printf("\nNew Garde %d : %d", (garde + i)->Id, (garde + i)->position);
//		(garde+i)->choix = 2;
//	}
//	else {
//		top(maze, cote, garde, i);
//	}
//	return;
//}
//
//void right(char* maze, int cote, Garde* garde, int i) {
//	if (maze[(garde + i)->position] != 'c' && maze[(garde + i)->position] != 'g' && maze[(garde + i)->position] != 'h' && maze[(garde + i)->position] != 'i' && maze[(garde + i)->position] != 'l' && maze[(garde + i)->position] != 'n' && maze[(garde + i)->position] != 'o') {
//		(garde + i)->position += 1;
//		printf("\nNew Garde %d : %d", (garde + i)->Id, (garde + i)->position);
//		(garde+i)->choix = 3;
//	}
//	else left(maze, cote, garde, i);
//	return;
//}
//
//void left(char* maze, int cote, Garde* garde, int i) {
//	if (maze[(garde + i)->position] != 'e' && maze[(garde + i)->position] != 'g' && maze[(garde + i)->position] != 'j' && maze[(garde + i)->position] != 'k' && maze[(garde + i)->position] != 'l' && maze[(garde + i)->position] != 'm' && maze[(garde + i)->position] != 'n') {
//		(garde + i)->position -= 1;
//		printf("\nNew Garde %d : %d", (garde + i)->Id, (garde + i)->position);
//		(garde+i)->choix = 4;
//	}
//	else right(maze, cote, garde, i);
//	return;
//}
//
//void ChoixMouvementGardes(char* maze, int size, Garde* garde, int Quantite_Garde) {
//	int tmp = 0;
//	int count = 0;
//	srand(time(NULL));
//	for (int i = 0; i < Quantite_Garde; i++) {
//		count = 0;
//		if (maze[(garde + i)->position] == 'b' || maze[(garde + i)->position] == 'f' || maze[(garde + i)->position] == 'h' || maze[(garde + i)->position] == 'k' || maze[(garde + i)->position] == 'm' || maze[(garde + i)->position] == 'n' || maze[(garde + i)->position] == 'o')
//			(garde + i)->t = false;
//		else {
//			(garde + i)->t = true;
//			count += 1;
//		}
//			
//		if (maze[(garde + i)->position] == 'c' || maze[(garde + i)->position] == 'g' || maze[(garde + i)->position] == 'h' || maze[(garde + i)->position] == 'i' || maze[(garde + i)->position] == 'l' || maze[(garde + i)->position] == 'n' || maze[(garde + i)->position] == 'o')
//			(garde + i)->r = false;
//		else {
//			(garde + i)->r = true;
//			count += 1;
//		}
//			
//		if (maze[(garde + i)->position] == 'd' || maze[(garde + i)->position] == 'f' || maze[(garde + i)->position] == 'i' || maze[(garde + i)->position] == 'j' || maze[(garde + i)->position] == 'l' || maze[(garde + i)->position] == 'm' || maze[(garde + i)->position] == 'o')
//			(garde + i)->d = false;
//		else {
//			(garde + i)->d = true;
//			count += 1;
//		}
//			
//		if (maze[(garde + i)->position] == 'e' || maze[(garde + i)->position] == 'g' || maze[(garde + i)->position] == 'j' || maze[(garde + i)->position] == 'k' || maze[(garde + i)->position] == 'l' || maze[(garde + i)->position] == 'm' || maze[(garde + i)->position] == 'n')
//			(garde + i)->l = false;
//		else {
//			(garde + i)->l = true;
//			count += 1;
//		}
//		tmp = rand() % count;
//		if ((garde + i)->d == true) {
//			if ((garde + i)->r == true) {
//				if ((garde + i)->t == true) {
//					if ((garde + i)->l == true) {
//						switch (tmp) {
//						case 0: bottom(maze, size, garde, i); break;
//						case 1: top(maze, size, garde, i); break;
//						case 2: right(maze, size, garde, i); break;
//						case 3: left(maze, size, garde, i); break;
//						}
//					}
//					else {
//						switch (tmp) {
//						case 0: bottom(maze, size, garde, i); break;
//						case 1: top(maze, size, garde, i); break;
//						case 2: right(maze, size, garde, i); break;
//						}
//					}
//				}
//				else if ((garde + i)->l == true) {
//					switch (tmp) {
//					case 0: bottom(maze, size, garde, i); break;
//					case 1: left(maze, size, garde, i); break;
//					case 2: right(maze, size, garde, i); break;
//					}
//				}
//				else {
//					switch (tmp) {
//					case 0: bottom(maze, size, garde, i); break;
//					case 2: right(maze, size, garde, i); break;
//					}
//				}
//			}
//			else if ((garde + i)->t == true && (garde + i)->l == true) {
//				switch (tmp) {
//				case 0: bottom(maze, size, garde, i); break;
//				case 1: left(maze, size, garde, i); break;
//				case 2: top(maze, size, garde, i); break;
//				}
//			}
//			else if ((garde + i)->t == true) {
//				switch (tmp) {
//				case 0: bottom(maze, size, garde, i); break;
//				case 1: top(maze, size, garde, i); break;
//				}
//			}
//			else if ((garde + i)->l == true) {
//				switch (tmp) {
//				case 0: bottom(maze, size, garde, i); break;
//				case 1: left(maze, size, garde, i); break;
//				}
//			}
//			else {
//				bottom(maze, size, garde, i);
//			}
//		}
//		else if ((garde + i)->r == true && (garde + i)->t == true && (garde + i)->l == true) {
//			switch (tmp) {
//			case 0: right(maze, size, garde, i); break;
//			case 1: left(maze, size, garde, i); break;
//			case 2: top(maze, size, garde, i); break;
//			}
//		}
//		else if ((garde + i)->r == true && (garde + i)->t == true) {
//			switch (tmp) {
//			case 0: right(maze, size, garde, i); break;
//			case 1: top(maze, size, garde, i); break;
//			}
//		}
//		else if ((garde + i)->t == true && (garde + i)->l == true) {
//			switch (tmp) {
//			case 0: left(maze, size, garde, i); break;
//			case 1: top(maze, size, garde, i); break;
//			}
//		}
//		else if ((garde + i)->r == true && (garde + i)->l == true) {
//			switch (tmp) {
//			case 0: left(maze, size, garde, i); break;
//			case 1: right(maze, size, garde, i); break;
//			}
//		}
//		else if ((garde + i)->r == true) {
//			right(maze, size, garde, i);
//		}
//		else if ((garde + i)->l == true) {
//			left(maze, size, garde, i);
//		}
//		else if ((garde + i)->t == true) {
//			top(maze, size, garde, i);
//		}
//		else {
//			printf("Une erreur est survenue dans l'apparition des gardes");
//		}
//	}
//	return;
//}
//
//
//
//void MouvementGardes(char* maze, int cote, Garde* garde, int Quantite_Garde) {
//	for (int i = 0; i < Quantite_Garde; i++) {
//		switch ((garde + i)->choix) {
//		case 1: top(maze, cote, garde, i); break;
//		case 2: bottom(maze, cote, garde, i); break;
//		case 3: right(maze, cote, garde, i); break;
//		case 4: left(maze, cote, garde, i); break;
//		}
//	}
//}
/*Fin Gardes*/

/*Téléporteurs*/
Teleporteurs_Paire* recherche_loc_tp(int nb_paires, char* maze, int size) {
	/*recherche localisation des tp*/
	DoubleLinkedList* List = newDoubleLinkedList();
	if (nb_paires >= size / 2) return NULL;


	for (int i = 1; i < size - 1; i++) {
		if (*(maze + i) == 'l' || *(maze + i) == 'm' || *(maze + i) == 'n' || *(maze + i) == 'o') {
			DoubleLinkedListElem* elem = NewDoubleLinkedListItem(i);
			insertItemAtDoubleLinkedListTail(List, elem);
		}
	}
	//printf("positions trouvees :\n");
	//DisplayDoubleList(List);



	/*Creation de paires de tp*/
	//printf("\nCreation des paires de teleporteurs :\n");
	Teleporteurs_Paire* tab = (Teleporteurs_Paire*)malloc(sizeof(Teleporteurs_Paire) * nb_paires);
	srand(time(NULL));

	int pos;
	if (tab != NULL) {
		for (int i = 0; i < nb_paires; i++) {
			int max_index = getDoubleLinkedListSize(List);

			//tirage d'une entrée
			pos = (rand() * max_index / RAND_MAX) - 1;
			DoubleLinkedListElem* elem_entree = getDoubleLinkedListElem(List, pos);

			(*(tab + i)).entree = elem_entree->data;
			DeleteDoubleLinkedListItem(List, elem_entree);


			//tirage d'une sortie
			pos = (rand() * (max_index - 1) / RAND_MAX) - 1;
			DoubleLinkedListElem* elem_sortie = getDoubleLinkedListElem(List, pos);
			(*(tab + i)).sortie = elem_sortie->data;
			DeleteDoubleLinkedListItem(List, elem_sortie);

			//DisplayDoubleList(List);
			//printf("\n\n");
		}
		for (int j = 0; j < nb_paires; j++) {
			//printf("Paire %d = [%d, %d]\n", j + 1, (*(tab + j)).entree, (*(tab + j)).sortie);
		}
		return tab;
	}
	return NULL;
}
/*Fin Téléporteurs*/

int printPath(Path* P) {
	printf("\033[1m\033[31m");
	printf("\n");
	printf("Path size : %d | ", P->pathSize);
	for (int i = 0; i < P->pathSize; i++) {
		printf("%d->", (*(P->cells + i)));
	}
	printf(" | END\n");
	printf("\033[0m");
	printf("\n");
	return 0;
}

int wLeft(Lab* L, int index) {
	int size = L->size;
	Cell* origin = L->tab;
	if ((index % size) == 0 && index != 0) {
		//printf("Left %d : NULL\n", index);
		return -1;
	}
	else {
		if (index - 1 > L->size * L->size) {
			//printf("\nIndex problem %d\n", index - 1);
		}		
		if (((origin + index)->l) == false) {
			//printf("(l-ok)");
			return (index - 1);
		}
		else {
			//printf("Mur à gauche");
			return -1;
		}
	}
}
int wRight(Lab* L, int index) {
	int size = L->size;
	Cell* origin = L->tab;
	if ((index + 1) % size == 0) {
		//printf("Right %d : NULL\n", index);
		return -1;
	}
	else {
		if (index + 1 > L->size * L->size) {
			//printf("\nIndex problem %d\n", index + 1);
		}
		if (((origin + index)->r) == false) {
			//printf("Aucun à droite");
			return (index + 1);
		}
		else {
			return -1;
			//printf("Mur à droite");
		}
	}
}
int wTop(Lab* L, int index) {
	int size = L->size;
	Cell* origin = L->tab;
	if (index < size) {
		//printf("Top %d : NULL\n", index);
		return -1;
	}
	else {
		if (index - size > L->size * L->size) {
			//printf("\nIndex problem %d\n", index - size);
		}
		if (((origin + index)->t) == false) {
			//printf("Aucun au dessus");
			return (index - size);
		}
		else {
			//printf("Mur au dessus");
			return -1;
		}
	}	
}
int wDown(Lab* L, int index) {
	printf("\033[1m\033[31m");
	int size = L->size;
	Cell* origin = L->tab;

	if (index >= ((size * size) - size)) {
		//printf("Bottom %d : NULL\n", index);
		return -1;
	}
	else {
		if (index + size > L->size * L->size) {
			//printf("\nIndex problem %d\n", index + size);
		}		
		if (((origin + index)->d) == false) {
			//printf("Aucun en dessous");
			return (index + size);
		}
		else {
			//printf("Mur en dessous");
			return -1;
		}
	}
	printf("\033[0m");
}

Path* newPath() 
{
	Path* p = (Path*)malloc(sizeof(Path));
	if (p != NULL) {
		p->cells = (int*)malloc(sizeof(int) * 300);
		//p->tps = (Teleporteurs_Pair*)malloc(sizeof(Teleporteurs_Pair) * 300);
		p->pathSize = 0;
		//p->tpSize = 0;
	}
	return p;
}
Path* clone(Path* basic) 
{
	Path* p = (Path*)malloc(sizeof(Path));
	if (p != NULL) {
		p->cells = (int*)malloc(sizeof(int) * 300);
		//p->tps = (Teleporteurs_Pair*)malloc(sizeof(Teleporteurs_Pair) * 300);
		p->pathSize = 0;
		//p->tpSize = 0;
		for (int i = 0; i < basic->pathSize; i++) {
			if (p->cells != NULL) {
				(*(p->cells + i)) = (*(basic->cells + i));
			}
		}
		/*for (int i = 0; i < basic->tpSize; i++) {
			if (p->tps != NULL) {
				(*(p->tps + i)) = (*(basic->tps + i));
			}
		}
		p->tpSize = basic->tpSize;*/
		p->pathSize = basic->pathSize;
	}
	return p;
}
Path* Solve(Lab* L, Teleporteurs_Pair* pairs, int nbTpPair) {
	Cell* origin = L->tab;
	Path* P = newPath(100);
	return PathIt(L, pairs, nbTpPair, P, 0);
}
Path* PathIt(Lab* Lab, Teleporteurs_Pair* pairs, int nbTpPair, Path* actual, int index) {
	if ((index + 1) == Lab->size * Lab->size) {
		(*(actual->cells + actual->pathSize)) = index;
		actual->pathSize++;
		printf("\nLast case call. %d \n", actual->pathSize);
		printPath(actual);
		return actual;
	}
	if (index != -1) {
		(*(actual->cells + actual->pathSize)) = index;
		actual->pathSize++;
		Path* R = NULL;
		Path* L = NULL;
		Path* T = NULL;
		Path* D = NULL;

		if (!Contains(actual, wRight(Lab, index))) {
			R = PathIt(Lab, pairs, nbTpPair, clone(actual), wRight(Lab, index));
			if (R != NULL) {
				
			}
		}
		if (!Contains(actual, wLeft(Lab, index))) {
			L = PathIt(Lab, pairs, nbTpPair, clone(actual), wLeft(Lab, index));
		}
		if (!Contains(actual, wTop(Lab, index))) {
			T = PathIt(Lab, pairs, nbTpPair, clone(actual), wTop(Lab, index));
		}
		if (!Contains(actual, wDown(Lab, index))) {
			D = PathIt(Lab, pairs, nbTpPair, clone(actual), wDown(Lab, index));
		}


		if (D == NULL && R == NULL && T == NULL && L == NULL) {
			//printf("NULL");
			return NULL;
		}
		else {
			if (R != NULL) {
				return R;
			}
			if (L != NULL) {
				return L;
			}
			if (T != NULL) {
				return T;
			}
			if (D != NULL) {
				return D;
			}
		}
		//else {
		//	Path* F = (Path*)malloc(sizeof(Path) * 4);
		//	Path* Smaller = (Path*)malloc(sizeof(Path));
		//	if (F != NULL) {
		//		if (R != NULL && R->pathSize >= 0) {
		//			(*(F)) = (*R);
		//			printf(" P%d ", (F->pathSize));
		//			printf(" P%d ", (R->pathSize));
		//			Smaller = R;
		//		}
		//		if (L != NULL && L->pathSize >= 0) {
		//			(*(F + 1)) = (*L);
		//			printf(" P%d ", (F->pathSize));
		//			printf(" P%d ", (L->pathSize));
		//			Smaller = L;
		//		}
		//		if (T != NULL && T->pathSize >= 0) {
		//			(*(F + 2)) = (*T);
		//			printf(" P%d ", (F->pathSize));
		//			printf(" P%d ", (T->pathSize));
		//			Smaller = T;
		//		}
		//		if (D != NULL && D->pathSize >= 0) {
		//			(*(F + 3)) = (*D);
		//			printf(" P%d ", (F->pathSize));
		//			printf(" P%d ", (D->pathSize));
		//			Smaller = D;
		//		}
		//		for (int i = 0; i < 4; i++) {
		//			if ((F + i) != NULL && Smaller != NULL) {
		//				if (((F + i)->pathSize) < (Smaller->pathSize)) {
		//					Smaller = (F + i);
		//				}
		//			}
		//		}
		//	}
		//	if (Smaller != NULL) {
		//		printPath(Smaller);
		//	}
		//	return Smaller;
		//}
	}
	else {
		return NULL;
	}
}

bool Contains(Path* actual, int index) {
	for (int i = 0; i < actual->pathSize; i++) {
		if ((*(actual->cells + i)) == index) {
			return true;
		}
	}
	return false;
}
int Check(Teleporteurs_Pair* pair, int nbTpPair, int labSize, int index) {
	
	for (int i = 0; i < nbTpPair; i++) {
		Teleporteur_Pos p1 = (pair + i)->Teleporteur1;
		Teleporteur_Pos p2 = (pair + i)->Teleporteur2;
		if (p1.x + (p2.y * labSize) == index) {
			// tp.
		}
		else {
			// no tp.
		}
	}
	return 0;
}

bool verifHaut(char posHero) {
	if (posHero == 'a' || posHero == 'c' || posHero == 'd' || posHero == 'e' || posHero == 'g' || posHero == 'i' || posHero == 'j' || posHero == 'l') {
		return true; // Pas de mur
	}
	else {
		return false; // mur
	}
}

bool verifDroite(char posHero) {
	if (posHero == 'a' || posHero == 'b' || posHero == 'd' || posHero == 'e' || posHero == 'f' || posHero == 'j' || posHero == 'k' || posHero == 'm') {
		return true; // Pas de mur
	}
	else {
		return false; // mur
	}
}

bool verifBas(char posHero) {
	if (posHero == 'a' || posHero == 'b' || posHero == 'c' || posHero == 'e' || posHero == 'g' || posHero == 'h' || posHero == 'k' || posHero == 'n') {
		return true; // Pas de mur
	}
	else {
		return false; // mur
	}
}

bool verifGauche(char posHero) {
	if (posHero == 'a' || posHero == 'b' || posHero == 'c' || posHero == 'd' || posHero == 'f' || posHero == 'h' || posHero == 'i' || posHero == 'o') {
		return true; // Pas de mur
	}
	else {
		return false; // mur
	}
}

void infoPositionHero() {
	/* Récupère la valeur de la position de héros dans le fichier CaCLC.csv */
	//char* posHero = readFile("CaCLC.csv");
	//printf("Valeur : %c", posHero);
	char* posHero = "a";

	if (verifHaut(posHero)) {
		printf("Haut : pas de mur\n");
	}
	else {
		printf("Haut : mur\n");
	}
	if (verifDroite(posHero)) {
		printf("Droite : pas de mur\n");
	}
	else {
		printf("Droite : mur\n");
	}
	if (verifBas(posHero)) {
		printf("Bas : pas de mur\n");
	}
	else {
		printf("Bas : mur\n");
	}
	if (verifGauche(posHero)) {
		printf("Gauche : pas de mur\n");
	}
	else {
		printf("Gauche : mur\n");
	}
}

void MouvementHero(int cote) {
	int tableau[2] = { 0 };
	readFile("CaCLC.csv", tableau);

	for (int i = 0; i < 2; i++) {
		printf("\nValeur : %d\n", tableau[i]);
	}
	int OneDirection = tableau[0];
	int ClaPosition = tableau[1];
	switch (OneDirection) {
	case 1:
		if (verifHaut) {
			if (/*Téléporteur*/true) {

			}
			else {
				ClaPosition -= cote;
				printf("%d", ClaPosition);
				break;
			}

		}
		else return -1;
	case 2:
		if (verifDroite) {
			ClaPosition += 1;
			printf("%d", ClaPosition);
			break;
		}
		else return -1;

	case 3:
		if (verifGauche) {
			ClaPosition -= 1;
			break;
		}
		else return -1;
	case 4:
		if (verifBas) {
			ClaPosition += cote;
			break;
		}
		else return -1;
	}
	return 1;
}

int main() {

	//Garde* garde = (Garde*)malloc(sizeof(Garde));
	//srand(time(NULL));
	Lab* newl = NewLab(10);
	Free* P = NewFree(100);
	int o = tryPath(newl, 0, P);
	////show(newl);
	letter(newl);
	//Generation_Teleporteurs(letter(newl), 40, 3);
	//ApparitionGardes(letter(newl), 40, 3);
	//ChoixMouvementGardes(letter(newl), 40, garde, 3);
	//MouvementGardes(letter(newl), 40, garde, 3);
	// 

	////letter(newl);
	//Teleporteurs_Pair* pairs = NULL;
	//Path* S = Solve(newl, pairs, 3);
	//show(newl, S);
	//printf("TAILLE : %d \n", S->pathSize);
	//printPath(S);
	//return EXIT_SUCCESS;
	ApparitionGardes(letter(newl), 10, 3);
	//printPath(S);
	int tableau[2] = { 0 };
	readFile("CaCLC.csv", tableau);
	
	for (int i = 0; i < 2; i++) {
		printf("\nValeur : %d\n", tableau[i]);
	}
	int OneDirection = tableau[0];
	int ClaPosition = tableau[1];
	printf("\ndir : %d", OneDirection);
	printf("\nposition : %d", ClaPosition);
	printf("\n");
	char LettrePosition = RechercheLettre(letter(newl), ClaPosition);
	printf("\nLettre Position : %c\n", LettrePosition);
	
	/* Récupère la valeur de la position de héros dans le fichier CaCLC.csv  */
	//char* posHero = readFile("CaCLC.csv");
	if (verifHaut(LettrePosition)) {
		printf("Haut \t: \tpas de mur\n");
	}
	else {
		printf("Haut \t: \tmur\n");
	}
	if (verifDroite(LettrePosition)) {
		printf("Droite \t: \tpas de mur\n");
	}
	else {
		printf("Droite \t: \tmur\n");
	}
	if (verifBas(LettrePosition)) {
		printf("Bas \t: \tpas de mur\n");
	}
	else {
		printf("Bas \t: \tmur\n");
	}
	if (verifGauche(LettrePosition)) {
		printf("Gauche \t: \tpas de mur\n");
	}
	else {
		printf("Gauche \t: \tmur\n");
	}
	//readFile("CaCLC.csv");
	MouvementHero(40);
	//infoPositionHero();
	return EXIT_SUCCESS;
}


