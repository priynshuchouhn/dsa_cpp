#include <iostream>

using namespace std;

// subarrays: enumerate and print all possible contiguous subarrays of `arr`.
// Approach: three nested loops - choose start i, end j, and iterate k to print
// the elements between i and j inclusive.
// Time complexity: O(n^3) because of the triple loop; useful for demonstration
// but not efficient for large arrays.
void subarrays(int arr[], int n){
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Print subarray arr[i..j]
            for (int k = i; k <= j; k++) {
                cout << arr[k] << ", ";
            }
            cout << endl;
        }
    }
}

int main(){
   int arr[] = {10,20,30,40,50};
   int n = sizeof(arr)/sizeof(int);

   // Print all contiguous subarrays of arr
   subarrays(arr, n);

   return 0;

}