//66070503413 Channathat Ueannapaphon
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct DoublyLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

void deleteNode(struct DoublyLinkedList* list, int data) {
    if (list->head == NULL) {
        return;
    }

    struct Node* current = list->head;
    while (current && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        return; // Node not found
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    free(current);
}

void searchNodes(struct DoublyLinkedList* list, int data) {
    if (list->head == NULL) {
        printf("none\n");
        return;
    }

    struct Node* current = list->head;
    while (current && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("none\n");
    } else {
        if (current->prev) {
            printf("%d ", current->prev->data);
        } else {
            printf("NULL ");
        }

        if (current->next) {
            printf("%d\n", current->next->data);
        } else {
            printf("NULL\n");
        }
    }
}

void printForward(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    int countfor = 0 ;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
        countfor ++ ;
    }
     if(countfor == 0){
        printf("none");
    }
    printf("\n");
}

void printBackward(struct DoublyLinkedList* list) {
    struct Node* current = list->tail;
    int countback = 0 ;
    while (current) {
        printf("%d ", current->data);
        current = current->prev;
        countback ++ ;
    }
     if(countback == 0){
        printf("none");
    }
    printf("\n");
}

int main() {
    struct DoublyLinkedList doublyLinkedList;
    doublyLinkedList.head = NULL;
    doublyLinkedList.tail = NULL;

    char command[4];
    int data;

    while (1) {
        scanf("%s", command);

        if (command[0] == 'A') {
            scanf("%d", &data);
            addNode(&doublyLinkedList, data);
        } else if (command[0] == 'D') {
            scanf("%d", &data);
            deleteNode(&doublyLinkedList, data);
        } else if (command[0] == 'S') {
            scanf("%d", &data);
            searchNodes(&doublyLinkedList, data);
        } else if (command[0] == 'E') {
            break;
        }
    }

    printForward(&doublyLinkedList);
    printBackward(&doublyLinkedList);

    return 0;
}
