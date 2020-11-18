#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

void printPath(vector<vector<bool>> &vis)
{
    static int k = 1;
    cout << k++ << "-" << endl;
    for (int i = 0; i < vis.size(); i++)
    {
        for (int j = 0; j < vis[0].size(); j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }
}
bool isValid(vector<vector<int>> &vact, int i, int j, vector<vector<bool>> &vis)
{
    int row = vact.size();
    int cols = vact[0].size();
    return i >= 0 && j >= 0 && i < row && j < cols && vact[i][j] == 1 && !vis[i][j];
}
bool SolutionUtil(vector<int> &length, vector<vector<int>> &vact, vector<vector<bool>> &vis, int i, int j, int x, int y, int steps, int move_i[], int move_j[], int cnt, vector<int> &solutions)
{
    if (x == i && y == j)
    {
        solutions.push_back(steps);
        return 1;
    }
    bool res = false;
    for (int k = 0; k < 4; k++)
    {
        int next_i = i + move_i[k];
        int next_j = j + move_j[k];
        if (isValid(vact, next_i, next_j, vis))
        {
            vis[next_i][next_j] = true;
            res = SolutionUtil(length, vact, vis, next_i, next_j, x, y, steps + 1, move_i, move_j, cnt, solutions) || res;

            vis[next_i][next_j] = false;
        }
    }
    return res;
}
void Solution(vector<vector<int>> &vact, vector<vector<bool>> &vis, int i, int j, int x, int y, vector<int> &length)
{
    vector<int> solutions;
    int min;
    int cnt = 0;
    int steps = 0;
    vis[i][j] = 1;
    int move_i[] = {0, 0, -1, 1};
    int move_j[] = {1, -1, 0, 0};
    if (SolutionUtil(length, vact, vis, i, j, x, y, steps, move_i, move_j, cnt, solutions) == 1)
    {
        min = *min_element(solutions.begin(), solutions.end());
        cout << min << endl;
    }
    else
    {
        cout << -1 << endl;
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
//1 0 0 1
//0 1 1 1