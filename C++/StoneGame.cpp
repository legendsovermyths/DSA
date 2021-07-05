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
        int n;
        cin >> n;
        vi arr(n, 0);
        loop(i, n)
        {
            cin >> arr[i];
        }
        int bigp = max_element(arr.begin(), arr.end()) - arr.begin() + 1;
        int minp = min_element(arr.begin(), arr.end()) - arr.begin() + 1;
        int l_mini = bigp > minp ? minp : bigp;
        int l_maxi = bigp <= minp ? minp : bigp;
        int r_mini = n - l_mini + 1;
        int r_maxi = n - l_maxi + 1;
        int answer = (min(l_maxi, min(r_mini, l_mini + r_maxi)));
        cout << answer << endl;
    }
} //1 4 7 2 0 5 3 4