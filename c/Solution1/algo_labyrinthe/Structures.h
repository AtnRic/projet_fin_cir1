#pragma once

/*typedef struct Bord {
	int racine;
	int dest;
	int weight;
}Bord;


typedef struct Graph {
	int S;	// S : nombre de sommets
	int B;	// B : Nombre de bord
	struct Bord* Bord; //Graph repr�sent� par un ensemble de bord
}Graph;*/

typedef struct Data {
	int haut;
	int droite;
	int bas;
	int gauche;
}Data;
/*
typedef struct subset {
	int parent;
	int rang;	//� noter que rang != hauteur
	struct Bord* Bord;
	struct Data* data;
	char dataRenvoye[];
}subset;*/

typedef struct Tab {
	struct Data* data;
	int idcase;
	int passage;
	char lettreRenvoye[];
}Tab;
/*
Graph* createGraph(int S, int B);

//Fonction qui trouve la racine d'un �l�ment i
int find(subset *subsets, int i, Graph* graph);

//Fonction qui unit 2 �l�ments � leurs racines
//L'�l�ment ayant le rang le plus faible est reli� � la racine de l'�l�ment ayant le rang le plus �lev�
void Union(subset *subsets, int xracine, int yracine);

//V�rifie si le graph contient un cycle ou pas
int isCycle(Graph* graph);*/
/*
int PremierPav�DeElseIf(int U, int V, int nombreSommets);
int Deuxi�mePav�DeElseIf(subset* subsets, int nombreSommets);
//Algorithme de Kruskal
Graph* Kruskal(Graph* graph, int nombreSommets);*/

int Labyrinthe(int cote, Tab* tab);
//affichage dans le format souhait�
void affichageDeSesGrandsMorts(Tab* tab, int cote);
int labyrinthe1if(int tmp, Tab* tab, int cote, int posinitial);
int TranscriptionPourJavaScript(Tab* tab, int cote);

/*D�but Pile*/
typedef struct StackElement
{
	int value;
	struct StackElement* next;
}StackElement, * Stack;

Stack new_stack(void);
bool is_empty_stack(Stack st);
void print_stack(Stack st);
Stack push_stack(Stack st, int x);
Stack pop_stack(Stack st);
int top_stack(Stack st);
int stack_length(Stack st);
Stack clear_stack(Stack st);
/*Fin Pile*/

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