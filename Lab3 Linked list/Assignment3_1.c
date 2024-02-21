//66070503413 Channathat Ueannapaphon
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int student_id;
    int score;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void insert(struct LinkedList* list, int student_id, int score) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->student_id = student_id;
    new_node->score = score;
    new_node->next = list->head;
    list->head = new_node;
}

void display_scores(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->score);
        head = head->next;
    }
    printf("\n");
}

void sort_list(struct LinkedList* list, int mode) {
    struct Node *current, *next;
    int temp;

    if (list->head == NULL || list->head->next == NULL) {
        return;
    }

    for (current = list->head; current->next != NULL; current = current->next) {
        for (next = current->next; next != NULL; next = next->next) {

            if ((mode == 0 && current->student_id > next->student_id) ||
                (mode == 1 && current->score > next->score)) {

                temp = current->student_id;
                current->student_id = next->student_id;
                next->student_id = temp;

                temp = current->score;
                current->score = next->score;
                next->score = temp;
            }
        }
    }
}

int main() {
    struct LinkedList list;
    list.head = NULL;

    int size;
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        int student_id, score;
        scanf("%d %d", &student_id, &score);
        insert(&list, student_id, score);
    }

    int mode;
    scanf("%d", &mode);

    sort_list(&list, mode);
    display_scores(list.head);

    return 0;
}
