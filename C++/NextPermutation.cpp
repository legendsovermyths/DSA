// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        int firstDown = -1;
        int firstDown_index = 0;
        for (int i = N - 1; i > 0; i--)
        {
            if (arr[i] > arr[i - 1])
            {
                firstDown = arr[i - 1];
                firstDown_index = i - 1;
                break;
            }
        }
        int closest = arr[N - 1];
        int closest_index = N - 1;
        int prev = arr[firstDown_index];
        for (int i = firstDown_index; i < N; i++)
        {
            if (arr[i] < firstDown)
            {
                closest = prev;
                closest_index = i - 1;
                break;
            }
            prev = arr[i];
        }
        if (firstDown != -1)
            swap(&arr[firstDown_index], &arr[closest_index]);
        else
            firstDown_index = -1;
        reverse(arr.begin() + firstDown_index + 1, arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends