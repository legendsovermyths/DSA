#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int solution(int eggs, int floors)
{
    int dp[eggs + 1][floors + 1] = {};
    for (int i = 1; i <= eggs; i++)
    {
        for (int j = 1; j <= floors; j++)
        {
            if (i == 1)
            {
                dp[i][j] = j;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = INT32_MAX;
                for (int k = 1; k <= j; k++)
                {
                    int res = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);
                    if (res < dp[i][j])
                    {
                        dp[i][j] = res;
                    }
                }
            }
        }
    }
    for (int s = 0; s <= eggs; s++)
    {
        for (int i = 0; i <= floors; i++)
        {
            cout << dp[s][i] << " ";
        }
        cout << "\n";
    }

    return dp[eggs][floors];
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int eggs, floors;
        cin >> eggs >> floors;
        cout << solution(eggs, floors) << endl;
    }
}