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

void solve()
{
    int N;
    cin >> N;
    vector<pair<string, string>> dp;
    for (int i = 0; i < N; i++)
    {
        pair<string, string> name;
        cin >> name.first;
        cin >> name.second;
        dp.push_back(name);
    }
    unordered_map<string, int> umap;
    for (int i = 0; i < N; i++)
    {
        umap[dp[i].first]++;
    }
    vector<string> answer;
    loop(i, N)
    {
        if (umap[dp[i].first] > 1)
        {
            string name;
            name = dp[i].first + " " + dp[i].second;
            answer.push_back(name);
        }
        else
        {
            string name;
            name = dp[i].first;
            answer.push_back(name);
        }
    }
    loop(i, N)
    {
        cout << answer[i] << endl;
    }
    return;
}

int main()
{
    w(T)
    {
        solve();
    }
    return 0;
}