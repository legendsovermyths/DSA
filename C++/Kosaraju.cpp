// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find number of strongly connected components in the graph.
    void dfs1(vector<int> adj[], int V, stack<int> &st, int i, vector<bool> &visited)
    {
        visited[i] = true;
        for (auto j : adj[i])
        {
            if (visited[j] == false)
            {
                dfs1(adj, V, st, j, visited);
            }
        }
        st.push(i);
    }

    void reverse(int V, vector<int> adj[], unordered_map<int, vector<int>> &rev)
    {
        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                rev[j].push_back(i);
            }
        }
    }

    void dfs2(int i, vector<bool> &visited, unordered_map<int, vector<int>> &rev)
    {
        visited[i] = true;
        for (auto j : rev[i])
        {
            if (!visited[j])
            {
                dfs2(j, visited, rev);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs1(adj, V, st, i, visited);
            }
        }
        unordered_map<int, vector<int>> rev;
        reverse(V, adj, rev);
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        int count = 0;
        while (!st.empty())
        {
            int curr = st.top();
            st.pop();
            if (!visited[curr])
            {
                count++;
                dfs2(curr, visited, rev);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends