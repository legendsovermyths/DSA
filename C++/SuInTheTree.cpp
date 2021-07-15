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

void dfs(unordered_map<ll, vector<ll>> &graph, vector<bool> &visited, ll prevSum, ll i, vector<ll> &sum, vector<ll> &value, bool &check)
{
    visited[i] = true;
    if (sum[i] == -1)
    {
        ll mini = INT_MAX;
        for (auto j : graph[i])
        {
            if (sum[j] - prevSum < mini)
            {
                mini = sum[j] - prevSum;
            }
        }
        value[i] = mini == INT_MAX ? 0 : mini;
        prevSum = mini == INT_MAX ? prevSum : prevSum + mini;
    }
    else
    {
        value[i] = sum[i] - prevSum;
        prevSum = sum[i];
    }
    for (auto j : graph[i])
    {
        if (!visited[j])
        {
            dfs(graph, visited, prevSum, j, sum, value, check);
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    unordered_map<ll, vector<ll>> graph;
    vector<ll> value(n + 1, 0);
    Loop(i, 2, n + 1)
    {
        ll x;
        cin >> x;
        graph[x].push_back(i);
    }
    // Loop(j, 1, n + 1)
    // {
    //     cout << j << ":";
    //     for (auto k : graph[j])
    //     {
    //         cout << k << " ";
    //     }
    //     cout << endl;
    // }

    vector<ll> sum(n + 1, -1);
    Loop(i, 1, n + 1)
    {
        cin >> sum[i];
    }
    value[1] = sum[1];
    vector<bool> visited(n + 1, false);
    bool check = false;
    dfs(graph, visited, 0, 1, sum, value, check);
    ll answer = 0;
    Loop(i, 1, n + 1)
    {
        if (value[i] < 0)
        {
            cout << -1 << endl;
            return 0;
        }
        answer += value[i];
    }

    cout << answer << endl;
    return 0;
}