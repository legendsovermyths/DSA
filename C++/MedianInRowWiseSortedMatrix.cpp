// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int countMin(vector<vector<int>> matrix, long long int key, int r, int c)
    {
        int count = 0;
        for (int i = 0; i < r; i++)
        {
            int left = 0, right = c - 1;
            int mid = (right + left) / 2;
            while (left <= right)
            {
                if (key > matrix[i][mid])
                {
                    count += mid - left + 1;
                    left = mid + 1;
                    mid = (left + right) / 2;
                }
                else
                {
                    right = mid - 1;
                    mid = (left + right) / 2;
                }
            }
        }
        return count;
    }

    int median(vector<vector<int>> &matrix, int r, int c)
    {
        long long int high = 10e9, low = 0;
        long long int mid = (high + low) / 2;
        int req = (r * c) / 2;
        while (high >= low)
        {
            int have = countMin(matrix, mid, r, c);
            if (have > req)
            {
                high = mid - 1;
                mid = (high + low) / 2;
            }
            else
            {
                low = mid + 1;
                mid = (high + low) / 2;
            }
        }
        return high;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
} // } Driver Code Ends