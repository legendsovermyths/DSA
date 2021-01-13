#include <bits/stdc++.h>
using namespace std;
int Solution(vector<vector<int>> arr, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = arr[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int temp1 = 0, temp2 = 0, temp3 = 0;
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j - 1 >= 0 && i - 1 >= 0)
            {
                temp1 = dp[i - 1][j - 1] + arr[i][j];
            }
            else
                temp1 = 0;
            if (j - 1 >= 0)
            {
                temp2 = dp[i][j - 1] + arr[i][j];
            }
            else
                temp2 = 0;
            if (j - 1 >= 0 && i + 1 < n)
            {
                temp3 = dp[i + 1][j - 1] + arr[i][j];
            }
            else
                temp3 = 0;
            dp[i][j] = max(temp1, max(temp2, temp3));
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
int main()
{
    vector<vector<int>> arr = {{1, 3, 1, 5},
                               {2, 2, 4, 1},
                               {5, 0, 2, 3},
                               {0, 6, 1, 2}};
    int n = 4;
    int m = 4;
    Solution(arr, n, m);
}