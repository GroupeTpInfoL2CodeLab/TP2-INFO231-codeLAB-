#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Création d'un nouveau nœud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insertion en tête avec message
void insertHead(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        printf("Insertion en tête : %d (liste était vide)\n", value);
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        printf("Insertion en tête : %d\n", value);
    }
}

// Insertion en queue avec message
void insertTail(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        printf("Insertion en queue : %d (liste était vide)\n", value);
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {  // aller jusqu’à la fin
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        printf("Insertion en queue : %d\n", value);
    }
}

// Affichage de la liste du début à la fin
void printList(Node* head) {
    Node* temp = head;
    printf("État actuel de la liste : ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Programme principal
int main() {
    Node* head = NULL;
    int choix, valeur;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à insérer en tête : ");
                scanf("%d", &valeur);
                insertHead(&head, valeur);
                printList(head);
                break;
            case 2:
                printf("Entrez la valeur à insérer en queue : ");
                scanf("%d", &valeur);
                insertTail(&head, valeur);
                printList(head);
                break;
            case 3:
                printList(head);
                break;
            case 0:
                printf("Programme terminé.\n");
                break;
            default:
                printf("Choix invalide, réessayez.\n");
        }

    } while (choix != 0);

    return 0;
}