#include <iostream>
using namespace std;
int solution(int m, int n, int val[], int wt[])
{
    int arr[m + 1][n + 1] = {};
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (wt[i - 1] <= j)
            {
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - wt[i - 1]] + val[i - 1]);
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
    int test;
    cin >> test;
    while (test--)
    {
        int m;
        cin >> m;
        int n;
        cin >> n;
        int val[m];
        for (int i = 0; i < m; i++)
        {
            cin >> val[i];
        }
        int wt[m];
        for (int j = 0; j < m; j++)
        {
            cin >> wt[j];
        }

        cout << solution(m, n, val, wt) << endl;
    }
}