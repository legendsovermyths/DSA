// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph

*/
void DFS2(int v, vector<bool> &visited, vector<int> &toReturn, vector<int> g[])
{
    visited[v] = true;
    toReturn.push_back(v);
    for (int i = 0; i < g[v].size(); i++)
    {
        if (visited[g[v][i]] == false)
        {
            DFS2(g[v][i], visited, toReturn, g);
        }
    }
}

vector<int> dfs(vector<int> g[], int N)
{
    vector<int> toReturn;
    vector<bool> visited(N, false);
    DFS2(0, visited, toReturn, g);
    return toReturn;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        int N, E;
        cin >> N >> E;

        vector<int> g[N];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> res = dfs(g, N);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends