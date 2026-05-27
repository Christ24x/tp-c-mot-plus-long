#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "grid.h"

char genererVoyelle()
{
    char voyelles[] = {'A','E','I','O','U','Y'};

    return voyelles[rand() % 6];
}

char genererConsonne()
{
    char consonnes[] = {
        'B','C','D','F','G','H','J','K','L','M',
        'N','P','Q','R','S','T','V','W','X','Z'
    };

    return consonnes[rand() % 20];
}

void remplirGrille(char grille[])
{
    char choix;

    for(int i = 0; i < 9; i++)
    {
        printf("Lettre %d (V = voyelle, C = consonne) : ", i + 1);
        scanf(" %c", &choix);

        choix = toupper(choix);

        if(choix == 'V')
        {
            grille[i] = genererVoyelle();
        }
        else
        {
            grille[i] = genererConsonne();
        }
    }
}

void afficherGrille(char grille[])
{
    printf("\n======= GRILLE =======\n");

    for(int i = 0; i < 9; i++)
    {
        printf(" %c ", grille[i]);
    }

    printf("\n======================\n");
}
