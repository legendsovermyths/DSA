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

ll maxEvenLenSum(vl arr, ll n)
{

    if (n < 2)
        return 0;
    ll dp[n] = {0};
    dp[n - 1] = 0;
    dp[n - 2] = arr[n - 2] + arr[n - 1];

    for (ll i = n - 3; i >= 0; i--)
    {
        dp[i] = arr[i] + arr[i + 1];
        if (dp[i + 2] > 0)
            dp[i] += dp[i + 2];
    }

    ll maxSum = *max_element(dp, dp + n);
    return maxSum;
}
int main()
{
    w(t)
    {
        ll n;
        cin >> n;
        vl vec(n, 0);
        loop(i, n)
        {
            cin >> vec[i];
            if (i % 2 == 0)
            {
                vec[i] = -vec[i];
            }
        }
        ll total = 0;
        loop(i, n)
        {
            if (i % 2 == 0)
            {
                total += vec[i];
            }
        }
        total = -total;
        ll maxEven = maxEvenLenSum(vec, n);
        total += maxEven;
        cout << total << endl;
    }
    return 0;
}