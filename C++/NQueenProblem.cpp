#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<int>> &board, int i, int j, int row, int col)
{
    for (int start = col - 1; start >= 0; start--)
    {

        if (board[i][start] == 1)
        {
            return false;
        }
    }
    for (int start_i = i, start_j = j; start_i >= 0 && start_j >= 0; start_i--, start_j--)
    {

        if (board[start_i][start_j] == 1)
        {
            return false;
        }
    }
    for (int start_i = i, start_j = j; start_i < row && start_j >= 0; start_i++, start_j--)
    {

        if (board[start_i][start_j] == 1)
        {
            return false;
        }
    }

    return true;
}
void SolutionUtil(int i, int j, int col, int row, vector<vector<int>> &board, int &count)
{
    if (j == col)
    {
        count = count + 1;
        cout << count << "-" << endl;
        for (int n = 0; n < row; n++)
        {
            for (int m = 0; m < col; m++)
            {
                cout << board[n][m] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int k = 0; k < row; k++)
    {
        if (isValid(board, k, j, row, col))
        {
            board[k][j] = 1;
            SolutionUtil(k, j + 1, col, row, board, count);
            board[k][j] = 0;
        }
    }
}
void Solution(int row, int col, vector<vector<int>> &board)
{
    int count = 1;
    SolutionUtil(0, 0, col, row, board, count);
    return;
}
int main()
{
    vector<vector<int>> board(5, vector<int>(5, 0));
    Solution(5, 5, board);
}
