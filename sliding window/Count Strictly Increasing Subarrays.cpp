// C++ Code to count strictly increasing 
// subarrays using Length based Formula
#include <bits/stdc++.h>
using namespace std;

// Function to count strictly increasing 
// subarrays
int countIncreasing(vector<int>& arr) {
    
    int n = arr.size();
    int count = 0;
    int len = 1;

    // Iterate through the array
    for (int i = 1; i < n; i++) {
        
        // If current element is greater than 
        // previous, increase len
        if (arr[i] > arr[i - 1]) {
            len++;
        } 
        
        else {
            
            // Add subarrays count and reset len
            count += (len * (len - 1)) / 2;
            len = 1;
        }
    }

    // Add remaining subarrays count
    count += (len * (len - 1)) / 2;

    return count;
}

// Driver code
int main() {
    
    vector<int> arr = {1, 4, 5, 3, 7, 9};
    
    cout << countIncreasing(arr) << endl;
    
    return 0;
}