// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{

    int a[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout << longestSubsequence(16, a) << endl;
}
int Search(vector<int> arr, int l, int r, int x)
{
    int count = 0;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] < x)
        {
            count++;
        }
        else
        {
            return count;
        }
    }
    return count;
}
int binarySearch(vector<int> arr, int l, int r, int x)
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
    return l;
}
int CeilIndex(std::vector<int> &v, int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int longestSubsequence(int n, int a[])
{
    vector<int> dp(n, 0);
    dp[0] = a[0];
    int length = 1;
    for (int i = 1; i < n; i++)
    {
        if (dp[0] > a[i])
            dp[0] = a[i];
        if (dp[length - 1] < a[i])
            dp[length++] = a[i];
        else
            dp[CeilIndex(dp, -1, length - 1, a[i])] = a[i];
    }
    return length;
}