// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int MinSquares(int n)
    {
        vector<vector<int>> dp(int(sqrt(n) + 1), vector<int>(n + 1, 0));
        for (int i = 1; i <= int(sqrt(n)); i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1)
                {
                    dp[i][j] = j;
                }
                else if (i * i <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - i * i], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for (int i = 0; i <= int(sqrt(n)); i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[int(sqrt(n))][n];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends