#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool isValid(vector<vector<int>> &vact, int i, int j, vector<vector<bool>> &vis)
{
    int row = vact.size();
    int cols = vact[0].size();
    return vact[i][j] == 1 && i >= 0 && j >= 0 && i < row && j < cols && !vis[i][j];
}

int shortestPath(vector<vector<int>> vact, int i, int j, int x, int y, vector<vector<bool>> vis)
{
    if (!isValid(vact, i, j, vis))
        return 9999;
    if (i == x && j == y)
        return 0;
    vis[i][j] = true;
    int left = shortestPath(vact, i, j - 1, x, y, vis) + 1;
    int right = shortestPath(vact, i, j + 1, x, y, vis) + 1;
    int up = shortestPath(vact, i - 1, j, x, y, vis) + 1;
    int bottom = shortestPath(vact, i + 1, j, x, y, vis) + 1;
    vis[i][j] = false;
    return min(min(left, right), min(up, bottom));
}
int main()
{
    // int test;
    // cin >> test;
    // while (test--)
    // {
    // int rows, cols;
    // cin >> rows >> cols;
    vector<vector<int>> vact(3, vector<int>(3, 1));
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cin >> vact[i][j];
    //     }
    // }
    // int x, y;
    // cin >> x >> y;
    vector<vector<bool>> vis(3, vector<bool>(3, 0));
    int answer = shortestPath(vact, 0, 0, 2, 2, vis);
    if (answer >= 9999)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << answer << endl;
    }
    // }
}