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
        if (n % 2 == 0)
        {
            while (n)
            {
                cout << "1";

                n = n - 2;
            }
            cout << "\n";
        }
        else
        {
            n = n - 3;
            cout << "7";
            while (n)
            {
                cout << "1";
                n = n - 2;
            }
            cout << "\n";
        }
    }
}