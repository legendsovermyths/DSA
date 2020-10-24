#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long int count(int S[], int m, int n)
    {
        int arr1[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                {
                    arr1[i][j] = 0;
                }
                else if (j == 0)
                {
                    arr1[i][j] = 1;
                }
                else if (j >= S[i - 1])
                {
                    arr1[i][j] = arr1[i - 1][j] + arr1[i][j - S[i - 1]];
                }
                else
                {
                    arr1[i][j] = arr1[i - 1][j];
                }
            }
        }

        return arr1[m][n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}