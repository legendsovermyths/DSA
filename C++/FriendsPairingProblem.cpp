// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countFriendsPairings(int n)
    {
        vector<int> dp(n, 0);

        dp[0] = 1, dp[1] = 2;
        for (int i = 2; i < n; i++)
        {
            dp[i] = (dp[i - 1] + (i)*dp[i - 2]) % int(pow(10, 9) + 7);
        }
        return dp[n - 1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
// } Driver Code Ends