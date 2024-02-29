#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 1000

struct BinaryTree {
    int tree[MAX_NODES];
    int max_nodes;
    bool root_created;
};

struct BinaryTree* createBinaryTree(int max_nodes) {
    struct BinaryTree* tree = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    tree->max_nodes = max_nodes;
    tree->root_created = false;
    for (int i = 0; i < MAX_NODES; ++i) {
        tree->tree[i] = -999; // Representing null with -999
    }
    return tree;
}

void createRoot(struct BinaryTree* tree, int val) {
    if (!tree->root_created) {
        tree->tree[1] = val;
        tree->root_created = true;
    } else {
        printf("cannot create duplicated root\n");
    }
}

void insertLeft(struct BinaryTree* tree, int parent_val, int val) {
    int i;
    for (i = 1; i < MAX_NODES; ++i) {
        if (tree->tree[i] == parent_val)
            break;
    }
    if (i == MAX_NODES) {
        printf("not found\n");
        return;
    }
    if (2 * i <= tree->max_nodes) {
        if (tree->tree[2 * i] != -999) {
            printf("node already presented\n");
        } else {
            tree->tree[2 * i] = val;
        }
    } else {
        printf("overflow\n");
    }
}

void insertRight(struct BinaryTree* tree, int parent_val, int val) {
    int i;
    for (i = 1; i < MAX_NODES; ++i) {
        if (tree->tree[i] == parent_val)
            break;
    }
    if (i == MAX_NODES) {
        printf("not found\n");
        return;
    }
    if ((2 * i) + 1 <= tree->max_nodes) {
        if (tree->tree[(2 * i) + 1] != -999) {
            printf("node already presented\n");
        } else {
            tree->tree[(2 * i) + 1] = val;
        }
    } else {
        printf("overflow\n");
    }
}

void displayLevelOrder(struct BinaryTree* tree) {
    for (int i = 1; i <= tree->max_nodes; ++i) {
        if (tree->tree[i] != -999) {
            printf("%d ", tree->tree[i]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct BinaryTree* tree = createBinaryTree(n);

    char command[5];
    int val, parent;
    while (true) {
        scanf("%s", command);
        if (strcmp(command, "ROOT") == 0) {
            scanf("%d", &val);
            createRoot(tree, val);
        } else if (strcmp(command, "INSL") == 0) {
            scanf("%d %d", &parent, &val);
            insertLeft(tree, parent, val);
        } else if (strcmp(command, "INSR") == 0) {
            scanf("%d %d", &parent, &val);
            insertRight(tree, parent, val);
        } else if (strcmp(command, "END") == 0) {
            displayLevelOrder(tree);
            break;
        }
    }

    free(tree);
    return 0;
}
