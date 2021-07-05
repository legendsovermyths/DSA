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

void DFS(unordered_map<int, vector<int>> &graph, int i, int &k, vector<bool> &visited)
{
    visited[i] = true;
    k += 1;
    for (auto j : graph[i])
    {
        if (!visited[j])
        {
            DFS(graph, j, k, visited);
        }
    }
}

int main()
{
    w(t)
    {
        int n, x;
        cin >> n >> x;
        unordered_map<int, vector<int>> graph;
        loop(i, n - 1)
        {
            int v, u;
            cin >> v >> u;
            if (v == u)
                continue;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (graph[x].size() == 1 || graph[x].size() == 0)
        {
            cout << "Ayush" << endl;
            continue;
        }
        int k = -1;
        vector<bool> visited(n + 1, false);
        DFS(graph, x, k, visited);
        if (k & 1)
            cout << "Ayush" << endl;
        else

            cout << "Ashish" << endl;
    }
    return 0;
}