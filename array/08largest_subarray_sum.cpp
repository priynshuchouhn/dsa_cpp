#include <iostream>

using namespace std;

// Three approaches to find the maximum subarray sum (contiguous elements):
// 1) Brute-force O(N^3): enumerate all subarrays and compute each sum.
// 2) Prefix-sum O(N^2): precompute prefix sums to get subarray sums in O(1).
// 3) Kadane's algorithm O(N): single-pass dynamic approach maintaining current
//    running sum and best sum so far.

// Brute Force O(N^3)
int largest_sum_subarray1(int arr[], int n){
    int largest_sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sub_array_sum = 0;
            // Sum the elements from i to j inclusive
            for(int k = i; k <= j; k++){
                sub_array_sum += arr[k];
            }
            largest_sum = max(largest_sum, sub_array_sum);
        }
    }
    return largest_sum;
}

// Prefix Sum approach O(N^2)
int largest_sum_subarray2(int arr[], int n){

    // Build prefix sums: prefix[i] = sum(arr[0..i])
    int prefix[100] = {0};
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    int largest_sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            // Sum of arr[i..j] = prefix[j] - prefix[i-1] (if i>0)
            int sub_array_sum = i > 0 ? prefix[j] - prefix[i-1] : prefix[j];
            largest_sum = max(largest_sum, sub_array_sum);
        }
    }
    return largest_sum;
}

// Kadane's Algorithm O(N)
// Maintain a current sum (cs). If cs becomes negative, reset it to zero
// because a negative prefix won't help future subarrays. Track the maximum
// value seen in largest_sum.
int largest_sum_subarray3(int arr[], int n){
    int cs = 0;
    int largest_sum = 0;

    for (int i = 0; i < n; i++){
        cs += arr[i];
        if (cs < 0){
            cs = 0;
        }
        largest_sum = max(largest_sum, cs);
    }
    return largest_sum;
}

int main(){
    // Example array. Note: `4-1` evaluates to 3; if intended to be two
    // separate elements (4 and -1) write: { -2, 3, 4, -1, 5, -12, 6, 1, 3 }.
    int arr[] = {-2,3,4-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);

    cout << "largest sum is: " << largest_sum_subarray1(arr, n) << endl;
    cout << "largest sum is: " << largest_sum_subarray2(arr, n) << endl;
    cout << "largest sum is: " << largest_sum_subarray3(arr, n) << endl;

    return 0;
}