// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            dp[0][i] = Matrix[0][i];
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (j > 0 && j < N - 1)
                {
                    dp[i][j] = Matrix[i][j] + max(dp[i - 1][j - 1], max(dp[i - 1][j + 1], dp[i - 1][j]));
                }
                else if (j == 0)
                {
                    dp[i][j] = Matrix[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j]);
                }
                else if (j == N - 1)
                {
                    dp[i][j] = Matrix[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < N; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return *max_element(dp[N - 1].begin(), dp[N - 1].end());
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
} // } Driver Code Ends