// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    int a[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout << longestSubsequence(16, a) << endl;
    return 0;
}

int longestSubsequence(int n, int a[])
{
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    dp[0][0] = a[0];
    dp[0][1] = 1;
    bool checker = false;
    for (int i = 1; i < n; i++)
    {
        checker = false;
        for (int j = 0; j < n; j++)
        {
            if (a[i] < dp[j][0])
            {
                // cout << a[i] << ' ';
                dp[j][0] = a[i];
                checker = true;
                break;
            }
            if (dp[j][0] == -1)
            {
                dp[j][0] = a[i];
                dp[j][1] = dp[j - 1][1] + 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i][1] == -1)
            return dp[i - 1][1];
    }
    return 1;
}