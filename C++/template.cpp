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
#define N 200000
typedef vector<int> vi;
typedef vector<ll> vl;

/*.................Combinatorics...............*/
vl fac;
ll power(ll a, ll n)
{
    a = a % MOD;
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n = n >> 1;
    }
    return res;
}
ll modInverse(ll n)
{
    return power(n, MOD - 2);
}
void fact(ll n)
{
    fac = vl(N);
    fac[0] = 1;
    Loop(i, 1, n + 1)
        fac[i] = (fac[i - 1] * i) % MOD;
}
ll nCr(ll n, ll r)
{
    ll res = ((fac[n] * modInverse(fac[n - r])) % MOD * modInverse(fac[r])) % MOD;
    return res;
}
/*.........................end-template.................*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact(N);
    int n = 3000, r = 1000;
    cout << nCr(n, r) << endl;
    return 0;
}