#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
void printSol(vector<vector<int>> &placed)
{
    cout << "[";
    for (int i = 0; i < placed.size(); i++)
    {
        for (int j = 0; j < placed[1].size(); j++)
        {
            if (placed[j][i] == 1)
            {
                cout << j + 1 << " ";
            }
        }
    }
    cout << "] ";
    return;
}
bool isValid(vector<vector<int>> &placed, int Row, int Col, int siz)
{
    int i, j;
    for (i = Row, j = Col; i >= 0 && j >= 0; i--, j--)
    {
        if (placed[i][j])
        {
            return false;
        }
    }
    for (i = Row, j = Col; i < siz && j >= 0; j--, i++)
    {
        if (placed[i][j])
        {
            return false;
        }
    }
    for (i = 0; i < Col; i++)
    {
        if (placed[Row][i])
        {
            return false;
        }
    }
    return true;
}
int SolutionUtil(vector<vector<int>> &placed, int Col, int N)
{
    if (Col == N)
    {
        printSol(placed);
        return 1;
    }
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (isValid(placed, i, Col, N))
        {
            placed[i][Col] = 1;
            res = (SolutionUtil(placed, Col + 1, N)) || res;
            placed[i][Col] = 0;
        }
    }
    return res;
}
void solution(vector<vector<int>> &placed, int N)
{
    if (N == 1)
    {
        cout << "[1 ]" << endl;
        return;
    }
    if (SolutionUtil(placed, 0, N) == 0)
    {
        cout << -1 << endl;
        return;
    }
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> placed(n, vector<int>(n, 0));
        solution(placed, n);
    }
    return 0;
}