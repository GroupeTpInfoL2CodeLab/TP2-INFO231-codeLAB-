#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int valeur;
    struct cellule *suivant;
} cellule, *liste;

// Insertion en tête
liste AjoutTete(int val, liste l) {
    liste l1 = (liste)malloc(sizeof(cellule));
    l1->valeur = val;

    if (l == NULL) {
        l1->suivant = l1;
        return l1;
    } else {
        liste l2 = l;
        while (l2->suivant != l) {
            l2 = l2->suivant;
        }
        l1->suivant = l;
        l2->suivant = l1;
        return l1;
    }
}

// Affichage
void AfficherListe(liste l) {
    if (l == NULL) {
        printf("Liste vide.\n");
        return;
    }
    liste temp = l;
    do {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    } while (temp != l);
    printf("HEAD\n");
}

int main() {
    liste maListe = NULL;

    maListe = AjoutTete(30, maListe);
    maListe = AjoutTete(20, maListe);
    maListe = AjoutTete(10, maListe);

    AfficherListe(maListe);

    return 0;
}



