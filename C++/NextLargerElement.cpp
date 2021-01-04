// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to store Next larger elements

vector<long long> nextLargerElement(long long arr[], int n)
{
    vector<long long> vec;
    stack<long long> s;
    s.push(arr[0]);
    int next;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[i] > s.top())
        {
            vec.push_back(arr[i]);
            s.pop();
        }
        s.push(arr[i]);
    }
    return vec;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long> res = nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends