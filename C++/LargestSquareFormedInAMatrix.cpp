// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                {
                    if (mat[i][j] == 1)
                    {
                        dp[i][j] = 1;
                    }
                }
                else if (mat[i][j] == 0)
                {
                    dp[i][j] = 0; //min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                }
                else if (mat[i][j] != 0)
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        int maxElement = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < n; i++)
        {
            int temp = *max_element(dp[i].begin(), dp[i].end());
            if (temp > maxElement)
            {
                maxElement = temp;
            }
        }

        return maxElement;
    }
};
//5 6
//0 1 0 1 0 1
//1 0 1 0 1 0
//0 1 1 1 1 0
//0 0 1 1 1 0
//1 1 1 1 1 1
// { Driver Code Starts.
// 4 19
// 0 0 1 0 1 1 1 1 1 0 1 1 1 0 1 1 0 1 1
// 1 1 1 1 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0
// 1 0 1 1 0 1 0 1 1 0 0 1 1 1 0 0 1 0 0
// 1 1 1 1 1 0 0 1 0 0 1 1 0 0 0 0 0 0 1

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
} // } Driver Code Ends