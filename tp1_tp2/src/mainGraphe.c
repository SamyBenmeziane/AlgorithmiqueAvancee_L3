#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

int main() {
    Graphe* G = NULL;
    int choix;
    char nomFichier[256];

    printf("=== Gestion d'un graphe ===\n");
    printf("Choisissez le mode d'entrée :\n");
    printf("1. Lecture depuis un fichier\n");
    printf("2. Saisie interactive\n");
    printf("Votre choix : ");
    if (scanf("%d", &choix) != 1) {
        printf("Entrée invalide !\n");
        return 1;
    }
    while(getchar() != '\n'); // vider le buffer

    if (choix == 1) {
        printf("Entrez le nom du fichier : ");
        if (scanf("%s", nomFichier) != 1) {
            printf("Erreur lecture nom fichier !\n");
            return 1;
        }
        FILE* fp = fopen(nomFichier, "r");
        if (!fp) {
            printf("Impossible d'ouvrir le fichier %s\n", nomFichier);
            return 1;
        }
        G = chargeGraphe(fp);
        fclose(fp);
    } else if (choix == 2) {
        G = chargeGraphe(NULL);
    } else {
        printf("Choix invalide !\n");
        return 1;
    }

    testerGraphe(G);
    return 0;
}

