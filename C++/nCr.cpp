#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nCr(int n, int r)
    {
        if (r > n)
            return 0;
        if (r > n - r)
            r = n - r;

        int arr[r + 1] = {};
        arr[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = min(i, r); j > 0; j--)
            {
                arr[j] = (arr[j] + arr[j - 1]) % (int(pow(10, 9) + 7));
            }
        }
        return arr[r];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
}