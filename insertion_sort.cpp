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

    auto start = chrono::high_resolution_clock::now();

    for(int i = 1; i < n; i++) {
        int cur = a[i];
        int j = i - 1;
        while (a[j] > cur && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = cur;
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "\nAfter sorting:\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "\nTime spent: " << duration.count() << " microseconds";

    // Space complexity is O(1) since it uses a constant amount of extra space for variables

    return 0;
}