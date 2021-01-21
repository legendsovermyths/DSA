// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <iostream>
#include <cstring>
using namespace std;

// Function return the total palindromic subsequence
int countPS(string str);

// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << countPS(str) << endl;
    }
} // } Driver Code Ends

/*You are required to complete below method */
#include <vector>
int countPS(string str)
{
    int count = str.length();
    vector<vector<int>> dp(count, vector<int>(count, 0));
    for (int i = 0; i < count; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 1; i < count; i++)
    {
        for (int j = 0; j < count - i; j++)
        {
            int n = i + j;
            if (str[j] == str[n])
            {
                dp[j][n] = 1 + dp[j + 1][n] + dp[j][n - 1];
            }
            else
            {
                dp[j][n] = dp[j + 1][n] + dp[j][n - 1] - dp[j + 1][n - 1];
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][count - 1];
}
//abbcdbbk
