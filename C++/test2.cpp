#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool isValid(vector<vector<int>> &vact, int i, int j, vector<vector<bool>> &vis)
{
    int row = vact.size();
    int cols = vact[0].size();
    return i < row && j < cols && !vis[i][j] && vact[i][j] == 1 && i >= 0 && j >= 0;
}
int main()
{

    vector<vector<int>> vact{
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1}};

    vector<vector<bool>> vis(3, vector<bool>(4, 0));
    vis[2][3] = 1;
    cout << isValid(vact, 0, 0, vis);
    cout << vis[0][0] << " " << vis[2][3];
}