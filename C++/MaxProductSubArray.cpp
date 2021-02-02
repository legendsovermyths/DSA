// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(int *arr, int n)
    {
        long long int MAXproduct = 1;
        long long int tempMin = 1;
        long long int tempMax = 1;
        long long int one = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                tempMin = 1;
                tempMax = 1;
            }
            else if (arr[i] > 0)
            {
                tempMax = tempMax * arr[i];
                tempMin = min(tempMin * arr[i], one);
            }
            else if (arr[i] < 0)
            {
                long long int prevMax = tempMax;
                tempMax = max(tempMin * arr[i], one);
                tempMin = prevMax * arr[i];
            }
            if (tempMax >= MAXproduct)
            {
                cout << tempMax << " ";
                MAXproduct = tempMax;
            }
        }
        return MAXproduct;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends