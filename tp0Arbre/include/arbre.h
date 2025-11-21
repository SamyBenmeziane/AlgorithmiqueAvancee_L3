// arbre.h

#ifndef ARBRE_H
#define ARBRE_H

#include <stdlib.h>


typedef struct noeud {
    char c;
    int n;
    struct noeud *gauche;
    struct noeud *droite;
} noeud;


noeud *nouvNoeud(char carac, int num);
noeud *rechercheNoeud(noeud *n, int num_noeud);

void insererFG(noeud *n, noeud *root, int num_noeud); 

void parcourPrefixe(noeud *n);
void libererArbre(noeud *n);
void parcoursInfixe(noeud *n);
void parcoursPostfixe(noeud *n);
noeud* creerArbreRecursif(int h, char *c);
#endif 