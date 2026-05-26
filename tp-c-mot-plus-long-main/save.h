#ifndef SAVE_H
#define SAVE_H

// Vérifie si un mot peut être formé avec les lettres de la grille
// Retour: 1 si possible, 0 sinon
int motPossible(char mot[], char grille[]);

// Sauvegarde une partie dans "save.txt"
// Paramètres: joueur1, joueur2, score1, score2, tour, joueurActuel, grille
void sauvegarderPartie(char joueur1[], char joueur2[], int score1, int score2, int tour, int joueurActuel, char grille[]);

// Charge une partie depuis "save.txt"
// Remplit les paramètres passés en pointeurs
void chargerPartie(char joueur1[], char joueur2[], int *score1, int *score2, int *tour, int *joueurActuel, char grille[]);

// Propose le meilleur mot possible en testant le dictionnaire
// Affiche le résultat directement
void proposerMeilleurMot(char grille[]);

#endif