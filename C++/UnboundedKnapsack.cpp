#include <iostream>
#include <algorithm>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dpVec[N + 1][W + 1] = {};
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (j >= wt[i - 1])
                {
                    dpVec[i][j] = max(dpVec[i - 1][j], dpVec[i][j - wt[i - 1]] + val[i - 1]);
                }
                else
                {
                    dpVec[i][j] = dpVec[i - 1][j];
                }
            }
        }

        return dpVec[N][W];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
} // } Driver Code Ends