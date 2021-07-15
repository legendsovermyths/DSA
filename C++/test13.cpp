
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// subarray sum of even length
int maxEvenLenSum(int arr[], int n)
{

    // There has to be at
    // least 2 elements
    if (n < 2)
        return 0;

    // dp[i] will store the maximum
    // subarray sum of even length
    // starting at arr[i]
    int dp[n] = {0};

    // Valid subarray cannot start from
    // the last element as its
    // length has to be even
    dp[n - 1] = 0;
    dp[n - 2] = arr[n - 2] + arr[n - 1];

    for (int i = n - 3; i >= 0; i--)
    {

        // arr[i] and arr[i + 1] can be added
        // to get an even length subarray
        // starting at arr[i]
        dp[i] = arr[i] + arr[i + 1];

        // If the sum of the valid subarray starting
        // from arr[i + 2] is greater than 0 then it
        // can be added with arr[i] and arr[i + 1]
        // to maximize the sum of the subarray
        // starting from arr[i]
        if (dp[i + 2] > 0)
            dp[i] += dp[i + 2];
    }

    // Get the sum of the even length
    // subarray with maximum sum
    int maxSum = *max_element(dp, dp + n);
    return maxSum;
}

// Driver code
int main()
{

    int arr[] = {-7, 8, -4, 5, -7, 6, -8, 9, -7, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << maxEvenLenSum(arr, n);

    return 0;
}