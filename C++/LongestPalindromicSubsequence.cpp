#include <bits/stdc++.h>
using namespace std;
void Solution(string s)
{
    int count = s.length();
    vector<vector<int>> dp(count + 1, vector<int>(count + 1, 0));
    for (int i = 1; i <= count; i++)
    {
        for (int j = 1; j <= count; j++)
        {
            if (s[i - 1] == s[count - j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j <= count; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
int main()
{
    Solution("BBABCBCAB");
}