// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    int LowestIndex(vector<int> vec, int m)
    {
        int right = m - 1, left = 0, mid = left + (right - left) / 2;
        while (left <= right)
        {
            if (vec[mid] == 1)
            {
                right = mid - 1;
                mid = left + (right - left) / 2;
            }
            if (vec[mid] == 0)
            {
                left = mid + 1;
                mid = left + (right - left) / 2;
            }
        }
        return right;
    }
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int answer = -1;
        int finalMin = m - 1;
        int tempMin = 0;
        for (int i = 0; i < n; i++)
        {
            tempMin = LowestIndex(arr[i], m);
            if (finalMin > tempMin)
            {
                finalMin = tempMin;
                answer = i;
            }
            if (tempMin == -1)
            {
                return i;
            }
        }

        return answer;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends