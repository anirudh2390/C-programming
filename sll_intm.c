#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void insertAfter() {
    int key;
    printf("Enter the node value after which to insert: ");
    scanf("%d", &key);
    struct Node* ptr = head;
    while (ptr != NULL && ptr->data != key) ptr = ptr->next;
    if (ptr == NULL) {
        printf("Key node not found\n");
    } else {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void deleteAfter() {
    int key;
    printf("Enter the node value after which to delete: ");
    scanf("%d", &key);
    struct Node* ptr = head;
    while (ptr != NULL && ptr->data != key) ptr = ptr->next;
    if (ptr == NULL || ptr->next == NULL) {
        printf("No node exists after the given key\n");
    } else {
        struct Node* temp = ptr->next;
        ptr->next = temp->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}

void append(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val; temp->next = NULL;
    if (head == NULL) { head = temp; return; }
    struct Node* p = head;
    while (p->next != NULL) p = p->next;
    p->next = temp;
}

void display() {
    struct Node* p = head;
    while (p) { printf("%d -> ", p->data); p = p->next; }
    printf("NULL\n");
}

int main() {
    int choice, val;
    printf("Creating initial elements (Enter -1 to stop initialization):\n");
    while (1) {
        scanf("%d", &val);
        if (val == -1) break;
        append(val);
    }
    while (1) {
        printf("\n1. Insert After Node\n2. Delete After Node\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertAfter(); break;
            case 2: deleteAfter(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}