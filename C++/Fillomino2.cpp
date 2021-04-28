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
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(int m, vi &vec)
{
    int i = m - 1, j = m - 1;
    int t = m - 1;
    vector<vector<int>> dp(m, vector<int>(m, 0));
    int k = 1;
    while (k <= m)
    {
        i = m - k;
        j = m - k;
        t = m - k;
        int n = vec[t];
        if (dp[i][j] == 0)
        {
            dp[i][j] = vec[t];
            n--;
        }
        while (n > 0)
        {
            if (i < m - 1 && dp[i + 1][j] == 0)
            {
                dp[i + 1][j] = vec[t];
                n--;
                i++;
            }
            else if (j > 0 && dp[i][j - 1] == 0)
            {
                dp[i][j - 1] = vec[t];
                n--;
                j--;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        k++;
    }
    loop(i, m)
    {
        loop(j, i + 1)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vi vec(n, 0);
    loop(i, n)
    {
        cin >> vec[i];
    }
    solve(n, vec);
}