#include <bits/stdc++.h>
using namespace std;

// Function to calculate the nth Fibonacci number using recursion
int nthFibonacci(int n){
    // Handle the edge cases
    if (n <= 1)
        return n;

    // Create a vector to store Fibonacci numbers
    vector<int> dp(n + 1);

    // Initialize the first two Fibonacci numbers
    dp[0] = 0;
    dp[1] = 1;

    // Fill the vector iteratively
    for (int i = 2; i <= n; ++i){

        // Calculate the next Fibonacci number
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the nth Fibonacci number
    return dp[n];
}

int main(){
    int n = 5;
    int result = nthFibonacci(n);

    cout << result << endl;

    return 0;
}