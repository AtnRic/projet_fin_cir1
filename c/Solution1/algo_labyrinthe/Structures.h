#pragma once

typedef struct Bord {
	int racine;
	int dest;
	int weight;
}Bord;


typedef struct Graph {
	int S;	// S : nombre de sommets
	int B;	// B : Nombre de bord
	struct Bord* Bord; //Graph représenté par un ensemble de bord
}Graph;

typedef struct Data {
	int haut;
	int droite;
	int bas;
	int gauche;
}Data;

typedef struct subset {
	int parent;
	int rang;	//à noter que rang != hauteur
	struct Bord* Bord;
	struct Data* data;
	char dataRenvoye[];
}subset;

typedef struct Tab {
	struct Data* data;
	int idcase;
	int passage;
}Tab;

Graph* createGraph(int S, int B);

//Fonction qui trouve la racine d'un élément i
int find(subset *subsets, int i, Graph* graph);

//Fonction qui unit 2 éléments à leurs racines
//L'élément ayant le rang le plus faible est relié à la racine de l'élément ayant le rang le plus élevé
void Union(subset *subsets, int xracine, int yracine);

//Vérifie si le graph contient un cycle ou pas
int isCycle(Graph* graph);
/*
int PremierPavéDeElseIf(int U, int V, int nombreSommets);
int DeuxièmePavéDeElseIf(subset* subsets, int nombreSommets);
//Algorithme de Kruskal
Graph* Kruskal(Graph* graph, int nombreSommets);*/

int Labyrinthe(int cote, Tab* tab, int piege, int teleporteur);
//affichage dans le format souhaité
void affichageDeSesGrandsMorts(Graph* graph);

/*Début Pile*/
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