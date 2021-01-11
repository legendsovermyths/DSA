#include <bits/stdc++.h>
using namespace std;
void Solution(int arr[], int res, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i] + 1;
    }
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = dp[0][i - 1] + arr[i] + 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1] + arr[j] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int i = 0, j = 1;
    int prev = 0;
    while (i < n)
    {
        prev = j;
        cout << j << " " << '!';
        while (j < n && dp[i][j] <= res)
        {
            j = j + 1;
        }
        cout << j << ' ' << '&';
        i = i + 1 + j - prev;
    }
    cout << j + 1 << " " << i;
}

int main()
{
    int arr[] = {3, 4, 5, 3, 2};
    int n = 5;
    int res = 6;
    Solution(arr, res, n);
}