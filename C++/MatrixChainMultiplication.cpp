#include <bits/stdc++.h>
using namespace std;
int calculateMinOperation(int i, int j, vector<vector<int>> &vec, int p[])
{
    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int curr = p[i] * p[k + 1] * p[j + 1] + vec[k + 1][j] + vec[i][k];
        if (min > curr)
        {
            min = curr;
        }
    }
    return min;
}
void solution(int p[], int n)
{
    vector<vector<int>> vec(n, vector<int>(n, 0));
    for (int i = 0; i < n - 1; i++)
    {
        vec[i][i] = 0;
    }
    int k = 0;

    for (int j = 0; j < n - 2; j++)
    {
        k = 1 + j;
        vec[j][k] = p[j] * p[j + 1] * p[j + 2];
    }
    k = 0;
    for (int i = 2; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            k = j + i;
            vec[j][k] = calculateMinOperation(j, k, vec, p);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int p[] = {1, 2, 3, 4, 3};
    int n = 5;
    solution(p, n);
}