#include <iostream>
#include <vector>
using namespace std;
bool isValid(int i, int j, int M, vector<vector<int>> &board)
{
    return (i >= 0 && j >= 0 && i < M && j < M && board[i][j] == -1);
}
bool SolutionUtil(int i, int j, int count, int arr_x[], int arr_y[], vector<vector<int>> &board, int N)
{
    if (count == N * N)
    {
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
                cout << board[x][y] << " ";
            cout << endl;
        }
        return true;
    }
    bool res = false;
    for (int k = 0; k < 8; k++)
    {
        int next_i = i + arr_x[k];
        int next_j = j + arr_y[k];
        if (isValid(next_i, next_j, N, board))
        {
            board[next_i][next_j] = count;
            res = SolutionUtil(next_i, next_j, count + 1, arr_x, arr_y, board, N) || res;
            board[next_i][next_j] = -1;
        }
    }
    return false;
}
void solution(vector<vector<int>> &board, int N)
{
    board[0][0] = 1;
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    if (SolutionUtil(0, 0, 1, xMove, yMove, board, N) == true)
    {
    }
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    vector<vector<int>> vec(8, vector<int>(8, -1));
    solution(vec, 8);
}