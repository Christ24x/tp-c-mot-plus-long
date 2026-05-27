#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "grid.h"
#include "display.h"
#include "validation.h"
#include "save.h"

#define MAX_MOT 50
int main()
{
    srand(time(NULL));

    char joueur1[20];
    char joueur2[20];

    int score1 = 0;
    int score2 = 0;

    int tours;
    int premierJoueur;

    char grille[9];

    char mot1[MAX_MOT];
    char mot2[MAX_MOT];

    printf("=====================================\n");
    printf("     LE MOT LE PLUS LONG\n");
    printf("=====================================\n\n");

    printf("Nom du joueur 1 : ");
    scanf("%s", joueur1);

    printf("Nom du joueur 2 : ");
    scanf("%s", joueur2);

    printf("Nombre de tours : ");
    scanf("%d", &tours);

    printf("Qui commence ? (1 ou 2) : ");
    scanf("%d", &premierJoueur);

    printf("\nDebut de la partie...\n\n");
for(int tour = 1; tour <= tours; tour++)
        printf("              TOUR %d\n", tour);
        printf("=====================================\n\n");

        remplirGrille(grille);

        afficherGrille(grille);

        printf("\n%s entre un mot : ", joueur1);
        scanf("%s", mot1);

        printf("%s entre un mot : ", joueur2);
        scanf("%s", mot2);

        printf("\nVerification des mots...\n\n");

        int scoreTour1 = 0;
        int scoreTour2 = 0;

        if(motValideGrille(mot1, grille) && motExisteDictionnaire(mot1))
        {
            scoreTour1 = calculerScore(mot1);
            score1 += scoreTour1;

            printf("Mot valide pour %s (+%d points)\n", joueur1, scoreTour1);
        }
        else
        {
            printf("Mot invalide pour %s (+0 point)\n", joueur1);
        }

        if(motValideGrille(mot2, grille) && motExisteDictionnaire(mot2))
        {
            scoreTour2 = calculerScore(mot2);
            score2 += scoreTour2;

            printf("Mot valide pour %s (+%d points)\n", joueur2, scoreTour2);
        }
        else
        {
            printf("Mot invalide pour %s (+0 point)\n", joueur2);
        }

        printf("\n--- PROPOSITIONS ---\n");
        printf("%s : %s\n", joueur1, mot1);
        printf("%s : %s\n", joueur2, mot2);

        afficherScores(joueur1, joueur2, score1, score2);

        char choix;

        printf("\nVoulez-vous sauvegarder la partie ? (o/n) : ");
        scanf(" %c", &choix);

        if(choix == 'o' || choix == 'O')
        {
            sauvegarderPartie(joueur1, joueur2, score1, score2, tour, tours);
        }

        printf("\n\n");
    }

    printf("=====================================\n");
    printf("           FIN DE PARTIE\n");
    printf("=====================================\n\n");

    afficherScores(joueur1, joueur2, score1, score2);

    if(score1 > score2)
    {
        printf("\nLe gagnant est %s !\n", joueur1);
    }
    else if(score2 > score1)
    {
        printf("\nLe gagnant est %s !\n", joueur2);
    }
    else
    {
        printf("\nMatch nul !\n");
    }

    return 0;
}
