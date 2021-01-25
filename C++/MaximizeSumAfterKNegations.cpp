// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long int maximizeSum(long long int a[], int n, int k);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << maximizeSum(a, n, k) << endl;
    }

    return 0;
} // } Driver Code Ends

long long int maximizeSum(long long int a[], int n, int k)
{
    long long int sum = 0;
    sort(a, a + n);
    int i = 0;
    while (k > 0)
    {
        if (a[i] >= 0)
        {
            k = 0;
        }
        else
        {
            a[i] = -1 * a[i];
        }
        i++;
    }
    if (k % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            sum = sum + a[i];
        }
    }
    else
    {
        sort(a, a + n);
        a[0] = -1 * a[0];
        for (int i = 0; i < n; i++)
        {
            sum = sum + a[i];
        }
    }
    return sum;
}