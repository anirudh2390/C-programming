#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val; temp->left = temp->right = NULL;
        return temp;
    }
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(struct Node* root) {
    if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

int main() {
    struct Node* root = NULL;
    int choice, val;
    while (1) {
        printf("\n1. Insert into BST\n2. Inorder Display\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); root = insert(root, val); break;
            case 2: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 3: return 0;
        }
    }
}