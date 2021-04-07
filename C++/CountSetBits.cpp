#include <bits/stdc++.h>
using namespace std;
int countSetBits(int a)
{
    int count = 0;
    while (a > 0)
    {
        if (a % 2 == 1)
        {
            count++;
        }
        a = a / 2;
    }
    return count;
}
int main()
{
    cout << countSetBits(94207) << endl;
    return 0;
}