#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int x, bool findStart) {
    int n = arr.size();

    // Initialize low and high index
    int low = 0, high = n - 1;

    // Initialize the index
    int ind = -1;

    // Find occurrence of x
    while(low <= high) {

        // Find the mid index
        int mid = (low + high) / 2;

        // If x is equal to arr[mid]
        if (x == arr[mid]) {
            ind = mid;

            if(findStart == true)
                high = mid - 1;
            else
                low = mid + 1;
        }

        // If x is less than arr[mid], 
        // then search in the left subarray
        else if (x < arr[mid])
            high = mid - 1;

        // If x is greater than arr[mid], 
        // then search in the right subarray
        else
            low = mid + 1;
    }

    return ind;
}

// Function for finding first and last occurrence of x
vector<int> find(vector<int> &arr, int x) {

    // return index of first occurrence
    int first = search(arr, x, true);

    // return index of last occurrence
    int last = search(arr, x, false);
    vector<int> res = {first, last};
    return res;
}

int main() {
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;
    vector<int> res = find(arr, x);
    cout << res[0] << " " << res[1];
    return 0;
}