// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> x_moves = {1, -1, 0, 0};
    vector<int> y_moves = {0, 0, -1, 1};
    void check(vector<vector<int>> &grid, int i, int j, int n, int m, int currGen, queue<vector<int>> &q)
    {
        for (int k = 0; k < 4; k++)
        {
            int new_x = i + x_moves[k];
            int new_y = j + y_moves[k];
            if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && grid[new_x][new_y] == 1)
            {
                grid[new_x][new_y] = 2;
                q.push({new_x, new_y, currGen + 1});
            }
        }
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        int maxi = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j, 0});
                }
            }
        }
        while (!q.empty())
        {
            vector<int> temp = q.front();
            q.pop();
            maxi = max(maxi, temp[2]);
            check(grid, temp[0], temp[1], n, m, temp[2], q);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main()
{

    int n = 3, m = 3;
    vector<vector<int>> grid = {{0, 1, 2},
                                {0, 1, 2},
                                {2, 1, 1}};

    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout << ans << "\n";

    return 0;
} // } Driver Code Ends