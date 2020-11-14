// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    bool DpSol(int arr[], int sum, int N)
    {
        int dp[2][sum + 1];
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i % 2][j] = 0;
                }
                else if (j >= arr[i - 1])
                {
                    dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[(i + 1) % 2][j - arr[i - 1]] + arr[i - 1]);
                }
                else
                {
                    dp[i % 2][j] = dp[(i + 1) % 2][j];
                }
            }
        }
        if (dp[N % 2][sum] == sum)
        {
            return true;
        }
        return false;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 == 1)
        {
            return 0;
        }
        else
        {
            if (DpSol(arr, int(sum / 2), N))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends