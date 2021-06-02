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

int dfs(ll node, ll parent, map<ll, vi> &graph)
{
    multiset<ll> answers;
    loop(i, graph[node].size())
    {
        if (graph[node][i] == parent)
            continue;

        ll answer = dfs(graph[node][i], node, graph);
        answers.insert(answer);
    }
    ll res = 1;
    ll x = 1;
    for (auto i = answers.rbegin(); i != answers.rend(); i++)
    {
        res += *i * x;
        x += 1;
    }
    return res;
}

int main()
{
    w(T)
    {
        map<ll, vi> graph;
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        loop(i, n - 1)
        {
            ll x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        ll answer = dfs(1, -1, graph) % mod;
        answer = (answer * k) % mod;
        cout << answer << endl;
    }
}