// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends

// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N)
{
    int maxi = *max_element(arr, arr + N);
    vector<bool> vec(maxi + 1, 0);
    for (int i = 0; i < N; i++)
    {
        vec[arr[i]] = 1;
    }
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i <= maxi; i++)
    {
        if (vec[i] == 1)
        {
            count++;
        }
        else
        {
            if (maxCount < count)
                maxCount = count;
            count = 0;
        }
    }
    if (maxCount < count)
        maxCount = count;
    return maxCount;
}