#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include<time.h>
#include "Structures.h"
#define MAXSIZE 123


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
/*int main() {
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
}*/
/*Fin tri Fusion*/

/*Pile*/
Stack new_stack(void) {
	return NULL;
}

bool is_empty_stack(Stack st) {
	if (st == NULL) return true;
	return false;
}

Stack push_stack(Stack st, int x) {
	StackElement* element;
	element = malloc(sizeof(*element));
	if (element == NULL) {
		fprintf(stderr, "Probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}
	element->value = x;
	element->next = st;
	return element;
}

Stack pop_stack(Stack st) {
	StackElement* element;
	if (is_empty_stack(st)) return new_stack();
	element = st->next;
	free(st);
	return element;
}

void print_stack(Stack st) {
	if (is_empty_stack(st)) {
		printf("Rien a afficher, la Pile est vide.\n");
		return;
	}
	while (!is_empty_stack(st)){
	 	printf("[%d]\n", st->value);
		st = st->next;
	}
}

int top_stack(Stack st) {
	if (is_empty_stack(st)) {
		printf("Aucun sommet, la Pile est vide.\n");
		exit(EXIT_FAILURE);
	}
	return st->value;
}

int stack_length(Stack st) {
	int length = 0;
	while (!is_empty_stack(st)) {
		length++;
		st = st->next;
	}
	return length;
}

Stack clear_stack(Stack st) {
	while (!is_empty_stack(st)) st = pop_stack(st);
	return new_stack();
}
/*Fin Pile*/

/*Algorithme Kruskal*/
Graph* createGraph(int S, int B) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	if (graph != NULL) {
		(graph->S) = S;
		(graph->B) = B;
		graph->Bord = (Bord*)malloc(graph->B * sizeof(Bord));
	}
	return graph;
}


/* Pseudo code fonction find
function Find(x)
	if x.parent != x
		x.parent : = Find(x.parent)
	return x.parent
*/
//Fonction qui trouve la racine d'un élément i
int find(subset * subsets, int i, int graph) {
	// Trouve la racine et fait de la racine le parent de i
	isCycle(graph);
	if ( (subsets + i)->parent != NULL) {
		if ((subsets + i)->parent != i) {
			(subsets + i)->parent = find(subsets, subsets[i].parent, graph);
		}
	}
	return (subsets+i)->parent;
}


//Fonction qui unit 2 éléments à leurs racines
//L'élément ayant le rang le plus faible est relié à la racine de l'élément ayant le rang le plus élevé
void Union(subset * subsets, int xracine, int yracine) {
	if ((subsets+xracine)->rang < (subsets+yracine)->rang) {
		(subsets+xracine)->parent = yracine;
		return;
	}
	else if ((subsets+xracine)->rang > (subsets+yracine)->rang) {
		(subsets+yracine)->parent = xracine;
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
	if (subsets != NULL) {
		for (int v = 0; v < S; ++v) {
			(subsets + v)->parent = v;
			(subsets + v)->rang = 0;
		}
	}
	// Parcours la totalité des sommets des bords et si les ensembles sont identiques alors il y a un cycle
	for (int e = 0; e < B; ++e) {
		int x = find(subsets, (graph->Bord+e)->racine, graph);
		int y = find(subsets, (graph->Bord+e)->dest, graph);
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
/*
int PremierPavéDeElseIf(int U, int V, int nombreSommets) {
	int tmp;
	if (U > (int)sqrt(nombreSommets)) { //U n'est pas sur les bords du tableau donc toutes possibilités possibles
		if (U % (int)(sqrt(nombreSommets) + 1) != 1) {
			if (U % (int)(sqrt(nombreSommets) + 1) != 1) {
				if (U >= nombreSommets - sqrt(nombreSommets)) {
					tmp = rand() % 4;
					switch (tmp) {
					case 0:
						V = U - 1;
						break;
					case 1:
						V = U + 1;
						break;
					case 2:
						V = U - (int)sqrt(nombreSommets);
						break;
					case 3:
						V = U + (int)sqrt(nombreSommets);
						break;
					}
				}
				else {
					tmp = rand() % 3;
					switch (tmp) {
					case 0:
						V = U - 1;
						break;
					case 1:
						V = U + 1;
						break;
					case 2:
						V = U - (int)sqrt(nombreSommets);
						break;
					}
				}
			}
			else if (U >= nombreSommets - (int)sqrt(nombreSommets)) {
				tmp = rand() % 3;
				switch (tmp) {
				case 0:
					V = U - 1;
					break;
				case 1:
					V = U + (int)sqrt(nombreSommets);
					break;
				case 2:
					V = U - (int)sqrt(nombreSommets);
					break;
				}
			}
			else {
				tmp = rand() % 2;
				switch (tmp) {
				case 0:
					V = U - 1;
					break;
				case 2:
					V = U - (int)sqrt(nombreSommets);
					break;
				}
			}
		}
		else if ((U % (int)(sqrt(nombreSommets) + 1) != 1) && (U >= nombreSommets - (int)sqrt(nombreSommets))) {
			tmp = rand() % 3;
			switch (tmp) {
			case 0:
				V = U + (int)sqrt(nombreSommets);
				break;
			case 1:
				V = U + 1;
				break;
			case 2:
				V = U - (int)sqrt(nombreSommets);
				break;
			}
		}
		else if (U % (int)(sqrt(nombreSommets) + 1) != 1) {
			tmp = rand() % 2;
			switch (tmp) {
			case 0:
				V = U + (int)sqrt(nombreSommets);
				break;
			case 1:
				V = U - (int)sqrt(nombreSommets);
				break;
			}
		}
		else if (U >= nombreSommets - (int)sqrt(nombreSommets)) {
			tmp = rand() % 2;
			switch (tmp) {
			case 0:
				V = U - 1;
				break;
			case 1:
				V = U - (int)sqrt(nombreSommets);
				break;
			}
		}
		else V = U - (int)sqrt(nombreSommets);
	}
	else if ((U % (int)(sqrt(nombreSommets) + 1) != 1) && (U % (int)(sqrt(nombreSommets) + 1) != 1) && (U >= nombreSommets - (int)sqrt(nombreSommets))) {
		tmp = rand() % 3;
		switch (tmp) {
		case 0:
			V = U - 1;
			break;
		case 1:
			V = U + 1;
			break;
		case 2:
			V = U - (int)sqrt(nombreSommets);
			break;
		}
	}
	else if ((U % (int)(sqrt(nombreSommets) + 1) != 1) && (U % (int)(sqrt(nombreSommets) + 1) != 1)) {
		tmp = rand() % 2;
		switch (tmp) {
		case 0:
			V = U - 1;
			break;
		case 1:
			V = U - (int)sqrt(nombreSommets);
			break;
		}
	}
	else if ((U % (int)(sqrt(nombreSommets) + 1) != 1) && (U >= nombreSommets - (int)sqrt(nombreSommets))) {
		tmp = rand() % 2;
		switch (tmp) {
		case 0:
			V = U + 1;
			break;
		case 1:
			V = U - (int)sqrt(nombreSommets);
			break;
		}
	}
	else if ((U >= nombreSommets - (int)sqrt(nombreSommets)) && (U % (int)(sqrt(nombreSommets) + 1) != 1)) {
		tmp = rand() % 2;
		switch (tmp) {
		case 0:
			V = U + 1;
			break;
		case 1:
			V = U - (int)sqrt(nombreSommets);
			break;
		}
	}
	else {
		return NULL;
	}
	return V;
}
int DeuxièmePavéDeElseIf(subset* subsets, int nombreSommets) {
	for (int i = 0; i < nombreSommets; i++) {
		if (subsets->data->haut == 1) {
			if (subsets->data->droite == 1) {
				if (subsets->data->bas == 1) {
					if (subsets->data->gauche == 1) {
						return NULL;
					}
					else subsets->dataRenvoye[i] = 'o';
				}
				else if (subsets->data->gauche == 1) subsets->dataRenvoye[i] = 'n';
				else subsets->dataRenvoye[i] = 'h';
			}
			else if ((subsets->data->bas == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye[i] = 'm';
			else if (subsets->data->bas == 1) subsets->dataRenvoye[i] = 'f';
			else if (subsets->data->gauche == 1) subsets->dataRenvoye[i] = 'k';
			else subsets->dataRenvoye[i] = 'b';
		}
		else if ((subsets->data->droite == 1) && (subsets->data->bas == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye[i] = 'l';
		else if ((subsets->data->droite == 1) && (subsets->data->bas == 1)) subsets->dataRenvoye[i] = 'i';
		else if ((subsets->data->bas == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye[i] = 'j';
		else if ((subsets->data->droite == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye[i] = 'g';
		else if (subsets->data->droite == 1) subsets->dataRenvoye[i] = 'c';
		else if (subsets->data->bas == 1) subsets->dataRenvoye[i] = 'd';
		else if (subsets->data->gauche == 1) subsets->dataRenvoye[i] = 'e';
		else subsets->dataRenvoye[i] = 'a';
	}
}
//Algorithme de Kruskal de génération et transcription
Graph * Kruskal(Graph* graph, int nombreSommets) {
	int U = nombreSommets;
	int V = nombreSommets;
	int tmp = NULL;
	int tab[MAXSIZE];
	subset* subsets = (subset*)malloc(U * sizeof(subset));
	subset* Subsets = (subset*)malloc(V * sizeof(subset));
	for (int i = 0; i < nombreSommets; ++i) {
		if ((subsets + i) != NULL) {
			(*(subsets + i)).data = (Data*)malloc(sizeof(Data));
			(*(subsets + i)).Bord = (Bord*)malloc(sizeof(Bord));
			srand(time(NULL));
			graph = createGraph(i, U);
			//Graph* Graph = createGraph(i, V);
			tab[i] = graph->Bord[i].weight = rand();
			((subsets + i)->data)->haut = 1;
			((subsets + i)->data)->droite = ((subsets + i)->data)->bas = ((subsets + i)->data)->gauche = 1;
			//Subsets[i]->data.haut = Subsets[i]->data.droite = Subsets[i]->data.bas = Subsets[i]->data.gauche = 1;
			(subsets + i)->parent = subsets + i;
		}
	}
	//Tri par fusion 
	while(graph->S != nombreSommets) {
		U = rand() % nombreSommets;
		V = PremierPavéDeElseIf(U, V, nombreSommets);
		if (find(subsets, U, graph) != find(Subsets, V, graph)) {
				Union( subsets, find(subsets, U, graph), find(Subsets, V, graph));
				if (U = V + 1) {
					subsets->data->gauche = Subsets->data->droite = 0;
				}
				else if (U = V - 1) {
					Subsets->data->gauche = subsets->data->droite = 0; 
				}
				else if (U = V + (int)sqrt(nombreSommets)) Subsets->data->bas = subsets->data->haut = 0;
				else if (U = V - (int)sqrt(nombreSommets)) Subsets->data->haut = subsets->data->bas = 0;
				graph->S++;
		}
	}
	DeuxièmePavéDeElseIf(subsets, nombreSommets);
	/*for (int i = 0; i < nombreSommets; i++) {
		if (subsets->data->haut == 1) {
			if (subsets->data->droite == 1) {
				if (subsets->data->bas == 1) {
					if (subsets->data->gauche == 1) {
						return NULL;
					}
					else subsets->dataRenvoye[i] = 'o';
				}
				else if (subsets->data->gauche == 1) subsets->dataRenvoye[i] = 'n';
				else subsets->dataRenvoye[i] = 'h';
			}
			else if ((subsets->data->bas == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye[i] = 'm';
			else if (subsets->data->bas == 1) subsets->dataRenvoye[i] = 'f';
			else if (subsets->data->gauche == 1) subsets->dataRenvoye[i] = 'k';
			else subsets->dataRenvoye[i] = 'b';
		}
		else if ((subsets->data->droite == 1) && (subsets->data->bas == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye[i] = 'l';
		else if ((subsets->data->droite == 1) && (subsets->data->bas == 1)) subsets->dataRenvoye[i] = 'i';
		else if ((subsets->data->bas == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye[i] = 'j';
		else if ((subsets->data->droite == 1) && (subsets->data->gauche == 1)) subsets->dataRenvoye[i] = 'g';
		else if (subsets->data->droite == 1) subsets->dataRenvoye[i] = 'c';
		else if (subsets->data->bas == 1) subsets->dataRenvoye[i] = 'd';
		else if (subsets->data ->gauche == 1) subsets->dataRenvoye[i] = 'e';
		else subsets->dataRenvoye[i] = 'a';
	}
	return graph;
}*/

void affichageDeSesGrandsMorts(Tab* tab, int cote) {
	printf("[ ");
	for (int i = 0; i < cote^2; i++) {
		if ((i % cote == 0) && i != cote^2) {
			printf("], [");
		}
		else if (i == cote^2) {
			printf("]");
		}
		else {
			printf("\"%d\", ", (tab+i)->lettreRenvoye);
		}
	}
}

int labyrinthe1if(int tmp, Tab* tab, int cote, int posinitial) {
	Stack* GPS = (Stack*)malloc(sizeof GPS);
	int i = posinitial;
	(tab + posinitial)->passage = 1;
	/*if ((tab + (i - cote))->passage == 1 && (tab + (i + cote))->passage == 1 && (tab + (i - 1))->passage == 1) {

	}
	else if (i < cote || (tab + (i - cote))->passage == 1) {
		if (i % cote == 1 || (tab + (i - 1))->passage == 1) {
			if (i % cote == cote - 1) {

			}
			tmp = rand() % 2;
			switch (tmp) {
			case 0: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i-1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0;  break;
			case 1: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
			}
		}
		else if (i % cote == cote - 1) {
				tmp = rand() % 2;
				switch (tmp) {
				case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i +1); ((tab + i)->data)->droite = 0; ((tab + (i+1))->data)->gauche = 0; break;
				case 1: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i-cote))->data)->bas = 0; break;
				}
		}
		else {
			tmp = rand() % 3;
					switch (tmp){
						case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i +1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
						case 1: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i -1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0; break;
						case 2: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
					}
		}
		
	}
	else if (i > cote ^ 2 - cote || (tab + (i + cote))->passage == 1) {
		if (i % cote == 1) {
			tmp = rand() % 2;
			switch (tmp) {
			case 0: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i -1); ((tab + i)->data)->gauche = 0; ((tab + (i-1))->data)->droite = 0; break;
			case 1: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas= 0; ((tab + (i-cote))->data)->haut = 0; break;
			}
		}
		else if (i % cote == cote - 1) {
			tmp = rand() % 2;
			switch (tmp) {
			case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i+1))->data)->gauche = 0;  break;
			case 1: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
			}
		}
		else {
			tmp = rand() % 3;
			switch (tmp) {
			case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
			case 1: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0; break;
			case 2: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
			}
		}
			
	}
	else if (i % cote == 1 || (tab + (i - 1))->passage == 1) {
		tmp = rand() % 3;
		switch (tmp) {
		case 0: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); (tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
		case 1: i += 1; (tab + i)->passage = 1; push_Stack(GPS, -1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0; break;
		case 2: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
		}
	}
	else if (i % cote == cote - 1 || (tab + (i + 1))->passage == 1) {
		tmp = rand() % 3;
		switch (tmp) {
		case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
		case 1: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
		case 2: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
		}
	}
	posinitial = i;*/
	if (i < cote || (tab + (i - cote))->passage == 1) {
		if (i % cote == 1 || (tab + (i - 1))->passage == 1) {
			if (i % cote == cote - 1 || (tab + (i + 1))->passage == 1) {
				if (i > cote ^ 2 - cote || (tab + (i + cote))->passage == 1) {
					labyrinthe1if(tmp, tab, cote, pop_stack(GPS));
				}
				else {
					i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0;
				}
			}
			else if (i > cote ^ 2 - cote || (tab + (i + cote))->passage == 1) {
				i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0;
			}
			else {
				tmp = rand() % 2;
				switch (tmp) {
				case 0: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0;  break;
				case 1: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
				}
			}
		}
		else if ((i % cote == cote - 1 && i > cote ^ 2 - cote) || ((tab + (i + 1))->passage == 1 && (tab + (i + cote))->passage == 1)) {
			i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0;
		}
		else if (i % cote == cote - 1 || (tab + (i + 1))->passage == 1) {
			tmp = rand() % 2;
			switch (tmp) {
			case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
			case 1: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
			}
		}
		else if (i > cote ^ 2 - cote || (tab + (i + cote))->passage == 1) {
			tmp = rand() % 2;
			switch (tmp) {
			case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
			case 1: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0;  break;
			}
		}
		else {
			tmp = rand() % 3;
			switch (tmp) {
			case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
			case 1: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0; break;
			case 2: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
			}
		}

	}
	else if ((i % cote == cote - 1 && i > cote ^ 2 - cote && i % cote == 1) || ((tab + (i + 1))->passage == 1 && (tab + (i - 1))->passage == 1 && (tab + (i + cote))->passage == 1)) {
		i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0;
	}
	else if ((i % cote == cote - 1 && i > cote ^ 2 - cote) || ((tab + (i + 1))->passage == 1 && (tab + (i + cote))->passage == 1)) {
		tmp = rand() % 2;
		switch (tmp) {
		case 0: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0; break;
		case 1: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
		}
	}
	else if ((i > cote ^ 2 - cote && i % cote == 1) || ((tab + (i + cote))->passage == 1 && (tab + (i - 1))->passage == 1)) {
		tmp = rand() % 2;
		switch (tmp) {
		case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
		case 1: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
		}
	}
	else if ((i % cote == cote - 1 && i % cote == 1)||((tab + (i + 1))->passage == 1 && (tab + (i - 1))->passage == 1)) {
		tmp = rand() % 2;
		switch (tmp) {
		case 0: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0; break;
		case 1: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
		}
	}
	else if (i % cote == cote - 1 || (tab + (i + 1))->passage == 1){
		tmp = rand() % 3;
		switch (tmp) {
		case 0: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
		case 1: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
		case 2: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
		}
	}
	else if (i % cote == 1 || (tab + (i - 1))->passage == 1) {
		tmp = rand() % 3;
		switch (tmp) {
		case 0: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0; break;
		case 1: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
		case 2: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
		}
	}
	else if (i > cote ^ 2 - cote || (tab + (i + cote))->passage == 1) {
		tmp = rand() % 3;
		switch (tmp) {
		case 0: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0; break;
		case 1: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
		case 2: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
		}
	}
	else {
		tmp = rand() % 4;
		switch (tmp) {
		case 0: i += 1; (tab + i)->passage = 1; push_Stack(GPS, i - 1); ((tab + i)->data)->gauche = 0; ((tab + (i - 1))->data)->droite = 0; break;
		case 1: i -= cote; (tab + i)->passage = 1; push_Stack(GPS, i + cote); ((tab + i)->data)->bas = 0; ((tab + (i - cote))->data)->haut = 0; break;
		case 2: i -= 1; (tab + i)->passage = 1; push_Stack(GPS, i + 1); ((tab + i)->data)->droite = 0; ((tab + (i + 1))->data)->gauche = 0; break;
		case 3: i += cote; (tab + i)->passage = 1; push_Stack(GPS, i - cote); ((tab + i)->data)->haut = 0; ((tab + (i - cote))->data)->bas = 0; break;
		}
	}
	posinitial = i;
}

int TranscriptionPourJavaScript(Tab* tab, int cote) {
	for (int i = 0; i < cote^2; i++) {
		if ((tab+i)->data->haut == 1) {
			if ((tab + i)->data->droite == 1) {
				if ((tab + i)->data->bas == 1) {
					if ((tab + i)->data->gauche == 1) {
						printf("Il y a une erreur");
						return EXIT_FAILURE;
					}
					else (tab+i)->lettreRenvoye[i] = 'o';
				}
				else if ((tab + i)->data->gauche == 1) (tab + i)->lettreRenvoye[i] = 'n';
				else (tab + i)->lettreRenvoye[i] = 'h';
			}
			else if (((tab + i)->data->bas == 1) && ((tab + i)->data->gauche == 1)) (tab + i)->lettreRenvoye[i] = 'm';
			else if ((tab + i)->data->bas == 1) (tab + i)->lettreRenvoye[i] = 'f';
			else if ((tab + i)->data->gauche == 1) (tab + i)->lettreRenvoye[i] = 'k';
			else (tab + i)->lettreRenvoye[i] = 'b';
		}
		else if (((tab + i)->data->droite == 1) && ((tab + i)->data->bas == 1) && ((tab + i)->data->gauche == 1)) (tab + i)->lettreRenvoye[i] = 'l';
		else if (((tab + i)->data->droite == 1) && ((tab + i)->data->bas == 1)) (tab + i)->lettreRenvoye[i] = 'i';
		else if (((tab + i)->data->bas == 1) && ((tab + i)->data->gauche == 1)) (tab + i)->lettreRenvoye[i] = 'j';
		else if (((tab + i)->data->droite == 1) && ((tab + i)->data->gauche == 1)) (tab + i)->lettreRenvoye[i] = 'g';
		else if ((tab + i)->data->droite == 1) (tab + i)->lettreRenvoye[i] = 'c';
		else if ((tab + i)->data->bas == 1) (tab + i)->lettreRenvoye[i] = 'd';
		else if ((tab + i)->data->gauche == 1) (tab + i)->lettreRenvoye[i] = 'e';
		else (tab + i)->lettreRenvoye[i] = 'a';
	}
}

int Labyrinthe(int cote, Tab* tab, int piege, int teleporteur) {
	Tab* tab = (Tab*)malloc((cote^2) * sizeof(Tab));
	srand(time(NULL));
	int tmp = 0;
	int compteur = 0;
	for (int i = 0; i < cote ^ 2; i++) {
		(*(tab + i)).data = (Data*)malloc(sizeof(Data));
		((tab + i)->data)->haut = ((tab + i)->data)->bas = ((tab + i)->data)->gauche = ((tab + i)->data)->droite = 1;
	}
	int posintial = rand() % cote;
	while (compteur != cote ^ 2) {
		int labyrinthe1if(tmp, tab, cote, posintial);
		compteur++;
	}
	return tab;
}

int main() {
	int cote = 12;
	Tab* tab = (Tab*)malloc(sizeof (Tab));
	int piege = 0;
	int teleporteur = 0;
	Labyrinthe(cote, tab, piege, teleporteur);
}

//faire un tableau avec allocation dynamique des valeurs lorsque celui-ci est dépassé en taille