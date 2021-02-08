// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

long long maximumAmount(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int k = j + i;
            if (j + 1 == k)
                dp[j][k] = max(arr[j], arr[k]);
            else
                dp[j][k] = max(arr[j] + min(dp[j + 2][k], dp[j + 1][k - 1]), arr[k] + min(dp[j][k - 2], dp[j + 1][k - 1]));
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    return dp[0][n - 1];
}

// { Driver Code Starts.

int main()
{

    //taking total testcases
    int T;
    cin >> T;
    while (T--)
    {
        //taking number of elements
        int N;
        cin >> N;

        int A[N];

        //inserting the elements
        for (int i = 0; i < N; i++)
            cin >> A[i];

        //calling function maximumAmount()
        cout << maximumAmount(A, N) << endl;
    }
    return 0;
} // } Driver Code Ends