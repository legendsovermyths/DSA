#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void printSolution(vector<vector<int>> &M, int N1, int N2)
{
    for (int x = 0; x < N1; x++)
    {
        for (int y = 0; y < N2; y++)
            cout << setw(2) << M[x][y] << " ";
        cout << endl;
    }
}
bool isValid(int i, int j, vector<vector<int>> &M, int N1, int N2)
{
    return (i < N1 && j < N2 && i >= 0 && j >= 0 && M[i][j] == -1);
}
int solutionUtil(int i, int j, vector<vector<int>> &M, int N1, int N2, int xMove[], int yMove[], int moves)
{
    int k, next_x, next_y;
    if (moves == N1 * N2)
        return 1;
    for (int k = 0; k < 8; k++)
    {
        next_x = i + xMove[k];
        next_y = j + yMove[k];
        if (isValid(next_x, next_y, M, N1, N2))
        {
            M[next_x][next_y] = moves;

            if (solutionUtil(next_x, next_y, M, N1, N2, xMove, yMove, moves + 1) == 1)
            {

                return 1;
            }
            else
            {
                M[next_x][next_y] = -1;
            }
        }
    }
    return 0;
}
void solution(int i, int j, vector<vector<int>> &M, int N1, int N2)
{
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    if (solutionUtil(i, j, M, N1, N2, xMove, yMove, 1) == 0)
    {
        cout << "soltion does not exist";
    }
    else
    {
        printSolution(M, N1, N2);
    }
}

int main()
{
    int m = 8, n = 8;
    vector<vector<int>> vec(n, vector<int>(m, -1));
    vec[0][0] = 0;
    solution(0, 0, vec, 8, 8);
};