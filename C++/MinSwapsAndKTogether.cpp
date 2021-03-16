// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;

int minSwap(int *arr, int n, int k);

// Driver code
int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        cout << minSwap(arr, n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends

void swa(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
#include <numeric>
int minSwap(int *arr, int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            cnt += 1;
            arr[i] = 0;
        }
        else
            arr[i] = 1;
    }
    int i = 0;
    int j = cnt - 1;
    int answer = INT32_MAX;
    int tempAns = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (arr[i] == 1)
        {
            tempAns++;
        }
    }
    answer = tempAns;
    for (int i = 0; j < n - 1; i++, j++)
    {
        cout << tempAns << ' ';
        tempAns = tempAns - arr[i] + arr[j + 1];
        if (tempAns < answer)
        {
            answer = tempAns;
        }
    }
    return answer;
}