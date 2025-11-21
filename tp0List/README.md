# TP0 : Implémentation d'une Liste Doublement Chaînée (Polygone)

##  Objectif du Travaux Pratiques

Ce Travaux Pratiques (TP0) a pour objectif d'implémenter une **liste doublement chaînée** en langage C. Cette structure de données est utilisée pour gérer une séquence de **points géométriques** (`(x, y)`), simulant les sommets d'une **forme polygonale**.

Le code définit les structures de données (Point et Cellule) et implémente les fonctions essentielles pour manipuler la liste (création, insertion, suppression, affichage et libération de la mémoire).

---

##  Organisation du Code

* **`liste.h`** : Fichier d'en-tête contenant les définitions des structures (`point`, `cellule`) et les prototypes de toutes les fonctions.
* **`liste.c`** : Fichier source qui contient l'**implémentation de toutes les fonctions** de manipulation de la liste doublement chaînée.
* **`maListe.c`** : Fichier principal (`main`) contenant le programme de test et la validation des fonctionnalités.

---

##  Structures de Données Clés

* **Structure `point`**
    * **Description :** Représente un sommet dans l'espace 2D.
    * **Membres :** `int x`, `int y`.
* **Structure `cellule`**
    * **Description :** Représente un nœud dans la liste (doublement chaînée).
    * **Membres :**
        * `point p` (Les données du point).
        * `struct cellule *suiv` (Pointeur vers la cellule **suivante**).
        * `struct cellule *pres` (Pointeur vers la cellule **précédente**). 

---

##  Fonctionnalités Implémentées dans `liste.c`

### Gestion de la Liste

* **`NouvCel(point p)`** : **Constructeur de Cellule**. Alloue la mémoire et initialise la cellule avec les coordonnées du point donné.
* **`InsererCellule(int pl, cellule *cel, cellule *liste)`** : **Insertion**. Insère une nouvelle cellule **après la position** (`pl`) spécifiée en mettant à jour les pointeurs des cellules précédentes et suivantes.
    * *Note :* L'insertion en tête n'est pas gérée par cette fonction.
* **`SupprimeCellule(int pl, cellule *liste)`** : **Suppression**. Supprime la cellule située à la position (`pl`) spécifiée et libère sa mémoire après avoir re-chaîné les éléments voisins.
    * *Note :* La suppression de la tête n'est pas gérée par cette fonction.

###  Affichage et Nettoyage

* **`Afficher(cellule *liste)`** : Affiche les coordonnées de chaque point de la liste dans l'ordre séquentiel.
* **`LibererListe(cellule *liste)`** : Fonction essentielle qui parcourt la liste et libère la mémoire allouée à chaque cellule pour éviter les fuites.

---

## Compilation et Exécution

Ce projet est écrit en C et nécessite un compilateur (ex: GCC).

### 1. Compilation

Utilisez la commande suivante pour compiler les deux fichiers source et créer l'exécutable (`tp0Liste`) :

```bash
gcc src/liste.c src/maListe.c -o tp0Liste -I include
2. Exécution
Exécutez le programme principal :

Bash

./tp0Liste