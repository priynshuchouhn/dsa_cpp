#include <iostream>

using namespace std;

// printing_pairs: print all unique pairs (i, j) with i < j from the array.
// This demonstrates nested loops where the inner loop starts from i+1 so
// each unordered pair is printed once.
// Time complexity: O(n^2).
void printing_pairs(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << arr[i] << ", " << arr[j] << endl;
        }
        // Separate the blocks of pairs for readability when printing.
        cout << endl;
    }
}

int main()
{
    int arr[] = {10, 20, 39, 45, 53, 66, 70, 89, 90, 101};
    int n = sizeof(arr) / sizeof(int);

    // Print all unique pairs from the array
    printing_pairs(arr, n);
    return 0;
}