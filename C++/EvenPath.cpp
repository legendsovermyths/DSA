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

int n, q;
int r[200020], c[200020];
int labelR[200020], labelC[200020];
int a, b, x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        r[i] %= 2;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        c[i] %= 2;
    }

    labelR[0] = 0;
    labelC[0] = 0;
    for (int i = 1; i < n; i++)
    {
        labelR[i] = labelR[i - 1] + (r[i] != r[i - 1]);
        labelC[i] = labelC[i - 1] + (c[i] != c[i - 1]);
    }

    while (q--)
    {
        cin >> a >> b >> x >> y;

        a--, b--, x--, y--;

        if (labelR[a] == labelR[x] && labelC[b] == labelC[y])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}