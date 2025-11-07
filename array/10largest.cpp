/*
 * Purpose: Find the largest element in a vector using a linear scan.
 */
#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> arr) {
    int largest = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(largest < arr[i]){
            largest = arr[i];
        }
    }
    
    return largest;
     
}

int main() {
    vector<int> arr = {2, 4, 1, 5, 3};
    cout << "Largest element in the array is: " << largestElement(arr) << endl;
    return 0;
}