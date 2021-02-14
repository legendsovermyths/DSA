// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to store Next larger elements

vector<long long> nextLargerElement(long long arr[], int n)
{
    vector<long long> vec(n, 0);
    pair<long long, int> Pair1;
    stack<pair<long long, int>> s;
    Pair1.first = arr[0];
    Pair1.second = 0;
    s.push(Pair1);
    int next;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && s.top().first < arr[i])
        {
            vec[s.top().second] = arr[i];
            s.pop();
        }
        Pair1.first = arr[i];
        Pair1.second = i;
        s.push(Pair1);
    }
    for (int i = 0; i < n; i++)
    {
        if (vec[i] == 0)
            vec[i] = -1;
    }

    return vec;
}
//
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