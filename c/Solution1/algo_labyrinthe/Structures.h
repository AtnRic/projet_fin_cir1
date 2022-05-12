#pragma once

typedef struct Bord {
	int racine;
	int dest;
}Bord;


typedef struct Graph {
	int S;	// S : nombre de sommets
	int B;	// B : Nombre de bord
	struct Bord* Bord; //Graph représenté par un ensemble de bord
}Graph;

typedef struct subset {
	int parent;
	int rang;	//à noter que rang != hauteur
}subset;

typedef struct poids {
	int weight; //valeur du poids
	struct Bord* bord; //pointeur sur le bord auquel le poids est relié
	struct poids* next; //pointeur vers élément suivant
}poids;

typedef struct LinkedListPoids {
	poids* head; // pointeur vers la tête de liste (le poids le plus petit)
	int size;
	poids* tail; // pointeur vers la queue de liste
} LinkedListPoids;

Graph* createGraph(int S, int B);

//Fonction qui trouve la racine d'un élément i
int find(subset subsets[], int i);

//Fonction qui unit 2 éléments à leurs racines
//L'élément ayant le rang le plus faible est relié à la racine de l'élément ayant le rang le plus élevé
void Union(subset subsets[], int xracine, int yracine);

//Vérifie si le graph contient un cycle ou pas
int isCycle(Graph* graph);

//Algorithme de Kruskal
int Kruskal(Graph* graph, int S, int B);