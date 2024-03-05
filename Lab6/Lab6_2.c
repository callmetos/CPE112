//Channathat Ueanapaphon 66070503413

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->value);
    }
}

void printSorted(struct Node* root) {
    inorderTraversal(root);
}

int main() {
    struct Node* root = NULL;
    char command[20];
    int value;
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "INS") == 0) {
            scanf("%d", &value);
            root = insert(root, value);
        } else if (strcmp(command, "PREORDER") == 0) {
            preorderTraversal(root);
            printf("\n");
        } else if (strcmp(command, "INORDER") == 0) {
            inorderTraversal(root);
            printf("\n");
        } else if (strcmp(command, "POSTORDER") == 0) {
            postorderTraversal(root);
            printf("\n");
        } else if (strcmp(command, "END") == 0) {
            printSorted(root);
            break;
        }
    }
    return 0;
}
