// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], int l, int m, int r, long long &count)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temp arrays
        int L[n1], R[n2];

        // Copy data to temp arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        // Merge the temp arrays back into arr[l..r]

        // Initial index of first subarray
        int i = 0;

        // Initial index of second subarray
        int j = 0;

        // Initial index of merged subarray
        int k = l;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                count += n1 - i;
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of
        // R[], if there are any
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(long long arr[], int l, int r, long long &count)
    {
        if (l >= r)
        {
            return; //returns recursively
        }
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long count = 0;
        mergeSort(arr, 0, N - 1, count);
        return count;
    }
};

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends
//42
