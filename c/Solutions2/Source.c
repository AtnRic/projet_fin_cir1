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


typedef struct Cell {
	bool t;
	bool d;
	bool l; 
	bool r; // top, down, left, right.
	bool used;
}Cell;
typedef struct LastCell {
	Cell* cells;
	int size;
}LastCell;
typedef struct Lab {
	Cell* tab;
	int size;
}Lab;
typedef struct Free {
	int* List;
	int Size;
}Free;

int Right(Lab* L, int index);
int Left(Lab* L, int index);
int Top(Lab* L, int index);
int Down(Lab* L, int index);
bool Isolate(Lab* L, int index);
int DelWall(Lab* L, int index, char wall);
char r_CaseNear(Lab* L, int index);
int tryPath(Lab* L, int index, Free* F);
Lab* NewLab(int size);
int show(Lab* L);
Free* NewFree(int max);

int main() {
	srand(time(NULL));
	Lab* newl = NewLab(40);
	Free* P = NewFree(100);
	int o = tryPath(newl, 0, P);
	show(newl);

}


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
	Cell * origin = L->tab;
	return EXIT_SUCCESS;
}

int tryPath(Lab* L, int index, Free* F) {
	char wall = r_CaseNear(L, index);	
	//printf("%d(%c)-", index, (L->tab+index)->used ? 'y' : 'n');
	if (!Isolate(L, index)) {
		printf("%d ", index);
		(* (F->List + F->Size)) = index;
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
	if (Right(L, index) == - 1 && Left(L, index) == -1 && Top(L, index) == -1 && Down(L, index) == -1) {
		//printf("%d Isolated %d %d %d %d\n", index, Right(L, index), Left(L, index), Top(L, index), Down(L, index));
		return true;
	}
	else {
		//printf("%d Not isolated%d %d %d %d\n", index, Right(L, index), Left(L, index), Top(L, index), Down(L, index));
		return false;
	}
}


int Left(Lab * L, int index) {
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
		if (index-1 > L->size*L->size) {
			//printf("\nIndex problem %d\n", index - 1);
		}		
		return (index - 1);
	}	printf("\033[0m");
}

int Right(Lab* L, int index) {
	printf("\033[1m\033[31m");
	int size = L->size;
	Cell* origin = L->tab;
	if ((index+1) % size == 0) {
		//printf("Right %d : NULL\n", index);
		return -1;
	}
	
	if (((origin + index + 1)->used)) {
		//printf("Right %d : %c : USED\n", index+1, ((origin + index + 1)->used) ? 'y':'n');
		return -1;
	}
	else {
		if (index + 1 > L->size*L->size) {
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
		if (index - size > L->size*L->size) {
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
		if (index + size > L->size*L->size) {
			//printf("\nIndex problem %d\n", index + size);
		}		
		return (index + size);
	}
	printf("\033[0m");
}

// wall = t, d, l, r
int DelWall(Lab* L, int index, char wall) {


	if (L == NULL || index == -1 || index >= (L->size*L->size)) {
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
