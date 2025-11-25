#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    int N = v.size();
    sort(v.begin(), v.end(), compare);
    
    return v;
    
}

int main() {
    vector<pair<int, int>> points = {{3, 4}, {1, 2}, {3, 2}, {0, 0}, {1, 3}};
    
    vector<pair<int, int>> sortedPoints = sortCartesian(points);
    
    cout << "Sorted Cartesian Points: " << endl;
    for(auto p : sortedPoints){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    
    return 0;
}