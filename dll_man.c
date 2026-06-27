#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};
struct Node* head = NULL;

void insertBeg() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = head;
    if (head != NULL) head->prev = temp;
    head = temp;
}

void deleteEnd() {
    if (head == NULL) { printf("List Empty\n"); return; }
    struct Node* ptr = head;
    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (ptr->next != NULL) ptr = ptr->next;
    ptr->prev->next = NULL;
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
}

void display() {
    struct Node* ptr = head;
    if (ptr == NULL) { printf("List Empty\n"); return; }
    printf("Forward Traverse: ");
    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        if (ptr->next == NULL) break;
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert Front\n2. Delete Rear\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertBeg(); break;
            case 2: deleteEnd(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}