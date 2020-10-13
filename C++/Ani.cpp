#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
        }
        if (n >= 2)
        {
            cout << 2;
            n = n - 1;
            while (n--)
            {
                cout << 9;
            }
        }
        cout << "\n";
    }
}
