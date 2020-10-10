#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int ans;
    while (t--)
    {
        long long int x, y, n;
        cin >> x >> y >> n;
        long long remainder = n % x;
        if (remainder > n)
            cout << n - remainder + y << endl;
        else
        {
            int temp_n = n + y - remainder;
            while (temp_n > n)
            {
                temp_n = temp_n - x;
            }
            cout << temp_n << endl;
        }
    };
}