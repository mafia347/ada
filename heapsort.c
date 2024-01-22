#include <stdio.h>

// Function to heapify a subtree rooted with the given index
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        // Swap the largest element with the root
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heapsort on an array of given size
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (maximum element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    // Example: List of student IDs
    int studentIds[] = {12, 4, 5, 6, 7, 3, 1, 15};

    int n = sizeof(studentIds) / sizeof(studentIds[0]);

    // Perform heapsort on the array of student IDs
    heapSort(studentIds, n);

    // Print the sorted student IDs
    printf("Sorted Student IDs: ");
    for (int i = 0; i < n; i++)
        printf("%d ", studentIds[i]);
    
    return 0;
}