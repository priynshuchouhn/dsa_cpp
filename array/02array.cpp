#include <iostream>

using namespace std;

// Demonstrates passing C-style arrays to functions and the difference between
// `sizeof` inside main (where the array's size is known) and inside a function
// (where the array decays to a pointer and size information is lost).

// NOTE: When an array parameter is declared as `int arr[]` or `int *arr`,
// the function receives a pointer to the first element. The array does NOT
// get copied; however, `sizeof(arr)` inside the function returns the size
// of the pointer type (e.g., 8 on a 64-bit machine), not the number of
// elements in the original array.
void printArray(int arr[])
{ // `int *arr` would be equivalent here: both are a pointer to int
    // This is an intentional demonstration: sizeof(arr) here gives the size
    // of a pointer, not the original array length. Dividing by sizeof(int)
    // therefore produces an incorrect element count.
    int n = sizeof(arr) / sizeof(int);
    cout << "Size of array in function " << n << endl;

    // Because n above is not the real length, this loop may not behave as
    // expected for determining bounds. Prefer passing the length explicitly.
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

// Correct approach: accept a pointer and the array length separately.
void printArray2(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    // Here the compiler knows the size of `arr`, so sizeof works as expected.
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int); // correct only in this scope
    cout << "Size of array in main " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;

    // This call demonstrates the pitfall: printArray will not be able to
    // compute the real length using sizeof.
    printArray(arr);

    cout << "Output of printArray2" << endl;
    // Pass the known length explicitly when calling helper functions.
    printArray2(arr, n);
}