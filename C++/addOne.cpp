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

vector<ll> dp(2 * 100000 + 10, -1);
int Solution(ll n, ll k)
{
    if (n + k < 10)
        return dp[n + k] = 1;
    if (dp[n + k] != -1)
        return dp[n + k];
    ll elsa = 10 - n;
    ll answer = 0;
    answer = (Solution(0, k - elsa) + Solution(1, k - elsa)) % MOD;
    return dp[n + k] = answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    w(t)
    {
        ll answer = 0;
        ll n, k;
        cin >> n >> k;
        while (n > 0)
        {
            answer += Solution(n % 10, k) % MOD;
            n /= 10;
        }
        cout << answer % MOD << "\n";
    }

    return 0;
}
