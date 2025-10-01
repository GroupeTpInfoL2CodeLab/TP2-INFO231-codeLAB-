#include<stdio.h>
#include<stdlib.h>

typedef struct Cellule {
    int info;
    struct Cellule* precedent;
    struct Cellule* suivant;
} Cellule;

Cellule* inserer(Cellule* tête, int info, int croissant) {
    Cellule* nouveau = (Cellule*) malloc(sizeof(Cellule));
    nouveau->info = info;
    nouveau->precedent = nouveau->suivant = NULL;
    
    if (croissant) {
        if(tête == NULL || info <= tête->info) {
            if(tête != NULL) {
                nouveau->suivant = tête;
                tête->precedent = nouveau;
            }
            return nouveau;
        }
        
        Cellule* current = tête; 
        while(current->suivant != NULL && current->suivant->info < info) {
            current = current->suivant;
        }
        
        nouveau->suivant = current->suivant;
        nouveau->precedent = current;
        
        if(current->suivant != NULL) {
            current->suivant->precedent = nouveau;
        }
        current->suivant = nouveau;
    }
    
    else {
        if(tête == NULL || info >= tête->info) {
            if(tête != NULL) {
                nouveau->suivant = tête;
                tête->precedent = nouveau;
            }
            return nouveau;
        }
        
        Cellule* current = tête; 
        while(current->suivant != NULL && current->suivant->info > info) {
            current = current->suivant;
        }
        
        nouveau->suivant = current->suivant;
        nouveau->precedent = current;
        
        if(current->suivant != NULL) {
            current->suivant->precedent = nouveau;
        }
        current->suivant = nouveau;
    }
    
    return tête;
}

int main() {
    Cellule* tête = NULL;
    int n, valeur, ordre;
    
    printf("Choisir l'ordre (1=Croissant, 0=Décroissant): ");
    scanf("%d", &ordre);
    
    printf("Nombre d'éléments à insérer: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        printf("Valeur %d: ", i+1);
        scanf("%d", &valeur);
        tête = inserer(tête, valeur, ordre);
    }
    
    
    Cellule* current = tête;
    printf("Liste triée: ");
    while(current != NULL) {
        printf("%d ", current->info);
        current = current->suivant;
    }
    printf("\n");
    
    
    printf("Nouvelle valeur à insérer: ");
    scanf("%d", &valeur);
    tête = inserer(tête, valeur, ordre);
    current = tête;
    printf("Liste après insertion: ");
    while(current != NULL) {
        printf("%d ", current->info);
        current = current->suivant;
    }
    
    return 0;
}