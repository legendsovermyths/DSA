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

bool check()
{
    unordered_map<ll, int> umap;
    ll n;
    cin >> n;
    vector<ll> vec(n, 0);
    loop(i, n)
    {
        cin >> vec[i];
    }
    loop(i, n)
    {
        ll k = (i + vec[i]) % n;
        k = k < 0 ? n + k : k;
        umap[k]++;
        if (umap[k] > 1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    w(t)
    {
        if (check())
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}