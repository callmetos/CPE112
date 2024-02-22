// Problem 1: Set 
//66070503413 Channathat Ueanapaphon

#include <stdio.h>
#include <stdlib.h>

struct sortedset
{
    int *elements;
    int size;
    int capacity;
};

void init(struct sortedset *s, int initial_capacity)
{
    s->size = 0;
    s->capacity = initial_capacity;
    s->elements = (int *)malloc(sizeof(int) * initial_capacity);
    if (s->elements == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void checkAndResize(struct sortedset *s)
{
    if (s->size >= s->capacity)
    {
        s->capacity *= 2;
        s->elements = (int *)realloc(s->elements, sizeof(int) * s->capacity);
        if (s->elements == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
}

int checkDuplicate(struct sortedset *s, int target)
{
    for (int i = 0; i < s->size; i++)
    {
        if (s->elements[i] == target)
        {
            return 1;
        }
    }
    return 0;
}

void insertElement(struct sortedset *s, int newNum)
{
    if (!checkDuplicate(s, newNum))
    {
        checkAndResize(s);
        s->elements[s->size++] = newNum;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(struct sortedset *s)
{
    insertionSort(s->elements, s->size);
    printf("%d\n", s->size);
    printf("{");
    for (int i = 0; i < s->size; i++)
    {
        printf("%d", s->elements[i]);
        if (i != s->size - 1)
            printf(", ");
    }
    printf("}\n");
}

void freeSortedSet(struct sortedset *s)
{
    free(s->elements);
}

int main()
{
    struct sortedset s;
    int n, i;
    scanf("%d", &n);
    init(&s, n); 
    for (i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        insertElement(&s, num);
    }
    printArray(&s);
    freeSortedSet(&s); 
    return 0;
}
