#include <iostream>
#include <algorithm>
using namespace std;
int smallest(int x, int y, int z)
{

    int smallest = 9999999;

    if (x < smallest)
        smallest = x;
    if (y < smallest)
        smallest = y;
    if (z < smallest)
        smallest = z;

    return smallest;
}
int moneyChange(int number)
{
    int dpArr[number];

    dpArr[0] = 0;
    for (int i = 1; i <= number; i++)
    {

        if (i >= 3)
        {
            dpArr[i] = smallest(dpArr[i - 1] + 1, dpArr[i - 3] + 1, dpArr[i - 4] + 1);
        }
        else if (i >= 2)
        {
            dpArr[i] = min(dpArr[i - 1] + 1, dpArr[i - 3] + 1);
        }
        else
        {
            dpArr[i] = dpArr[i - 1] + 1;
        }
    }
    return dpArr[number];
}

int main()
{
    int test;
    cin >> test;
    cout << moneyChange(test);
}