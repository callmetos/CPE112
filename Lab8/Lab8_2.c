//Channathat Ueanapaphon 66070503413
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapify_up(parent);
    }
}

void insert(int value) {
    if (size < MAX_SIZE) {
        heap[size++] = value;
        heapify_up(size - 1);
    } else {
        printf("Heap is full. Cannot insert more elements.\n");
    }
}

void heapify_down(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapify_down(largest);
    }
}

void delete(int value) {
    int i;
    for (i = 0; i < size; i++) {
        if (heap[i] == value) {
            heap[i] = heap[size - 1];
            size--;
            heapify_down(i);
            return;
        }
    }
    printf("Element not found in the heap.\n");
}

void print_heap() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    char operation[10];
    int value;

    while (1) {
        scanf("%s", operation);

        if (strcmp(operation, "INSERT") == 0) {
            while (scanf("%d", &value) == 1) {
                insert(value);
            }
        } else if (strcmp(operation, "DELETE") == 0) {
            while (scanf("%d", &value) == 1) {
                delete(value);
            }
        } else if (strcmp(operation, "PRINT") == 0) {
            print_heap();
        } else if (strcmp(operation, "EXIT") == 0) {
            break;
        } else {
            printf("Invalid operation. Please enter INSERT, DELETE, PRINT, or EXIT.\n");
        }
    }

    return 0;
}
