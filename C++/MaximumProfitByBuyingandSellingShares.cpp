#include <bits/stdc++.h>
using namespace std;
int Solution(vector<int> stocks, int n)
{
    vector<int> profit(n, 0);
    int max_profit = stocks[n - 1];
    for (int i = n - 2; i > 0; i--)
    {
        if (stocks[i] > max_profit)
        {
            max_profit = stocks[i];
        }
        profit[i] = max(profit[i + 1], max_profit - stocks[i]);
    }
    int min_profit = stocks[0];
    for (int i = 0; i < n; i++)
    {
        cout << profit[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        if (min_profit > stocks[i])
        {
            min_profit = stocks[i];
        }
        profit[i] = max(profit[i - 1], profit[i] + stocks[i] - min_profit);
    }
    "hello";
    for (int i = 0; i < n; i++)
    {
        cout << profit[i] << " ";
    }
    cout << endl;

    return profit[n - 1];
}
int main()
{
    vector<int> stocks = {100, 30, 15, 10, 8, 25, 80};
    cout << Solution(stocks, 7);
}