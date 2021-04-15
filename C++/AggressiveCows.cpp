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
    w(t)
    {
        int n;
        cin >> n;
        ll cow;
        cin >> cow;
        int c = 1;
        ll ub = 10e9;
        ll lb = 1;
        vi vec(n, 0);
        loop(i, n)
                cin >>
            vec[i];
        sortall(vec);
        ll ans = 0;
        int prev = vec[0];
        while (lb <= ub)
        {
            c = 1;
            prev = vec[0];
            ll mid = (ub + lb) / 2;
            loop(i, n)
            {
                if (vec[i] - prev >= mid)
                {
                    prev = vec[i];
                    c++;
                }
            }
            if (c >= cow)
            {
                ans = mid;
                lb = mid + 1;
            }
            else
            {
                ub = mid - 1;
            }
        }
        cout << ans << endl;
    }
}