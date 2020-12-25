// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int minw = arr[0];
        int maxw = arr[n - 1];
        for (int i = 0; i < n; i++)
        {
            if (abs(arr[i] - minw) > abs(arr[i] - maxw))
            {
                arr[i] -= k;
            }
            else
            {
                arr[i] += k;
            }
        }
        /* for(int i=0;i<n;i++){
	    	cout<<v[i]<<",";
	    }*/
        int min1 = arr[0];
        int max1 = arr[n - 1];
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] < min1)
            {
                min1 = arr[i];
            }
            if (arr[i] > max1)
            {
                max1 = arr[i];
            }
        }
        return (max1) - (min1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends