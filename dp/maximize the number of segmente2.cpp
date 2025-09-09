// C++ implementation to find max cut segments
// using Tabulation
#include <bits/stdc++.h>
using namespace std;

// Main function to start the cutting process
int maximizeTheCuts(int n, int x, int y, int z) {

    // Create a table to store results of subproblems
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {

        // Check if the current length is at least x
        // If so, check if the previous result
        // (dp[i - x]) is valid (not -1)
        // Update dp[i] by considering this cut
        if (i >= x && dp[i - x] != -1) {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }

        // Similarly, check for the other two possible
        // cuts (y and z)
        if (i >= y && dp[i - y] != -1) {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i >= z && dp[i - z] != -1) {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }

        // If no valid cut was found for length i,
        if (dp[i] == 0) {
            dp[i] = -1;
        }
    }

    // If no valid cuts are found for the full length n,
    // return 0
    if (dp[n] == -1) {
        return 0;
    }

    // Return the maximum number of cuts for the rod
    // of length n
    return dp[n];
}

int main() {

    int n = 11;
    int x = 2, y = 3, z = 5;

    cout << maximizeTheCuts(n, x, y, z);

    return 0;
}