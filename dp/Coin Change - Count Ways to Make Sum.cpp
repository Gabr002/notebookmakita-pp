// C++ program for coin change problem
// using memoization
#include <bits/stdc++.h>
using namespace std;

// Returns the count of ways we can
// sum coins[0...n-1] coins to get sum "sum"
int countRecur(vector<int>& coins, int n, int sum, 
               vector<vector<int>> &memo) {
  
    // If sum is 0 then there is 1 solution
    // (do not include any coin)
    if (sum == 0) return 1;

    // 0 ways in the following two cases
    if (sum < 0 || n == 0) return 0;
    
    // If the subproblem is previously calculated then
    // simply return the result
    if (memo[n-1][sum]!=-1) return memo[n-1][sum];

    // count is sum of solutions (i)
    // including coins[n-1] (ii) excluding coins[n-1]
    return memo[n-1][sum] = 
        countRecur(coins, n, sum - coins[n-1], memo) + 
        countRecur(coins, n - 1, sum, memo);
}

int count(vector<int> &coins, int sum) {
    
    vector<vector<int>> memo(coins.size(), vector<int>(sum+1, -1));
    return countRecur(coins, coins.size(), sum, memo);
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << count(coins, sum);
    return 0;
}