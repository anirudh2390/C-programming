#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void insertBeg() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = head;
    head = temp;
}

void insertEnd() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct Node* ptr = head;
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = temp;
    }
}

void deleteBeg() {
    if (head == NULL) { printf("List Empty\n"); return; }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void deleteEnd() {
    if (head == NULL) { printf("List Empty\n"); return; }
    struct Node *ptr = head, *prev = NULL;
    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
}

void traverse() {
    if (head == NULL) { printf("List Empty\n"); return; }
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert Beg\n2. Insert End\n3. Delete Beg\n4. Delete End\n5. Traverse\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: deleteBeg(); break;
            case 4: deleteEnd(); break;
            case 5: traverse(); break;
            case 6: return 0;
        }
    }
}