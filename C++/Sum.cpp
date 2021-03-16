// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Complete this function
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> umap;

        umap[arr[0]]++;

        int sum = arr[0];
        for (int i = 1; i < n; i++)
        {
            umap[sum]++;
            sum += arr[i];
            cout << umap[sum] << ':' << sum << " ";
            if (sum == 0)
            {
                return true;
            }
            if (umap[sum] != 0)
            {
                return true;
            }
        }
        if (sum == 0)
            return true;
        return false;
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
} // } Driver Code Ends