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

class cell
{
public:
    int x;
    int y;
    int dis;
    cell(int xc, int yc, int distance)
    {
        x = xc;
        y = yc;
        dis = distance;
    }
};

bool isValid(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minStepToReachTarget(int knightPos[], int targetPos[], int N)
{
    int x, y;
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    queue<cell> q;
    q.push(cell(knightPos[0], knightPos[1], 0));
    cell s = q.front();
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    visited[knightPos[0]][knightPos[1]] = true;

    while (!q.empty())
    {

        s = q.front();
        q.pop();
        if (s.x == targetPos[0] && s.y == targetPos[1])
            return s.dis;
        for (int i = 0; i < 8; i++)
        {

            x = s.x + dx[i];
            y = s.y + dy[i];

            if (isValid(x, y, N) && !visited[x][y])
            {

                visited[x][y] = true;
                q.push(cell(x, y, s.dis + 1));
            }
        }
    }
}