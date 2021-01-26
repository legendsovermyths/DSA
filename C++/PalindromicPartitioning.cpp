// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int calculateMin(vector<vector<int>> &dp, int i, int j, int count)
    {
        int min = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int temp = dp[i][k] + dp[k + 1][j];
            if (min > temp)
            {
                min = temp;
            }
        }
        return min;
    }
    int palindromicPartition(string str)
    {
        int count = str.length();
        vector<vector<int>> dp(count, vector<int>(count, 0));
        for (int i = 1; i < count; i++)
        {
            for (int j = 0; j < count - i; j++)
            {
                int n = j + i;
                if (str[n] == str[j])
                {
                    if (dp[j + 1][n - 1] == 0)
                        dp[j][n] = 0;
                    else
                        dp[j][n] = calculateMin(dp, j, n, count) + 1;
                }
                else
                {
                    dp[j][n] = calculateMin(dp, j, n, count) + 1;
                }
            }
        }
        // for (int i = 0; i < count; i++)
        // {
        //     for (int j = 0; j < count; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[0][count - 1];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
//O(n^3)