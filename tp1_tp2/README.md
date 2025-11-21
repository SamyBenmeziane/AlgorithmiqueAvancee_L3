# Projet : Coloration de Graphe par Algorithme de Welsh-Powell

##  Objectif du Projet

Ce projet implémente les structures et fonctions nécessaires pour représenter un **graphe non-orienté** en utilisant une **matrice d'adjacence**. L'objectif principal est d'appliquer l'algorithme glouton de **Welsh-Powell** pour effectuer une **coloration du graphe**, c'est-à-dire attribuer un minimum de couleurs aux sommets de telle sorte qu'aucun sommet adjacent n'ait la même couleur.

Le graphe peut être chargé depuis un fichier ou construit de manière interactive.

---

##  Organisation du Code

| Fichier | Rôle | Description |
| :--- | :--- | :--- |
| **`graphe.h`** | Définitions et Prototypes | Contient la structure du graphe (`Graphe`) et les prototypes de toutes les fonctions de gestion et de coloration. |
| **`graphe.c`** | Implémentation des Fonctions | Contient l'implémentation des algorithmes de lecture, de tri, de coloration (Welsh-Powell) et de libération de la mémoire. |
| **`main.c`** | Programme Principal | Gère l'interface utilisateur (choix du mode d'entrée) et orchestre le chargement, l'analyse et la libération du graphe. |

---

##  Structure de Données Clé

### Structure `Graphe`

Cette structure représente le graphe non-orienté :

* **`int nbsommets`** : Le nombre total de sommets (taille de la matrice).
* **`int nbarretes`** : Le nombre d'arêtes.
* **`int **adjacence`** : La **matrice d'adjacence** dynamique. `adjacence[i][j] = 1` si un arc existe entre le sommet `i` et le sommet `j`, `0` sinon. (Pour un graphe non-orienté, cette matrice est symétrique).

---

##  Fonctionnalités Implémentées dans `graphe.c`

###  Chargement et Validation du Graphe

* **`Graphe* chargeGraphe(FILE* fp)`**
    * **Rôle :** Alloue la structure `Graphe` et sa matrice d'adjacence.
    * **Détails :** Prend en charge la lecture des données soit :
        1.  Depuis un **fichier** (`fp != NULL`). Le fichier doit contenir le nombre de sommets suivi de la matrice d'adjacence ligne par ligne.
        2.  En **saisie interactive** (`fp == NULL`).
    * **Validation :** Effectue plusieurs vérifications (symétrie de la matrice, absence de boucles, valeurs binaires 0/1) pour assurer la validité du graphe non-orienté.

###  Algorithme de Coloration (Welsh-Powell)

* **`void coloration_welsh_powell(int **adj, int n, int *couleurs)`**
    * **Principe :** Implémente l'algorithme glouton de Welsh-Powell.
    * **Étapes :**
        1.  Calcule le **degré** de chaque sommet.
        2.  **Trie** les sommets par ordre de degré **décroissant** (`trier_degres`).
        3.  Attribue séquentiellement la première couleur disponible à chaque sommet de la liste triée.
        4.  Tente d'attribuer la même couleur à tous les sommets non colorés restants qui ne sont pas adjacents à un sommet déjà coloré avec cette couleur.
* **`void afficher_coloration(int *couleurs, int n)`**
    * **Rôle :** Affiche le résultat final de l'attribution des couleurs pour chaque sommet.

###  Gestion de la Mémoire

* **`void liberer_graphe(Graphe* G)`**
    * **Rôle :** Libère la mémoire de la matrice d'adjacence ligne par ligne, puis la mémoire de la structure `Graphe` elle-même pour éviter les fuites.
* **`void testerGraphe(Graphe* G)`**
    * **Rôle :** Fonction d'orchestration qui lance l'algorithme de coloration et s'assure de la libération de toute la mémoire (graphe et tableau de couleurs).

---

## Compilation et Utilisation

Ce projet est écrit en C et nécessite un compilateur (ex: GCC).

### 1. Compilation

```bash
gcc main.c graphe.c -o coloration
2. Exécution
Le programme demande à l'utilisateur de choisir entre le chargement par fichier ou la saisie interactive.

Bash

./coloration