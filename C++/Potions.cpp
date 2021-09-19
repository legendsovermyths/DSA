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

ll Solution(vl &a, ll n)
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll res = 0;
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            res += a[i];
            count++;
        }
        else
        {
            res += a[i];
            count++;
            pq.push(a[i]);
            if (res < 0)
            {
                int emp = pq.top();
                res -= emp;
                count--;
                pq.pop();
            }
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vl a(n);
    loop(i, n) cin >> a[i];
    cout << Solution(a, n) << endl;
}