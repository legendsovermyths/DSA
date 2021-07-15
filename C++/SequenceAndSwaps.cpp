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

bool checkSorted(vector<int> v)
{
    vi arr = v;
    sortall(arr);
    loop(i, arr.size())
    {
        if (v[i] != arr[i])
            return false;
    }
    return true;
}

void solution()
{
    int n, x;
    cin >> n >> x;
    int swaps = 0;
    vi v(n, 0);
    loop(i, n) cin >> v[i];
    if (checkSorted(v))
    {
        cout << 0 << endl;
        return;
    }
    loop(i, n)
    {
        if (x < v[i])
        {
            int t = x;
            x = v[i];
            v[i] = t;
            swaps++;
            if (checkSorted(v))
            {
                cout << swaps << endl;
                return;
            }
        }
    }
    int prec = v[0];
    loop(i, n)
    {
        if (prec > v[i])
        {
            cout << -1 << "\n";
            return;
        }
        prec = v[i];
    }
    cout << swaps << endl;
    return;
}
int main()
{
    w(t)
    {
        solution();
    }
}