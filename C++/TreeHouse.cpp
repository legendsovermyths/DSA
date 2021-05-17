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

unordered_map<ll, ll> umap;

bool sort2(ll i, ll j)
{
    return (umap[i] > umap[j]);
}
void Calc(ll X, ll i, map<ll, vector<ll>> &graph, vector<bool> &visited, ll &answer)
{
    visited[i] = true;
    answer = (answer + (ll)(X % mod)) % mod;
    for (ll j = 0; j < graph[i].size(); j++)
    {
        if (!visited[graph[i][j]])
        {
            Calc(X * (j + 1), graph[i][j], graph, visited, answer);
        }
    }
}

void solve()
{
    ll N, X;
    cin >> N >> X;
    map<ll, vector<ll>> graph;
    for (ll i = 0; i < N - 1; i++)
    {
        ll nod1, nod2;
        cin >> nod1 >> nod2;
        graph[nod1].push_back(nod2);
        umap[nod1]++;
    }

    itr(it, graph)
    {
        sort(it->second.begin(), it->second.end(), sort2);
    }
    ll answer = 0;
    vector<bool> visited(N + 1, false);
    Calc(X, 1, graph, visited, answer);
    cout << answer << endl;
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