#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
bool isValid(vector<vector<int>> &vact, int i, int j, vector<vector<bool>> &vis)
{
    int row = vact.size();
    int cols = vact[0].size();
    return i >= 0 && j >= 0 && i < row && j < cols && vact[i][j] == 1 && !vis[i][j];
}
int SolutionUtil(vector<int> &length, vector<vector<int>> &vact, vector<vector<bool>> &vis, int i, int j, int x, int y, int steps, int move_i[], int move_j[])
{
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
    cout << "steps: " << steps << endl;
    if (x == i && y == j)
    {
        for (int i = 0; i < vis.size(); i++)
        {
            for (int j = 0; j < vis[0].size(); j++)
            {
                cout << vis[i][j] << " ";
            }
            cout << "\n";
        }
        return 1;
    }
    for (int k = 0; k < 4; k++)
    {
        int next_i = i + move_i[k];
        int next_j = j + move_j[k];
        if (isValid(vact, next_i, next_j, vis))
        {
            vis[next_i][next_j] = true;
            int next_step = steps + 1;
            if (SolutionUtil(length, vact, vis, next_i, next_j, x, y, next_step, move_i, move_j) == 1)
            {
                vis[next_i][next_j] = false;
            }
            else
            {

                vis[next_i][next_j] = false;
            }
        }
    }
    return 0;
}
int Solution(vector<vector<int>> &vact, vector<vector<bool>> &vis, int i, int j, int x, int y, vector<int> &length)
{
    int steps = 0;
    vis[i][j] = 1;
    int move_i[] = {0, 0, -1, 1};
    int move_j[] = {1, -1, 0, 0};
    if (SolutionUtil(length, vact, vis, i, j, x, y, steps, move_i, move_j) == 1)
    {

        // for (int i = 0; i < vis.size(); i++)
        // {
        //     for (int j = 0; j < vis[0].size(); j++)
        //     {
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
    else
    {
        cout << "No path Possible" << endl;
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> vact(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> vact[i][j];
            }
        }
        int x, y;
        cin >> x >> y;
        vector<vector<bool>> vis(rows, vector<bool>(cols, 0));
        vector<int> length;
        Solution(vact, vis, 0, 0, x, y, length);
    }
}

//1 0 0 0
//1 1 0 1
//0 1 1 1