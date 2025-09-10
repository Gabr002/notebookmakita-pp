// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

int maxSumWithK(vector<int>& arr, int k) {
    int n = arr.size();
    
    // maxSum[i] stores maximum sum till index i
    vector<int> maxSum(n);
    maxSum[0] = arr[0];
    
    // Use Kadane's algorithm to fill maxSum[]
    int currMax = arr[0];
    for (int i = 1; i < n; i++) {
        currMax = max(arr[i], currMax + arr[i]);
        maxSum[i] = currMax;
    }
    
    // Sum of first k elements
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    
    // Use sliding window concept
    int result = sum;
    for (int i = k; i < n; i++) {
        
        // Compute sum of k elements ending with a[i]
        sum = sum + arr[i] - arr[i-k];
        
        // Update result if required
        result = max(result, sum);
        
        // Include maximum sum till [i-k] 
        // if it increases overall max
        result = max(result, sum + maxSum[i-k]);
    }
    
    return result;
}

int main() {
    vector<int> arr = {-4, -2, 1, -3};
    int k = 2;
    cout << maxSumWithK(arr, k);
    return 0;
}