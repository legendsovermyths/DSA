// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
vector<vector<long long>> dp(1000, vector<long long>(1000, -1));
long long Solution(int arr[], int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i - j == 0)
        return dp[i][j] = arr[i];
    if (i - j == 1 || j - i == 1)
        return dp[i][j] = max(arr[i], arr[j]);
    int ans = max(arr[i] + min(Solution(arr, i + 2, j), Solution(arr, i + 1, j - 1)), arr[j] + min(Solution(arr, i + 1, j - 1), Solution(arr, i, j - 2)));
    return dp[i][j] = ans;
}
long long maximumAmount(int arr[], int n)
{
    int i = 0, j = n - 1;
    return Solution(arr, i, j);
}
// long long maximumAmount(int arr[], int n)
// {
//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     for (int i = 0; i < n; i++)
//     {
//         dp[i][i] = arr[i];
//     }
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < n - i; j++)
//         {
//             int k = j + i;
//             if (j + 1 == k)
//                 dp[j][k] = max(arr[j], arr[k]);
//             else
//                 dp[j][k] = max(arr[j] + min(dp[j + 2][k], dp[j + 1][k - 1]), arr[k] + min(dp[j][k - 2], dp[j + 1][k - 1]));
//         }
//     }
//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int j = 0; j < n; j++)
//     //     {
//     //         cout << dp[i][j] << ' ';
//     //     }
//     //     cout << endl;
//     // }
//     return dp[0][n - 1];
// }
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