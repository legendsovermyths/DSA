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
int primitiveCalculator(int n)
{
    int dpVec[n + 1];
    dpVec[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((i + 1) % 6 == 0)
        {
            dpVec[i] = smallest(dpVec[(i + 1) / 3 - 1] + 1, dpVec[(i + 1) / 2 - 1] + 1, dpVec[i - 1] + 1);
        }
        else if ((i + 1) % 3 == 0)
        {
            dpVec[(i)] = min(dpVec[(i + 1) / 3 - 1] + 1, dpVec[i - 1] + 1);
        }
        else if ((i + 1) % 2 == 0)
        {
            dpVec[(i)] = min(dpVec[(i + 1) / 2 - 1] + 1, dpVec[i - 1] + 1);
        }
        else
        {
            dpVec[i] = dpVec[i - 1] + 1;
        }
    }
    return dpVec[n - 1];
}
int main()
{
    cout << primitiveCalculator(5);
}