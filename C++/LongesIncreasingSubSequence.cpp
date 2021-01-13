// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << longestSubsequence(n, a) << endl;
    }
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int longestSubsequence(int n, int a[])
{
    vector<int> dp(n, -1);
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
    }
}