// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long countWays(int n, int k)
    {
        vector<long long> vec(n, 0);
        vec[0] = k;
        vec[1] = (k * (k - 1) + k) % int((pow(10, 9) + 7));
        for (int i = 2; i < n; i++)
        {
            vec[i] = ((vec[i - 1] + vec[i - 2]) * (k - 1)) % int((pow(10, 9) + 7));
        }
        for (int i = 0; i < n; i++)
        {
            cout << vec[i] << " ";
        }

        return vec[n - 1];
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
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;
    }
    return 0;
} // } Driver Code Ends