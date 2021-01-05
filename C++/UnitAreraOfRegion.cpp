// { Driver Code Starts
//Initial funciton template for C++

#include <bits/stdc++.h>
using namespace std;

int Shape(vector<vector<int>> &, int, int);

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
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << Shape(arr, n, m) << endl;
    }
} // } Driver Code Ends

//User function template for C++

// A : vector of given strings
bool isValid(int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<int>> &arr)
{
    return i >= 0 && j >= 0 && i < n && j < m && !visited[i][j] && arr[i][j] == 1;
}
void SolutionUtil(vector<int> &answer, int i, int j, int n, int m, vector<vector<bool>> &visited, vector<vector<int>> &arr, int darr_x[], int darr_y[], int &area)
{

    answer.push_back(area);
    if (i == n && j == m)
    {
        return;
    }
    for (int k = 0; k < 8; k++)
    {
        int x = i + darr_x[k];
        int y = j + darr_y[k];
        if (isValid(x, y, n, m, visited, arr))
        {
            visited[x][y] = true;
            area = area + 1;
            SolutionUtil(answer, x, y, n, m, visited, arr, darr_x, darr_y, area);
        }
    }
}
int Shape(vector<vector<int>> &arr, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int darr_x[] = {1, 0, -1, 0, 1, -1, -1, 1};
    int darr_y[] = {0, 1, 0, -1, 1, -1, 1, -1};
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isValid(i, j, n, m, visited, arr))
            {
                int area = 1;
                visited[i][j] = true;
                SolutionUtil(answer, i, j, n, m, visited, arr, darr_x, darr_y, area);
            }
        }
    }
    int ans = *max_element(answer.begin(), answer.end());
    return ans;
}
//10 3
// 0 0 1
// 1 1 0
// 1 0 1
// 1 1 1
// 0 1 0
// 0 1 0
// 1 0 1
// 0 0 1
// 0 0 0
// 1 1 1
