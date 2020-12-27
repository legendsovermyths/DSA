// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *ar = new int[2];
        unordered_map<int, int> umap;
        int missing = 0;
        int twice = 0;
        for (int i = 0; i < n; i++)
        {
            if (!umap[arr[i]])
            {
                umap[arr[i]] = 1;
            }
            else
            {
                twice = umap[arr[i]];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!umap[i])
                missing = i;
        }
        ar[0] = twice;
        ar[1] = missing;
        return ar;
    }
};

// { Driver Code Starts.

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {

    int a[2] = {2, 2};

    Solution ob;
    auto ans = ob.findTwoElement(a, 2);
    cout << ans[0] << " " << ans[1] << "\n";
    // }
    return 0;
} // } Driver Code Ends