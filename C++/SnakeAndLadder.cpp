#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> g[36];
        for (int i = 0; i < 30; i++)
        {
            for (int j = 1; j <= 6; j++)
            {
                g[i].push_back(i + j);
            }
        }
        int SnakesAndLadded;
        cin >> SnakesAndLadded;
        for (int i = 0; i < SnakesAndLadded; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u - 1] = g[v - 1];
        }
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                std::cout << g[i][j] << " ";
            }
            cout << endl;
        }
        queue<int> q;
        int s = 0;
        vector<int> d(36, INT8_MAX);
        d[0] = 0;
        vector<bool> visited(36, false);

        visited[0] = true;
        q.push(s);
        bool checker = false;
        while (!q.empty() && !checker)
        {
            s = q.front();
            q.pop();
            for (int i = 0; i < g[s].size(); i++)
            {
                if (!visited[g[s][i]])
                {
                    visited[g[s][i]] = true;
                    d[g[s][i]] = d[s] + 1;

                    q.push(g[s][i]);
                    if (g[s][i] == 29)
                    {
                        cout << d[g[s][i]] << endl;
                        checker = true;
                    }
                }
            }
        }
        for (int i = 0; i < d.size(); i++)
        {
            std::cout << d[i] << " ";
        }
    }
    return 0;
}