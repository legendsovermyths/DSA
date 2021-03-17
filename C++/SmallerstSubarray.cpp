// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int sb(int arr[], int n, int x)
    {
        int left = 0;
        int right = 0;
        int sum = arr[0];
        int mincount = right - left + 1;
        while (right < n)
        {
            if (arr[0] > x)
            {
                mincount = min(mincount, right - left + 1);
                sum = sum - arr[left];
                left++;
            }
            else
            {
                right++;
                sum = sum + arr[right];
            }
        }
        return mincount;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.sb(a, n, x) << endl;
    }
    return 0;
} // } Driver Code Ends