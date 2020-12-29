#include <iostream>
using namespace std;
void bin(int n)
{
    if (n == 0)
    {
        return;
    }
    bin(n / 2);
    cout << n % 2;
    bin(n / 3);
}
int main()
{
    bin(175);
    return 0;
}