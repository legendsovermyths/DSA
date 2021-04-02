// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int arr[], int n)
    {
        register int m = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int max_ = 0;
        for (int i = 0; i < n; i++)
        {
            max_ = max(max_, arr[i]);
            left[i] = max_;
        }
        max_ = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            max_ = max(max_, arr[i]);
            right[i] = max_;
        }
        int answer;
        for (int i = 0; i < n; i++)
        {
            answer = min(right[i], left[i]) - arr[i] + answer;
        }
        return answer;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends