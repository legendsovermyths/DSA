#include <iostream>
#include <vector>
using namespace std;
long long int catalanNumber(int n)
{
    vector<long long int> dpVec(n + 1, 0);
    dpVec[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dpVec[i] += dpVec[i - 1 - j] * dpVec[j];
        }
    }
    return dpVec[n];
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        long long int batao;
        cin >> batao;
        cout << catalanNumber(batao) << endl;
    }
}