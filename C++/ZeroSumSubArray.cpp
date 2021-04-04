// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {
        int t;
        map<ll, int> umap;
        int count = 0;
        int sum = 0;
        umap[0]++;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            umap[sum]++;
        }
        map<ll, int>::iterator it;
        for (it = umap.begin(); it != umap.end(); it++)
        {
            cout << it->first << ":" << it->second << endl;
        }
        for (it = umap.begin(); it != umap.end(); it++)
        {
            if (it->second > 1)
            {
                t = it->second - 1;
                count = count + t * (t + 1) / 2;
            }
        }
        return count;
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
        cin >> n; //input size of array

        vector<ll> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
} // } Driver Code Ends
  // -2:1
  // -1:1
  // 0:1
  // 2:1
  // 3:1
  // 8:1
  // 9:1
  // 15:1
  // 20:2
  // 27:1
  // 32:1
  // 35:1
  // 37:2
  // 38:1
  // 43:2
  // 48:4
  // 49:1
  // 51:1
  // 52:1
  // 55:2
  // 56:2
  // 57:1
  // 59:1