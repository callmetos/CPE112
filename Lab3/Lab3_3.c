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

void insertNode(struct LinkedList* list, int data) {
    struct Node* node = createNode(data);
    if (list->head == NULL) {
        list->head = node;
    } else {
        struct Node* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }
}

void deleteFirstNode(struct LinkedList* list) {
    if (list->head == NULL) {
        return;
    }

    struct Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void deleteLastNode(struct LinkedList* list) {
    if (list->head == NULL) {
        return;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    struct Node* current = list->head;
    while (current->next->next) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void deleteNodeByValue(struct LinkedList* list, int value) {
    if (list->head == NULL) {
        return;
    }

    if (list->head->data == value) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    struct Node* current = list->head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (current->next) {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

void printList(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("none\n");
        return;
    }

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
        insertNode(&linkedList, element);
    }

    char command;
    while (1) {
        scanf(" %c", &command);
        if (command == 'F') {
            deleteFirstNode(&linkedList);
        } else if (command == 'L') {
            deleteLastNode(&linkedList);
        } else if (command == 'N') {
            int value;
            scanf("%d", &value);
            deleteNodeByValue(&linkedList, value);
        } else if (command == 'E') {
            printList(&linkedList);
            break;
        }
    }

    return 0;
}


