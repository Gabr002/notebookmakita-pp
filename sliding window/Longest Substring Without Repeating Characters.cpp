#include <iostream>
#include <vector>
using namespace std;


int longestUniqueSubstr(string& s) {
    if (s.length() == 0 || s.length() == 1)
        return s.length();

    int res = 0;
    vector<bool>vis(26, false);

    // left and right pointer of sliding window
    int left = 0, right = 0;
    while (right < s.length()) {

        // If character is repeated, move left pointer marking
      	// visited characters as false until the repeating 
      	// character is no longer part of the current window
        while (vis[s[right] - 'a'] == true) {

                vis[s[left] - 'a'] = false;
                left++;
       	}

        vis[s[right] - 'a'] = true;

        // The length of the current window (right - left + 1)
        // is calculated and answer is updated accordingly.
        res = max(res, (right - left + 1));
        right++;
    }
    return res;
}

int main() {
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr(s);
    return 0;
}