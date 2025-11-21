#ifndef GRAPHE_LIN_H
#define GRAPHE_LIN_H

typedef struct {
    int nbsommets;         // Nombre de sommets
    int nbarretes;         // Nombre d’arêtes
    int *adjacence_lin;    // Matrice d’adjacence linéarisée
} GrapheLin;

typedef struct {
    int sommet;
    int degre;
} Sommet;

GrapheLin* creer_graphe_lin();
void liberer_graphe_lin(GrapheLin* G);
void coloration_welsh_powell_lin(int *adj, int n, int *couleurs);
void afficher_coloration(int *couleurs, int n);

#endif
