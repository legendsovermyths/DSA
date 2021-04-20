// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
// } Driver Code Ends
class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (k == 1)
            return min(arr1[0], arr2[0]);
        if (k == 2)
            return max(arr1[0], arr2[0]);
        int mid1 = 0, mid2 = 0, lb1 = 0, ub1 = n - 1, lb2 = 0, ub2 = m - 1;
        mid1 = (ub1 + lb1) / 2;
        mid2 = (ub2 + lb2) / 2;
        while (mid1 + mid2 != k - 2)
        {
            if (mid1 + mid2 < k - 2)
            {
                if (arr1[mid1] <= arr2[mid2])
                {
                    lb2 = mid2 + 1;
                    mid2 = (lb2 + ub2) / 2;
                }
                else
                {
                    lb1 = mid1 + 1;
                    mid1 = (lb1 + ub1) / 2;
                }
            }
            else if (mid1 + mid2 > k - 2)
            {
                if (arr1[mid1] <= arr2[mid2])
                {
                    ub2 = mid2;
                    mid2 = (lb2 + ub2) / 2;
                }
                else
                {
                    ub1 = mid1;
                    mid1 = (lb1 + ub1) / 2;
                }
            }
        }

        return max(arr1[mid1], arr2[mid2]);
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    }
    return 0;
} // } Driver Code Ends