#include <stdio.h>

void heapify(int arr[], int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < n && arr[left] > arr[largest])
largest = left;

if (right < n && arr[right] > arr[largest])
largest = right;

if (largest != i) {
int temp = arr[i];
arr[i] = arr[largest];
arr[largest] = temp;

heapify(arr, n, largest);
}
}

void heapSort(int arr[], int n) {
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i);

for (int i = n - 1; i > 0; i--) {
int temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;

heapify(arr, i, 0);
}
}

int main() {
int x;
printf("Enter the no of student id = ");
scanf("%d", &x);
int studentIds[x];
printf("Enter student ids = ");
for (int i = 0; i < x; i++) {
scanf("%d", &studentIds[i]);
}
int n = sizeof(studentIds) / sizeof(studentIds[0]);

heapSort(studentIds, n);

printf("Sorted Student IDs: ");
for (int i = 0; i < n; i++)
printf("%d ", studentIds[i]);

return 0;
}
