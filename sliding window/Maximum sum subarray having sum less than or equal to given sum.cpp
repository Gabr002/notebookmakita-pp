#include <bits/stdc++.h>
using namespace std;

int findMaxSubarraySum(vector<int> &arr, int sum)
{   
    int n = arr.size();
    int curr_sum = arr[0], max_sum = 0, start = 0;

    for (int i = 1; i < n; i++) {

        if (curr_sum <= sum)
            max_sum = max(max_sum, curr_sum);

        while (start < i && curr_sum + arr[i] > sum) {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum < 0)
        {
            curr_sum = 0;
        }

        curr_sum += arr[i];

    }

    if (curr_sum <= sum)
        max_sum = max(max_sum, curr_sum);

    return max_sum;
}

int main()
{
    vector<int> arr = {6, 8, 9};
    int sum = 20;

    cout << findMaxSubarraySum(arr, sum);

    return 0;
}