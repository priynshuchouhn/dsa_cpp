/*
 * Purpose: Given a sorted array, find the pair whose sum is closest to a
 *          target value x using the two-pointer technique.
 * Complexity: O(n) time, O(1) extra space.
 */
#include<bits/stdc++.h>
using namespace std;

// Function to find a pair in a sorted array whose sum is closest to a given value x
pair<int, int> closestSum(vector<int> arr, int x){
    int n = arr.size();
    int s = 0, e = n-1;
    int minDiff = INT_MAX;
    int ans[2]={-1};
    
    while(s<e){
        int sum = arr[s]+arr[e];
        if(abs(sum - x) < minDiff){
            ans[0] = arr[s];
            ans[1] = arr[e];
            minDiff = abs(sum-x);
        }
        if(sum > x){
            e--;
        }else{
            s++;
        }
    }
    
    return {ans[0],ans[1]};
}

int main() {
    vector<int> arr = {1, 2, 3, 5, 7, 12};
    int x = 11;
    pair<int, int> result = closestSum(arr, x);
    cout << "The pair with sum closest to " << x << " is: (" << result.first << ", " << result.second << ")" << endl;
    return 0;
}