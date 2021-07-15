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

void Solution(int n, int &k)
{
    cout << n << ' ';
    if (n == 0)
    {
        k += 1;
        return;
    }
    loop(i, 2)
    {
        if (n < 2)
        {
            Solution(n - 1, k);
            Solution(n - 1, k);
        }

        else
        {
            Solution(n - 1, k);
            Solution(n - 1, k);
            Solution(n - 2, k);
        }
    }
}

int main()
{
    int k = 1;
    Solution(2, k);
    cout << k << endl;
}