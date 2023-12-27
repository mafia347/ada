#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    int arr[] = {15, 114, 133, 554, 346, 27};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    cout << "Execution time: " << duration.count() << " seconds\n";
    return 0;
}
