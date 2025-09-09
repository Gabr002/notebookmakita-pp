// A C++ program to count all possible paths
// from top left to bottom right
// using space optimised

#include <iostream>
using namespace std;
int numberOfPaths(int m, int n) {

    //  `dp[j]` will represent the number of paths to
    // reach the current cell in the row, with `dp[j]` initialized
    // to 1 as the only path in the first row.
    int dp[n] = {1};
    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {

            // Update dp[j] to include paths from the 
          	// cell directly to the left. dp[j - 1]` is the value of
         	// the current row's previous cell, and `dp[j]` itself stores
          	// the value from the previous row (same column).
            dp[j] += dp[j - 1];
        }
    }

    return dp[n - 1];
}

int main() {
    int res = numberOfPaths(3, 3);
    cout << res << endl;
}