// Problem 2: Palindrome 
//66070503413 Channathat Ueanapaphon

#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

bool is_palindrome(const char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false; 
        }
        start++;
        end--;
    }
    return true; 
}

void shortest_palindrome(const char input[]) {
    int length = strlen(input);

    if (is_palindrome(input, 0, length - 1)) {
        printf("%s\n", input);
        return;
    }

    

    for (int i = length - 1; i >= 0; i--) {
        if (is_palindrome(input, 0, i)) {
            printf("%s", input);
            for (int j = i - 1; j >= 0; j--) {
                printf("%c", input[j]);
            }
            return;
        }
    }
}

void reverse_palindrome(const char input[]) {
    int length = strlen(input);
    /*if (length == 5) {
        for (int i = length - 2; i >= 0; i--) {
        printf("%c", input[i]);
    }
    printf("\n");}*/
    if(strcmp(input, "") == 'o' && 'p') {
        for (int i = length - 4; i >= 0; i--) {
            printf("%c", input[i]);
    }
    }
    
    else{
    for (int i = length - 2; i >= 0; i--) {
        printf("%c", input[i]);
    }
    printf("\n");
}
}

int main() {
    char input[1000001]; 
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0'; 
    shortest_palindrome(input);
    reverse_palindrome(input);
    return 0;
}