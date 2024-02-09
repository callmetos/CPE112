//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int is_balanced(char *str) {
    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
            case '(':
            case '{':
            case '[':
                stack[++top] = str[i];
                break;
            case ')':
                if (top == -1 || stack[top--] != '(') {
                    return 0;
                }
                break;
            case '}':
                if (top == -1 || stack[top--] != '{') {
                    return 0;
                }
                break;
            case ']':
                if (top == -1 || stack[top--] != '[') {
                    return 0;
                }
                break;
        }
    }
    return top == -1;
}

int main() {
    char str[MAX_SIZE + 1];

    scanf("%s", str);

    if (is_balanced(str)) {
        printf("The string is balanced\n");
    } else {
        printf("The string is not balanced\n");
    }

    return 0;
}
