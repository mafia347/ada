#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
int main() {
    int n;

    cout << "Enter the size: ";
    cin >> n;

    int a[n];

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "\nBefore sorting:\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    // Time complexity measurement
    auto start = chrono::high_resolution_clock::now();

    // Selection sort algorithm
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[i]) {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "\nAfter sorting:\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "\nTime spent: " << duration.count() << " microseconds";

    // Space complexity is O(1) since it uses a constant amount of extra space

    return 0;
}