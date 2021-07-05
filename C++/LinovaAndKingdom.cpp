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

int DFS_Child(unordered_map<int, vector<int>> &graph, vector<long long int> &children, int i, vector<int> &visited)
{
    visited[i] = true;
    if (children[i] != -1)
    {
        return children[i];
    }
    if (graph[i].size() == 1 && i != 1)
    {
        return children[i] = 0;
    }
    int childs = 0;
    for (auto j : graph[i])
    {
        if (!visited[j])
            childs += DFS_Child(graph, children, j, visited) + 1;
    }
    return children[i] = childs;
}

void DFS_Cost(unordered_map<int, vector<int>> &graph, vector<long long int> &cost, int i, vector<bool> &visited, int c)
{
    visited[i] = true;
    cost[i] = c;
    for (auto j : graph[i])
    {
        if (!visited[j])
        {
            DFS_Cost(graph, cost, j, visited, c + 1);
        }
    }
    return;
}

int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> visited(n + 1, false);
    vector<long long int> children(n + 1, -1);
    vector<long long int> Cost(n + 1, 0);
    DFS_Child(graph, children, 1, visited);
    vector<bool> visited2(n + 1, false);
    DFS_Cost(graph, Cost, 1, visited2, 1);
    vector<long long int> Answers(n, 0);
    Loop(i, 1, n + 1)
    {
        Answers[i - 1] = Cost[i] - children[i];
    }
    // loop(i, n + 1)
    // {
    //     cout << children[i] << " ";
    // }
    // cout << endl;
    // loop(i, n + 1)
    // {
    //     cout << Cost[i] << " ";
    // }
    // cout << endl;
    sortall(Answers);
    // loop(i, n)
    // {
    //     cout << Answers[i] << " ";
    // }
    // cout << endl;
    long long int answer = 0;
    Loop(i, n - 1, n - k - 1)
    {
        answer += Answers[i] - 1;
    }
    cout << answer << endl;
    return 0;
}