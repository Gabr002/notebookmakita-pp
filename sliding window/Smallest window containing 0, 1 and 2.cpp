#include <bits/stdc++.h>
using namespace std;

int smallestSubstring(string &S) {
    int n = S.length(), i = 0, j = 0, k = 0, cnt = 0, min_len = INT_MAX;
    int freq[3] = {0};
    while (k < n) {
        freq[S[k]-'0']++;
        if (freq[S[k]-'0'] == 1) cnt++;
        if (cnt == 3) {
            while (freq[S[i]-'0'] > 1) {
                freq[S[i]-'0']--;
                i++;
            }
            min_len = min(min_len, k-i+1);
            freq[S[i]-'0']--;
            i++;
            cnt--;
        }
        k++;
    }
    return (min_len == INT_MAX) ? -1 : min_len;
}

int main() {
    string S = "01212";
    cout << smallestSubstring(S) << endl;
    return 0;
}