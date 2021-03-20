// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    int search(int arr2[], int m)
    {
        int target = arr2[0];
        int right = m - 1, left = 1, mid = right + (left - right) / 2;
        while (left < right)
        {
            if (target < arr2[mid])
            {
                right = mid - 1;
                mid = right + (left - right) / 2;
            }
            else if (target >= arr2[mid])
            {
                left = mid + 1;
                mid = right + (left - right) / 2;
            }
        }
        if (arr2[left] > target)
        {
            return left;
        }
        return left + 1;
    }
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] < arr2[0])
            {
                i++;
            }
            else
            {
                swap(&arr1[i], &arr2[0]);
                j = search(arr2, m);
                cout << j << endl;
                swap(&arr2[0], &arr2[j - 1]);
                for (int k = 0; k < m; k++)
                {
                    cout << arr2[k] << " ";
                }
                cout << endl;
                i++;
            }
        }
        j = search(arr2, m);
        swap(&arr2[0], &arr2[j - 1]);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends