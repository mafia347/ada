#include <iostream>
#include <ctime>

using namespace std;

void merge(int a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int* a_ = new int[n1];  // Dynamic array allocation
    int* b = new int[n2];   // Dynamic array allocation

    // ... rest of the code remains the same

    delete[] a_;
    delete[] b;
}

void mergesort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int* a = new int[n];  // Dynamic array allocation
    cout << "Enter the elements\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Sorted\n";
    clock_t start, end;
    start = clock();
    mergesort(a, 0, n - 1);
    end = clock();

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime spent: " << time_spent << " seconds\n";

    delete[] a;  // Release dynamically allocated memory
    return 0;
}