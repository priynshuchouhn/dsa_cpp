#include <iostream>
using namespace std;

// reverse_array: reverse the contents of a C-style array in-place
// Approach: two-pointer swap. Start at the left (s) and right (e) ends and
// swap elements while moving the pointers towards each other.
// Time complexity: O(n), Space complexity: O(1).
void reverse_array(int arr[], int n){
  int s = 0;        // start index
  int e = n - 1;    // end index

  // Swap elements until the two pointers meet or cross.
  while (s < e) {
    swap(arr[s], arr[e]);
    s++;
    e--;
  }
}

int main(){
  // Example array to demonstrate reversal
  int arr[] = {10, 20, 39, 45, 53, 66, 70, 89, 90, 101};
  int n = sizeof(arr) / sizeof(int);

  // Print original array
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Reverse and print again
  reverse_array(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}