#include <bits/stdc++.h>
using namespace std;
void findPalindrome(string s)
{
    int l = s.length();
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
    for (int i = 0; i < l - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
        }
        dp[i][i] = true;
    }
    dp[l - 1][l - 1] = true;
    for (int i = 1; i < l; i++)
    {
        for (int j = 0; j < l - i; j++)
        {
            int k = j + i;
            if (dp[j][k] != true)
            {
                if (dp[j + 1][k - 1] == true && s[j] == s[k])
                    dp[j][k] = true;
            }
        }
    }
    int x = 0, y = 0;
    for (int i = l - 1; i > 0; i--)
    {
        for (int j = 0; j < l - i; j++)
        {
            int n = i + j;
            if (dp[j][n] == true)
            {
                x = j;
                y = n;
                cout << s.substr(x, y - x + 1) << endl;
                return;
            }
        }
    }
    cout << s[0] << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        findPalindrome(s);
    }
}