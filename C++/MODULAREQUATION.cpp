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

int main()
{
    w(T)
    {
        ll n, m;
        cin >> n >> m;
        ll counter = 0;
        vi dp(n + 1, 1);
        Loop(i, 2, n + 1)
        {
            ll s = m % i;
            counter += dp[s];
            for (ll j = s; j <= n; j = j + i)
            {
                dp[j] += 1;
            }
        }
        cout << counter << endl;
    }
}