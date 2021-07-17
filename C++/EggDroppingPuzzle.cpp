// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find minimum number of attempts needed in
    //order to find the critical floor.
    int Soln(int i, int j, vector<vector<int>> &dp, int k)
    {
        cout << i << " " << j << " " << k << endl;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (i == 1)
        {
            return dp[i][j] = j;
        }
        if (j == 0)
        {
            return dp[i][j] = 0;
        }
        if (j == 1)
        {
            return dp[i][j] = 1;
        }
        int ans = 1 + max(Soln(i - 1, j - 1, dp, k), Soln(i, k - j, dp, k));
        return dp[i][j] = ans;
    }

    int eggDrop(int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return Soln(n, k, dp, k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases

    //taking eggs and floors count
    int n = 4, k = 10;
    Solution ob;
    //calling function eggDrop()
    cout << ob.eggDrop(n, k) << endl;

    return 0;
}
// } Driver Code Ends