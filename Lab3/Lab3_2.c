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

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(struct LinkedList* list, int key, int newData) {
    struct Node* new_node = createNode(newData);
    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    struct Node* current = list->head;
    while (current) {
        if (current->data == key) {
            new_node->next = current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    }
}

void insertBefore(struct LinkedList* list, int key, int newData) {
    struct Node* new_node = createNode(newData);

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    if (list->head->data == key) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }

    struct Node* current = list->head;
    while (current->next) {
        if (current->next->data == key) {
            new_node->next = current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    }
}

void printList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList linkedList;
    linkedList.head = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        struct Node* node = createNode(element);
        if (linkedList.head == NULL) {
            linkedList.head = node;
        } else {
            struct Node* current = linkedList.head;
            while (current->next) {
                current = current->next;
            }
            current->next = node;
        }
    }

    char command;
    int key, newData;
    while (1) {
        scanf(" %c", &command);
        if (command == 'A') {
            scanf("%d %d", &key, &newData);
            insertAfter(&linkedList, key, newData);
        } else if (command == 'B') {
            scanf("%d %d", &key, &newData);
            insertBefore(&linkedList, key, newData);
        } else if (command == 'E') {
            printList(&linkedList);
            break;
        }
    }

    return 0;
}


