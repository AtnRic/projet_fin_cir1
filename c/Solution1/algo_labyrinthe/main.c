#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Structures.h"


//Ce qui doit être obtenu

//test
//Ce qui doit �tre obtenu

/*var labyrinthe = [
		["k", "f", "b", "f", "f", "f", "b", "f", "f", "o"],
		["e", "h", "g", "m", "b", "h", "g", "m", "f", "h"],
		["l", "g", "j", "f", "d", "g", "g", "k", "f", "i"],
		["n", "j", "f", "h", "k", "d", "a", "a", "f", "c"],
		["e", "f", "h", "j", "i", "a", "i", "g", "k", "i"],
		["g", "n", "j", "f", "b", "f", "f", "i", "j", "o"],
		["g", "j", "f", "f", "i", "k", "h", "k", "f", "h"],
		["j", "f", "f", "f", "f", "i", "j", "d", "o", "l"],
];
var correspondance = {
  a : [0, 0, 0, 0] ,
  b : [1, 0, 0, 0] ,
  c : [0, 1, 0, 0] ,
  d : [0, 0, 1, 0] ,
  e : [0, 0, 0, 1] ,
  f : [1, 0, 1, 0] ,
  g : [0, 1, 0, 1] ,
  h : [1, 1, 0, 0] ,
  i : [0, 1, 1, 0] ,
  j : [0, 0, 1, 1] ,
  k : [1, 0, 0, 1] ,
  l : [0, 1, 1, 1] ,
  m : [1, 0, 1, 1] ,
  n : [1, 1, 0, 1] ,
  o : [1, 1, 1, 0] ,
  p : [1, 1, 1, 1] ,
};
console.log(labyrinthe[3][1]);*/


/*-----------Liste chainée POUR LE GARDE---------------*/

typedef struct LinkedElemGuard {
	//pas encore adapté au garde
	int data;
	struct LinkedElemGuard* next;
	struct LinkedElemGuard* previous;
}LinkedElemGuard;

typedef struct LinkedListGuard {
	struct LinkedElem* head;
	struct LinkedElem* tail;
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
	LinkedListGuard deplacementGarde;
}Guard;

Graph* createGraph(int S, int B) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->S = S;
	graph->B = B;
	graph->Bord = (Bord*)malloc(graph->B * sizeof(Bord));
	return graph;
}

//Fonction qui trouve la racine d'un élément i
int find(subset subsets[], int i) {
	// Trouve la racine et fait de la racine le parent de i
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

//Fonction qui unit 2 éléments à leurs racines
//L'élément ayant le rang le plus faible est relié à la racine de l'élément ayant le rang le plus élevé
void Union(subset subsets[], int xracine, int yracine) {
	if (subsets[xracine].rang < subsets[yracine].rang) {
		subsets[xracine].parent = yracine;
		return;
	}
	else if (subsets[xracine].rang > subsets[yracine].rang) {
		subsets[yracine].parent = xracine;
		return;
	}
	else { //cas où les rang sont égaux, faire rang+1
		subsets[yracine].parent = xracine;
		subsets[xracine].rang++;
		return;
	}
}

//Vérifie si le graph contient un cycle ou pas
int isCycle(Graph* graph) {
	int S = graph->S;
	int B = graph->B;
	subset* subsets = (subset*)malloc(S * sizeof(subset));
	for (int v = 0; v < S; ++v) {
		subsets[v].parent = v;
		subsets[v].rang = 0;
	}
	// Parcours la totalité des sommets des bords et si les ensembles sont identiques alors il y a un cycle
	for (int e = 0; e < B; ++e) {
		int x = find(subsets, graph->Bord[e].racine);
		int y = find(subsets, graph->Bord[e].dest);
		if (x == y)
			return 1;
		Union(subsets, x, y);
	}
	return 0;
}

/*Algo Kruskal pseudo-code*/
/*	E <- NULL
	pour chaque sommet v appartenant S[G]
		faire CRÉER - ENSEMBLE(v)
	trier les arêtes de A par ordre croissant de poids w
	pour chaque arête(u, v) appartenant A pris par ordre de poids croissant
		faire si TROUVER - ENSEMBLE(u) != TROUVER - ENSEMBLE(v)
			alors E <- E Union{ (u, v) }
			UNION(u, v)
	retourner E
*/

//Algorithme de Kruskal
int Kruskal(Graph* graph, int U, int V) {
	subset* subsets = (subset*)malloc(U * sizeof(subset));
	subset* Subsets = (subset*)malloc(V * sizeof(subset));
	for (int i = 0; i < U; i++) {
		createGraph(i, V);
	}
	if (find(subsets, U) != find(Subsets, V)) {
		Union( subsets, U, V);
	}
	return graph;
}

int main() {
	int S = 3;
	int B = 3;
	Graph* graph = createGraph(S, B);

	//Ajouter bord 0-1
	graph->Bord[0].racine = 0;
	graph->Bord[0].dest = 1;

	//Ajouter bord 1-2
	graph->Bord[1].racine = 1;
	graph->Bord[1].dest = 2;

	//Ajouter bord 0-2
	/*graph->Bord[0].racine = 2;
	graph->Bord[0].dest = 2;*/

	//Ajouter bord 2-3
	graph->Bord[2].racine = 2;
	graph->Bord[2].dest = 3;

	if (isCycle(graph)) {
		printf("Le graph a un cycle");
	}
	else printf("Le graph ne comporte pas de cycle");
}