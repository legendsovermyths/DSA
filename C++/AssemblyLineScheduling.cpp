#include <bits/stdc++.h>
using namespace std;
int Solution(int x[], int e[], vector<vector<int>> t, vector<vector<int>> arr, int n)
{
    arr[0][0] = arr[0][0] + e[0];
    arr[1][0] = arr[1][0] + e[1];
    vector<vector<int>> vec(2, vector<int>(n, 0));
    vec[0][0] = arr[0][0];
    vec[1][0] = arr[1][0];
    for (int j = 1; j < n; j++)
    {

        vec[0][j] = min(vec[0][j - 1] + arr[0][j], vec[1][j - 1] + arr[0][j] + t[1][j]);
        vec[1][j] = min(vec[1][j - 1] + arr[1][j], vec[0][j - 1] + arr[1][j] + t[0][j]);
    }
    vec[0][n - 1] = vec[0][n - 1] + x[0];
    vec[1][n - 1] = vec[1][n - 1] + x[1];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> arr = {{4, 5, 3, 2},
                               {2, 10, 1, 4}};
    vector<vector<int>> t = {{0, 7, 4, 5},
                             {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};
    int n = 4;
    Solution(x, e, t, arr, n);
}