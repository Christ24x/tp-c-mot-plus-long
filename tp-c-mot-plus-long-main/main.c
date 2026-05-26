#include <stdio.h>
#include <string.h>
#include "save.h"

int main()
{
    printf("=== TEST MODULE SAVE ===\n\n");
    
    // Test 1: motPossible()
    printf("--- Test 1: motPossible() ---\n");
    char grille1[] = "abcde";
    
    printf("Grille: %s\n", grille1);
    printf("Mot 'abc': %d (attendu: 1)\n", motPossible("abc", grille1));
    printf("Mot 'abd': %d (attendu: 1)\n", motPossible("abd", grille1));
    printf("Mot 'abcde': %d (attendu: 1)\n", motPossible("abcde", grille1));
    printf("Mot 'xyz': %d (attendu: 0)\n", motPossible("xyz", grille1));
    printf("Mot 'abcdef': %d (attendu: 0)\n\n", motPossible("abcdef", grille1));
    
    // Test 2: sauvegarderPartie()
    printf("--- Test 2: sauvegarderPartie() ---\n");
    sauvegarderPartie("Alice", "Bob", 10, 15, 5, 1, "acbde");
    printf("\n");
    
    // Test 3: chargerPartie()
    printf("--- Test 3: chargerPartie() ---\n");
    char j1[100], j2[100];
    int s1, s2, t, jActuel;
    char grille[100];
    chargerPartie(j1, j2, &s1, &s2, &t, &jActuel, grille);
    printf("Données chargées: %s vs %s | Scores: %d-%d | Tour: %d | Joueur: %d | Grille: %s\n\n", 
           j1, j2, s1, s2, t, jActuel, grille);
    
    // Test 4: proposerMeilleurMot()
    printf("--- Test 4: proposerMeilleurMot() ---\n");
    printf("Grille: 'acbde'\n");
    proposerMeilleurMot("acbde");
    printf("\n");
    
    printf("Grille: 'abc'\n");
    proposerMeilleurMot("abc");
    printf("\n");
    
    printf("Grille: 'xyz'\n");
    proposerMeilleurMot("xyz");
    printf("\n");
    
    printf("=== TESTS TERMINÉS ===\n");
    
    return 0;
}
