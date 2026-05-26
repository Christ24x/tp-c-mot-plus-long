# Guide d'utilisation - Module SAVE

## Structure du projet

```
tp-c-mot-plus-long-main/
├── main.c                      # Programme principal avec tests
├── save.c                      # Implémentation du module save
├── save.h                      # En-têtes du module save
├── dictionnaire.txt            # Dictionnaire de mots valides
├── compile.bat                 # Script de compilation (Windows)
├── Makefile                    # Configuration de compilation (Unix/Linux/MinGW)
├── SAVE_MODULE.md              # Documentation technique
└── SYNTHESE_FINALISATION.md    # Résumé du travail effectué
```

## Installation et compilation

### Prérequis

- Compiler C: `gcc`, `clang`, ou MinGW
- Pour Windows: MinGW-w64 (https://www.mingw-w64.org/)

### Installation de MinGW (Windows)

1. Télécharger MinGW-w64 depuis: https://www.mingw-w64.org/downloads/
2. Installer avec l'option "Add to PATH"
3. Vérifier l'installation: `gcc --version`

### Compilation

#### Option 1 : Ligne de commande
```bash
cd /chemin/vers/tp-c-mot-plus-long-main
gcc main.c save.c -o jeu.exe
```

#### Option 2 : Script batch (Windows)
```bash
double-click compile.bat
```

#### Option 3 : Make (Unix/Linux/MinGW)
```bash
make all
make run
```

## Exécution

```bash
./jeu.exe          # Windows
./jeu              # Unix/Linux
```

## Tests inclus

Le programme affichera les résultats de 4 suites de tests:

### Test 1: motPossible()
Teste la détection de mots formables à partir d'une grille.

**Exemples:**
- Grille "abcde" + mot "abc" → **1** (OK)
- Grille "abcde" + mot "xyz" → **0** (impossible)

### Test 2: sauvegarderPartie()
Sauvegarde l'état d'une partie exemple:
- Joueurs: Alice vs Bob
- Scores: 10 vs 15
- Tour: 5
- Joueur actuel: 1 (Bob)
- Grille: acbde

Crée le fichier `save.txt`

### Test 3: chargerPartie()
Charge les données depuis `save.txt` et les affiche.

### Test 4: proposerMeilleurMot()
Trouve le meilleur mot possible pour différentes grilles:
- Grille "acbde" → Cherche le mot le plus long
- Grille "abc" → Idem
- Grille "xyz" → Aucun mot trouvé

## Fichiers générés

### save.txt
Fichier créé lors du test 2, format:
```
Alice
Bob
10
15
5
1
acbde
```

## Utilisation dans votre propre code

### Exemple 1: Vérifier un mot

```c
#include "save.h"

int main() {
    char grille[] = "abcdefgh";
    
    if (motPossible("cafe", grille)) {
        printf("Le mot 'cafe' est possible!\n");
    }
    
    return 0;
}
```

### Exemple 2: Sauvegarder une partie

```c
#include "save.h"

int main() {
    sauvegarderPartie(
        "Alice",      // joueur1
        "Bob",        // joueur2
        25,           // score1
        30,           // score2
        10,           // tour
        0,            // joueurActuel (0 = Alice)
        "abcdefgh"    // grille
    );
    
    return 0;
}
```

### Exemple 3: Charger une partie

```c
#include "save.h"

int main() {
    char j1[100], j2[100];
    int s1, s2, t, jActuel;
    char grille[100];
    
    chargerPartie(j1, j2, &s1, &s2, &t, &jActuel, grille);
    
    printf("Partie: %s (%d) vs %s (%d)\n", j1, s1, j2, s2);
    
    return 0;
}
```

### Exemple 4: Proposer le meilleur mot

```c
#include "save.h"

int main() {
    proposerMeilleurMot("abcdefgh");
    // Affichera: "Meilleur mot : XXX" ou "Aucun mot trouve."
    
    return 0;
}
```

## Dépannage

### Erreur: "gcc: command not found"
- Installer MinGW et ajouter au PATH
- Ou utiliser le chemin complet: `C:\path\to\mingw64\bin\gcc.exe main.c save.c -o jeu.exe`

### Le programme ne trouve pas dictionnaire.txt
- Vérifier que `dictionnaire.txt` existe dans le même répertoire
- Ajouter des mots au dictionnaire (un mot par ligne)

### Le programme ne trouve pas save.txt lors du chargement
- D'abord exécuter le Test 2 (sauvegarderPartie) qui crée le fichier
- Ou créer manuellement `save.txt` avec le format correct

### Erreur de compilation "undefined reference to..."
- Vérifier que TOUS les fichiers .c sont listés: `gcc main.c save.c -o jeu.exe`
- Ne pas oublier `save.c`!

## Performance

- **motPossible()**: O(n*m) où n est la taille du mot et m la taille de la grille
- **proposerMeilleurMot()**: O(k*n*m) où k est le nombre de mots dans le dictionnaire

Pour de grandes bases de mots (>10000), considérer une optimisation avec un trie ou un arbre de recherche.

## Notes

- Les buffers sont limités à 100 caractères
- Les noms de joueurs ne doivent pas contenir d'espaces (sinon utiliser scanf("%99[^\n]", nom))
- Le dictionnaire accepte des mots de n'importe quelle longueur
- Le fichier save.txt est créé/écrasé à chaque sauvegarde

## Support

Pour des problèmes:
1. Vérifier la documentation SAVE_MODULE.md
2. Relire les commentaires du code
3. Consulter la SYNTHESE_FINALISATION.md
4. Tester avec le code d'exemple ci-dessus
