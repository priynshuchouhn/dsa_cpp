#include <iostream>

using namespace std;
// Binary search demonstration
// Key points:
// - Binary search requires the array to be sorted in ascending order.
// - It repeatedly halves the search interval, comparing the key with the
//   middle element and moving either the start or end accordingly.
// - Time complexity: O(log n). Space complexity: O(1) (iterative version).
// - Returns the index of the key if found, or -1 when not found.

int binary_search(int arr[], int n, int key){
    int s = 0;        // start index
    int e = n - 1;    // end index

    // Loop until the search interval is empty
    while (s <= e) {
        // Compute middle index. For very large indices, (s+e) can overflow
        // for signed integer types; a safer alternative is `s + (e - s) / 2`.
        int mid = (s + e) / 2;

        // If the middle element matches the key, return its index.
        if (arr[mid] == key) {
            return mid;
        }
        // If the middle element is greater than the key, search left half.
        else if (arr[mid] > key) {
            e = mid - 1;
        }
        // Otherwise search right half.
        else {
            s = mid + 1;
        }
    }

    // Not found: return sentinel value -1.
    return -1;
}

int main()
{
    // Example sorted array required by binary search
    int arr[] = {10, 20, 39, 45, 53, 66, 70, 89, 90, 101};

    // Determine number of elements in this scope using sizeof.
    // Note: sizeof(arr) / sizeof(int) only yields the correct element count
    // here where `arr` is an actual array variable. If `arr` is passed to a
    // function, it decays to a pointer and sizeof will not give the element count.
    int n = sizeof(arr) / sizeof(int);

    int key;
    cout << "Enter key: " << endl;
    cin >> key;

    int result = binary_search(arr, n, key);
    if (result > -1)
    {
        cout << "Element has found at " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}