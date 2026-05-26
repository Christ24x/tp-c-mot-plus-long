#include <stdio.h>
#include <string.h>

#include "save.h"

// Vérifie si un mot peut être formé avec les lettres de la grille
// Une lettre ne peut être utilisée qu'une seule fois
int motPossible(char mot[], char grille[])
{
    char copie[100];

    strcpy(copie, grille);

    int i;
    int j;
    int trouve;

    for(i = 0; mot[i] != '\0'; i++)
    {
        trouve = 0;

        for(j = 0; copie[j] != '\0'; j++)
        {
            if(mot[i] == copie[j])
            {
                copie[j] = '*';

                trouve = 1;

                break;
            }
        }

        if(trouve == 0)
        {
            return 0;
        }
    }

    return 1;
}

// Sauvegarde une partie dans "save.txt"
// Format: ligne par ligne (joueur1, joueur2, score1, score2, tour, joueurActuel, grille)
void sauvegarderPartie(char joueur1[], char joueur2[], int score1, int score2, int tour, int joueurActuel, char grille[])
{
    FILE *fichier = fopen("save.txt", "w");
    
    if(fichier == NULL)
    {
        printf("Erreur : impossible d'ouvrir save.txt pour écriture.\n");
        return;
    }
    
    fprintf(fichier, "%s\n", joueur1);
    fprintf(fichier, "%s\n", joueur2);
    fprintf(fichier, "%d\n", score1);
    fprintf(fichier, "%d\n", score2);
    fprintf(fichier, "%d\n", tour);
    fprintf(fichier, "%d\n", joueurActuel);
    fprintf(fichier, "%s\n", grille);
    
    fclose(fichier);
    
    printf("Partie sauvegardée dans save.txt.\n");
}

// Charge une partie depuis "save.txt"
// Remplit les variables passées en paramètres
void chargerPartie(char joueur1[], char joueur2[], int *score1, int *score2, int *tour, int *joueurActuel, char grille[])
{
    FILE *fichier = fopen("save.txt", "r");
    
    if(fichier == NULL)
    {
        printf("Erreur : fichier save.txt non trouvé.\n");
        return;
    }
    
    // Lecture ligne par ligne
    if(fscanf(fichier, "%99s", joueur1) != 1)
    {
        printf("Erreur lors de la lecture de joueur1.\n");
        fclose(fichier);
        return;
    }
    
    if(fscanf(fichier, "%99s", joueur2) != 1)
    {
        printf("Erreur lors de la lecture de joueur2.\n");
        fclose(fichier);
        return;
    }
    
    if(fscanf(fichier, "%d", score1) != 1)
    {
        printf("Erreur lors de la lecture de score1.\n");
        fclose(fichier);
        return;
    }
    
    if(fscanf(fichier, "%d", score2) != 1)
    {
        printf("Erreur lors de la lecture de score2.\n");
        fclose(fichier);
        return;
    }
    
    if(fscanf(fichier, "%d", tour) != 1)
    {
        printf("Erreur lors de la lecture de tour.\n");
        fclose(fichier);
        return;
    }
    
    if(fscanf(fichier, "%d", joueurActuel) != 1)
    {
        printf("Erreur lors de la lecture de joueurActuel.\n");
        fclose(fichier);
        return;
    }
    
    if(fscanf(fichier, "%99s", grille) != 1)
    {
        printf("Erreur lors de la lecture de grille.\n");
        fclose(fichier);
        return;
    }
    
    fclose(fichier);
    
    printf("Partie chargée depuis save.txt.\n");
}

// Propose le meilleur mot possible en testant le dictionnaire
// Lit "dictionnaire.txt" et retourne le mot le plus long valide
void proposerMeilleurMot(char grille[])
{
    FILE *dictionnaire = fopen("dictionnaire.txt", "r");
    
    if(dictionnaire == NULL)
    {
        printf("Aucun mot trouve.\n");
        return;
    }
    
    char meilleurMot[100] = "";
    int tailleMax = 0;
    char motActuel[100];
    
    // Parcourt le dictionnaire
    while(fscanf(dictionnaire, "%99s", motActuel) == 1)
    {
        // Teste si le mot peut être formé
        if(motPossible(motActuel, grille))
        {
            int taille = strlen(motActuel);
            
            // Garde le mot le plus long
            if(taille > tailleMax)
            {
                tailleMax = taille;
                strcpy(meilleurMot, motActuel);
            }
        }
    }
    
    fclose(dictionnaire);
    
    if(tailleMax > 0)
    {
        printf("Meilleur mot : %s\n", meilleurMot);
    }
    else
    {
        printf("Aucun mot trouve.\n");
    }
}