#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Función para dividir la lista en dos partes
void split(struct Node* source, struct Node** front, struct Node** back) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    // Avanza rápido dos nodos y lento un nodo
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Slow está en el medio, divide la lista en dos partes
    *front = source;
    *back = slow->next;
    slow->next->prev = NULL;
    slow->next = NULL;
}

// Función para combinar dos listas ordenadas
struct Node* merge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    // Comparar nodos y fusionar recursivamente
    if (a->data < b->data) {
        a->next = merge(a->next, b);
        a->next->prev = a;
        a->prev = NULL;
        return a;
    } else {
        b->next = merge(a, b->next);
        b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}

// Función principal de Merge Sort para listas doblemente enlazadas
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    // Caso base: lista vacía o con un solo nodo
    if (head == NULL || head->next == NULL) {
        return;
    }

    // Dividir la lista en dos partes
    split(head, &a, &b);

    // Recursivamente ordenar las dos partes
    mergeSort(&a);
    mergeSort(&b);

    // Combinar las dos partes ordenadas
    *headRef = merge(a, b);
}

// Función para insertar un nuevo nodo al final de la lista
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Función para imprimir la lista
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Función principal
int main() {
    struct Node* head = NULL;

    // Insertar elementos en la lista
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 7);

    printf("Lista original:\n");
    printList(head);

    // Aplicar Merge Sort a la lista
    mergeSort(&head);

    printf("Lista ordenada:\n");
    printList(head);

    return 0;
}
