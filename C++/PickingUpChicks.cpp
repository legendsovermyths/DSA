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
#define mod 1000000007
typedef vector<int> vi;
typedef vector<ll> vl;
int k = 1;
int main()
{
    w(t)
    {
        ll N, K, B, T;
        cin >> N >> K >> B >> T;
        vi chicks(N, 0);
        vi vel(N, 0);
        loop(i, N)
        {
            cin >> chicks[i];
        }
        loop(i, N)
        {
            cin >> vel[i];
        }
        ll count = 0, not_possible = 0, time = 0;
        Loop(i, N - 1, -1)
        {
            ll distance_req = B - chicks[i];
            ll ditance = vel[i] * T;
            if (ditance >= distance_req)
            {
                if (not_possible > 0)
                    time += not_possible;
                count++;
            }
            else
            {
                not_possible++;
            }
            if (count >= K)
            {
                break;
            }
        }
        if (count < K)
        {
            cout << "Case #" << k << ": IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "Case #" << k << ": " << time << endl;
        }
        k++;
    }
    return 0;
}