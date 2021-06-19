// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = M[0][i];
        }
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = M[i][0];
        }
        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (M[i][j] == 1)
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    if (dp[i][j] > maxi)
                    {
                        maxi = dp[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends