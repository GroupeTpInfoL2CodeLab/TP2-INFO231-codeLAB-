#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node *next;
} Node;

// Création d'un nouveau nœud
Node* createNode(char *value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, value);
    newNode->next = NULL;
    return newNode;
}

// Insertion en fin de liste
void insertEnd(Node **head, char *value) {
    Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Affichage de la liste
void displayList(Node *head) {
    if (!head) {
        printf("Liste vide.\n");
        return;
    }
    Node *temp = head;
    while (temp) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Suppression de toutes les occurrences d'une valeur
void deleteOccurrences(Node **head, char *value) {
    Node *temp = *head, *prev = NULL;

    while (temp) {
        if (strcmp(temp->data, value) == 0) {
            if (prev == NULL) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Libération mémoire
void freeList(Node *head) {
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    char input[50];
    int choix;

    printf("=== Lecture des elements (tapez * pour arreter) ===\n");
    while (1) {
        printf("Entrer un element: ");
        scanf("%s", input);
        if (strcmp(input, "*") == 0)
            break;
        insertEnd(&head, input);
    }

    do {
        printf("\n=== MENU ===\n");
        printf("1. Afficher la liste\n");
        printf("2. Supprimer toutes les occurrences d'un element\n");
        printf("3. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Entrer l'element a supprimer: ");
                scanf("%s", input);
                deleteOccurrences(&head, input);
                printf("Liste apres suppression:\n");
                displayList(head);
                break;
            case 3:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 3);

    freeList(head);
    return 0;
}