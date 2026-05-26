#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "validation.h"



// Vérifie si le mot peut être construit avec les lettres de la grille
int motValideGrille(char mot[], char grille[])
{
    int lettresGrille[26] = {0};
    int lettresMot[26] = {0};

    int i;

    // Compter les lettres de la grille
    for(i = 0; grille[i] != '\0'; i++)
    {
        char c = toupper(grille[i]);

        if(c >= 'A' && c <= 'Z')
        {
            lettresGrille[c - 'A']++;
        }
    }

    // Compter les lettres du mot
    for(i = 0; mot[i] != '\0'; i++)
    {
        char c = toupper(mot[i]);

        if(c >= 'A' && c <= 'Z')
        {
            lettresMot[c - 'A']++;
        }
    }

    // Vérification
    for(i = 0; i < 26; i++)
    {
        if(lettresMot[i] > lettresGrille[i])
        {
            return 0;
        }
    }

    return 1;
}



// Vérifie si le mot existe dans le dictionnaire
int motExisteDictionnaire(char mot[])
{
    FILE *fichier;
    char ligne[100];

    fichier = fopen("dictionnaire.txt", "r");

    if(fichier == NULL)
    {
        printf("Erreur ouverture dictionnaire\n");
        return 0;
    }

    while(fgets(ligne, sizeof(ligne), fichier))
    {
        // supprimer le retour à la ligne
        ligne[strcspn(ligne, "\n")] = '\0';

        if(strcmp(ligne, mot) == 0)
        {
            fclose(fichier);
            return 1;
        }
    }

    fclose(fichier);

    return 0;
}



// Calcul du score
int calculerScore(char mot[])
{
    return strlen(mot);
}
