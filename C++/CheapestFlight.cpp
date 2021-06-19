#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> dp(n, INT_MAX);
    int i, j, m, cost, u, v;
    m = flights.size();
    dp[src] = 0;
    for (i = 0; i < k + 1; i++)
    {
        vector<int> temp = dp;
        for (j = 0; j < m; j++)
        {
            u = flights[j][0];
            v = flights[j][1];
            cost = flights[j][2];
            if (temp[u] == INT_MAX)
                continue;
            dp[v] = min(dp[v], cost + temp[u]);
        }
    }
    if (dp[dst] == INT_MAX)
        return -1;
    return dp[dst];
}

int main()
{
    vector<vector<int>> flights = {{0, 1, 1},
                                   {0, 2, 5},
                                   {1, 2, 1},
                                   {2, 3, 1}};
    int src = 0, dst = 3, k = 1;
    cout << findCheapestPrice(4, flights, src, dst, k) << " ";
}
// 4
// [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
// 0
// 3
// 1