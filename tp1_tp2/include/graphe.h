#ifndef GRAPHE_H
#define GRAPHE_H

typedef struct {
    int nbsommets;      // Nombre de sommets
    int nbarretes;      // Nombre d’arêtes
    int **adjacence;    // Matrice d’adjacence dynamique
} Graphe;

// Prototypes des fonctions
void liberer_graphe(Graphe* G);
void coloration_welsh_powell(int **adj, int n, int *couleurs);
void afficher_coloration(int *couleurs, int n);
Graphe* chargeGraphe(FILE* fp);
void testerGraphe(Graphe* G);
#endif
