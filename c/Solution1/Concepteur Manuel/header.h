#pragma once

typedef struct DoubleLinkedListElem {
	int data;
	struct DoubleLinkedListElem* previous;
	struct DoubleLinkedListElem* next;
} DoubleLinkedListElem;


typedef struct DoubleLinkedList {
	DoubleLinkedListElem* head;
	int size;
	DoubleLinkedListElem* tail;
} DoubleLinkedList;


typedef struct Teleporteurs_Paire {
	int entree;
	int sortie;
	int size;
}Teleporteurs_Paire;

typedef struct CSV_lineStruct {
	char Chaine[900];
} CSV_lineStruct;

// cr�ation d'une nouvelle liste cha�n�e bilat�re vide
// cette fonction renvoie un pointeur sur la nouvelle structure liste cha�n�e bilat�re vide
DoubleLinkedList* newDoubleLinkedList();
// instanciation (cr�ation) d'un �l�ment (maillon) � ins�rer dans une liste cha�n�e bilat�re
// avec stockage de la donn�e value dans l'�l�ment de liste
DoubleLinkedListElem* NewDoubleLinkedListItem(int value);
// affichage des �l�ments d'une liste cha�n�e bilat�re en commen�ant par la t�te
int DisplayDoubleList(DoubleLinkedList* list);


int insertItemAtDoubleLinkedListTail(DoubleLinkedList* list, DoubleLinkedListElem* newItem);



int DeleteDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* elem);



/*Algo labyrinthe*/
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



Teleporteurs_Paire* recherche_loc_tp(int nb_paires, char* maze, int size);



int Right(Lab* L, int index);
int Left(Lab* L, int index);
int Top(Lab* L, int index);
int Down(Lab* L, int index);
bool Isolate(Lab* L, int index);
int DelWall(Lab* L, int index, char wall);
char r_CaseNear(Lab* L, int index);
//char r_CaseNear(Lab* L, int index, bool t, bool d, bool l, bool r);
int tryPath(Lab* L, int index, Free* F);
Lab* NewLab(int size);

Free* NewFree(int max);
char* letter(Lab* L);
char* letterSansPrintf(Lab* L);
/*Fin algo labyrinthe*/


typedef struct Path {
	int* cells;
	int pathSize;
	//Teleporteurs_Pair* tps;
	//int tpSize;
}Path;


Path* newPath();
Path* clone(Path* base);
Path* Solve(Lab* L, Teleporteurs_Paire* pairs, int nbTpPair);
Path* PathItLong(Lab* Lab, Teleporteurs_Paire* pairs, int nbTpPair, Path* actual, int index, bool first);
Path* PathIt(Lab* Lab, Teleporteurs_Paire* pairs, int nbTpPair, Path* actual, int index, bool first);
Path* SolveLong(Lab* L, Teleporteurs_Paire* pairs, int nbTpPair);
int show(Lab* L, Path* P, Teleporteurs_Paire* T, int nbPaire);
bool ContainsPath(Path* actual, int index);
int ContainsTp(int index, Teleporteurs_Paire* T, int nbPaire);
Teleporteurs_Paire* GetStart(int index, Teleporteurs_Paire* T, int nbPaire);
int printPath(Path* P);
int printTp(Teleporteurs_Paire* P, int nbPaire);
int wLeft(Lab* L, int index);
int wRight(Lab* L, int index);
int wTop(Lab* L, int index);
int wDown(Lab* L, int index);
//int mouvementHero(int posHero);

/*Gardes*/
typedef struct Garde {
	int Id; //num�ro du garde

	/* Direction dans laquelle le garde va se d�placer */

	bool t;  //top
	bool d;  //down
	bool r;  //right
	bool l;  //left

	int move; //nombre de case avant de toucher le mur en face et de devoir faire demi-tour
	int choix;
	int position;
}Garde;

void ApparitionGardes(char* maze, int cote, int Quantite_Garde);
/*Fin gardes*/

int readFile(char* filename, int tableau[]);