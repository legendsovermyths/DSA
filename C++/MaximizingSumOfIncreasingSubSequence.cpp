// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int maxSumIS(int arr[], int n)
    {
        vector<vector<int>> dp;
        dp.push_back({arr[0], arr[0]});
        bool checker = false;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < dp.size(); j++)
            {
                if (dp[j][0] < arr[i])
                {
                    dp.push_back({arr[i], arr[i] + dp[j][1]});
                    checker = true;
                }
            }
            if (checker == false)
            {
                dp.push_back({arr[i], arr[i]});
            }
            checker = false;
        }
        int maxSum = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i][1] > maxSum)
            {
                maxSum = dp[i][1];
            }
        }
        return maxSum;
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

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends