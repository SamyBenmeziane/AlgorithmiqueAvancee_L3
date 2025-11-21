#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

typedef struct {
    int sommet;
    int degre;
} Sommet;


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
    printf("Ordre de marquage (tri par degrés décroissants) : ");
    for (int i = 0; i < n; i++)
        printf("%d ", sommets[i].sommet);
        printf("\n");


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
    printf("(Sommets , Couleurs ) : ");
    for (int i = 0; i < n; i++)
        printf("(%d, %d)   ", i, couleurs[i]);
    printf("\n");
}


Graphe* chargeGraphe(FILE* fp) {
    int i, j, u, v;
    Graphe* G = malloc(sizeof(Graphe));
    if (!G) {
        printf("Erreur allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    if (fp != NULL) {
        if (fscanf(fp, "%d", &G->nbsommets) != 1) {
            printf("Erreur : impossible de lire le nombre de sommets.\n");
            free(G);
            return NULL;
        }
    } else {
        printf("Entrez le nombre de sommets : ");
        scanf("%d", &G->nbsommets);
    }

    // Limite maximale pour éviter une surcharge mémoire
    if (G->nbsommets <= 0 || G->nbsommets > 1000) {
        printf("Erreur : nombre de sommets invalide.\n");
        free(G);
        return NULL;
    }

    // Initialiser la matrice à 0
    G->adjacence = malloc(G->nbsommets * sizeof(int*));
    for (i = 0; i < G->nbsommets; i++)
        G->adjacence[i] = calloc(G->nbsommets, sizeof(int));

    G->nbarretes = 0;

    if (fp != NULL) {
        // Lecture depuis fichier
        for (i = 0; i < G->nbsommets; i++) {
            for (j = 0; j < G->nbsommets; j++) {
                int val;
                if (fscanf(fp, "%d", &val) != 1) {
                    printf("Erreur lecture matrice : case (%d,%d)\n", i, j);
                    for (int k = 0; k <= i; k++) free(G->adjacence[k]);
                    free(G->adjacence);
                    free(G);
                    return NULL;
                }
                if (val != 0 && val != 1) {
                    printf("Erreur : la matrice doit contenir uniquement 0 ou 1\n");
                    for (int k = 0; k <= i; k++) free(G->adjacence[k]);
                    free(G->adjacence);
                    free(G);
                    return NULL;
                }
                if (i == j && val != 0) {
                    printf("Erreur : diagonale doit être 0 (pas de boucle) en (%d,%d)\n", i, j);
                    for (int k = 0; k <= i; k++) free(G->adjacence[k]);
                    free(G->adjacence);
                    free(G);
                    return NULL;
                }
                G->adjacence[i][j] = val;
            }
        }

        // Vérification symétrie et compter les arêtes
        for (i = 0; i < G->nbsommets; i++) {
            for (j = i+1; j < G->nbsommets; j++) {
                if (G->adjacence[i][j] != G->adjacence[j][i]) {
                    printf("Erreur : la matrice n'est pas symétrique en (%d,%d)\n", i, j);
                    for (int k = 0; k < G->nbsommets; k++) free(G->adjacence[k]);
                    free(G->adjacence);
                    free(G);
                    return NULL;
                }
                if (G->adjacence[i][j] == 1) G->nbarretes++;
            }
        }

    } else {
        // Lecture interactive
        printf("\nAjoutez les arêtes :\n");
        printf("Entrez une arête sous la forme : sommet1 sommet2 (0 à %d)\n", G->nbsommets-1);
        printf("Entrez -1 -1 pour terminer.\n");
        while (1) {
            printf("Arête : ");
            if (scanf("%d %d", &u, &v) != 2) {
                printf("Entrée invalide ! Réessayez.\n");
                while(getchar() != '\n');
                continue;
            }
            while(getchar() != '\n');

            if (u == -1 && v == -1) break;
            if (u < 0 || u >= G->nbsommets || v < 0 || v >= G->nbsommets) {
                printf("Erreur : sommet inexistant !\n");
                continue;
            }
            if (u == v) {
                printf("Erreur : pas de boucle autorisée.\n");
                continue;
            }
            if (G->adjacence[u][v] == 1) {
                printf("Erreur : cette arête existe déjà.\n");
                continue;
            }

            G->adjacence[u][v] = 1;
            G->adjacence[v][u] = 1;
            G->nbarretes++;
            printf("Arête ajoutée : %d - %d\n", u, v);
        }
    }

    // Affichage final
    printf("\nMatrice d'adjacence finale (%d arêtes) :\n", G->nbarretes);
    for (i = 0; i < G->nbsommets; i++) {
        for (j = 0; j < G->nbsommets; j++)
            printf("%d ", G->adjacence[i][j]);
        printf("\n");
    }

    return G;
}
void testerGraphe(Graphe* G) {
    if (!G) {
        printf("Erreur : le graphe n'a pas pu être chargé.\n");
        return;
    }

    // Allocation du tableau de couleurs
    int *couleurs = calloc(G->nbsommets, sizeof(int));
    if (!couleurs) {
        printf("Erreur allocation mémoire.\n");
        liberer_graphe(G);
        return;
    }

    // Appliquer Welsh-Powell
    coloration_welsh_powell(G->adjacence, G->nbsommets, couleurs);

    // Affichage du résultat
    afficher_coloration(couleurs, G->nbsommets);

    // Libération mémoire
    free(couleurs);
    liberer_graphe(G);
}
