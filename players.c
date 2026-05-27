#include <stdio.h>
#include <string.h>
#include "players.h"

void initialiserJoueur(Joueur *j, char nom[])
{
    strcpy(j->nom, nom);
    j->score = 0;
}

void afficherJoueur(Joueur j)
{
    printf("%s : %d points\n", j.nom, j.score);
}
