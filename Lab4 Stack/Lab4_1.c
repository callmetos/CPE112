//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int max_size;
} Stack;

void init(Stack *stack, int size) {
    stack->arr = (int *)malloc(size * sizeof(int));
    if (stack->arr == NULL) {
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->max_size = size;
}

bool isFull(Stack *stack) {
    return stack->top == stack->max_size - 1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow.\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

void pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        exit(EXIT_FAILURE);
    }
    stack->top--;
}

void show(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = stack->top; i >= 0; i--) {
      printf("%d\n", stack->arr[i]);
    }
}

int main() {
    int size, choice, value;
    scanf("%d", &size);
    if (size <= 0) {
        printf("Please enter a positive number.\n");
        exit(EXIT_FAILURE);
    }
    Stack stack;
    init(&stack, size);
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (scanf("%d", &value) != 1) {
                    printf("Invalid choice.\n");
                    exit(EXIT_FAILURE);
                }
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                show(&stack);
                exit(EXIT_SUCCESS);
            case 4:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice.\n");
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}
