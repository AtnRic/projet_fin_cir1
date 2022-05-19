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

/*Téléporteurs*/
typedef struct Teleporteur_Pos {
	int x;
	int y;
}Teleporteur_Pos;

typedef struct Teleporteurs_Pair {
	Teleporteur_Pos Teleporteur1;
	Teleporteur_Pos Teleporteur2;
}Teleporteurs_Pair;

//génére les "quantites" téléporteurs dans le maze renvoie le tableau comportant les coordonnees des téléporteurs
Teleporteurs_Pair* Generation_Teleporteurs(char* maze, int size, int quantites);
/*Fin téléporteurs*/

/*Gardes*/
typedef struct Garde {
	int Id; //numéro du garde

	/* Direction dans laquelle le garde va se déplacer */

	bool t;     //top
	bool d;  //down
	bool r;  //right
	bool l;     //left

	int move; //nombre de case avant de toucher le mur en face et de devoir faire demi-tour
}Garde;

Garde* ApparitionGardes(char* maze, int size, int quantites_pair);
void MouvementGardes(char* maze, int size, Garde* garde);
/*Fin gardes*/