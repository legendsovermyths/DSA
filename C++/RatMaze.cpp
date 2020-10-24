#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

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
}

bool isValid(int i, int j, bool isVisted, int n, int m[MAX][MAX])
{
    return ((i >= 0) && j >= 0 && !isVisted && i < n && j < n && m[i][j] == 1);
}
string Path(int i, int j, int m[MAX][MAX], bool isVisited, string step, int n)
{
    if (!isValid(i, j, isVisited, n, m))
        return " ";
    if (i == n - 1 && j == n - 1)
        return step;
    isVisited = true;
    string left = step + Path(i, j - 1, m, isVisited, "L", n);
    string Right = step + Path(i, j + 1, m, isVisited, "R", n);
    string Top = step + Path(i - 1, j, m, isVisited, "T", n);
    string Bottom = step + Path(i + 1, j - 1, m, isVisited, "D", n);
    isVisited = false;
    return left + Right + Top + Bottom;
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> allOfIt;
    allOfIt.push_back(Path(0, 0, m, false, "", n));
    return allOfIt;
}