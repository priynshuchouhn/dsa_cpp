/*
 * Purpose: Compute the maximum subarray sum using Kadane's algorithm.
 * Notes: Uses INT_MIN so it correctly handles all-negative arrays. Time O(n).
 */
#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> A) {
    int cs = 0;
    int maxSum = INT_MIN;
    
    for(int i =0; i<A.size(); i++){
        cs = max(A[i], cs+ A[i]);
        maxSum = max(maxSum, cs);
    }
    
    return maxSum;
}

// Example usage
int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Maximum subarray sum is: " << maxSumSubarray(arr) << endl;
    return 0;
}