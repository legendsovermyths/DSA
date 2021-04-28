// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(vector<bool> &visited, vector<int> adj[], int j, vector<int> &to_return)
    {
        visited[j] = true;

        for (int i = 0; i < adj[j].size(); i++)
        {
            if (!visited[adj[j][i]])
            {
                dfs(visited, adj, adj[j][i], to_return);
            }
        }
        to_return.push_back(j);
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> to_return;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(visited, adj, i, to_return);
            }
        }

        reverse(to_return.begin(), to_return.end());
        for (int i = 0; i < to_return.size(); i++)
        {
            cout << to_return[i] << " ";
        }

        return to_return;
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
} // } Driver Code Ends