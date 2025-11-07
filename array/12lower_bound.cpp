/*
 * Purpose: Demonstrate lower-bound search in a sorted array using binary
 *          search and a simple linear search fallback. Functions shown
 *          return the element value (not index) that is the greatest value
 *          <= target.
 * Notes: Time complexity: O(log n) for binary search, O(n) for linear fallback.
 */
#include<bits/stdc++.h>
using namespace std;

// Function to find the lower bound of a value in a sorted array
// using Binary Search
int lowerBoundBS(vector<int> arr, int val) {
    int ans = -1;
    int s = 0;
    int e = arr.size() - 1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]<= val){
            ans = arr[mid];
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return ans;    
}

// using linear search
int lowerBound(vector<int> arr, int val) {
    int ans = -1;
    int s = 0;
    int e = arr.size() - 1;
    for(int i = arr.size()-1; i > 0; i--){
        if(arr[i] <= val){
            return arr[i];
        }
    }
    return -1;
}



int main() {
    vector<int> arr = {1, 2, 4, 6, 10, 12};
    int val = 5;
    cout << "Lower bound of " << val << " is: " << lowerBoundBS(arr, val) << endl;
    cout << "Lower bound of " << val << " is: " << lowerBound(arr, val) << endl;
    return 0;
}