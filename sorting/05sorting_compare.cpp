#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
  sorting/05sorting_compare.cpp
  - Demonstrates using a comparator with std::sort
  - sort can accept a custom comparator to change ordering (here: descending)
  - Time complexity: O(n log n) in typical implementations of std::sort
  - Space complexity: O(log n) auxiliary (implementation dependent)
*/

// Comparator function used by std::sort to sort in descending order.
// It returns true when 'a' should come before 'b'. For descending order
// we want larger elements first, so we return (a > b).
bool compare(int a, int b)
{
    return a > b;
}

// sortingWithComparator
// - Parameters:
//    a    : vector<int> - the array to sort (passed by value so original is unchanged)
//    flag : bool        - if true, sort ascending using default operator<;
//                        if false, sort descending using the custom comparator
// - Returns: sorted vector<int>
// Note: copying the vector (pass-by-value) is intentional here so the caller's
// original vector is not modified. For large vectors consider passing by
// reference and operating in-place.
vector<int> sortingWithComparator(vector<int> a, bool flag)
{
    if (!flag)
    {
        // Use the custom comparator to sort in descending order
        sort(a.begin(), a.end(), compare);
    }
    else
    {
        // Default sort (ascending)
        sort(a.begin(), a.end());
    }

    return a;
}

int main()
{
    // Example usage: unsorted array
    vector<int> arr = {4, 2, 8, 5, 1, 7, 6, 3};

    // flag controls sort order: false => descending, true => ascending
    bool flag = false; // change to 'true' to see ascending order

    // We receive a sorted copy from sortingWithComparator
    vector<int> sortedArr = sortingWithComparator(arr, flag);

    cout << "Sorted array: ";
    for (size_t i = 0; i < sortedArr.size(); i++)
    {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    return 0;
}