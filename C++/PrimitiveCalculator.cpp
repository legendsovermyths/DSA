#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;
void printMap(int n, int dpVec[])
{
    list<int> sequences;
    while (n > 0)
    {
        sequences.push_front(n);
        if (n % 2 != 0 && n % 3 != 0)
        {
            n = n - 1;
        }
        else if (n % 6 == 0)
        {
            n = n / 3;
        }
        else if (n % 2 == 0)
        {
            if (dpVec[n - 1] < dpVec[(n) / 2])
            {
                n = n - 1;
            }
            else
            {
                n = n / 2;
            }
        }
        else if (n % 3 == 0)
        {
            if (dpVec[n - 1] < dpVec[(n) / 3])
            {
                n = n - 1;
            }
            else
            {
                n = n / 3;
            }
        }
    }
    while (!sequences.empty())
    {
        cout << sequences.front() << " ";
        sequences.pop_front();
    }
    cout << "\n";
}

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
    unordered_map<int, int> umap;
    int dpVec[n + 1];
    dpVec[0] = 0;
    dpVec[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if ((i) % 6 == 0)
        {
            dpVec[i] = smallest(dpVec[(i) / 3] + 1, dpVec[(i) / 2] + 1, dpVec[i - 1] + 1);
        }
        else if ((i) % 3 == 0)
        {
            dpVec[(i)] = min(dpVec[(i) / 3] + 1, dpVec[i - 1] + 1);
        }
        else if ((i) % 2 == 0)
        {
            dpVec[(i)] = min(dpVec[(i) / 2] + 1, dpVec[i - 1] + 1);
        }
        else
        {
            dpVec[i] = dpVec[i - 1] + 1;
        }
    }
    cout << dpVec[n] << endl;
    printMap(n, dpVec);

    return dpVec[n];
}
int main()
{
    primitiveCalculator(5);
}