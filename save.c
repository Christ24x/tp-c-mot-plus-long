#include <stdio.h>
#include "save.h"

void sauvegarderPartie(char joueur1[], char joueur2[], int score1, int score2, int tour)
{
    FILE *fichier = fopen("sauvegarde.txt", "w");

    if(fichier == NULL)
    {
        printf("Erreur de sauvegarde\n");
        return;
    }

    fprintf(fichier, "%s\n", joueur1);
    fprintf(fichier, "%s\n", joueur2);
    fprintf(fichier, "%d\n", score1);
    fprintf(fichier, "%d\n", score2);
    fprintf(fichier, "%d\n", tour);

    fclose(fichier);

    printf("Partie sauvegardee avec succes !\n");
}
