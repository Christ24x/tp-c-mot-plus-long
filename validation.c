#include <stdio.h>
#include <ctype.h>
#include "validation.h"

int motValideGrille(char mot[], char grille[])
{
    int lettresGrille[26] = {0};
    int lettresMot[26] = {0};

    for(int i = 0; i < 9; i++)
    {
        lettresGrille[toupper(grille[i]) - 'A']++;
    }

    for(int i = 0; mot[i] != '\0'; i++)
    {
        lettresMot[toupper(mot[i]) - 'A']++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(lettresMot[i] > lettresGrille[i])
        {
            return 0;
        }
    }

    return 1;
}

int motExisteDictionnaire(char mot[])
{
    FILE *fichier = fopen("dictionnaire.txt", "r");

    if(fichier == NULL)
    {
        printf("Erreur ouverture dictionnaire\n");
        return 0;
    }

    char ligne[100];

    while(fgets(ligne, sizeof(ligne), fichier))
    {
        ligne[strcspn(ligne, "\n")] = 0;

        if(strcasecmp(ligne, mot) == 0)
        {
            fclose(fichier);
            return 1;
        }
    }

    fclose(fichier);

    return 0;
}

int calculerScore(char mot[])
{
    return strlen(mot);
}
