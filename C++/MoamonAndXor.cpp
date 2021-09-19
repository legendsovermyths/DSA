#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
ll fact[N], inv[N], invfact[N];
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

int mem[N][2], vis[N][2], test_id;
int cntEven, _2pwn, n;
int dp(int i, bool equal)
{
    if (i < 0)
        return 1;
    int &rt = mem[i][equal];
    if (vis[i][equal] == test_id)
        return rt;
    vis[i][equal] = test_id;
    if (equal == false)
        return rt = mul(_2pwn, dp(i - 1, 0));
    if (n & 1)
        return rt = mul(dp(i - 1, 1), add(cntEven, 1));
    return rt = add(mul(dp(i - 1, 1), cntEven), dp(i - 1, 0));
}

int main()
{
    factInverse();
    int t;
    cin >> t;
    while (t--)
    {
        test_id++;
        int k;
        cin >> n >> k;
        cntEven = 0;
        for (int i = 0; i < n; i += 2)
            cntEven = add(cntEven, nCr(n, i));
        _2pwn = 1;
        for (int i = 0; i < n; i++)
            _2pwn = mul(_2pwn, 2);
        cout << dp(k - 1, 1) << endl;
    }
}