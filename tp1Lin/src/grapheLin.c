#include <stdio.h>
#include <stdlib.h>
#include "grapheLin.h"

GrapheLin* creer_graphe_lin() {
    int u, v, i;
    GrapheLin *G = (GrapheLin*) malloc(sizeof(GrapheLin));
    if (!G) {
        printf("Erreur allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez le nombre de sommets et d'arêtes : ");
    scanf("%d %d", &G->nbsommets, &G->nbarretes);

    G->adjacence_lin = (int*) calloc(G->nbsommets * G->nbsommets, sizeof(int));
    printf("Entrez chaque arête sous forme de deux entiers u v (indices 0-based) :\n");
    for (i = 0; i < G->nbarretes; i++) {
        scanf("%d %d", &u, &v);
        G->adjacence_lin[u * G->nbsommets + v] = 1;
        G->adjacence_lin[v * G->nbsommets + u] = 1;
    }
    return G;
}

void liberer_graphe_lin(GrapheLin* G) {
    free(G->adjacence_lin);
    free(G);
}

void trier_degres_lin(Sommet *tab, int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if (tab[j].degre < tab[j+1].degre) {
                Sommet tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
}

void coloration_welsh_powell_lin(int *adj, int n, int *couleurs) {
    Sommet *sommets = malloc(n * sizeof(Sommet));
    for (int i = 0; i < n; i++) {
        sommets[i].sommet = i;
        sommets[i].degre = 0;
        for (int j = 0; j < n; j++)
            sommets[i].degre += adj[i * n + j];
        couleurs[i] = 0;
    }
    trier_degres_lin(sommets, n);

    int couleur_courante = 1;
    for (int i = 0; i < n; i++) {
        int u = sommets[i].sommet;
        if (couleurs[u] == 0) {
            couleurs[u] = couleur_courante;
            for (int j = i+1; j < n; j++) {
                int v = sommets[j].sommet;
                if (couleurs[v] == 0) {
                    int adjacent = 0;
                    for (int k = 0; k < n; k++) {
                        if (adj[u*n + k] == 1 && v == k) { adjacent = 1; break; }
                        if (adj[v*n + k] == 1 && couleurs[k] == couleur_courante) { adjacent = 1; break; }
                    }
                    if (!adjacent)
                        couleurs[v] = couleur_courante;
                }
            }
            couleur_courante++;
        }
    }
    free(sommets);
}

void afficher_coloration(int *couleurs, int n) {
    printf("(Sommets , Couleurs ) : ");
    for (int i = 0; i < n; i++)
        printf("(%d, %d)   ", i, couleurs[i]);
    printf("\n");
}
