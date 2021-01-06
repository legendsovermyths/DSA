// { Driver Code Starts
//Initial funciton template for C++

#include <bits/stdc++.h>
using namespace std;

int Shape(vector<vector<char>> &, int, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<vector<char>> arr;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char ch;
                cin >> ch;
                arr[i].push_back(ch);
            }
        }

        cout << Shape(arr, n, m) << endl;
    }
} // } Driver Code Ends

//User function template for C++

// A : vector of given strings
bool isValid(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<char>> &arr)
{
    return i >= 0 && j >= 0 && i < n && j < m && !visited[i][j] && arr[i][j] == 'O';
}
void Solution(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<char>> &arr, int darr_x[], int darr_y[])
{
    if (i == n && j == m)
    {
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int x = i + darr_x[k];
        int y = j + darr_y[k];
        if (isValid(x, y, n, m, visited, arr))
        {
            arr[x][y] = 'X';
            visited[x][y] = true;
            Solution(x, y, n, m, visited, arr, darr_x, darr_y);
        }
    }
}
void SolutionUtil(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<char>> &arr, int darr_x[], int darr_y[])
{
    if (i == n && j == m)
    {
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int x = i + darr_x[k];
        int y = j + darr_y[k];
        if (isValid(x, y, n, m, visited, arr))
        {
            visited[x][y] = true;
            SolutionUtil(x, y, n, m, visited, arr, darr_x, darr_y);
        }
    }
}
int Shape(vector<vector<char>> &arr, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int darr_x[] = {1, 0, -1, 0};
    int darr_y[] = {0, 1, 0, -1};

    for (int j = 0; j < m; j++)
    {
        if (isValid(0, j, n, m, visited, arr))
        {
            visited[0][j] = true;
            SolutionUtil(0, j, n, m, visited, arr, darr_x, darr_y);
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (isValid(n - 1, j, n, m, visited, arr))
        {
            visited[n - 1][j] = true;
            SolutionUtil(n - 1, j, n, m, visited, arr, darr_x, darr_y);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (isValid(i, 0, n, m, visited, arr))
        {
            visited[i][0] = true;
            SolutionUtil(i, 0, n, m, visited, arr, darr_x, darr_y);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (isValid(i, m - 1, n, m, visited, arr))
        {
            visited[i][m - 1] = true;
            SolutionUtil(i, m - 1, n, m, visited, arr, darr_x, darr_y);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isValid(i, j, n, m, visited, arr))
            {
                visited[i][j] = true;
                arr[i][j] = 'X';
                Solution(i, j, n, m, visited, arr, darr_x, darr_y);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}