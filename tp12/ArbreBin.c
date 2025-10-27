#include <stdio.h>
#include <stdlib.h>
typedef struct noeud {
    char c;
    int n;
    struct noeud *gauche;
    struct noeud *droite;
}noeud;
noeud * nouvNoeud (char carac,int num){
    noeud * nouveau = (noeud *) malloc (sizeof (noeud));
    if (nouveau == NULL){
        perror ("allocation memoire a echoue");
        return NULL;
    }
    nouveau->c = carac;
    nouveau->n = num;
    nouveau->gauche = NULL;
    nouveau->droite = NULL;
    return nouveau;
}
noeud * rechercheNoeud( noeud *n, int num_noeud){
 noeud *tmpNoeud;
 if(n == NULL)return(NULL);
 if(n->n == num_noeud)
 return(n);
    tmpNoeud = rechercheNoeud(n->gauche, num_noeud);
    if(tmpNoeud != NULL)
        return(tmpNoeud);
    return(rechercheNoeud(n->droite, num_noeud));
}
void insererFG(noeud *enfant_a_inserer, noeud *root, int num_parent) {
    
    if (enfant_a_inserer == NULL) return;
    
    noeud *parent = rechercheNoeud(root, num_parent);
    
    if(parent == NULL) {
        printf("Erreur : Noeud parent %d introuvable.\n", num_parent);
        return;
    }
    
    enfant_a_inserer->gauche = parent->gauche;
    parent->gauche = enfant_a_inserer;
    
    printf("-> Nœud %c (%d) inséré comme nouveau FG de %c (%d).\n", 
           enfant_a_inserer->c, enfant_a_inserer->n, parent->c, parent->n);
}

void parcourPrefixe(noeud *n){
    if(n == NULL)return;
    printf("%c ", n->c);
    parcourPrefixe(n->gauche);
    parcourPrefixe(n->droite);
}
void libererArbre(noeud *n) {
    if (n == NULL) return;
    libererArbre(n->gauche);
    libererArbre(n->droite);
    free(n);
}
