#include<iostream>
using namespace std;
int binary_search(int a[], int first, int last, int search) {
    if (first > last) {
        return -1; 
    }
    int mid = (first + last) / 2;

    if (search < a[mid]) {
        return binary_search(a, first, mid - 1, search);
    }
    else if (search > a[mid]) {
        return binary_search(a, mid + 1, last, search);
    }
    else {
        return mid;
    }
}
int main() {
    int a[100], n, search;
    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cout<<"Enter element: ";
        cin >> a[i];
    }

    cout << "Enter search element: ";
    cin >> search;

    int result = binary_search(a, 0, n - 1, search);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found.";
}
