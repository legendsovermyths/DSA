// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution
{

public:
    int calc(int cost[], vector<int> &dp, int i, int N)
    {
        if (dp[i] != INT_MAX)
            return dp[i];
        if (i == 0)
            return 0;
        if (i == 1)
        {
            return dp[i] = cost[0];
        }
        if (i == 2)
        {
            return dp[i] = min(2 * cost[0], cost[1]);
        }

        int res = INT_MAX;
        for (int j = 1; j < i; j++)
        {
            res = min(res, calc(cost, dp, j, N) + calc(cost, dp, i - j, N));
            if (i <= N)
                res = min(res, cost[i - 1]);
        }
        return dp[i] = res;
    }
    int minimumCost(int cost[], int N, int W)
    {
        vector<int> dp(W + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < N; i++)
        {
            if (cost[i] == -1)
                cost[i] = 100000000;
        }
        calc(cost, dp, W, N);
        for (int i = 0; i <= W; i++)
            cout << dp[i] << " ";
        return 0;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
} // } Driver Code Ends