// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
bool isValid(int v, bool graph[101][101], int m, int V, vector<int> &color, int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && color[i] == c)
        {
            return false;
        }
    }
    return true;
}
bool DFSUtil(int v, bool graph[101][101], int m, int V, vector<int> &color)
{
    if (v == V)
    {
        return true;
    }
    for (int c = 1; c <= m; c++)
    {
        if (isValid(v, graph, m, V, color, c))
        {
            color[v] = c;
            if (DFSUtil(v + 1, graph, m, V, color) == true)
            {
                return true;
            }

            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<bool> visited(V, false);
    vector<int> Color(V + 1, 0);
    return (DFSUtil(0, graph, m, V, Color));
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends