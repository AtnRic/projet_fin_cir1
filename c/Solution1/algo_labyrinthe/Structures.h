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

Graph* createGraph(int S, int B);

//Fonction qui trouve la racine d'un élément i
int find(subset *subsets, int i);

//Fonction qui unit 2 éléments à leurs racines
//L'élément ayant le rang le plus faible est relié à la racine de l'élément ayant le rang le plus élevé
void Union(subset *subsets, int xracine, int yracine);

//Vérifie si le graph contient un cycle ou pas
int isCycle(Graph* graph);

//Algorithme de Kruskal
Graph* Kruskal(Graph* graph, int nombreSommets);

//affichage dans le format souhaité
void affichageDeSesGrandsMorts(Graph* graph);