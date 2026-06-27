#include <stdio.h>

void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) { printf("Element found at index %d\n", i); return; }
    }
    printf("Element not found\n");
}

void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) { printf("Element found at index %d\n", mid); return; }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    printf("Element not found\n");
}

int main() {
    int arr[100], n, choice, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    printf("\n1. Linear Search\n2. Binary Search (Requires sorted input)\nChoice: ");
    scanf("%d", &choice);
    if (choice == 1) linearSearch(arr, n, key);
    else if (choice == 2) binarySearch(arr, n, key);
    return 0;
}