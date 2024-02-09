//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void stepDeleteLastOne(node** start, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;

    if (*start == NULL) {
        *start = newnode;
    } else {
        node* temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int main(void) {
    int num_nodes, decreasing_by;
    scanf("%d %d", &num_nodes, &decreasing_by);
    node* val = NULL;

    for (int i = 0; i < num_nodes; i++) {
        int num;
        scanf("%d", &num);
        stepDeleteLastOne(&val, num);
    }

    node* last = val;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = val;

    node* preptr = NULL;
    last = val;

    while (last->next != last) {
        for (int i = 0; i < decreasing_by - 1; i++) {
            preptr = last;
            last = last->next;
        }
        preptr->next = last->next;
        node* temp = last;
        last = last->next;

        free(temp);
    }
    printf("%d", last->data);
    return 0;
}
