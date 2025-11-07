/*
 * Purpose: Rotate an array to the right by k positions. Two implementations
 * - kRotateOptimised: uses three reverses in-place (O(n) time, O(1) extra)
 * - kRotate: builds a new vector by slicing (O(n) time, O(n) extra)
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> kRotateOptimised(vector<int> a, int k){
    int n = a.size();
    k = k%n;
    
    reverse(a.begin(), a.begin()+(n-k));
    reverse(a.begin()+(n-k), a.end());
    reverse(a.begin(), a.end());
    return a;
   
}
vector<int> kRotate(vector<int> a, int k){
    int n = a.size();
    k = k%n;
    
    vector<int> output;
    for(int i=n-k; i < n;i++){
        output.push_back(a[i]);
    }
    for(int i =0; i < n-k;i++){
        output.push_back(a[i]);
    }
    
    return output;

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    
    vector<int> rotatedArray = kRotateOptimised(arr, k);
    
    cout << "Array after " << k << " rotations: ";
    for(int i = 0; i < rotatedArray.size(); i++){
        cout << rotatedArray[i] << " ";
    }
    cout << endl;

    vector<int> rotatedArray2 = kRotate(arr, k);
    cout << "Array after " << k << " rotations (using kRotate): ";
    for(int i = 0; i < rotatedArray2.size(); i++){
        cout << rotatedArray2[i] << " ";
    }
    cout << endl;

    return 0;
}