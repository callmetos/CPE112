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

char* transform_secret_code(const char *input_text) {
    char *result_text = (char *)malloc(strlen(input_text) + 1);
    if (result_text == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    PriorityQueue queue = {{0}, 0};
    
    for (int i = 0; input_text[i] != '\0'; i++) {
        int priority;
        if (tolower(input_text[i]) == 'a' || tolower(input_text[i]) == 'e' || 
            tolower(input_text[i]) == 'i' || tolower(input_text[i]) == 'o' || 
            tolower(input_text[i]) == 'u') {
            priority = 3;
        } else if (isalpha(input_text[i])) {
            priority = 1;
        } else {
            priority = 2;
        }
        enqueue(&queue, input_text[i], priority);
    }

    int result_index = 0;
    while (queue.size > 0) {
        CharPriority item = dequeue(&queue);
        result_text[result_index++] = item.character;
    }
    result_text[result_index] = '\0';
    return result_text;
}

int main() {
    char *input_text = (char *)malloc(MAX_TEXT_LENGTH * sizeof(char));
    if (input_text == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fgets(input_text, MAX_TEXT_LENGTH, stdin);

    input_text[strcspn(input_text, "\n")] = '\0';

    if (strlen(input_text) == 0) {
        printf("Input text is empty.\n");
        free(input_text);
        return 1;
    }

    char *transformed_text = transform_secret_code(input_text);
    if (transformed_text != NULL) {
        printf("%s\n", transformed_text);
        free(transformed_text);
    }
    
    free(input_text);
    return 0;
}
