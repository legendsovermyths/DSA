// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

public:
    int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int top = 0, right = m - 1, left = 0, down = n - 1;
        int dir = 0;
        int num = 1;
        while (top <= down && right >= left)
        {
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    cout << a[top][i] << " ";
                    if (num == k)
                        return a[top][i];
                    num++;
                }
                top += 1;
            }
            else if (dir == 1)
            {
                for (int i = top; i <= down; i++)
                {
                    cout << a[i][right] << " ";
                    if (num == k)
                        return a[i][right];
                    num++;
                }
                right -= 1;
            }
            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    cout << a[down][i] << " ";
                    if (num == k)
                        return a[down][i];
                    num++;
                }
                down -= 1;
            }
            else if (dir == 3)
            {
                for (int i = down; i >= top; i--)
                {
                    cout << a[i][left] << " ";
                    if (num == k)
                        return a[i][left];
                    num++;
                }
                left += 1;
            }
            dir = (dir + 1) % 4;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        int k = 0;
        //cin>>k;
        cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        Solution obj;

        cout << obj.findK(a, n, m, k) << "\n";
    }
} // } Driver Code Ends