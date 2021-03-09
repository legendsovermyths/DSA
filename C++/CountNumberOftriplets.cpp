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
        while (left < right)
        {
            if (arr[left] + arr[right] <= sum)
            {
                cout << arr[left] << '+' << arr[right] << '+' << arr[k - 1];
                left++;
            }
            else if (arr[left] + arr[right] > sum)
            {
                right--;
                count++;
            }
        }
        return count;
    };

    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        long long int count = 0;
        long long int newSum = 0;
        for (int i = 0; i < n; i++)
        {
            newSum = sum - arr[i];
            count = count + Addcount(arr, i + 1, newSum, n);
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