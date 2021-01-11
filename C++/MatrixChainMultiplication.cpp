#include <bits/stdc++.h>
using namespace std;
int calculateMinOperation(int i, int j, vector<vector<int>> &vec, int p[])
{
    int min = INT_MAX;
    // for (int k = i; k < j; k++)
    // {
    //     int curr=p[i]*p[j+1]*
    // }
}
void solution(int p[], int n)
{
    vector<vector<int>> vec(n, vector<int>(n, 0));
    for (int i = 0; i < n - 1; i++)
    {
        vec[i][i] = p[i];
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
        for (int j = 0; j < i; j++)
        {
            k = j + i;
            vec[j][k] = calculateMinOperation(j, k, vec, p);
        }
    }
}
int main() {}