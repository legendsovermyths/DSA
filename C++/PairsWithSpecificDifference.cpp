#include <bits/stdc++.h>
using namespace std;
int solution(int A[], int n, int k)
{
    sort(A, A + n, greater<int>());
    int sum = 0;
    int i = 1, j = 0;
    while (i < n)
    {
        while (j < n - 1)
        {
            if (A[j] - A[i] < k)
            {
                sum = sum + A[i] + A[j];
                i += 2;
                j += 2;
            }
            else
            {
                i++;
                j++;
            }
        }
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int k;
        cin >> k;
        cout << solution(A, n, k) << endl;
    }
}