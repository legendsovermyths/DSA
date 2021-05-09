// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int s, map<int, vector<int>> &graph, int &MI, vector<bool> &visited, vector<int> &ass)
    {
        visited[s] = true;

        if (graph[s].size() == 0)
        {
            ass[1] = s;
        }
        else
        {
            if (!visited[graph[s][0]])
            {
                MI = min(graph[s][1], MI);
                dfs(graph[s][0], graph, MI, visited, ass);
            }
        }
    }

    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        map<int, vector<int>> graph;
        vector<bool> to_check(n, true);
        vector<bool> dp(n, true);
        for (int i = 0; i < p; i++)
        {
            graph[a[i]].push_back(b[i]);
            graph[a[i]].push_back(d[i]);
            dp[b[i] - 1] = false;
            to_check[a[i] - 1] = false;
            to_check[b[i] - 1] = false;
        }
        vector<bool> visited(n, 0);
        vector<int> to_start;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == true && to_check[i] != true)
            {
                counter++;
                to_start.push_back(i + 1);
            }
        }
        vector<vector<int>> answer(counter);
        vector<int> ass(3, 0);
        int MI = 100000;
        for (int i = 0; i < counter; i++)
        {
            ass[0] = (to_start[i]);
            dfs(to_start[i], graph, MI, visited, ass);
            ass[2] = (MI);
            MI = 100000;
            answer[i] = (ass);
            ass = {0, 0, 0};
        }
        return answer;
    }
};

// { Driver Code Starts.
int main()
{

    int n = 6;
    int p = 3;
    vector<int> a = {4, 3, 2};
    vector<int> b = {3, 1, 5};
    vector<int> d = {96, 48, 6};

    Solution obj;
    vector<vector<int>> answer = obj.solve(n, p, a, b, d);
    cout << answer.size() << endl;
    for (auto i : answer)
    {
        cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }

    return 0;
} // } Driver Code Ends

// vector<int> a = {7, 5, 4, 2, 9, 3};
//     vector<int> b = {4, 9, 6, 8, 7, 1};
//     vector<int> d = {98, 72, 10, 22, 17, 66};