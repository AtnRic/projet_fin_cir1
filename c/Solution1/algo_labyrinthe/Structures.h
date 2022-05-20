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
char* letter(Lab* L);
/*Fin algo labyrinthe*/

/*T�l�porteurs*/
typedef struct Teleporteur_Pos {
	int x;
	int y;
}Teleporteur_Pos;

typedef struct Teleporteurs_Pair {
	Teleporteur_Pos Teleporteur1;
	Teleporteur_Pos Teleporteur2;
}Teleporteurs_Pair;

//g�n�re les "quantites" t�l�porteurs dans le maze renvoie le tableau comportant les coordonnees des t�l�porteurs
Teleporteurs_Pair* Generation_Teleporteurs(char* maze, int size, int quantites);
/*Fin t�l�porteurs*/

/*Gardes*/
typedef struct Garde {
	int Id; //num�ro du garde

	/* Direction dans laquelle le garde va se d�placer */

	bool t;     //top
	bool d;		//down
	bool r;		//right
	bool l;     //left

	int move; //nombre de case avant de toucher le mur en face et de devoir faire demi-tour
	int position; //position initiale du garde
	int choix;	//Direction vers laquelle le garde va aller jusqu'� ce que se pr�sente devant lui un obstacle
}Garde;

Garde* ApparitionGardes(char* maze, int size, int quantites_pair);
void ChoixMouvementGardes(char* maze, int size, Garde* garde, int Quantite_Garde);
void top(char* maze, int cote, Garde* garde, int i);
void bottom(char* maze, int cote, Garde* garde, int i);
void right(char* maze, int cote, Garde* garde, int i);
void left(char* maze, int cote, Garde* garde, int i);
void MouvementGardes(char* maze, int cote, Garde* garde, int Quantite_Garde);
/*Fin gardes*/