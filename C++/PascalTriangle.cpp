// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends

// #define ll long long
class Solution
{
public:
    vector<ll> nthRowOfPascalTriangle(int n)
    {
        vector<vector<ll>> vec(n + 1, vector<ll>(n + 1, 0));
        vector<ll> dp;
        if (n == 1)
        {
            dp.push_back(1);
            return dp;
        }
        vec[0][1] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= i + 1; j++)
            {
                vec[i][j] = vec[i - 1][j] + vec[i - 1][j - 1];
                if (i == n - 1 && vec[i][j] != 0)
                    dp.push_back(vec[i][j]);
            }
        }
        return dp;
    }
};

// { Driver Code Starts.

void printAns(vector<ll> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
// } Driver Code Ends