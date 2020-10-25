#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> seq(n);
    int sum = 0;
    for (auto &x : seq)
    {
        cin >> x;
        sum += x;
    }
    if (sum % 3 != 0)
    {
        cout << "0";
        return;
    }
    int m = sum / 3;
    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(m + 1, vector<bool>(m + 1, 0)));
    //bool[n+1][m+1][m+1] with all values 0
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= m; k++)
            {
                dp[i + 1][j][k] = dp[i][j][k];
                if (j >= seq[i])
                {
                    dp[i + 1][j][k] = dp[i + 1][j][k] | dp[i][j - seq[i]][k];
                }
                if (k >= seq[i])
                {
                    dp[i + 1][j][k] = dp[i + 1][j][k] | dp[i][j][k - seq[i]];
                }
            }
        }
    }
    cout << dp[n][m][m];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
