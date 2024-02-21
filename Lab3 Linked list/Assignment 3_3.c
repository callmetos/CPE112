//66070503413 Channathat Ueannapaphon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *reverseLinkedList(ListNode *head, int start, int end) {
    if (!head || start == end) {
        return head; //O(1)
    }

    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = NULL;

    for (int i = 1; i < start && current; i++) {
        prev = current;
        current = current->next; //O(1)
    }

    ListNode *startNode = prev;
    ListNode *endNode = current;

    for (int i = start; i <= end && current; i++) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; //O(1)
    }

    if (startNode) {
        startNode->next = prev;
    } else {
        head = prev;
    }

    endNode->next = current;

    return head;
}

void printLinkedList(ListNode *head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n"); //O(n)
}

void freeLinkedList(ListNode *head) {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        free(temp); //O(n)
    }
}

int main() {
    ListNode *head = NULL;
    ListNode *current = NULL;
    int value;
    char input[10];

    while (scanf("%s", input) == 1 && strcmp(input, "END") != 0) {
        value = atoi(input);

        ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->val = value;
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    int start, end;

    scanf("%d %d", &start, &end);

    head = reverseLinkedList(head, start, end);

    printLinkedList(head);

    freeLinkedList(head);

    return 0;
}
