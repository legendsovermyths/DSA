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

pair<ll, ll> calcIntersection(ll tower, ll low, ll high, ll k)
{
    pair<ll, ll> p1, p2;
    p1.first = max(low - k + 1, (ll)0);
    p1.second = high + k - 1;
    p2.first = tower;
    p2.second = tower + k - 1;
    pair<ll, ll> to_return;
    to_return.first = max(p1.first, p2.first);
    to_return.second = min(p2.second, p1.second);
    return to_return;
}
void Solution(vl a, ll n, ll k)
{
    vl up(n, 0), down(n, 0);
    up[0] = a[0];
    down[0] = a[0];
    pair<ll, ll> p = {a[0], a[0]};

    for (int i = 1; i < n - 1; i++)
    {
        p = calcIntersection(a[i], down[i - 1], up[i - 1], k);
        if (p.first > p.second)
        {

            cout << "NO" << endl;
            return;
        }
        down[i] = p.first;
        up[i] = p.second;
    }
    p.first = max(p.first - k + 1, (ll)0);
    p.second = p.second + k - 1;
    if (p.first > a[n - 1] || p.second < a[n - 1])
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    w(t)
    {
        ll n, k;
        cin >> n >> k;
        vl a(n, 0);
        loop(i, n) cin >> a[i];
        Solution(a, n, k);
    }
}