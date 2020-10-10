#include <iostream>
using namespace std;
int Maximize_n(long long x, long long y, long long n, long long k, long long remainder)
{
    if (remainder > n)
        return k;
    if (k <= n)
        return k;
    return Maximize_n(x, y, n, k - x, remainder);
}
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
        cout << Maximize_n(x, y, n, n - remainder + y, remainder) << endl;
    }
}