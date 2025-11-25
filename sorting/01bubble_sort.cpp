#include<bits/stdc++.h>
using namespace std;

// Optimized Bubble Sort
// ---------------------
// This function implements bubble sort with an early-exit optimization.
// It takes the input vector `v` by value (a copy) and returns a sorted copy.
// Complexity:
// - Worst-case time: O(n^2)
// - Best-case time (already sorted): O(n) due to early exit
// - Space: O(n) because we take the vector by value (copy). If in-place
//   sorting is desired without a copy, change signature to `vector<int>& v`.
// Notes:
// - This implementation resets the `swapped` flag at the start of each
//   outer-loop iteration so the algorithm can detect when the array becomes
//   sorted and exit early.
// - Bubble sort is stable: equal elements preserve their relative order.
vector<int> optimizedBubbleSort(vector<int> v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        // Track whether we made any swaps during this pass.
        // If no swaps occur, the array is already sorted and we can stop.
        bool swapped = false;

        // After i passes the last i elements are already in place
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }

        // If no swaps were made, the vector is sorted — exit early.
        if(!swapped) break;
    }
    return v;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> sortedArr = optimizedBubbleSort(arr);
    
    cout << "Sorted array: ";
    for(int i = 0; i < sortedArr.size(); i++){
        cout << sortedArr[i] << " ";
    }
    cout << endl;
    
    return 0;
}