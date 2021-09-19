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

ll Solution(vl &a, ll n, ll k)
{
    ll maxAns = -10000;

    for (ll i = max((ll)0, n - 2 * k); i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll temp = (ll)(i + 1) * (ll)(j + 1) - k * (a[i] | a[j]);
            maxAns = max(maxAns, temp);
        }
    }
    return maxAns;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    w(t)
    {
        ll n, k;
        cin >> n >> k;
        vl a(n, 0);
        loop(i, n) cin >> a[i];
        cout << Solution(a, n, k) << endl;
    }
}