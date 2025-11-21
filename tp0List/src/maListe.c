// maListe.c

#include <stdio.h>
#include "liste.h"

int main() {
    cellule *polyGone = NULL;

    point pTete = {10, 20};
    polyGone = NouvCel(pTete); 
    if (polyGone == NULL) return 1;

    printf(">>> DÉBUT du Programme de Test de la Liste Chaînée <<<\n");

    cellule *cel2 = NouvCel((point){30, 40});
    cellule *cel3 = NouvCel((point){50, 60});
    cellule *cel4 = NouvCel((point){70, 80});

    printf("\n--- Phase d'Insertion ---\n");
    InsererCellule(1, cel2, polyGone); 
    InsererCellule(2, cel3, polyGone); 
    InsererCellule(1, cel4, polyGone);

    Afficher(polyGone);

    cellule *celErr = NouvCel((point){99, 99});
    InsererCellule(0, celErr, polyGone);
    free(celErr);

    printf("\n--- Phase de Suppression ---\n");
    SupprimeCellule(2, polyGone); 
    SupprimeCellule(2, polyGone); 
    SupprimeCellule(1, polyGone);

    printf("\nListe finale:\n");
    Afficher(polyGone);

    LibererListe(polyGone);

    printf("<<< FIN du Programme >>>\n");

    return 0;
}