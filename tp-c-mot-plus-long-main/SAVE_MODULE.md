# Module SAVE - Documentation

## Description

Module C pour la gestion de sauvegarde, chargement et analyse de mots pour le jeu "mot le plus long".

## Fichiers

- `save.h` : En-têtes et prototypes des fonctions
- `save.c` : Implémentation des fonctions
- `main.c` : Tests des fonctions
- `dictionnaire.txt` : Dictionnaire de mots valides
- `save.txt` : Fichier de sauvegarde (généré à la runtime)

## Fonctions

### 1. `motPossible(char mot[], char grille[])`

**Objectif** : Vérifie si un mot peut être formé avec les lettres de la grille.

**Paramètres** :
- `mot` : Mot à vérifier
- `grille` : Grille de lettres disponibles

**Retour** :
- `1` si le mot peut être formé
- `0` sinon

**Exemple** :
```c
motPossible("abc", "abcde");  // Retourne 1
motPossible("xyz", "abcde");  // Retourne 0
```

**Notes** :
- Chaque lettre de la grille ne peut être utilisée qu'une seule fois
- La fonction crée une copie de la grille pour marquer les lettres utilisées

### 2. `sauvegarderPartie(...)`

**Objectif** : Sauvegarde l'état d'une partie dans `save.txt`.

**Paramètres** :
```c
void sauvegarderPartie(
    char joueur1[],      // Nom du joueur 1
    char joueur2[],      // Nom du joueur 2
    int score1,          // Score du joueur 1
    int score2,          // Score du joueur 2
    int tour,            // Numéro du tour
    int joueurActuel,    // 0 ou 1 (joueur actuel)
    char grille[]        // Grille de lettres
);
```

**Format du fichier `save.txt`** :
```
Alice
Bob
10
15
5
1
acbde
```

**Exemple** :
```c
sauvegarderPartie("Alice", "Bob", 10, 15, 5, 1, "acbde");
```

### 3. `chargerPartie(...)`

**Objectif** : Charge l'état d'une partie depuis `save.txt`.

**Paramètres** :
```c
void chargerPartie(
    char joueur1[],      // Buffer pour joueur 1 (min 100 chars)
    char joueur2[],      // Buffer pour joueur 2 (min 100 chars)
    int *score1,         // Pointeur vers le score 1
    int *score2,         // Pointeur vers le score 2
    int *tour,           // Pointeur vers le tour
    int *joueurActuel,   // Pointeur vers le joueur actuel
    char grille[]        // Buffer pour la grille (min 100 chars)
);
```

**Exemple** :
```c
char j1[100], j2[100], grille[100];
int s1, s2, t, jActuel;

chargerPartie(j1, j2, &s1, &s2, &t, &jActuel, grille);
```

### 4. `proposerMeilleurMot(char grille[])`

**Objectif** : Lit le `dictionnaire.txt` et propose le mot le plus long formable.

**Paramètres** :
- `grille` : Grille de lettres disponibles

**Affichage** :
- `"Meilleur mot : XXX"` si un mot est trouvé
- `"Aucun mot trouve."` sinon

**Exemple** :
```c
proposerMeilleurMot("acbde");  // Affiche le meilleur mot possible
```

## Compilation

### Méthode 1 : Avec MinGW/GCC

```bash
gcc main.c save.c -o jeu
```

Ou avec Make :

```bash
make all
make run
```

### Méthode 2 : Script batch (Windows)

Double-cliquez sur `compile.bat` pour compiler et exécuter.

## Utilisation

```bash
./jeu
```

Le programme affichera les résultats des différents tests :

1. Tests de `motPossible()` avec différentes grilles et mots
2. Sauvegarde d'une partie d'exemple
3. Chargement de la partie depuis le fichier
4. Recherche du meilleur mot pour différentes grilles

## Gestion des erreurs

- Si `dictionnaire.txt` n'existe pas : affiche "Aucun mot trouve."
- Si `save.txt` n'existe pas lors du chargement : affiche un message d'erreur
- Les buffers sont protégés avec une taille maximale de 99 caractères (+ \0)

## Contraintes respectées

✓ Standard C99  
✓ Pas de dépendances externes  
✓ Utilisation de FILE*, fopen, fclose, fprintf, fscanf  
✓ Prototypes stricts respectés  
✓ Code propre et sans duplication  
✓ Gestion simple des erreurs  
✓ Utilisation sécurisée de strcpy et strlen  
✓ Gestion des buffers (100 caractères)  

## Notes de développement

- La taille des buffers est de 100 caractères pour éviter les débordements
- Les fichiers de sauvegarde utilisent le format texte pour faciliter le débogage
- Le dictionnaire peut contenir des mots de n'importe quelle longueur
- L'algorithme de recherche du meilleur mot est O(n*m) où n est le nombre de mots et m la longueur moyenne

## Prochaines étapes possibles

- Optimisation avec un arbre de recherche pour les mots
- Support des accents et caractères spéciaux
- Interface utilisateur pour la sauvegarde/chargement
- Validation des noms de joueurs
