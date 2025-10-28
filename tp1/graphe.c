#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

typedef struct {
    int sommet;
    int degre;
} Sommet;

 Graphe* creer_graphe() {
    int u, v, i;
     Graphe* G = (Graphe*) malloc(sizeof(Graphe));
    if (!G) {
        printf("Erreur allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez le nombre de sommets et d'arêtes : ");
    scanf("%d %d", &G->nbsommets, &G->nbarretes);

    G->adjacence = malloc(G->nbsommets * sizeof(int*));
    for (u = 0; u < G->nbsommets; u++)
        G->adjacence[u] = calloc(G->nbsommets, sizeof(int));

    printf("Entrez chaque arête sous forme deux entiers u v (indices 0-based) :\n");
    for (i = 0; i < G->nbarretes; i++) {
        scanf("%d %d", &u, &v);
        G->adjacence[u][v] = 1;
        G->adjacence[v][u] = 1;  // Graphe non orienté
    }
    return G;
}

void liberer_graphe(Graphe* G) {
    for (int i = 0; i < G->nbsommets; i++)
        free(G->adjacence[i]);
    free(G->adjacence);
    free(G);
    G = NULL;
}

void echanger(Sommet* a, Sommet* b) {
    Sommet tmp = *a;
    *a = *b;
    *b = tmp;
}

void trier_degres(Sommet *tab, int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if (tab[j].degre < tab[j+1].degre)
                echanger(&tab[j], &tab[j+1]);
}

void coloration_welsh_powell(int **adj, int n, int *couleurs) {
    Sommet *sommets = malloc(n * sizeof(Sommet));
    for (int i = 0; i < n; i++) {
        sommets[i].sommet = i;
        sommets[i].degre = 0;
        for (int j = 0; j < n; j++)
            sommets[i].degre += adj[i][j];
        couleurs[i] = 0;   // Pas encore coloré
    }
    trier_degres(sommets, n);

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
                        if (adj[u][k] == 1 && v == k) {
                            adjacent = 1;
                            break;
                        }
                        if (adj[v][k] == 1 && couleurs[k] == couleur_courante) {
                            adjacent = 1;
                            break;
                        }
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
    printf("Sommets : ");
    for (int i = 0; i < n; i++)
        printf("%d ", i);
    printf("\nCouleurs : ");
    for (int i = 0; i < n; i++)
        printf("%d ", couleurs[i]);
    printf("\n");
}

