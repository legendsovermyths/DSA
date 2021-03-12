#include <bits/stdc++.h>
using namespace std;
string Solution(string s)
{
    int lenght = s.length();
    vector<vector<int>> dp(lenght, vector<int>(lenght, 0));
    vector<string> vec;
    string answer;
    int max = 1;
    for (int i = 0; i < lenght; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 1; i < lenght; i++)
    {
        for (int j = 0; j < lenght - i; j++)
        {
            int n = i + j;
            if (s[j] == s[n] && dp[j + 1][n - 1] != 0)
            {
                dp[j][n] = dp[j + 1][n - 1] + 2;
                if (dp[j][n] > max)
                {
                    answer = s.substr(j, n - j + 1);
                }
            }
            else
            {
                dp[j][n] = dp[j + 1][n - 1];
            }
        }
    }
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < lenght; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << answer << endl;
}
int main()
{
    string s = "aaaabbaa";
    Solution(s);
}