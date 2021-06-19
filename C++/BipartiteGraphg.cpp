// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> Color(V, -1);
        queue<int> q;

        int currentColor;
        vector<int> visited(V, 0);
        for (int j = 0; j < V; j++)
        {
            if (Color[j] == -1)
            {
                q.push(j);
                Color[j] = 0;
                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    currentColor = Color[curr];
                    for (auto i : adj[curr])
                    {
                        if (!visited[i])
                        {
                            q.push(i);
                            Color[i] = currentColor xor 1;
                            visited[i] = true;
                        }
                        else if (visited[i])
                        {
                            if (Color[i] == currentColor)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends