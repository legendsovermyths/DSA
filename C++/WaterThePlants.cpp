// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            if (gallery[i] > -1)
                arr.push_back({i - gallery[i], i + gallery[i]});
        sort(arr.begin(), arr.end());
        int res = 0, maxRight = 0, i = 0;
        int currMax = arr[i].second;
        while (maxRight < n)
        {
            if (i == arr.size() || maxRight < arr[i].first)
                return -1;
            currMax = arr[i].second;
            while (i + 1 < arr.size() && arr[i + 1].first <= maxRight)
            {
                i++;
                currMax = max(currMax, arr[i].second);
            }
            if (maxRight > currMax)
                return -1;
            maxRight = currMax + 1;
            res++;
            i++;
        }
        return res;
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

        int gallery[n];
        for (int i = 0; i < n; i++)
            cin >> gallery[i];
        Solution obj;
        cout << obj.min_sprinklers(gallery, n) << endl;
    }
    return 1;
}