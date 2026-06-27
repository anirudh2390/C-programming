#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (front == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
    } else {
        struct Node* temp = front;
        printf("Dequeued: %d\n", front->data);
        front = front->next;
        if (front == NULL) rear = NULL;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = front;
        printf("Queue elements: ");
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
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}