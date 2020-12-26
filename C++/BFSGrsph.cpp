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
    vector<int> res;
    queue<int> q;
    int s;
    vector<bool> boolean;
    for (int i = 0; i < N; i++)
    {
        boolean.push_back(false);
    }
    q.push(g[0][0]);
    boolean[0] = true;
    while (!q.empty())
    {
        s = q.front();
        res.push_back(s);
        q.pop();
        cout << "H";
        for (auto i : g[s])
        {
            cout << "k";
            if (boolean[i] == false)
            {
                boolean[i] = true;
                q.push(i);
            }
        }
        cout << "d";
    }
    return res;
}