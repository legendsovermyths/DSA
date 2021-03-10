// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long Addcount(long long arr[], int k, long long sum, int n)
    {
        long long int count = 0;
        int right = n - 1;
        int left = k;
        bool inloop = false;
        while (left < right)
        {
            inloop = true;
            if (arr[left] + arr[right] < sum)
            {
                left++;
            }
            else if (arr[left] + arr[right] >= sum)
            {
                right--;
            }
        }
        cout << left;
        if (left == right)
            return ((left - k + 1) * (left - k)) / 2;
        return 0;
    };

    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        long long int count = 0;
        long long int newSum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            newSum = sum - arr[i];
            count = count + Addcount(arr, i + 1, newSum, n);
        }
        return count + 1;
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