#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &stocks)
{
    int count = stocks.size();
    int maxProfit = 0;
    int tempprofit = 0;
    int mini = INT_MAX;
    for (int i = 0; i < count; i++)
    {
        if (stocks[i] < mini)
        {
            mini = stocks[i];
        }
        maxProfit = max(maxProfit, stocks[i] - mini);
    }
    return maxProfit;
}
int main()
{
    vector<int> stocks = {7, 6, 5, 4, 3, 2, 1};
    cout << solution(stocks);
}