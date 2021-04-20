// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    bool solve(long long int mid, int arr[], int n, int m)
    {
        int sum = 0;
        int st = 1;
        for (int i = 0; i < n; i++)
        {

            if (arr[i] > mid)
                return false;
            if (sum + arr[i] > mid)
            {
                st++;
                sum = arr[i];
                if (st > m)
                    return false;
            }
            else if (sum + arr[i] <= mid)
                sum = sum + arr[i];
        }
        return true;
    }
    int findPages(int arr[], int n, int m)
    {
        long long int ub = 10e6, lb = 0, ans = 0;
        while (lb <= ub)
        {
            long long int mid = (ub + lb) / 2;
            if (!solve(mid, arr, n, m))
                lb = mid + 1;

            else
            {
                ans = mid;
                ub = mid - 1;
            }
        }
        return ans;
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends