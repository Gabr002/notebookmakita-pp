#include <bits/stdc++.h>
using namespace std;

/* Returns counts of 1's in arr[low..high]. 
   The array is assumed to be sorted in 
   non-increasing order */
int countOnes(vector<int> &arr)
{   
    int n = arr.size();
    int ans = 0;
    int low = 0, high = n - 1;
    
    // get the middle index
    while (low <= high) { 
        int mid = (low + high) / 2;

        // If mid element is 0
        if (arr[mid] == 0)
            high = mid - 1;
            
        // If element is last 1
        else if (mid == n - 1 || arr[mid + 1] != 1)
            return mid + 1;
            
        // If element is not last 1    
        else
            low = mid + 1;
    }
    return 0;
}

int main()
{
    vector<int> arr = { 1, 1, 1, 1, 0, 0, 0 };
    cout << countOnes(arr);
    return 0;
}