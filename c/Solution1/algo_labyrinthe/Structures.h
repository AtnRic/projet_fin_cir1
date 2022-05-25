#pragma once

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


/*T�l�porteurs*/
typedef struct Teleporteur_Pos {
	int x;
	int y;
}Teleporteur_Pos;

typedef struct Teleporteurs_Pair {
	Teleporteur_Pos Teleporteur1;
	Teleporteur_Pos Teleporteur2;
}Teleporteurs_Pair;






int Right(Lab* L, int index);
int Left(Lab* L, int index);
int Top(Lab* L, int index);
int Down(Lab* L, int index);
bool Isolate(Lab* L, int index);
int DelWall(Lab* L, int index, char wall);
char r_CaseNear(Lab* L, int index);
int tryPath(Lab* L, int index, Free* F);
Lab* NewLab(int size);

Free* NewFree(int max);
char* letter(Lab* L);
/*Fin algo labyrinthe*/



//g�n�re les "quantites" t�l�porteurs dans le maze renvoie le tableau comportant les coordonnees des t�l�porteurs
typedef struct Teleporteurs_Paire {
	int entree;
	int sortie;
}Teleporteurs_Paire;

Teleporteurs_Paire* recherche_loc_tp(int nb_paires, char* maze, int size);
/*Fin t�l�porteurs*/

/*Gardes*/
typedef struct Garde {
	int Id; //num�ro du garde

	/* Direction dans laquelle le garde va se d�placer */

	bool t;     //top
	bool d;  //down
	bool r;  //right
	bool l;     //left

	int move; //nombre de case avant de toucher le mur en face et de devoir faire demi-tour
	int choix;
	int position;
}Garde;

void ApparitionGardes(char* maze, int cote, int Quantite_Garde);
void ChoixMouvementGardes(char* maze, int size, Garde* garde, int Quantite_Garde);
void MouvementGardes(char* maze, int cote, Garde* garde, int Quantite_Garde);
void top(char* maze, int cote, Garde* garde, int i);
void bottom(char* maze, int cote, Garde* garde, int i);
void right(char* maze, int cote, Garde* garde, int i);
void left(char* maze, int cote, Garde* garde, int i);
/*Fin gardes*/

/*Fichier lecture*/
int readFile(char* filename, int tableau[]);
/*Fin fichier lecture*/

/*Conversion position renvoy�e par le fichier csv en lettre*/
char RechercheLettre(char* letter, int LaPosition);
/*Fin Conversion position renvoy�e par le fichier csv en lettre*/
typedef struct Path {
	int* cells;
	int pathSize;
	//Teleporteurs_Pair* tps;
	//int tpSize;
}Path;

bool Contains(Path* actual, int index);
Path* newPath();
Path* clone(Path* base);
Path* Solve(Lab* L, Teleporteurs_Pair* pairs, int nbTpPair);
Path* PathIt(Lab* Lab, Teleporteurs_Pair* pairs, int nbTpPair, Path* actual, int index);
int Check(Teleporteurs_Pair* pair, int nbTpPair, int labSize, int index);
int show(Lab* L, Path* P); 
int printPath(Path* P);
int wLeft(Lab* L, int index);
int wRight(Lab* L, int index);
int wTop(Lab* L, int index);
int wDown(Lab* L, int index);
bool verifHaut(char* posHero);
bool verifDroite(char* posHero);
bool verifBas(char* posHero);
bool verifGauche(char* posHero);
void infoPositionHero();

/*Liste Chain�e double*/
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
/*Fin liste chain�e double*/