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
    vector<int> arr = {2, 6, 8, 1, 4};
    int MinSoFar = 100000;
    int ans = 100000;
    for (int i = 0; i < arr.size(); i++)
    {
        MinSoFar = min(arr[i], MinSoFar + arr[i]);
        if (MinSoFar < ans)
        {
            ans = MinSoFar;
        }
    }
    cout << ans << endl;
    return 0;
}