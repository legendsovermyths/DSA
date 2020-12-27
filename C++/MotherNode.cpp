// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * g[]: graph representation
 */

void dfsUtil(int u, vector<bool> &visited, vector<int> adj[])
{
    visited[u] = true;

    for (auto v : adj[u])
        if (!visited[v])
            dfsUtil(v, visited, adj);
}

int findMother(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    int v = 0;
    // track the last visited vertex.
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            dfsUtil(i, visited, adj);
            v = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    // starting from vertex v visit the whole graph
    dfsUtil(v, visited, adj);
    // if any vertex is unvisited then the node v is not mother vertex
    // so on mother vertex is present
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return -1;

    return v;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int num, edges;
        cin >> num >> edges;

        vector<int> adj[num];

        int u, v;
        while (edges--)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << findMother(num, adj) << endl;
    }

    return 0;
} // } Driver Code Ends