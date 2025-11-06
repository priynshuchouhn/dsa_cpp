#include <iostream>
// Simple demo of a fixed-size C-style array, input, output and update
// File: array/01array.cpp
// Shows: declaration, reading elements, printing elements, and updating an element
using namespace std;

int main() {
    // Declare an array of 100 integers and initialize all to 0.
    // We use a fixed-size array for simplicity; only the first `n` entries
    // (entered by the user) will be used.
    int arr[100] = {0};

    // Read how many elements the user wants to provide.
    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    // Input loop: read `n` elements from the user and store them in arr[0..n-1].
    // Note: No bounds checking here — for real code you should ensure n <= 100.
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Print the elements the user entered.
    cout << "You entered: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Demonstrate updating an element in the array. Here we set the first
    // element (index 0) to 100, then print the array again so the change is visible.
    cout << "Updated: ";
    arr[0] = 100; // Update the first element to 100
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}