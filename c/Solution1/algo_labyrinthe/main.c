#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Ce qui doit être obtenu
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
int isCycle(Graph* graph)
{
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
	graph->Bord[0].racine = 2;
	graph->Bord[0].dest = 2;

	//Ajouter bord 2-3
	/*sgraph->Bord[2].racine = 2;
	graph->Bord[2].dest = 3;*/

	if (isCycle(graph)) {
		printf("Le graph a un cycle");
	}
	else printf("Le graph ne comporte pas de cycle");
}