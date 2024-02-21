//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *word) {
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
       word[i] = tolower(word[i]);
    }

    int start = 0;
    int end = len - 1;
    while (start < end) {

        if (!isalnum(word[start])) {
            start++;
            continue;
        }
        if (!isalnum(word[end])) {
            end--;
            continue;
        }

        if (word[start] != word[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char word[100];

    scanf("%s", word);

    if (is_palindrome(word)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

