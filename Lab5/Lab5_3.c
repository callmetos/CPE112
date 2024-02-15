//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 1000

typedef struct {
    char character;
    int priority;
} CharPriority;

typedef struct {
    CharPriority data[MAX_TEXT_LENGTH];
    int size;
} PriorityQueue;

void enqueue(PriorityQueue *queue, char character, int priority) {
    if (queue->size >= MAX_TEXT_LENGTH) {
        printf("Queue is full. Cannot enqueue more elements.\n");
        return;
    }
    queue->data[queue->size].character = character;
    queue->data[queue->size].priority = priority;
    queue->size++;
}

CharPriority dequeue(PriorityQueue *queue) {
    if (queue->size <= 0) {
        printf("Queue is empty. Cannot dequeue.\n");
        CharPriority emptyCharPriority = {'\0', 0};
        return emptyCharPriority;
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->data[i].priority > queue->data[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }

    CharPriority result = queue->data[highestPriorityIndex];

    for (int i = highestPriorityIndex; i < queue->size - 1; i++) {
        queue->data[i] = queue->data[i + 1];
    }
    queue->size--;

    return result;
}

char* transform_secret_code(const char *text) {
    char *result = (char *)malloc(strlen(text) + 1);
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    PriorityQueue queue = {{0}, 0};
    
    for (int i = 0; text[i] != '\0'; i++) {
        int priority;
        if (tolower(text[i]) == 'a' || tolower(text[i]) == 'e' || 
            tolower(text[i]) == 'i' || tolower(text[i]) == 'o' || 
            tolower(text[i]) == 'u') {
            priority = 3;
        } else if (isalpha(text[i])) {
            priority = 1;
        } else {
            priority = 2;
        }
        enqueue(&queue, text[i], priority);
    }

    int resultIndex = 0;
    while (queue.size > 0) {
        CharPriority item = dequeue(&queue);
        result[resultIndex++] = item.character;
    }
    result[resultIndex] = '\0';
    return result;
}

int main() {
    char text[MAX_TEXT_LENGTH];

    fgets(text, MAX_TEXT_LENGTH, stdin);

    char *transformed_text = transform_secret_code(text);
    if (transformed_text != NULL) {
        printf("%s\n", transformed_text);
        free(transformed_text);
    }

    return 0;
}
