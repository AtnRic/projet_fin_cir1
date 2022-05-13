#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    if (tab != NULL && tmp!= NULL) {
        srand(time(NULL));

        for (int i = 0; i <= nbr; i++) {
            float v = (float)((float)rand() / (float)RAND_MAX);
            u = v*100.0;
            (* (tab + i)) = u;
            
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