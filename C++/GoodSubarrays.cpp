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
        ll n;
        cin >> n;
        vector<char> arr(n);
        loop(i, n)
        {
            cin >> arr[i];
        }
        map<ll, ll> hash;
        ll sum = 0;
        hash[0] = 1;
        loop(i, n)
        {
            sum = sum - arr[i] + '0' + 1;
            hash[sum]++;
        }
        ll answer = 0;
        itr(it, hash)
        {
            // cout << it->first << ":" << it->second << " ";
            // cout << endl;
            if (it->second >= 2)
            {
                ll temp = it->second;
                answer += ((temp * (temp - 1)) / 2);
            }
        }
        cout << answer << endl;
    }
}