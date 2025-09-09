// C++ implementation to find max cut segments
// using Recursion and Memoization
#include <bits/stdc++.h>
using namespace std;

// Helper function to maximize the number
// of cuts using recursion and memoization
int maxCutHelper(int n, int x, int y, int z,
                           vector<int>& memo) {
    
    // Base case: If the length is zero, 
    // return zero cuts
    if (n == 0) {
        return 0;
    }
    
    // Base case: If the length becomes negative, 
    // return an invalid result
    if (n < 0) {
        return -1; 
    }
    
    // If the result is already computed, 
    // return it from the memo array
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Recursive step: Try all three segment 
    // lengths and choose the maximum result
    int cut1 = maxCutHelper(n - x, x, y, z, memo);
    int cut2 = maxCutHelper(n - y, x, y, z, memo);
    int cut3 = maxCutHelper(n - z, x, y, z, memo);
    
    // Get the maximum number of cuts among
    // the 3 options
    int maxCut = max(cut1, max(cut2, cut3));
    
    // If no valid cut found, return negative
    // value indicating no valid cuts
    if (maxCut == -1) {
        return memo[n] = -1; 
    }
  
    return memo[n] = maxCut + 1;
}

// Main function to start the cutting process
int maximizeTheCuts(int n, int x, int y, int z) {
  
    // Create memoization array initialized to -1
    vector<int> memo(n + 1, -1);
  
    int res = maxCutHelper(n, x, y, z, memo); 
  
    // No valid cuts found
    if(res == -1) return 0;
  
    return res;
}

int main() {
    
    int n = 11; 
    int x = 2, y = 3, z = 5;  

    cout << maximizeTheCuts(n, x, y, z);
    
    return 0;
}