
#ifndef LISTE_H
#define LISTE_H

#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct cellule {
    point p;
    struct cellule *suiv;
    struct cellule *pres;
} cellule;


cellule *NouvCel(point p);
void InsererCellule(int pl, cellule *cel, cellule *liste);
void SupprimeCellule(int pl, cellule *liste);
void Afficher(cellule *liste);
void LibererListe(cellule *liste); // Utile pour le nettoyage

#endif 