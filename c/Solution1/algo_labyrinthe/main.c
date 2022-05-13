#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Structures.h"
#define MAXSIZE 16340

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

/*Tri Fusion*/
void triFusion(int i, int j, int tab[], int tmp[]) {
	if (j <= i) { return; }

	int m = (i + j) / 2;

	triFusion(i, m, tab, tmp);     //trier la moiti� gauche r�cursivement
	triFusion(m + 1, j, tab, tmp); //trier la moiti� droite r�cursivement
	int pg = i;     //pg pointe au d�but du sous-tableau de gauche
	int pd = m + 1; //pd pointe au d�but du sous-tableau de droite
	int c;          //compteur
// on boucle de i � j pour remplir chaque �l�ment du tableau final fusionn�
	for (c = i; c <= j; c++) {
		if (pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
			tmp[c] = tab[pd];
			pd++;
		}
		else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
			tmp[c] = tab[pg];
			pg++;
		}
		else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un �l�ment plus petit
			tmp[c] = tab[pg];
			pg++;
		}
		else {  //le pointeur du sous-tableau de droite pointe vers un �l�ment plus petit
			tmp[c] = tab[pd];
			pd++;
		}
	}
	for (c = i; c <= j; c++) {  //copier les �l�ments de tmp � tab
		tab[c] = tmp[c];
	}
}
int main() {
	int  nbr, u;
	nbr = 100000000;
	int* tab = (int*)malloc(nbr * sizeof(int));
	int* tmp = (int*)malloc(nbr * sizeof(int));
	if (tab != NULL && tmp != NULL) {
		srand(time(NULL));

		for (int i = 0; i <= nbr; i++) {
			float v = (float)((float)rand() / (float)RAND_MAX);
			u = v * 100.0;
			(*(tab + i)) = u;

		}
	}
	triFusion(0, nbr - 1, tab, tmp);

	printf("\n Tableau trie : ");
	for (int j = 0; j < nbr; j++) {
		//printf(" %4d", tab[j]);
	}
	printf("\n");
	return 0;
}
/*Fin tri Fusion*/

/*Algorithme Kruskal*/
Graph* createGraph(int S, int B) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->S = S;
	graph->B = B;
	graph->Bord = (Bord*)malloc(graph->B * sizeof(Bord));
	return graph;
}


/* Pseudo code fonction find
function Find(x)
	if x.parent != x
		x.parent : = Find(x.parent)
	return x.parent
*/
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

/*Algo Kruskal pseudo-code
	graph <- NULL
	pour chaque sommet v appartenant S[G]
		faire CRÉER - ENSEMBLE(v)
	trier les arêtes de A par ordre croissant de poids w
	pour chaque arête(u, v) appartenant A pris par ordre de poids croissant
		faire si TROUVER - ENSEMBLE(u) != TROUVER - ENSEMBLE(v)
			alors graph <- graph Union{ (u, v) }
			UNION(u, v)
	retourner E
*/
//Algorithme de Kruskal
int Kruskal(Graph* graph, int nombreSommets) {
	int U, V;
	int tab[MAXSIZE];
	subset* subsets = (subset*)malloc(U * sizeof(subset));
	subset* Subsets = (subset*)malloc(V * sizeof(subset));
	for (int i = 0; i < nombreSommets; ++i) {
		srand(time(NULL));
		graph = createGraph(i, V);
		tab[i] = graph->Bord->weight = rand();
		subsets->data->haut = subsets->data->droite = subsets->data->bas = subsets->data->gauche = 1;
	}
	//Tri par fusion 
	if (find(subsets, U) != find(Subsets, V)) {
		Union( subsets, find(subsets, U), find(Subsets, V));
		if (U = V + 1) {
			subsets->data->gauche = Subsets->data->droite = 0;
		}
		if (U = V - 1) {
			Subsets->data->gauche = subsets->data->droite = 0;
		}
		if (U = V + sqrt(nombreSommets)) Subsets->data->bas = subsets->data->haut = 0;
		if (U = V - sqrt(nombreSommets)) Subsets->data->haut = subsets->data->bas = 0;
	}
	for (int i = 0; i < nombreSommets; i++) {
		if (subsets->data->haut == 1) {
			if (subsets->data->droite == 1) {
				if (subsets->data->bas == 1) {
					if (subsets->data->gauche == 1) {
						subsets->dataRenvoye = "p";
					}
					else subsets->dataRenvoye = "o";
				}
				else if (subsets->data->gauche == 1) subsets->dataRenvoye = "n";
				else subsets->dataRenvoye = "h";
			}
			else if ((subsets->data->bas == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye = "m";
			else if (subsets->data->bas == 1) subsets->dataRenvoye = "f";
			else if (subsets->data->gauche == 1) subsets->dataRenvoye = "k";
			else subsets->dataRenvoye = "b";
		}
		else if ((subsets->data->droite == 1) && (subsets->data->bas == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye = "l";
		else if ((subsets->data->droite == 1) && (subsets->data->bas == 1)) subsets->dataRenvoye = "i";
		else if ((subsets->data->bas == 1) && (subsets->data ->gauche == 1)) subsets->dataRenvoye = "j";
		else if ((subsets ->data->droite == 1) && (subsets->data ->gauche == 1)) subsets->dataRenvoye = "g";
		else if (subsets->data->droite == 1) subsets ->dataRenvoye = "c";
		else if (subsets->data->bas == 1) subsets ->dataRenvoye = "d";
		else if (subsets->data ->gauche == 1) subsets->dataRenvoye = "e";
		else subsets->dataRenvoye = "a";
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
	graph->Bord[0].racine = 2;
	graph->Bord[0].dest = 2;

	//Ajouter bord 2-3
	graph->Bord[2].racine = 2;
	graph->Bord[2].dest = 3;

	if (isCycle(graph)) {
		printf("Le graph a un cycle");
	}
	else printf("Le graph ne comporte pas de cycle");
}

//faire un tableau avec allocation dynamique des valeurs lorsque celui-ci est dépassé en taille