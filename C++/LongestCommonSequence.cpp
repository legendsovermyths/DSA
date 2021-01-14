// { Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int lcs(int, int, string, string);

int main()
{

    int x = 20;
    int y = 21; // Take size of both the strings as input
    string s1 = "LSDBOFDMXJJYYFKROILT", s2 = "UIEVCFFIGZRTRVUHCAUCL";
    // Take both the string as input

    cout << lcs(x, y, s1, s2) << endl;
}

// } Driver Code Ends

// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2)
{
    int s11 = s1.length();
    int s22 = s2.length();
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    for (int i = 1; i <= s11; i++)
    {
        for (int j = 1; j <= s22; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= s11; i++)
    {
        for (int j = 0; j <= s22; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[s11][s22];
}
//ABCDGH
//AEDFHR