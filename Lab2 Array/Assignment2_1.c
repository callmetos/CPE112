//Channathat Ueanapaphon 66070503413
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 100

struct Student {
    char name[100];
    float score;
};

float calculateMean(struct Student students[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += students[i].score;
    }
    return sum / size;
}

float calculateSD(struct Student students[], int size, float mean) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(students[i].score - mean, 2);
    }
    return sqrt(sum / size);
}

int main() {
    int size;
    scanf("%d", &size);

    struct Student students[MAX_SIZE];

    for (int i = 0; i < size; i++) {
        scanf("%s %f", students[i].name, &students[i].score);
    }

    float mean = calculateMean(students, size);
    float sd = calculateSD(students, size, mean);

    printf("%.2f %.2f", mean, sd);

    // Find student with highest and lowest scores
    float maxScore = -1, minScore = 101;
    char maxName[100], minName[100];

    for (int i = 0; i < size; i++) {
        if (students[i].score > maxScore) {
            maxScore = students[i].score;
            strcpy(maxName, students[i].name);
        }

        if (students[i].score < minScore) {
            minScore = students[i].score;
            strcpy(minName, students[i].name);
        }
    }

    printf(" %s %s\n", maxName, minName);

    return 0;
}
