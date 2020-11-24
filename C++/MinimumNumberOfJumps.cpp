// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n)
{
    int solutionDp[n];
    std::fill_n(solutionDp, n, 0);
    if (arr[0] == 0)
    {
        return -1;
    }
    if (arr[0] >= n)
    {
        return 1;
    }
    solutionDp[n - 1] = 0;
    int min = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        min = INT_MAX;
        if (arr[i] < n - i)
        {
            if (arr[i] == 0)
            {
                solutionDp[i] = INT_MAX;
            }
            else
                for (int j = 1; j <= arr[i]; j++)
                {
                    if (min > solutionDp[j + i])
                    {
                        min = solutionDp[j + i];
                        solutionDp[i] = min + 1;
                    }
                }
        }
        else
        {
            solutionDp[i] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << solutionDp[i] << " ";
    }
    if (solutionDp[0] == 1 || solutionDp[0] == 0)
    {
        return -1;
    }
    return solutionDp[0];
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends