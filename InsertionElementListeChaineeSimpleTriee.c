#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i, a, x, croissant = 1, decroissant = 1;
    
    struct cellule {
        int val;
        struct cellule *suiv;
    };
    struct cellule *head = NULL;
    struct cellule *liste, *Liste;

    printf("Quelle sera la longueur de votre liste ?\n");
    scanf("%i", &n);
    
    for(i = 1; i <= n; i++){
        printf("Entrez la valeur de l'element %i: \n", i);
        scanf("%i", &x);
        
        liste = malloc(sizeof(struct cellule));
        if(liste == NULL){
            printf("Erreur d'allocation memoire !\n");
            return 1;
        }
        liste->val = x;
        liste->suiv = NULL;

        // Insertion en fin
        if(head == NULL){
            head = liste;
        } else {
            Liste = head;
            while(Liste->suiv != NULL){
                Liste = Liste->suiv;
            }
            Liste->suiv = liste;
        }
    }
    
    // Vérification si la liste est triée
    Liste = head;
    while(Liste != NULL && Liste->suiv != NULL){
        if(Liste->val > Liste->suiv->val){ 
            croissant = 0; // pas croissante
        } else if (Liste->val < Liste->suiv->val){ 
            decroissant = 0; // pas décroissante
        }    
        Liste = Liste->suiv;
    }
    
    if(croissant == 1){
        Liste = head;
        printf("Veuillez saisir l'element a inserer dans la liste (croissante): \n");
        scanf("%i", &a);

        struct cellule *new = malloc(sizeof(struct cellule));
        if(new == NULL){
            printf("Erreur d'allocation memoire !\n");
            return 1;
        }
        new->val = a;
        new->suiv = NULL;

        if(head == NULL || a < head->val){
            new->suiv = head;
            head = new;
        } else {
            while(Liste->suiv != NULL && Liste->suiv->val < a) {
                Liste = Liste->suiv;
            }
            new->suiv = Liste->suiv;
            Liste->suiv = new;
        }
    } 
    else if(decroissant == 1){
        Liste = head;
        printf("Veuillez saisir l'element a inserer dans la liste (decroissante): \n");
        scanf("%i", &a);

        struct cellule *new = malloc(sizeof(struct cellule));
        if(new == NULL){
            printf("Erreur d'allocation memoire !\n");
            return 1;
        }
        new->val = a;
        new->suiv = NULL;

        if(head == NULL || a > head->val){
            new->suiv = head;
            head = new;
        } else {
            while(Liste->suiv != NULL && Liste->suiv->val > a) {
                Liste = Liste->suiv;
            }
            new->suiv = Liste->suiv;
            Liste->suiv = new;
        }    
    } 
    else {
        printf("Votre liste n'est pas triée !\n");
    }
    
    // Affichage de la liste 
    printf("Liste: ");
    Liste = head;
    while(Liste != NULL){
        printf("%d -> ", Liste->val);
        Liste = Liste->suiv;
    }
    printf("NULL\n");
    
    return 0;
}