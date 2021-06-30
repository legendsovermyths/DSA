#include <bits/stdc++.h>
using namespace std;
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define loop(k, n) for (int k = 0; k < n; k++)
#define deb(x) cout << #x << "= " << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define Loop(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define ll long long
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<ll> vl;

vector<vector<int>> dp(200, vector<int>(200, -1));
int c, k, destination;
int Solution(int n, int d)
{
    if (n < 0)
        return 0;

    if (n == 0)
    {
        if (d >= c)
            return 1;
        return 0;
    }
    if (dp[n][d] != -1)
        return dp[n][d];
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += Solution(n - i, max(d, i));
        ans %= MOD;
    }
    ans %= MOD;
    return dp[n][d] = ans;
}

int main()
{
    cin >> destination >> k >> c;
    cout << Solution(destination, 0) << endl;
}