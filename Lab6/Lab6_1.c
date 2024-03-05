//Channathat Ueanapaphon 66070503413

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode
{
    int *value;
    int size;
};

void init(struct TreeNode *arr, int size)
{
    arr->value = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr->value[i] = -999;
    }
    arr->size = size;
    return;
}

void CreateR(struct TreeNode *arr)
{
    int val;
    scanf("%d", &val);
    if (arr->value[0] != -999)
    {
        printf("cannot create duplicated root\n");
        return;
    }
    arr->value[0] = val;
    return;
}

void InsertLeft(struct TreeNode *arr)
{
    int root, val, location = -1;

    scanf("%d %d", &root, &val);

    for (int i = 0; i < arr->size; i++)
    {
        if (arr->value[i] == root)
        {
            location = i;
            break;
        }
    }
    if (location == -1)
    {
        printf("not found\n");
        return;
    }

    int new_val = ((location + 1) * 2) - 1;
    if (new_val >= arr->size)
    {
        printf("overflow\n");
        return;
    }
    else if (arr->value[new_val] != -999)
    {
        printf("node already presented\n");
        return;
    }
    arr->value[new_val] = val;
}

void InsertRight(struct TreeNode *arr)
{
    int root, val, location = -1;

    scanf("%d %d", &root, &val);

    for (int i = 0; i < arr->size; i++)
    {
        if (arr->value[i] == root)
        {
            location = i;
            break;
        }
    }
    if (location == -1)
    {
        printf("not found\n");
        return;
    }

    int new_val = ((location + 1) * 2);
    if (new_val >= arr->size)
    {
        printf("overflow\n");
        return;
    }
    else if (arr->value[new_val] != -999)
    {
        printf("node already presented\n");
        return;
    }
    arr->value[new_val] = val;
}

void END(struct TreeNode *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->value[i] == -999)
        {
            printf("null ");
        }
        else
        {
            printf("%d ", arr->value[i]);
        }
    }
    free(arr->value);
    return;
}

int main()
{
    int size;
    scanf("%d", &size);
    struct TreeNode *arr;
    init(arr, size);
    char command[4];
    scanf("%s", command);
    while (strcmp(command, "END") != 0)
    {
        if (strcmp(command, "ROOT") == 0)
        {
            CreateR(arr);
        }
        else if (strcmp(command, "INSL") == 0)
        {
            InsertLeft(arr);
        }
        else if (strcmp(command, "INSR") == 0)
        {
            InsertRight(arr);
        }
        scanf("%s", command);
    }
    END(arr);
    return 0;
}