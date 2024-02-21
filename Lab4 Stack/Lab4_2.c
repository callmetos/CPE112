//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void init(Stack* stack) {
    stack->top = NULL;
}

bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("empty\n");
        return;
    }
    Node* temp = stack->top;
    printf("%d\n", temp->data);
    stack->top = temp->next;
    free(temp);
}

void top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("empty\n");
        return;
    }
    printf("%d\n", stack->top->data);
}

void empty(Stack* stack) {
    printf("%d\n", isEmpty(stack) ? 1 : 0);
}

int main() {
    Stack stack;
    init(&stack);
    char command;
    int value;

    while (1) {
        scanf(" %c", &command);
        if (command == 'q')
            break;
        switch (command) {
            case 'p':
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 'o':
                pop(&stack);
                break;
            case 't':
                top(&stack);
                break;
            case 'e':
                empty(&stack);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}

