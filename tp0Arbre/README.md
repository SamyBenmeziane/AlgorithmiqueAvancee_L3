# TP0 : Implémentation d'Arbres Binaires en C

## Objectif du Travaux Pratiques

Ce Travaux Pratiques (TP0) a pour objectif d'implémenter les bases des **arbres binaires** en langage C. Il couvre la définition de la structure du nœud, les fonctions de création, de recherche, de gestion de la mémoire et les trois principaux types de parcours d'arbre.

---

## Organisation du Code

Le projet est organisé autour de la structure suivante :

* **`include/`** : Contient le fichier d'en-tête.
    * **`arbre.h`** : Déclaration de la structure du nœud (`struct noeud`) et des prototypes de toutes les fonctions de manipulation de l'arbre.
* **`src/`** : Contient les fichiers source C.
    * **`ArbreBin.c`** : **Implémentation des fonctions** de l'arbre binaire (création de nœud, recherche, insertion, parcours et libération de la mémoire).
    * **`monArbre.c`** : **Fichier principal** (`main`) contenant les tests pour valider les fonctions de l'arbre.

---

## Fonctionnalités Implémentées (ArbreBin.c)

| Fonction | Description | Type de Fonction |
| :--- | :--- | :--- |
| `nouvNoeud` | Crée et initialise un nouveau nœud (caractère, numéro, enfants à `NULL`). | Constructeur |
| `rechercheNoeud` | Recherche un nœud dans l'arbre par son numéro (`n`) de manière récursive. | Recherche |
| `insererFG` | Insère un nouveau nœud comme **fils gauche (FG)**, le FG existant du parent devenant le nouveau FG de l'enfant inséré. | Modification |
| `parcourPrefixe` | Affiche les nœuds selon le parcours **Préfixe** (Racine, Gauche, Droite). | Parcours |
| `parcoursInfixe` | Affiche les nœuds selon le parcours **Infixe** (Gauche, Racine, Droite). | Parcours |
| `parcoursPostfixe` | Affiche les nœuds selon le parcours **Postfixe** (Gauche, Droite, Racine). | Parcours |
| `creerArbreRecursif` | Fonction utilitaire pour construire un arbre binaire complet d'une hauteur donnée. | Création |
| `libererArbre` | Libère récursivement la mémoire allouée à tous les nœuds de l'arbre. | Gestion Mémoire |

---

##  Compilation et Exécution

Ce projet nécessite un compilateur C (comme GCC).

### 1. Compilation

Utilisez la commande suivante pour compiler les deux fichiers source et inclure les en-têtes :

```bash
gcc -I include src/ArbreBin.c src/monArbre.c -o tp0Arbre