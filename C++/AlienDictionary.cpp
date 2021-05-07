// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int i, map<int, vector<int>> &graph, string &answer, vector<bool> &visited)
    {
        visited[i] = 1;
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!visited[graph[i][j]])
            {
                dfs(graph[i][j], graph, answer, visited);
            }
        }
        char ch = i + 'a';
        answer = answer + ch;
    }
    string findOrder(string dict[], int N, int K)
    {
        map<int, vector<int>> graph;
        for (int i = 0; i < N; i++)
        {
            string w1 = dict[i];
            string w2 = dict[i + 1];
            if (w1 != w2)
            {
                for (int i = 0; i < min(w1.length(), w2.length()); i++)
                {
                    if (w1[i] != w2[i])
                    {
                        graph[w2[i] - 'a'].push_back(w1[i] - 'a');
                        break;
                    }
                }
            }
        }
        string answer = "";
        vector<bool> visited(K, 0);
        for (int i = 0; i < K; i++)
        {
            if (!visited[i])
            {
                dfs(i, graph, answer, visited);
            }
        }
        cout << answer << " ";
        return answer;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends