//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *array;
    int top;
    unsigned capacity;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return -1; 
}

char* infixToPostfix(char* infix) {
    int len = strlen(infix);
    char* postfix = (char*)malloc((len + 1) * sizeof(char));
    Stack* stack = createStack(len);
    int k = 0; 
    
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (isalpha(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
                return NULL; 
            else
                pop(stack); 
        } else if (isOperator(ch)) {
            while (!isEmpty(stack) && precedence(ch) <= precedence(peek(stack))) {
                postfix[k++] = pop(stack);
            }
            push(stack, ch);
        }
    }

    while (!isEmpty(stack)) {
        if (peek(stack) == '(')
            return NULL; 
        postfix[k++] = pop(stack);
    }
    
    postfix[k] = '\0'; 
    return postfix;
}

int main() {
    char infix[1000];
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; 
    
    char* postfix = infixToPostfix(infix);
    if (postfix) {
        printf("%s\n", postfix);
        free(postfix);
    } else {
        printf("Invalid infix expression\n");
    }

    return 0;
}
