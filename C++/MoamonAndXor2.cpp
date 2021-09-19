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
#define N 200001
typedef vector<int> vi;
typedef vector<ll> vl;

/*------------------------------------Combinatorics Functions----------------------------------*/

ll fact[N], inv[N], invfact[N];

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

void factInverse()
{
    fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
    for (long long i = 2; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
        invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
    }
}

int add(int a, int b)
{
    if ((a += b) >= MOD)
        a -= MOD;
    else if (a < 0)
        a += MOD;
    return a;
}

ll mul(int x, int y)
{
    return (1LL * x * y) % MOD;
}

ll nCr(int n, int r)
{
    if (r > n)
        return 0;
    return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}
/*-------------------------------------------------End Template----------------------------------------*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    w(t)
    {
        ll n, k;
        cin >> n >> k;
        if (n & 1)
        {
            ll res = power(2, n - 1) + 1;
            res = power(res, k);
            cout << res % MOD << endl;
        }
        else
        {
            vl dp(k + 1, 0);
            dp[0] = 1;
            ll n_2 = power(2, n), n1_2 = power(2, n - 1);
            Loop(i, 1, k + 1)
            {
                dp[i] = power(n_2, i - 1) % MOD + (n1_2 - 1) % MOD * (dp[i - 1]) % MOD;
                dp[i] = dp[i] % MOD;
            }
            cout << dp[k] << endl;
        }
    }
}