#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool isValid(vector<vector<int>> &vact, int i, int j, vector<vector<bool>> &vis)
{
    int row = vact.size();
    int cols = vact[0].size();
    return i >= 0 && j >= 0 && i < row && j < cols && vact[i][j] == 1 && !vis[i][j];
}

int shortestPath(vector<vector<int>> &vact, int i, int j, int x, int y, vector<vector<bool>> &vis)
{
    if (!isValid(vact, i, j, vis))
        return 9999;
    if (i == x && j == y)
        return 0;
    vis[i][j] = 1;
    int left = shortestPath(vact, i, j - 1, x, y, vis) + 1;
    int right = shortestPath(vact, i, j + 1, x, y, vis) + 1;
    int up = shortestPath(vact, i - 1, j, x, y, vis) + 1;
    int bottom = shortestPath(vact, i + 1, j, x, y, vis) + 1;
    vis[i][j] = 0;
    return min(min(left, right), min(up, bottom));
}
int main()
{
    
      for (int s = 1; s < 4; s++)
    {
        for (int i = 1; i <= numberToBeMade; i++)
        {
            cout << dpValues[s][i] << " ";
        }
        cout << "\n";
    }
    vector<vector<int>> vact{
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1}};

    vector<vector<bool>> vis(3, vector<bool>(4, 0));
    cout << shortestPath(vact, 0, 0, 2, 3, vis) << endl;
}