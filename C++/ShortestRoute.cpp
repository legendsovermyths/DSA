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
    w(T)
    {
        ll N, P;
        cin >> N >> P;
        vl vec(N, 0);
        vl Pass(P, 0);
        loop(i, N)
        {
            cin >> vec[i];
        }
        loop(i, P)
        {
            cin >> Pass[i];
        }
        vl right(N, INT_MAX);
        ll count = INT_MAX;
        loop(i, N)
        {
            if (vec[i] == 1)
            {
                count = 0;
                right[i] = 0;
                count++;
            }
            else if (count != INT_MAX)
            {
                right[i] = count;
                count++;
            }
        }
        count = INT_MAX;
        vl left(N, INT_MAX);
        Loop(i, N - 1, -1)
        {
            if (vec[i] == 2)
            {
                count = 0;
                left[i] = count;
                count++;
            }
            else if (count != INT_MAX)
            {
                left[i] = count;
                count++;
            }
        }
        loop(i, P)
        {
            ll mini = min(left[Pass[i] - 1], right[Pass[i] - 1]);
            if (Pass[i] - 1 == 0)
            {
                cout << 0 << ' ';
            }
            else if (mini != INT_MAX)
            {
                cout << mini << " ";
            }
            else
            {
                cout << -1 << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}