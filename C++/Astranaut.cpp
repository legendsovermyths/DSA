#include <bits/stdc++.h>
using namespace std;

void dfs(int &count, unordered_map<int, vector<int>> umap, vector<bool> visited, int i)
{
    visited[i] = true;
    count = count + 1;
    for (auto j : umap[i])
    {
        if (!visited[j])
        {
            dfs(count, umap, visited, j);
        }
    }
}

int main()
{
    unordered_map<int, vector<int>> umap;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int v, u;
        cin >> v >> u;
        umap[u].push_back(v);
        umap[v].push_back(u);
    }
    int count = 0;
    vector<int> sets;
    vector<bool> visited(m, false);
    for (int i = 0; i < m; i++)
    {
        if (!visited[i])
        {
            dfs(count, umap, visited, i);
            sets.push_back(count);
            count = 0;
        }
    }
    long long int answer = 0;
    for (int i = 0; i < sets.size(); i++)
    {
        for (int j = i + 1; j < sets.size(); j++)
        {
            answer += sets[i] * sets[j];
        }
    }
    cout << answer << endl;
    return 0;
}