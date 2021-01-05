// { Driver Code Starts
//Initial funciton template for C++

#include <bits/stdc++.h>
using namespace std;

int Shape(vector<string> &, int, int);

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
        vector<string> arr;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            arr.push_back(S);
        }
        cout << Shape(arr, n, m) << endl;
    }
} // } Driver Code Ends

//User function template for C++

// A : vector of given strings
bool isValid(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<string> &arr)
{
    return i >= 0 && j >= 0 && i < n && j < m && !visited[i][j] && arr[i][j] == 'X';
}
void SolutionUtil(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<string> &arr, int darr_x[], int darr_y[])
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
int Shape(vector<string> &arr, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int darr_x[] = {1, 0, -1, 0};
    int darr_y[] = {0, 1, 0, -1};
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isValid(i, j, n, m, visited, arr))
            {
                visited[i][j] = true;
                SolutionUtil(i, j, n, m, visited, arr, darr_x, darr_y);
                count++;
            }
        }
    }

    return count;
}