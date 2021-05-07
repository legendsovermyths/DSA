//wrong

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

void solve()
{
    bool checker = true;
    int m, n;
    cin >> n >> m;
    vector<vector<int>> dp(m);
    loop(i, m)
    {
        int k;
        cin >> k;
        loop(j, k)
        {
            int t;
            cin >> t;
            dp[i].push_back(t);
        }
    }
    int limit = 0;
    if (m % 2 == 0)
    {
        limit = m / 2;
    }
    else
    {
        limit = m / 2 + 1;
    }
    map<int, int> umap;
    vector<int> answer;
    int q = 0;
    loop(i, m)
    {
        if (umap[dp[i][q]] < limit)
        {
            umap[dp[i][q]]++;
            answer.push_back(dp[i][q]);
        }
        else
        {
            while (q < dp[i].size() && umap[dp[i][q]] >= limit)
            {
                q++;
            }
            if (q < dp[i].size())
            {
                umap[dp[i][q]]++;
                answer.push_back(dp[i][q]);
            }
            else
            {
                checker = false;
                cout << "NO" << endl;
                return;
            }
            q = 0;
        }
    }
    if (checker == true)
    {
        cout << "YES" << endl;
        loop(i, m)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    w(t)
    {
        solve();
    }
}