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

bool Solve(ll book, vl vec, ll time, ll n)
{
    ll ttime = 0;
    loop(i, book)
    {
        ttime += vec[i];
    }
    ll right = book - 1, left = 0;
    while (right < n - 1)
    {
        if (ttime <= time)
        {
            return true;
        }
        right++;
        ttime = ttime + vec[right] - vec[left];
        left++;
    }
    if (ttime <= time)
    {
        return true;
    }
    return false;
}

int main()
{
    ll nas;
    ll books, time;
    cin >> books >> time;
    vl vec(books, 0);
    loop(i, books)
    {
        cin >> vec[i];
    }
    ll ub = books, lb = 0;
    while (lb <= ub)
    {
        ll mid = (ub + lb) / 2;
        if (Solve(mid, vec, time, books))
        {

            nas = mid;
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    cout << nas << endl;
    return 0;
}