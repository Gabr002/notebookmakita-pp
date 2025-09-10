// C++ Code to find the maximum number of elements 
// that can be selected using Sliding Window
#include <bits/stdc++.h>
using namespace std;

int maxElements(vector<int> &arr, int k) {
    int n = arr.size();
    int right = 0, left = 0, count = 0;
    
    // Map to maintain count of elements in sections
    unordered_map<int, int> mpp;
    
    int maxCount = 0;

    // Iterate through the array
    while (right < n) {
        
        // Add current element to the frequency map
        mpp[arr[right]]++;
        count++;

        // If unique elements exceed k, shrink 
        // window from left
        while (mpp.size() > k) {
            mpp[arr[left]]--;
            count--;

            // Remove element if count becomes zero
            if (mpp[arr[left]] == 0) {
                mpp.erase(arr[left]);
            }
            left++;
        }

        // Update the maximum number of elements chosen
        if (mpp.size() <= k) {
            maxCount = max(maxCount, count);
        }
        right++;
    }

    // Return the final answer
    return maxCount;
}

int main() {
    
    vector<int> arr = {1, 2, 2, 3, 1, 4};
    int k = 2;
    
    cout << maxElements(arr, k) << endl;

    return 0;
}