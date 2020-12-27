// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<int> g[], int N);

int main()
{
    // int T;
    // cin >> T;
    // while (T--) {
    int N = 5, E = 4;
    // cin >> N >> E;
    vector<int> adj[N];
    // 0 1 0 2 0 3 2 4
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[2].push_back(4);
    // for (int i = 0; i < E; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    // }
    vector<int> res = bfs(adj, N);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    // }
} // } Driver Code Ends

/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector<int> bfs(vector<int> g[], int N)
{
    vector<bool> visited(N, false);
    vector<int> level;
    queue<int> q;
    q.push(0);
    int s = 0;
    level.push_back(0);
    visited[s] = true;
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        for (int i = 0; i < g[s].size(); i++)
        {
            if (visited[g[s][i]] == false)
            {
                level.push_back(g[s][i]);
                q.push(g[s][i]);
                visited[g[s][i]] = true;
            }
        }
    }
    return level;
}