#ifndef PLAYERS_H
#define PLAYERS_H

typedef struct
{
    char nom[20];
    int score;
} Joueur;

void initialiserJoueur(Joueur *j, char nom[]);
void afficherJoueur(Joueur j);

#endif
