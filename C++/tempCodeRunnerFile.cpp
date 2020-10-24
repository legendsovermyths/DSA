#include <iostream>
using namespace std;
int solution(int m, int n, int val[], int wt[])
{
    int arr[m + 1][n + 1] = {};
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (val[i - 1] <= j)
            {
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - wt[i - 1]] + val[i - 1]);
            }
            else
            {
                arr[i][j] = arr[i - 1][j];
            }
        }
    }
    for (int i = i; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return arr[m][n];
}
int main()
{
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    solution(3, 4, val, wt);
}