// C++ program to Find Minimum Sum Path in a Triangle
// using Space Optimized DP

#include <iostream>
#include <vector>
using namespace std;

int minSumPath(vector<vector<int> >& triangle) {
  
    int n = triangle.size();
    
    // 1-D dp to store the result
    vector<int> dp(n);
    
    // Base Case: Initially dp will be the 
    // same as last row of matrix
    for (int i = 0; i < n; i++) 
        dp[i] = triangle[n - 1][i]; 

    // Calculation of the remaining rows,
    // in bottom up manner.
    for (int i = triangle.size() - 2; i >= 0; i--) 
        for (int j = 0; j < triangle[i].size(); j++) 
            dp[j] = triangle[i][j] + min(dp[j],
                                    dp[j + 1]);

    return dp[0];
}

int main() {
    vector<vector<int> > triangle{{2},
                            {3, 9},
                            {1, 6, 7}};
    cout << minSumPath(triangle);
    return 0;
}