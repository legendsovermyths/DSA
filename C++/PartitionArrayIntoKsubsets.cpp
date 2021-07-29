// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    void SolutionUtil(int i, vector<int> &ans, int n, int k, int div, int a[], bool &UltChecker)
    {
        if (i == n)
        {
            int checker = true;
            int sum = 0;
            for (int t = 0; t < k; t++)
            {
                if (ans[t] != div)
                {
                    checker = false;
                    break;
                }
            }
            if (checker)
            {
                UltChecker = true;
            }
            return;
        }
        for (int j = 0; j < k; j++)
        {
            if (ans[j] + a[i] <= div && !UltChecker)
            {
                ans[j] += a[i];
                SolutionUtil(i + 1, ans, n, k, div, a, UltChecker);
                ans[j] -= a[i];
            }
        }
    }

    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        if (sum % k != 0)
            return 0;
        int div = sum / k;
        vector<int> ans(k, 0);
        bool UltChecker = false;
        SolutionUtil(0, ans, n, k, div, a, UltChecker);
        return UltChecker;
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
        int k;
        cin >> k;
        Solution obj;
        cout << obj.isKPartitionPossible(a, n, k) << endl;
    }
} // } Driver Code Ends