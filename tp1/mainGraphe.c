#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
int main() {
    Graphe* G = creer_graphe();

    int *couleurs = calloc(G->nbsommets, sizeof(int));
    coloration_welsh_powell(G->adjacence, G->nbsommets, couleurs);
    afficher_coloration(couleurs, G->nbsommets);

    liberer_graphe(G);
    free(couleurs);

    return 0;
}
