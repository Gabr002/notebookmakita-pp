#include <bits/stdc++.h>
using namespace std;

int findSubString(string str) {
    int n = str.size();

    // to store all distinct characters
    vector<bool> visited(26, false);
    int distinct = 0;

    for (int i = 0; i < n; i++) {
        if (visited[str[i] - 'a'] == false) {
            visited[str[i] - 'a'] = true;
            distinct++;
        }
    }

    // to store the visited of characters
    // in the current window
    vector<int> cur(26, 0);
    int cnt = 0;

    int ans = n;
    int start = 0;
    for(int i = 0; i < n; i++) {
        
        // Count characters in the current
        // window
        cur[str[i] - 'a']++;
        if(cur[str[i] - 'a'] == 1) {
            cnt++;
        }
        
        // If the count becomes same as overall
        while(cnt == distinct) {
            ans = min(ans, i - start + 1);
            
            // Remove characters from left
            cur[str[start] - 'a']--;
            if(cur[str[start] - 'a'] == 0) {
                cnt--;
            }
            start++;
        }
    }
    return ans;
}

int main() {
    string str = "aabcbcdbca";
    cout << findSubString(str);
    return 0;
}