#include <iostream>
#include <vector>
using namespace std;

int longestKSubstr(string &s, int k) {
    
    int n = s.size();
    int i = 0, j = 0;         
    int cnt = 0;               
    int maxi = -1;            
    vector<int> fre(26, 0);  
    
    // cnt represents the number of 
    // unique characters in the current window

    while (j < n) {
        
        // include s[j] into the window
        fre[s[j] - 'a']++;
        
        // it is the first occurrence of
        // this character in the window
        if (fre[s[j] - 'a'] == 1) cnt++;

        // shrink the window if the number of 
        // unique character is more than k
        while (cnt > k) {
            fre[s[i] - 'a']--;
            
            // one unique character removed
            if (fre[s[i] - 'a'] == 0) cnt--;  
            i++;
        }

        // we have exactly k unique characters
        if (cnt == k) {
            maxi = max(maxi, j - i + 1);
        }

        j++;
    }

    return maxi;
}

int main() {
    string s = "aabacbebebe";
    int k = 3;
    cout << longestKSubstr(s, k) << "\n";
    return 0;
}