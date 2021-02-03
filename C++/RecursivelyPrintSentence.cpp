#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<string>> &stringss, int i, int j, int n)
{
    return i < n;
}
void PrintSenctences(vector<vector<string>> &stringss, int n, vector<string> &sol, int i)
{

    if (i == n)
    {
        for (int k = 0; k < sol.size(); k++)
        {
            cout << sol[k] << ' ';
        }

        cout << endl;
        return;
    }
    int count = stringss[i].size();
    for (int j = 0; j < count; j++)
    {
        if (isValid(stringss, i, j, n))
        {
            sol.push_back(stringss[i][j]);
            PrintSenctences(stringss, n, sol, i + 1);
            sol.pop_back();
        }
    }
}
int main()
{
    vector<vector<string>> stringss = {{"you", "we"},
                                       {"have", "are"},
                                       {"sleep", "eat", "drink"}};
    int n = stringss.size();
    vector<string> sol;
    PrintSenctences(stringss, n, sol, 0);
}
