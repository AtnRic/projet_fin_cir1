#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 10

double* extract(char* nomFichier)
{
    char tampon[MAX] = { 0 };
    int i, n = 0, j, h;
    FILE* fichier = NULL;
    double* tableau;

    printf("Le fichier a ouvrir est : %s\n", nomFichier);
    fichier = fopen(nomFichier, "r");

    if (fichier != NULL)
    {
        printf("L'ouverture du fichier %s a reussie !\n", nomFichier);

        while (fgets(tampon, MAX, fichier) != NULL)
            n++;

        printf("Le fichier contient %d valeurs.\n", n);

        tableau = malloc(n * sizeof(double));

        if (tableau == NULL)
        {
            printf("Erreur allocation !");
            exit(0);
        }
        else
        {
            printf("Allocation reussie !\n");
        }

        rewind(fichier);

        for (h = 0; h < MAX; h++)
            tableau[h] = 0.0;

        for (i = 0; i < n; i++)
        {
            fgets(tampon, MAX, fichier);
            printf("tampon : %s\n", tampon);

            tableau[i] = atof(tampon);
        }

        for (j = 0; j < n; j++)
            printf("%f\n", tableau[j]);
    }
    else
        printf("L'ouverture du fichier %s a echouee !\n", nomFichier);

    return tableau;
}

int main(void)
{
    int     i;
    char nf[255] = "fichier.txt";
    double* nbre;
    nbre = extract(nf);

    for (i = 0; i < MAX; i++)
        printf("--> %f\n", nbre[i]);

    return 0;
}