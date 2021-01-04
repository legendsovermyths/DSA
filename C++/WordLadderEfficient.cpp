#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool isValid(string s1, string s2)
{
    int count = 0;
    int len = s1.length();
    for (int i = 0; i < len; i++)
    {
        if (s1[i] == s2[i])
        {
            count = count + 1;
        }
    }
    return count + 1 == len;
}
int main()
{
    vector<string> wordList = {"a", "a", "b", "c"};
    vector<int> g[wordList.size() + 1];
    for (int i = 0; i < wordList.size(); i++)
    {
        for (int j = 0; j < wordList.size(); j++)
        {
            if (isValid(wordList[i], wordList[j]))
            {
                g[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < wordList.size(); i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    int dest = 3;
    vector<int> dis(wordList.size(), INT8_MAX);
    dis[0] = 0;
    vector<bool> visited(wordList.size(), false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    int s = q.front();
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        for (int i = 0; i < g[s].size(); i++)
        {
            if (!visited[g[s][i]])
            {
                visited[g[s][i]] = true;
                dis[g[s][i]] = dis[s] + 1;
                q.push(g[s][i]);
                if (g[s][i] == dest)
                {
                    cout << dis[g[s][i]] + 1 << " ";
                    return dis[g[s][i]];
                }
            }
        }
    }
    for (int i = 0; i < dis.size(); i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}