// C++ program to find longest repeating
// and non-overlapping substring
// using memoization
#include <bits/stdc++.h>
using namespace std;

int findSuffix(int i, int j, string &s, 
               vector<vector<int>> &memo) {

    // base case
    if (j == s.length())
        return 0;

    // return memoized value
    if (memo[i][j] != -1)
        return memo[i][j];

    // if characters match
    if (s[i] == s[j]) {
        memo[i][j] = 1 + min(findSuffix(i + 1, j + 1, s, memo),
                             j - i - 1);
    }
    else {
        memo[i][j] = 0;
    }

    return memo[i][j];
}

string longestSubstring(string s) {

    int n = s.length();

    vector<vector<int>> memo(n, vector<int>(n, -1));

    // find length of non-overlapping
    // substrings for all pairs (i,j)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            findSuffix(i, j, s, memo);
        }
    }

    string ans = "";
    int ansLen = 0;

    // If length of suffix is greater
    // than ansLen, update ans and ansLen
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (memo[i][j] > ansLen) {
                ansLen = memo[i][j];
                ans = s.substr(i, ansLen);
            }
        }
    }

    return ansLen > 0 ? ans : "-1";
}

int main() {
    string s = "geeksforgeeks";
    cout << longestSubstring(s) << endl;
    return 0;
}