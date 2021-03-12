#include <bits/stdc++.h>
using namespace std;
int Kodane(int i, int j, vector<int> vec)
{
    int maxSum = INT_MIN, maxTillHere = 0;
    for (int k = i; k < j; k++)
    {
        maxTillHere = maxTillHere + vec[k];
        if (maxTillHere > maxSum)
        {
            maxSum = maxTillHere;
        }
        if (maxTillHere < 0)
        {
            maxTillHere = 0;
        }
    }
    return maxSum;
}
int SUM(vector<int> vec, int j, int i)
{
    int su = 0;

    for (int k = j; k <= i; k++)
    {
        su += vec[k];
    }
    return su;
}
int Soution(vector<vector<int>> &board, int row, int col)
{
    vector<int> temp(row, 0);

    int tempMax = 0, finalMax = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int n = 0; n < row; n++)
            {
                temp[n] = SUM(board[n], j, i);
            }
            tempMax = Kodane(0, row, temp);
            cout << tempMax << ' ';
            if (tempMax > finalMax)
            {
                finalMax = tempMax;
            }
        }
    }
    cout << finalMax;
    return 0;
}
int main()
{
    vector<vector<int>> vec = {{
                                   -17,
                                   -9,
                                   21,
                                   -12,
                                   10,
                                   -13,
                                   -21,
                                   4,
                               },
                               {10, 1, -16, -23, 15, 18, -15, 18},
                               {-25, 10, -2, -25, 24, 3, -8, 0},
                               {-16, -7, -22, 4, 2, -25, 13, 11},
                               {-9, 10, 24, -24, 24, -20, 8, 9},
                               {7, 17, 11, -1, 12, 23, -6, 12},
                               {11, 19, 15, 10, -3, -16, -13, 8}};
    vector<int> test = {4, -1, 8, -1, 14};
    cout << Kodane(0, 5, test) << endl;
    Soution(vec, 7, 8);
}
// 7 8
