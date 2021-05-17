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
    unordered_map<int, int> umap;
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int t;
        cin >> t;
        umap[t]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (umap[i] == 0)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}