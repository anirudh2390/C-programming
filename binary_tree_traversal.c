#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree() {
    int val;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &val);
    if (val == -1) return NULL;
    struct Node* root = createNode(val);
    printf("Left child of %d -> ", val);
    root->left = buildTree();
    printf("Right child of %d -> ", val);
    root->right = buildTree();
    return root;
}

void inorder(struct Node* root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

void preorder(struct Node* root) {
    if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}

void postorder(struct Node* root) {
    if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); }
}

int main() {
    struct Node* root = NULL;
    int choice;
    printf("Build your Binary Tree:\n");
    root = buildTree();
    while (1) {
        printf("\n1. Inorder\n2. Preorder\n3. Postorder\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 2: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 3: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 4: return 0;
        }
    }
}