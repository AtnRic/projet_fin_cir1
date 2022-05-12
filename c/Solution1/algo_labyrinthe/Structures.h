#pragma once

typedef struct Bord {
	int racine;
	int dest;
}Bord;


typedef struct Graph {
	int S;	// S : nombre de sommets
	int B;	// B : Nombre de bord
	struct Bord* Bord; //Graph repr�sent� par un ensemble de bord
}Graph;

typedef struct subset {
	int parent;
	int rang;	//� noter que rang != hauteur
}subset;

typedef struct poids {
	int weight; //valeur du poids
	struct Bord* bord; //pointeur sur le bord auquel le poids est reli�
	struct poids* next; //pointeur vers �l�ment suivant
}poids;

typedef struct LinkedListPoids {
	poids* head; // pointeur vers la t�te de liste (le poids le plus petit)
	int size;
	poids* tail; // pointeur vers la queue de liste
} LinkedListPoids;

Graph* createGraph(int S, int B);

//Fonction qui trouve la racine d'un �l�ment i
int find(subset subsets[], int i);

//Fonction qui unit 2 �l�ments � leurs racines
//L'�l�ment ayant le rang le plus faible est reli� � la racine de l'�l�ment ayant le rang le plus �lev�
void Union(subset subsets[], int xracine, int yracine);

//V�rifie si le graph contient un cycle ou pas
int isCycle(Graph* graph);

//Algorithme de Kruskal
int Kruskal(Graph* graph, int S, int B);