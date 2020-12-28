#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<bool>> &visited, int x, int y, int X, int Y)
{
    return x >= 0 && y >= 0 && x < X && y < Y && !visited[x][y];
}
void SolveUtil(int x, int y, int dx[], int dy[], int X, int Y, vector<vector<int>> &board, vector<vector<bool>> &visted, int newColor, int PrevColor)
{
    int cache = board[x][y];
    if (board[x][y] != PrevColor)
    {
        return;
    }
    if (board[x][y] == PrevColor)
    {
        board[x][y] = newColor;
    }
    int x2, y2;
    for (int i = 0; i < 4; i++)
    {
        x2 = x + dx[i];
        y2 = y + dy[i];
        if (isValid(visted, x2, y2, X, Y))
        {
            visted[x2][y2] = true;
            PrevColor = cache;

            SolveUtil(x2, y2, dx, dy, X, Y, board, visted, newColor, PrevColor);
        }
    }
}
void Solve(vector<vector<int>> &board, int newColor, int x, int y, int X, int Y)
{
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    vector<vector<bool>> visted(X, vector<bool>(Y, false));
    SolveUtil(x, y, dx, dy, X, Y, board, visted, newColor, board[x][y]);
    for (int j = 0; j < X; j++)
    {
        for (int n = 0; n < Y; n++)
        {
            cout << board[j][n] << ' ';
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> board(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> board[i][j];
            }
        }

        int x, y;
        cin >> x >> y;

        int newColor;
        cin >> newColor;

        Solve(board, newColor, x, y, rows, cols);
        cout << endl;
    }
}