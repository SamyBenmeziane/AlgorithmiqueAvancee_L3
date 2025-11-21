// monArbre.c

#include <stdio.h>
#include "arbre.h" 

int main() {
 
   
char c = 'A';
noeud *arbre = creerArbreRecursif(4, &c);

    
    printf("\nParcours Prefixe: ");
    parcourPrefixe(arbre); 
    printf("\n");



       printf("Parcours infixe   : ");
    parcoursInfixe(arbre);
    printf("\n");

    printf("Parcours postfixe : ");
    parcoursPostfixe(arbre);
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