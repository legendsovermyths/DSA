// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int *, int *, int);

// Driver code to test above methods
int main()
{
    // size of square board
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int N = 6;
    int a, b, c, d;
    // cin >> N;
    // cin >> a >> b;
    // cin >> c >> d;
    int knightPos[] = {4, 5};
    int targetPos[] = {1, 1};
    cout << minStepToReachTarget(knightPos, targetPos, N) << endl;
    // }
    return 0;
}

bool isValid(int x, int y, int N, vector<vector<bool>> &visited)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N && !visited[x][y])
        return true;
    return false;
}
void minStepUtil(int x, int y, int targetPos[], int dx[], int dy[], int dist, vector<vector<bool>> &visited, int N, int &steps)
{
    if (targetPos[0] == x && targetPos[1] == y)
    {
        steps = dist;
    }
    for (int i = 0; i < 8; i++)
    {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (isValid(x2, y2, N, visited))
        {
            visited[x2][y2] = true;
            if (steps == -1)
                minStepUtil(x2, y2, targetPos, dx, dy, dist + 1, visited, N, steps);
        }
    }
}
int minStepToReachTarget(int knightPos[], int targetPos[], int N)
{
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int steps = -1;
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    visited[knightPos[0]][knightPos[1]] = true;
    minStepUtil(knightPos[0], knightPos[1], targetPos, dx, dy, 0, visited, N, steps);
    return steps;
}