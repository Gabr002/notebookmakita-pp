#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    
    // If the string is empty, return it
    if (s.empty()) {
        return s;
    }

    // Initialize the result string
    string result = "";

    // Iterate through the string with the sliding window
    for (int i = 0; i < s.length(); i++) {
        
        // If the result is empty or the last character
        // in result is not the same as current character
        if (result.empty() || result.back() != s[i]) {
            result += s[i];  
        }
    }

    return result;
}

int main() {
    string s1 = "geeksforgeeks";
    cout << removeDuplicates(s1) << endl; 

    string s2 = "aabcca";
    cout << removeDuplicates(s2) << endl;

    return 0;
}