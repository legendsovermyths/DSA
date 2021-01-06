// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool isValid(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        return i < n && j < m && i >= 0 && j >= 0 && grid[i][j] == '1' && !visited[i][j];
    }
    void solution(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<char>> &grid, int disc_x[], int dis_y[])
    {
        if (i == n && j == m)
        {
            return;
        }
        for (int k = 0; k < 8; k++)
        {
            int x = i + disc_x[k];
            int y = j + dis_y[k];
            if (isValid(x, y, n, m, visited, grid))
            {
                visited[x][y] = true;
                solution(x, y, n, m, visited, grid, disc_x, dis_y);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int disc_x[] = {1, -1, 0, 0, 1, -1, 1, -1};
        int dis_y[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isValid(i, j, n, m, visited, grid))

                {
                    visited[i][j] = true;
                    solution(i, j, n, m, visited, grid, disc_x, dis_y);
                    count++;
                }
            }
        }
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends