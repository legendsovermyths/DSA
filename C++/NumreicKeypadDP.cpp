// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long getCount(int N)
    {
        vector<int> x_steps = {1, -1, 0, 0, 0};
        vector<int> y_steps = {0, 0, 1, -1, 0};
        vector<vector<long long>> dp(10, vector<long long>(N + 1, 0));
        vector<vector<int>>
            Matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
        for (int i = 0; i < 10; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        long long total = 0;
        for (int k = 2; k <= N; k++)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int m = 0; m < 5; m++)
                    {
                        int new_row = i + x_steps[m];
                        int new_col = j + y_steps[m];
                        if (new_col >= 0 && new_row >= 0 && new_col < 3 && new_row < 4 && Matrix[new_row][new_col] != -1 && Matrix[i][j] != -1)
                        {
                            dp[Matrix[i][j]][k] += dp[Matrix[new_row][new_col]][k - 1];
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            total += dp[i][N];
        }
        return total;
    }
};

// { Driver Code Starts.
int main()
{

    int n = 4;

    Solution ob;
    cout << ob.getCount(n) << "\n";

    return 0;
}
// } Driver Code Ends