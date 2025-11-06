#include <iostream>

using namespace std;

int linear_search(int arr[], int n, int key)
{
    // Iterate through the array from index 0 to n-1.
    // If we find the key, return its index immediately (first match).
    // This is the classic linear search algorithm with O(n) time complexity
    // in the worst case and O(1) additional space.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            // Found the element, return its index
            return i;
        }
    }

    // Not found — return -1 as a sentinel value.
    return -1;
}

int main()
{
    // Example array to search in
    int arr[] = {10, 20, 39, 45, 53, 66, 70, 89, 90, 101};

    // Compute the number of elements in this scope using sizeof.
    // Note: sizeof(arr)/sizeof(int) only works here, where `arr` is
    // a real array. If `arr` were passed to a function, it would decay
    // to a pointer and sizeof would not give the element count.
    int n = sizeof(arr) / sizeof(int);

    int key;
    cout << "Enter key: " << endl;
    cin >> key;

    // Call the linear search helper and inspect the result.
    // If the return value is >= 0, it's the index where the key was found.
    // If it is -1, the element is not present in the array.
    int result = linear_search(arr, n, key);
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