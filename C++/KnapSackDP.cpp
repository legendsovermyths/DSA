#include <iostream>
#include <algorithm>
using namespace std;
int solutionToProblemDuh(long long int n, long long int m, long long int arr1[])
{
    long long int arr[m + 1][n + 1] = {};
    for (long long int i = 1; i <= m; i++)
    {
        for (long long int j = 1; j <= n; j++)
        {
            if (j >= arr1[i - 1])
            {

                arr[i][j] = max(arr[i - 1][j], (arr[i - 1][j - arr1[i - 1]] + arr1[i - 1]));
            }
            else
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }
    return arr[m][n];
}
int main()
{
    long long int n, m;
    cin >> n >> m;
    long long int arr[m];
    for (long long int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    cout << solutionToProblemDuh(n, m, arr);
}