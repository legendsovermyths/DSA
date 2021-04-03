// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        int left = 0;
        int count = 0;
        int right = n - 1;
        for (int i = 0; i < n - 2; i++)
        {
            left = i + 1;
            right = n - 1;
            while (left < right)
            {
                if (arr[i] + arr[left] + arr[right] >= sum)
                {
                    right--;
                }
                else if (arr[i] + arr[left] + arr[right] < sum)
                {
                    cout << arr[i] << " " << arr[left] << ' ' << arr[right] << "    " << right - left << endl;
                    count = count + right - left;
                    left++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends