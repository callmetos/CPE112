//Channathat Ueanapaphon 66070503413
#include <stdio.h>

void findLargestSmallest(int n) {
    int largest = -2147483648;
    int smallest = 2147483647;
    int largestIndex = -1;
    int smallestIndex = -1;
    int num;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);

        if (num > largest) {
            largest = num;
            largestIndex = i;
        }
        if (num < smallest) {
            smallest = num;
            smallestIndex = i;
        }
    }
    printf("%d %d\n", largest, largestIndex);
    printf("%d %d\n", smallest, smallestIndex);
}

int main() {

    int n;
    scanf("%d", &n);

    findLargestSmallest(n);

    return 0;
}

