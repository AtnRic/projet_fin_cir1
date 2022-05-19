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

int show(Lab* L) {
	printf("\nLabyrinthe * Taille : %d : \n", L->size);
	for (int i = 0; i < L->size * L->size; i++)
	{
		if ((L->tab + i)->t == 0 || (L->tab + i)->r == 0 || (L->tab + i)->l == 0 || (L->tab + i)->d == 0) {
			printf("\033[31m");
		}
		else {
			printf("\033[32m");
		}
		//printf("Cell %d : t%d, d%d, l%d, r%d\n", i, (L->tab + i)->t, (L->tab + i)->d, (L->tab + i)->l, (L->tab + i)->r);
	}
	printf("\033[0m");
	for (int w = 0; w < L->size; w++) {
		for (int i = 0; i < L->size; i++) {
			int index = (L->size * w + i);
			if ((L->tab + index)->t == 1) {
				printf("----");
			}
			if ((L->tab + index)->t == 0) {

				printf("    ");
			}
		}
		printf("\n");
		for (int i = 0; i < L->size; i++) {
			int index = (L->size * w + i);
			if ((L->tab + index)->l == 1 && (L->tab + index)->r == 1) {
				printf("|%c |", (L->tab + index)->used ? ' ' : '0');
				//printf("|    |");
			}
			else if ((L->tab + index)->l == 0 && (L->tab + index)->r == 1) {
				//printf("     |");
				printf(" %c |", (L->tab + index)->used ? ' ' : '0');
			}
			else if ((L->tab + index)->l == 1 && (L->tab + index)->r == 0) {
				//printf("|     ");
				printf("| %c ", (L->tab + index)->used ? ' ' : '0');
			}
			else if ((L->tab + index)->l == 0 && (L->tab + index)->r == 0) {
				//printf("      ");
				printf(" %c  ", (L->tab + index)->used ? ' ' : '0');
			}
		}
		printf("\n");
		if (w == L->size - 1) {
			for (int i = 0; i < L->size; i++) {
				int index = (L->size * w + i);
				if ((L->tab + index)->d == 1) {
					printf("----");
				}
				else {
					printf("    ");
				}
			}
		}
	}
	return EXIT_SUCCESS;
}
/*Fin algo labyrinthe*/

/*Téléporteurs*/
Teleporteurs_Pair* Generation_Teleporteurs(char* maze, int size, int quantites_pair) {
	Teleporteur_Pos* Tab = malloc(sizeof(Teleporteur_Pos));
	if (Tab == NULL)
	{
		printf("erreur allocation mémoire");
	}
	Teleporteur_Pos Teleporteur1 = { 0,0 };
	Teleporteur_Pos Teleporteur2 = { 0,0 };
	char* mur = maze;
	int index = 0;
	//place  toutes les dead end dans un tableau pour facilité le placement des futures téléporteurs
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if ((x == 0 && y == 0) || (x == size - 1 && y == size - 1))
			{
				*(mur + (x * 10 + y) * 8) = 'a';
			}
			if (*(mur + (x * 10 + y) * 8) == 'l' || *(mur + (x * 10 + y) * 8) == 'm' || *(mur + (x * 10 + y) * 8) == 'n' || *(mur + (x * 10 + y) * 8) == 'o')
			{
				if ((Tab + index) == NULL)
				{
					Tab = (Teleporteur_Pos*)realloc(Tab, sizeof(Teleporteur_Pos) * 10);
					if (Tab != NULL)
					{
						printf("allocation réussie");
						(Tab + index)->x = x;
						(Tab + index)->y = y;
						index++;
					}
					else
					{
						printf("erreur allocation mémoire");
					}
				}
				else
				{
					printf("pas besoin d'allocation");
					(Tab + index)->x = x;
					(Tab + index)->y = y;
					printf(" Index :%d\n", index);
					printf("Tab[%d].x = %d \n", index, (Tab + index)->x);
					printf("Tab[%d].x = %d \n", index, (Tab + index)->y);

					index++;
				}
			}
			//printf("mur[%d][%d] = %c \n", x, y, *(mur + (x * 10 + y) * 8));
		}
	}
	//boucles permettant de placer les téléporteurs les plus éloignés possible.
	Teleporteurs_Pair* Tab2 = malloc(sizeof(Teleporteurs_Pair) * quantites_pair);
	/*if (Tab2 == NULL)
	{
		printf("erreur allocation mémoire");
	}*/
	int index2 = index - 1;
	for (int index1 = 0; index1 < quantites_pair; index1++)
	{
		(Tab2 + index1)->Teleporteur1.x = (Tab + index1)->x;
		(Tab2 + index1)->Teleporteur1.y = (Tab + index1)->y;
		(Tab2 + index1)->Teleporteur2.x = (Tab + index2)->x;
		(Tab2 + index1)->Teleporteur2.y = (Tab + index2)->y;
		index2--;

	}
	return Tab2;
}
/*Fin Téléporteurs*/


int main() {
	srand(time(NULL));
	Lab* newl = NewLab(40);
	Free* P = NewFree(100);
	int o = tryPath(newl, 0, P);
	show(newl);
}

