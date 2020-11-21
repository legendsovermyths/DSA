// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        if (SolveSudoku(grid) == true)
            printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
} // } Driver Code Ends

bool FindUnassignedLocation(int grid[N][N],
                            int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
bool isSafe(int grid[N][N], int num, int row, int col)
{
    for (int i = 0; i < 9; i++)
        if (grid[i][col] == num)
            return false;
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
    int start_R = row - row % 3;
    int start_C = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[start_R + i][start_C + j] == num)
                return false;
    return true;
}
bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
        return true;
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(grid, i, row, col))
        {
            grid[row][col] = i;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}