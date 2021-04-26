// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array

class Solution
{
public:
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> st;
        vector<long long> left(n, 0);
        for (long long i = 0; i < n; i++)
        {
            if (st.empty())
                st.push(0);
            else
            {
                while (!st.empty() && arr[i] <= arr[st.top()])
                {

                    st.pop();
                }
            }
            if (!st.empty())
                left[i] = st.top() + 1;
            st.push(i);
        }
        left[0] = 0;
        vector<long long> right(n, n - 1);
        stack<long long> st2;
        for (long long i = n - 1; i >= 0; i--)
        {
            if (st2.empty())
            {
                st2.push(n - 1);
            }
            else
            {
                while (!st2.empty() && arr[i] <= arr[st2.top()])
                {
                    st2.pop();
                }
            }
            if (!st2.empty())
                right[i] = st2.top() - 1;
            st2.push(i);
        }
        right[n - 1] = n - 1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = (right[i] - left[i] + 1) * arr[i];
            res = max(res, temp);
        }

        return res;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends