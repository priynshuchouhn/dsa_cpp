/*
 * Purpose: Demonstrate common std::vector operations in C++.
 * - declaration and initialization
 * - push_back / pop_back
 * - element access and iteration
 * - size and clear
 * Complexity: operations shown are O(1) or O(n) depending on the call.
 */
#include <iostream>
#include <vector>

using namespace std;

// Function to demonstrate vector operations in C++
void vector_operations() {
    // 1. Declaration and Initialization
    vector<int> vec1; // Empty vector
    vector<int> vec2(5, 10); // Vector of size 5, initialized with 10s
    vector<int> vec3 = {1, 2, 3, 4, 5}; // Vector initialized with a list

    // 2. Adding Elements
    vec1.push_back(20);
    vec1.push_back(30);

    // 3. Accessing Elements
    cout << "First element of vec3: " << vec3[0] << endl;
    cout << "Second element of vec1: " << vec1.at(1) << endl;

    // 4. Iterating through a vector
    cout << "Elements in vec2: ";
    for (size_t i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    cout << endl;   

    // 5. Removing Elements
    vec1.pop_back(); // Removes last element
    cout << "Size of vec1 after pop_back: " << vec1.size() << endl; 

    // 6. Vector Size
    cout << "Size of vec3: " << vec3.size() << endl;    

    // 7. Clearing a vector
    vec2.clear();
    cout << "Size of vec2 after clear: " << vec2.size() << endl;    
}


int main() {
    vector_operations();
    return 0;
}