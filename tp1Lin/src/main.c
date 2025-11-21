#include <stdio.h>
#include <stdlib.h>
#include "grapheLin.h"

int main() {
    GrapheLin *G = creer_graphe_lin();

    int *couleurs = calloc(G->nbsommets, sizeof(int));
    coloration_welsh_powell_lin(G->adjacence_lin, G->nbsommets, couleurs);
    afficher_coloration(couleurs, G->nbsommets);

    liberer_graphe_lin(G);
    free(couleurs);

    return 0;
}
