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
#define mod 1000000007
typedef vector<int> vi;
typedef vector<ll> vl;

bool sort2(pair<ll, int> p1, pair<ll, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    w(t)
    {
        ll n, m, x;
        cin >> n >> m >> x;
        vector<pair<ll, int>> dp;
        loop(i, n)
        {
            pair<ll, int> p;
            cin >> p.first;
            p.second = i + 1;
            dp.push_back(p);
        }
        sort(all(dp), sort2);
        vl sum(m, 0);
        ll k = 0;
        ll maxi = -1, mini = INT_MAX;
        map<int, int> umap;
        loop(i, n)
        {
            sum[k % m] += dp[i].first;
            umap[dp[i].second] = k % m + 1;
            if (sum[k % m] > maxi)
                maxi = sum[k % m];
            k++;
        }
        loop(i, m)
        {
            if (sum[i] < mini)
            {
                mini = sum[i];
            }
        }
        if (maxi - mini > x)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            loop(i, n)
            {
                cout << umap[i + 1] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}