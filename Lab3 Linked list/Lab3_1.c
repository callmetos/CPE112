//66070503413 Channathat Ueannapaphon
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void insertAtBeginning(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtEnd(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct Node* last = list->head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {

    int n, option;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid\n");
        return 0;
    }
    scanf("%d", &option);

    if (option != 1 && option != 2) {
        printf("Invalid\n");
        return 0;
    }

    struct LinkedList linkedList;
    linkedList.head = NULL;

    int value;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (option == 1) {
            insertAtBeginning(&linkedList, value);
        } else if (option == 2) {
            insertAtEnd(&linkedList, value);
        }
    }

    display(&linkedList);

    struct Node* current = linkedList.head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

