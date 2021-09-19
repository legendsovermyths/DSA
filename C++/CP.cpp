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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    w(t)
    {
        int n;
        cin >> n;
        vi odd(n, 0), even(n, 0);
        int end = 2 * n, res = INT_MAX;
        loop(i, n) cin >> odd[i];
        loop(i, n) cin >> even[i];
        unordered_map<int, int> umap;
        loop(i, n) umap[even[i]] = i;
        loop(i, n)
        {
            int temp = odd[i], tempEnd = end;
            for (int j = temp + 1; j <= tempEnd; j += 2)
            {
                if (j < end)
                    end = j;
                res = min(res, i + umap[j]);
            }
        }
        cout << res << endl;
    }
    return 0;
}