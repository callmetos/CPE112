//66070503413 Channathat Ueanapaphon
#include <stdio.h>

void swap(int n, char source, char auxiliary, char destination, int *steps) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        (*steps)++;
        return;
    }
    swap(n - 1, source, destination, auxiliary, steps);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    (*steps)++;
    swap(n - 1, auxiliary, source, destination, steps);
}

int main() {
    int n, steps = 0;
    scanf("%d", &n);
    swap(n, 'A', 'B', 'C', &steps);
    printf("Total moves: %d\n", steps);
    return 0;
}
