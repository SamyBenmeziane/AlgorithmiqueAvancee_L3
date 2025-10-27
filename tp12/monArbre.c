// monArbre.c

#include <stdio.h>
#include "arbre.h" 

int main() {
 
    noeud *arbre = nouvNoeud('A', 1);

    noeud *n2 = nouvNoeud('B', 2);
    noeud *n3 = nouvNoeud('C', 3);
    noeud *n4 = nouvNoeud('D', 4);

    
    insererFG(n2, arbre, 1);
    insererFG(n3, arbre, 1);  
    insererFG(n4, arbre, 3);
    
    printf("\nParcours Prefixe: ");
    parcourPrefixe(arbre); 
    printf("\n");

    noeud *recherche = rechercheNoeud(arbre, 3);
    if(recherche != NULL){
        printf("Noeud trouve : %c\n", recherche->c);
    } else {
        printf("Noeud non trouve.\n");
    }
    libererArbre(arbre); 
    
    return 0;
}