#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter element: ");
    scanf("%d", &temp->data);
    temp->next = top;
    top = temp;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
    } else {
        struct Node* temp = top;
        printf("Popped: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}