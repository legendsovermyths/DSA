// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution
{

public:
    int minimumCost(int cost[], int N, int W)
    {
        vector<vector<int>> dpVec(W + 1, vector<int>(N + 1, 0));
        for (int i = 0; i <= W; i++)
        {
            dpVec[i][0] = 10000;
        }
        for (int i = 0; i < N; i++)
        {
            if (cost[i] == -1)
            {
                cost[i] = 10000;
            }
        }

        for (int i = 1; i <= W; i++)
        {
            for (int j = 1; j <= N; j++)
            {

                if (j <= i)
                {

                    dpVec[i][j] = min(dpVec[i][j - 1], dpVec[i - j][j] + cost[j - 1]);
                }
                else
                {
                    dpVec[i][j] = dpVec[i][j - 1];
                }
            }
        }
        for (int i = 0; i <= W; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                cout << dpVec[i][j] << " ";
            }
            cout << endl;
        }
        if (dpVec[W][N] >= 10000)
        {
            return -1;
        }
        return dpVec[W][N];
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
} // } Driver Code Ends