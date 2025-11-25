#include <bits/stdc++.h>

using namespace std;

// Selection Sort
// ----------------
// This function sorts the input vector `arr` in ascending order using
// the selection sort algorithm. Selection sort repeatedly selects the
// minimum element from the unsorted portion and swaps it with the
// leftmost unsorted element.
//
// Contract:
// - Input: reference to a vector<int> (modified in-place)
// - Output: none (the vector `arr` will be sorted after the call)
// - Side effects: elements in `arr` are swapped during sorting
//
// Complexity:
// - Time: O(n^2) comparisons in the worst/average/best case
// - Space: O(1) additional memory (in-place)
// - Stability: Not stable by default (equal elements may be reordered)
void selection_sort(vector<int> &arr)
{
    int n = arr.size();

    // Move the boundary of the unsorted subarray one by one
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the current position i holds the minimum
        int min_index = i;

        // Find the index of the minimum element in arr[i..n-1]
        // Note: starting j at i is fine (it will compare arr[i] with itself)
        // but starting at i+1 avoids the trivial comparison arr[i] < arr[i].
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                // Found new minimum; remember its index
                min_index = j;
            }
        }

        // Place the found minimum at position i by swapping
        // If min_index == i this is a no-op.
        swap(arr[i], arr[min_index]);
    }
}

int main()
{
    // Example usage: unsorted array
    vector<int> arr = {64, 25, 12, 22, 11};

    // Sort the array in-place
    selection_sort(arr);

    // Print the sorted result
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}