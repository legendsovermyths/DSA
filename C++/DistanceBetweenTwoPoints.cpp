// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
int countPaths(list<int> g[], int V, int s, int d);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        int u, v;
        list<int> *adj = new list<int>[N + 1];
        while (M--)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int s, e;
        cin >> s >> e;
        cout << countPaths(adj, N, s, e) << endl;
    }
    return 0;
} // } Driver Code Ends

// The Graph structure is as folows
/*
g : Adjacency list of the graph
s : source node
d : destination node
V : number of vertices
*/

// Function to find paths between 2 nodes

void SolutionUtil(int &paths, int v, int s, int d, vector<bool> &visited, list<int> g[])
{
    if (v == d)
    {
        paths = paths + 1;
        return;
    }
    for (int x : g[v])
    {
        if (!visited[x])
        {
            visited[x] = true;
            SolutionUtil(paths, x, s, d, visited, g);
            visited[x] = false;
        }
    }
}
int countPaths(list<int> g[], int V, int s, int d)
{
    vector<bool> visited(V, false);
    int paths = 0;
    SolutionUtil(paths, s, s, d, visited, g);
    return paths;
}