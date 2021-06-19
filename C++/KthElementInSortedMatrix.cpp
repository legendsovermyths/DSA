// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}
// } Driver Code Ends

int search_less_equal(int matrix[MAX][MAX], int target, int n)
{
    int i = n - 1, j = 0, res = 0;
    while (i >= 0 && j < n)
    {
        if (matrix[i][j] <= target)
        {
            res += i + 1;
            ++j;
        }
        else
        {
            --i;
        }
    }
    // cout << res << " ";
    return res;
}

int kthSmallest(int matrix[MAX][MAX], int n, int k)
{
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    while (left < right)
    {

        int mid = left + (right - left) / 2;
        cout << mid << ' ';
        int cnt = search_less_equal(matrix, mid, n);
        if (cnt < k)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}