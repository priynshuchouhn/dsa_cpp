#include <bits/stdc++.h>
using namespace std;

/*
 Counting Sort (simple version)

 Contract:
 - Input: vector<int> &arr : contains non-negative integers
 - Output: in-place sorted `arr` in non-decreasing order
 - Side effects: modifies the input vector

 Notes / Constraints:
 - This implementation assumes all values are >= 0. For negative numbers,
   a shift or mapping would be required.
 - Time complexity: O(n + k) where n = arr.size() and k = max(arr)
 - Space complexity: O(k) due to the frequency array
 - This variant reconstructs the input from frequency counts and is NOT stable.
   To make it stable, use cumulative counts and an auxiliary output array.
*/

void counting_sort(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return; // nothing to sort

    // Find the maximum element to size the frequency array.
    int largest = -1;
    for (int i = 0; i < n; i++) {
        // We don't handle negative numbers here; caller must ensure non-negative input.
        largest = max(largest, arr[i]);
    }

    // Frequency array of size (largest + 1). Initialized to 0.
    // freq[v] will hold the number of occurrences of value v in arr.
    vector<int> freq(largest + 1, 0);

    // Build frequency table
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Reconstruct the sorted array by writing each value i, freq[i] times.
    // k is the write index into arr.
    int k = 0;
    for (int i = 0; i <= largest; i++) {
        while (freq[i] > 0) {
            arr[k] = i;
            k++;
            freq[i]--;
        }
    }
}

int main() {
    // Example usage
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    counting_sort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}