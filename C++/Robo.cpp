#include <iostream>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        int sum_A1B0 = 0;
        int sum_A0B1 = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            int checker = a[i] - b[i];
            if (checker == 1)
                sum_A1B0++;
            if (checker == -1)
                sum_A0B1++;
        }
        if (sum_A1B0 == 0)
            cout << -1;
        else
        {
            int x = int(sum_A0B1 / sum_A1B0) + 1;
            cout << x;
        }
    }
}