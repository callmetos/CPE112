#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5 

int item[MAX_SIZE];
int front = -1, rear = -1; 

void enQueue(int data) {
    if ((rear + 1) % MAX_SIZE == front) { // Check if the circular queue is full
        printf("Queue is full\n");
    } else {
        if (front == -1) { 
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE; 
        item[rear] = data; 
        printf("Inserted data\n");
    }
}

int deQueue() {
    int deletedData;
    if (front == -1) { // If the queue is empty
        printf("Queue is empty\n");
        return -1; 
    } else {
        deletedData = item[front];  
        printf("Deleted %d\n", deletedData);
        if (front == rear) { 
            front = -1; 
        } else {
            front = (front + 1) % MAX_SIZE; 
        }
        return deletedData; 
    }
}

void displayQueue() {
    if (front == -1) { // If the queue is empty
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        do {
            printf("%d ", item[i]); 
            i = (i + 1) % MAX_SIZE; 
        } while (i != (rear + 1) % MAX_SIZE); 
        printf("\n");
    }
}

int main() { 
    
    char option[10];
    int data;
    while (1){
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