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

/*-----------Liste chainée POUR LE GARDE---------------*/

typedef struct LinkedElemGuard {
	//pas encore adapté au garde
	int data;
	struct LinkedElemGuard* next;
	struct LinkedElemGuard* previous;
}LinkedElemGuard;

typedef struct LinkedListGuard{
	struct LinkedElemGuard* head;
	struct LinkedElemGuard* tail;
	int size;
}LinkedListGuard;

/*---------------Définition du garde-------------------*/

typedef struct Guard {
	//Position du garde sur la grille
	int posy;
	int posx;

	//Les valeurs sont true s'il n'y a pas de mur a {gauche, droite, en haut, en bas} du garde
	bool left;
	bool right;
	bool up;
	bool down;

	/*valeur de déplacement : initialisée puis ne change que lorsque que la garde touche un mur
	peut prendre 1 2 3 4 comme valeurs (gauche droite haut bas)
	ex : si le garde se dirige à gauche (valeur 1) et percute un mur, la valeur devient 2 et le garde repart dans l'autre sens
	//c'était la première idée Wallah, mais Thibaut le boss m'a donné une bête d'idée
	*/

	/*On crée une liste chainée bilatère modélisant la trajectoire (qui n'est que linéaire étant donné qu'on ne peut pas faire d'aléatoire)*/
	LinkedListGuard* deplacementGarde;
}Guard;

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

//crée une liste chainée bilatère pour la trajectoire du garde
LinkedListGuard* newLinkedListGuard();

//forme case par case la trajectoire du garde
int DrawTrajGuard(LinkedListGuard* list, LinkedElemGuard* newItem);