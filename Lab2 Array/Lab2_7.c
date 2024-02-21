//Channathat Ueanapaphon 66070503413
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_LENGTH 100


struct Dictionary {
    char keys[MAX_SIZE][MAX_LENGTH];
    char values[MAX_SIZE][MAX_LENGTH];
    int size;
};

void insert(struct Dictionary *dict, char key[MAX_LENGTH], char value[MAX_LENGTH]) {
    if (dict->size < MAX_SIZE) {
        strcpy(dict->keys[dict->size], key);
        strcpy(dict->values[dict->size], value);
        dict->size++;
    }
}

void edit(struct Dictionary *dict, char key[MAX_LENGTH], char newValue[MAX_LENGTH]) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->keys[i], key) == 0) {
            if (strcmp(dict->values[i], newValue) != 0) {
                strcpy(dict->values[i], newValue);
                return;
            }
        }
    }
    printf("No change\n");
}

void printDictionary(struct Dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        printf("%s : %s\n", dict->keys[i], dict->values[i]);
    }
}

int main() {
    struct Dictionary dict;
    dict.size = 0;

    int size;
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        char key[MAX_LENGTH];
        char value[MAX_LENGTH];
        scanf("%s %s", key, value);
        insert(&dict, key, value);
    }

    char editKey[MAX_LENGTH];
    char editValue[MAX_LENGTH];
    scanf("%s %s", editKey, editValue);

    edit(&dict, editKey, editValue);
    printDictionary(&dict);

    return 0;
}

