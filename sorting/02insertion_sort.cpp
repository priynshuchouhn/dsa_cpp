#include <bits/stdc++.h>
using namespace std;

/*
Insertion Sort

Complexity:
 - Worst/Average: O(n^2)
 - Best (already sorted): O(n)
 - Space: O(1) extra (in-place)

This implementation iterates the array from left to right. For each index i it
extracts the element at arr[i] (named `current`) and inserts it into the
correct position among the previously-sorted elements arr[0..i-1] by shifting
larger elements one position to the right. The loop invariant is that before
each iteration `i`, the subarray arr[0..i-1] is sorted.
*/
void insertion_sort(vector<int> &arr) {
    int n = arr.size();

    // Start from the second element (index 1). The single-element prefix
    // arr[0..0] is trivially sorted.
    for (int i = 1; i < n; i++) {
        int current = arr[i];   // value to insert into the sorted prefix
        int prev = i - 1;       // index of the last element in the sorted prefix

        // Shift elements in the sorted prefix to the right until we find the
        // correct insertion position for `current`.
        // Condition: while prev is valid and the element at prev is greater
        // than current, move it one slot to the right.
        while (prev >= 0 && arr[prev] > current) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        // Insert current into the correct spot. After the while-loop,
        // prev is the index of the element just before the insertion point,
        // therefore insert at prev+1.
        arr[prev + 1] = current;
    }
}

int main() {
    // Example usage: small unsorted array
    vector<int> arr = {12, 11, 13, 5, 6};

    // Sort in-place
    insertion_sort(arr);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}