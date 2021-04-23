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
    string a, b;
    cin >> a;
    cin >> b;
    unordered_map<char, int> umapa;
    unordered_map<char, int> umapb;
    unordered_map<char, int> umapc;
    int n1 = a.length(), n2 = b.length();
    loop(i, n1)
        umapa[a[i]]++;
    loop(i, n2)
        umapb[b[i]]++;
    int answer = 0;
    loop(i, n2)
    {
        if (umapa[b[i]] == 0)
        {
            cout << -1;
            return 0;
        }
        if (umapc[b[i]] == 0)
            answer = min(umapa[b[i]], umapb[b[i]]) + answer;
        umapc[b[i]] = 1;
    }
    cout << answer;
    return 0;
}