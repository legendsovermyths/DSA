// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isPossible(bool graph[101][101], int V, int C, vector<int> color, int i)
{
    for (int j = 0; j < V; j++)
    {
        if (graph[i][j] && color[j] == C)
            return false;
    }
    return true;
}

bool dfs(int i, vector<bool> &visited, vector<int> &color, bool graph[101][101], int m, int V)
{

    if (i == V)
    {
        return true;
    }

    for (int j = 0; j < m; j++)
    {

        if (isPossible(graph, V, j, color, i))
        {
            color[i] = j;
            if (dfs(i + 1, visited, color, graph, m, V))
                return true;
            color[i] = -1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<bool> visited(V, 0);
    vector<int> color(V, -1);

    if (dfs(0, visited, color, graph, m, V))
    {
        return true;
    }
    return false;
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