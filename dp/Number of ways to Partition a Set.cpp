// C++ program to find n'th Bell number using
// tabulation
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the Bell number for 'n'
int bellNumber(int n) {
  
    // Initialize the previous row of the Bell triangle with
    // dp[0] = 1
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
      
        // The first element in each row is the same as the
        // last element in the previous row
        int prev = dp[0];
        dp[0] = dp[i - 1];
        for (int j = 1; j <= i; j++) {
          
            // The Bell number for n is the sum of the Bell
            // numbers for all previous partitions
            int temp = dp[j];
            dp[j] = prev + dp[j - 1];
            prev = temp;
        }
    }

    return dp[0];
}

int main() {
  
    int n = 5;
    cout << bellNumber(n) << std::endl;
    return 0;
}