// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
public:
    void dfs(int k, int &count, map<int, vector<int>> graph, vector<bool> &visited, unordered_map<int, int> umap, vector<int> &nums)
    {
        visited[umap[k]] = 1;
        map<int, vector<int>>::iterator it;
        for (int i = 0; i < graph[k].size(); i++)
        {
            if (visited[umap[graph[k][i]]] == false)
            {
                count += 1;
                dfs(graph[k][i], count, graph, visited, umap, nums);
            }
        }
    }
    int minSwaps(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        unordered_map<int, int> umap;
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; i++)
        {
            umap[vec[i]] = i;
        }
        map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)

        {
            graph[nums[i]].push_back(nums[umap[nums[i]]]);
        }
        map<int, vector<int>>::iterator it;
        // for (it = graph.begin(); it != graph.end(); it++)
        // {
        //     cout << it->first << ": ";
        //     for (int i = 0; i < it->second.size(); i++)
        //     {
        //         cout << it->second[i] << " ";
        //     }
        //     cout << endl;
        // }
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[umap[nums[i]]])
            {
                dfs(nums[i], count, graph, visited, umap, nums);
            }
        }

        // cout << endl;
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends