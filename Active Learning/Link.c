#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enQueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("Inserted data\n");
}

int deQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int deletedData = front->data;
    struct Node* temp = front;
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    
    free(temp);
    printf("Deleted %d\n", deletedData);
    return deletedData;
}

void displayQueue() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    char option[10];
    int data;
    while (1) {
        printf("Commands:\n\tadd: Add an element to the queue\n\tdelete: Remove an element from the queue\n\tshow: Display the queue elements\n\texit: Exit the program\n");
        printf("Enter command: ");
        scanf("%s", option);
        if (strcmp(option, "add") == 0) {
            printf("Enter data to add: ");
            scanf("%d", &data);
            enQueue(data);
        } else if (strcmp(option, "delete") == 0) {
            deQueue();
        } else if (strcmp(option, "show") == 0) {
            displayQueue();
        } else if (strcmp(option, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}
