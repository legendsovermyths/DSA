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
    ll rb = 0, rs = 0, rc = 0;
    string s;
    cin >> s;
    loop(i, s.length())
    {
        if (s[i] == 'B')
            rb++;
        if (s[i] == 'C')
            rc++;
        if (s[i] == 'S')
            rs++;
    }
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll rubles;
    cin >> rubles;
    ll high = 10e12;
    ll low = 0;
    ll answer = 0;
    while (low <= high)
    {
        ll mid = (high + low) / 2;
        ll tb = mid * rb;
        ll ts = mid * rs;
        ll tc = mid * rc;
        tb = tb - nb;
        if (tb < 0)
            tb = 0;
        ts = ts - ns;
        if (ts < 0)
            ts = 0;
        tc = tc - nc;
        if (tc < 0)
            tc = 0;
        ll Rr = tb * pb + ts * ps + tc * pc;
        if (Rr <= rubles)
        {
            if (mid > answer)
                answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << answer << endl;
}