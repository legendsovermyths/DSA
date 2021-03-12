#include <bits/stdc++.h>
using namespace std;
int Algorithm(int A[], int n)
{
    int tempMax = 0, maxFinal = 0, curr = 0;
    tempMax = A[0];
    for (int i = 1; i < n; i++)
    {
        tempMax = max(tempMax + A[i], A[i]);
        if (maxFinal < tempMax)
            maxFinal = tempMax;
    }
    return maxFinal;
}
int main()
{
    int A[] = {4, -1, 8, -1, 14};
    int n = 5;
    cout << Algorithm(A, n) << endl;
    return 0;
}