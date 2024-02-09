//Channathat Ueanapaphon 66070503413
#include<stdio.h>
#include<stdlib.h>

typedef struct slicing {
    int start;
    int stop;
    int step;
} LS;

void position_set(LS* POS, int n) {
    if (POS->start < n * -1) {
        POS->start = 0;
    } else if (POS->start < 0) {
        POS->start += n;
    } else if (POS->start > n) {
        POS->start = n - 1;
    }

    if (POS->stop < n * -1) {
        POS->stop = 0;
    } else if (POS->stop < 0) {
        POS->stop += n;
    } else if (POS->stop > n) {
        POS->stop = n;
    }
}

void print_list(int* list, LS SSS, int n) {
    if (SSS.start >= n && SSS.stop >= n) {
        printf("empty");
        return;
    }
    if (SSS.start <= n * -1 && SSS.stop <= n * -1) {
        printf("empty");
        return;
    } else {
        position_set(&SSS, n);
        int printcount = 0;
        if (SSS.step > 0) {
            if (SSS.start < SSS.stop) {
                for (int i = SSS.start; i < n && i < SSS.stop; i += SSS.step) {
                    printf("%d ", *(list + i));
                    printcount++;
                }
            } else {
                printcount = 0;
            }
        } else {
            if (SSS.start > SSS.stop) {
                for (int i = SSS.start; i > -1 && i > SSS.stop; i += SSS.step) {
                    printf("%d ", *(list + i));
                    printcount++;
                }
            } else {
                printcount = 0;
            }
        }
        if (printcount == 0) {
            printf("empty");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* list = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", list + i);
    }
    LS SSS;
    scanf("%d", &SSS.start);
    scanf("%d", &SSS.stop);
    scanf("%d", &SSS.step);
    print_list(list, SSS, n);
    free(list);
}
