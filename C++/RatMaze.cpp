// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

bool isValid(int m[MAX][MAX], int N, int i, int j, vector<vector<bool>> &vis)
{
    int row = N;
    int cols = N;
    return i >= 0 && j >= 0 && i < row && j < cols && m[i][j] == 1 && !vis[i][j];
}
bool SolutionUtil(int m[MAX][MAX], int N, int i, int j, vector<vector<bool>> &vis, string solution, int x_moves[], int y_moves[], char moves[], vector<string> &sol2)
{
    if (i == N - 1 && j == N - 1)
    {
        sol2.push_back(solution);
        return 1;
    }
    bool res = false;
    vis[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int next_x = i + x_moves[k];
        int next_y = j + y_moves[k];

        if (isValid(m, N, next_x, next_y, vis))
        {

            solution.push_back(moves[k]);
            res = SolutionUtil(m, N, next_x, next_y, vis, solution, x_moves, y_moves, moves, sol2) || res;
            solution.pop_back();
        }
    }
    vis[i][j] = false;
    return res;
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> v;
    int x_moves[] = {1, 0, 0, -1};
    int y_moves[] = {0, -1, 1, 0};
    char moves[] = {'D', 'L', 'R', 'U'};
    string solution = "";
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    vis[0][0] = 1;
    SolutionUtil(m, n, 0, 0, vis, solution, x_moves, y_moves, moves, v);

    return v;
}