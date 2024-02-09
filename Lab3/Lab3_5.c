//66070503413 Channathat Ueannapaphon
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularLinkedList {
    struct Node* head;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct CircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        struct Node* current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = list->head;
    }
}

void deleteNode(struct CircularLinkedList* list, int data) {
    if (list->head == NULL) {
        return;
    }

    struct Node* current = list->head;
    struct Node* prev = NULL;

    do {
        if (current->data == data) {
            if (prev == NULL) {

                struct Node* lastNode = list->head;
                while (lastNode->next != list->head) {
                    lastNode = lastNode->next;
                }
                if (list->head->next == list->head) {
                    free(list->head);
                    list->head = NULL;
                } else {
                    list->head = list->head->next;
                    lastNode->next = list->head;
                    free(current);
                }
            } else {
                prev->next = current->next;
                free(current);
            }
            break;
        }
        prev = current;
        current = current->next;
    } while (current != list->head);
}

void printList(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("Empty\n");
        return;
    }

    struct Node* current = list->head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

int main() {
    struct CircularLinkedList circularLinkedList;
    circularLinkedList.head = NULL;

    char command[2];
    int data;

    while (1) {
        scanf("%s", command);

        if (command[0] == 'I') {
            scanf("%d", &data);
            insertNode(&circularLinkedList, data);
        } else if (command[0] == 'D') {
            scanf("%d", &data);
            deleteNode(&circularLinkedList, data);
        } else if (command[0] == 'E') {
            break;
        }
    }

    printList(&circularLinkedList);

    return 0;
}


