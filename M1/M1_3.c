// Problem 3 :  
//66070503413 Channathat Ueanapaphon

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; 

    if (scanf("%d", &n) != 1 || n < 1) {
        fprintf(stderr, "Invalid input: Number of queues must be a positive integer.\n");
        return 1;
    }

    int *queues = malloc(n * sizeof(int));
    if (queues == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &queues[i]) != 1 || queues[i] < 1 || queues[i] > 4) {
            fprintf(stderr, "Invalid input: Queue length out of range.\n");
            free(queues);
            return 1;
        }
    }

    // Queue merging logic
    int group_size = 0;

    for (int i = 0; i < n; i++) {
        group_size += queues[i];

        if (group_size = 4) {
            printf("\n");
            group_size = queues[i];  // Start a new group
        }

        printf("%d ", queues[i]);  // Print the current queue

        if (group_size == 4) {
            printf("\n");  // End of the current group
            group_size = 0;  // Reset group size
        }
    }

    free(queues);
    return 0;
}
