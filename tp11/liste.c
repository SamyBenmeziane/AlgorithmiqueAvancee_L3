// liste.c
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

cellule *NouvCel(point p) {
    cellule *c = (cellule *)malloc(sizeof(cellule));
    if (c == NULL) {
        perror("allocation mémoire a échoué");
        return NULL;
    }
    c->p = p;
    c->suiv = NULL;
    c->pres = NULL;
    return c;
}

void InsererCellule(int pl, cellule *cel, cellule *liste) {
    if (cel == NULL) return;

    if (pl <= 0 || liste == NULL) {
        printf("ERREUR CRITIQUE : L'insertion en TÊTE (pl=0) ou dans une liste vide ");
        printf("est impossible avec cette signature de fonction.\n");
        return;
    } 

    cellule *precedent = liste;
    int i = 1;

    while (precedent != NULL && i < pl) {
        precedent = precedent->suiv;
        i++;
    }

    if (precedent == NULL) {
        printf("Erreur : Position d'insertion (%d) hors limites.\n", pl);
        return;
    }

    cel->suiv = precedent->suiv;
    cel->pres = precedent;

    if (precedent->suiv != NULL) {
        precedent->suiv->pres = cel;
    }
    precedent->suiv = cel;
    printf("   -> Insertion du Point (%d, %d) après la position %d.\n", cel->p.x, cel->p.y, pl);
}

void SupprimeCellule(int pl, cellule *liste) {
    if (liste == NULL) return;

    if (pl == 1) {
        printf("ERREUR CRITIQUE : La suppression de la TÊTE (pl=1) ");
        printf("est impossible avec cette signature de fonction.\n");
        return;
    }

    cellule *a_supprimer = liste;
    int i = 1;

    while (a_supprimer != NULL && i < pl) {
        a_supprimer = a_supprimer->suiv;
        i++;
    }

    if (a_supprimer == NULL) {
        printf("Erreur : Position de suppression (%d) invalide.\n", pl);
        return;
    }

    a_supprimer->pres->suiv = a_supprimer->suiv;
    if (a_supprimer->suiv != NULL) {
        a_supprimer->suiv->pres = a_supprimer->pres;
    }

    printf("   -> Suppression du Point (%d, %d) à la position %d.\n", a_supprimer->p.x, a_supprimer->p.y, pl);
    free(a_supprimer);
}

void Afficher(cellule *liste) {
    if (liste == NULL) {
        printf("La forme polygonale est vide.\n");
        return;
    }

    cellule *courant = liste;
    int i = 1;

    printf("\n--- AFFICHAGE de la Forme Polygonale ---\n");
    while (courant != NULL) {
        printf("Point %d: (%d, %d)\n", i, courant->p.x, courant->p.y);
        courant = courant->suiv;
        i++;
    }
    printf("----------------------------------------\n");
}
void LibererListe(cellule *liste) {
    cellule *courant = liste;
    cellule *temp;

    while (courant != NULL) {
        temp = courant;
        courant = courant->suiv;
        free(temp);
    }
    printf("\nMémoire de la liste libérée.\n");
}