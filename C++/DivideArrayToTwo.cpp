// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum = sum + arr[i];
        }
        if (sum % 2 == 1)
        {
            return 0;
        }

        int dpArr[2][sum / 2 + 1];
        for (int i = 0; i <= N; i++)
        {

            for (int j = 0; j <= sum / 2; j++)
            {
                if (i % 2 == 0)
                {
                    if (i == 0 || j == 0)
                    {
                        dpArr[i % 2][j] = 0;
                    }
                    else if (arr[i - 1] <= j)
                    {
                        dpArr[i % 2][j] = max(dpArr[i % 2 + 1][j], dpArr[i % 2 + 1][j - arr[i - 1]] + arr[i - 1]);
                    }
                    else
                    {
                        dpArr[i % 2][j] = dpArr[i % 2 + 1][j];
                    }
                }
                if (i % 2 == 1)
                {
                    if (i == 0 || j == 0)
                    {
                        dpArr[i % 2][j] = 0;
                    }
                    else if (arr[i - 1] <= j)
                    {
                        dpArr[i % 2][j] = max(dpArr[i % 2 - 1][j], dpArr[i % 2 - 1][j - arr[i - 1]] + arr[i - 1]);
                    }
                    else
                    {
                        dpArr[i % 2][j] = dpArr[i % 2 - 1][j];
                    }
                }
            }
        }
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= sum / 2; j++)
            {
                cout << dpArr[i % 2][j] << " ";
            }
            cout << "\n";
        }
        if (dpArr[N % 2][sum / 2] == sum / 2)
        {
            return 1;
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