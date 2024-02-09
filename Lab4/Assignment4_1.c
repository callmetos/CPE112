//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100 

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = item;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

void decimalToBaseX(int decimal, int base) {
    Stack s;
    initStack(&s);

    
    if (decimal < 0 || base < 2 || base > 36) {
        printf("invalid\n");
        return;
    }

    
    do {
        int remainder = decimal % base;
        char digit;

        
        if (remainder >= 10) {
            digit = 'A' + (remainder - 10);
        } else {
            digit = '0' + remainder;
        }

        push(&s, digit);  
        decimal /= base;
    } while (decimal != 0);

    
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");
}

int main() {
    int decimal, base;

    scanf("%d", &decimal);
    scanf("%d", &base);

    decimalToBaseX(decimal, base);

    return 0;
}
