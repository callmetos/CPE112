//Channathat Ueanapaphon 66070503413
#include <stdio.h>

int contains(int element, int array[], int count) {
    for (int i = 0; i < count; i++) {
        if (element == array[i]) {
            return 1;
        }
    }
    return 0;
}

void printSet(int set[], int count) {
    if (count == 0) {
        printf("empty");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", set[i]);
        }
    }
    printf("\n");
}

void printOutput(int m, int n, int a[], int cntA, int b[], int cntB) {

    printSet(a, cntA);
    printSet(b, cntB);

    // union
    int un[cntA + cntB];
    int cntU = 0;
    for (int i = 0; i < cntA; i++) {
        un[cntU++] = a[i];
    }
    for (int i = 0; i < cntB; i++) {
        if (!contains(b[i], un, cntU)) {
            un[cntU++] = b[i];
        }
    }

    for (int i = 0; i < cntU - 1; i++) {
        for (int j = i + 1; j < cntU; j++) {
            if (un[i] > un[j]) {
                int temp = un[i];
                un[i] = un[j];
                un[j] = temp;
            }
        }
    }

    printSet(un, cntU);

    //Insec
    int inter[cntA < cntB ? cntA : cntB];
    int cntIn = 0;
    for (int i = 0; i < cntA; i++) {
        if (contains(a[i], b, cntB)) {
            inter[cntIn++] = a[i];
        }
    }
    printSet(inter, cntIn);

    // diff

    int difA[cntA];
    int cntDifA = 0;
    for (int i = 0; i < cntA; i++) {
        if (!contains(a[i], b, cntB)) {
            difA[cntDifA++] = a[i];
        }
    }
    printSet(difA, cntDifA);

    // diff

    int difB[cntB];
    int cntDifB = 0;
    for (int i = 0; i < cntB; i++) {
        if (!contains(b[i], a, cntA)) {
            difB[cntDifB++] = b[i];
        }
    }
    printSet(difB, cntDifB);

    // comA

    for (int i = m; i <= n; i++) {
        if (!contains(i, a, cntA)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // comB

    for (int i = m; i <= n; i++) {
        if (!contains(i, b, cntB)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int p, q;
    scanf("%d", &p);
    int a[p];
    int cntA = 0;
    for (int i = 0; i < p; i++) {
        int t;
        scanf("%d", &t);
        if (!contains(t, a, cntA) && t >= m && t <= n) {
            a[cntA++] = t;
        }
    }

    scanf("%d", &q);
    int b[q];
    int cntB = 0;
    for (int i = 0; i < q; i++) {
        int tt;
        scanf("%d", &tt);
        if (!contains(tt, b, cntB) && tt >= m && tt <= n) {
            b[cntB++] = tt;
        }
    }

    printOutput(m, n, a, cntA, b, cntB);

    return 0;
}
