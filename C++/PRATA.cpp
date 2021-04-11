#include <bits/stdc++.h>
using namespace std;
bool canCook(vector<long long int> Ranks, long long int order, int time, int n)
{
    int sum = 0;
    int sum2 = 0;
    int time_taken = 0;
    for (int i = 0; i < n; i++)
    {
        while (time_taken + (sum2 + 1) * Ranks[i] <= time)
        {
            sum2++;
            time_taken = time_taken + sum2 * Ranks[i];
        }
        time_taken = 0;
        sum = sum2 + sum;
        sum2 = 0;
    }
    return sum >= order;
}
long long int solution(vector<long long int> Ranks, long long int order, long long int number_chefs)
{
    if (order == 0)
        return 0;
    sort(Ranks.begin(), Ranks.end());
    long long int upper_limit = 10e8;
    long long int ans = 0;
    long long int right = upper_limit - 1;
    long long int left = 0;
    long long int mid = (right + left) / 2;
    while (left <= right)
    {
        if (!canCook(Ranks, order, mid, number_chefs))
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
        else
        {
            ans = mid;
            right = mid - 1;
            mid = (left + right) / 2;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int order;
        cin >> order;
        long long number_chefs;
        cin >> number_chefs;
        vector<long long int> vec(number_chefs, 0);
        for (int i = 0; i < number_chefs; i++)
        {
            cin >> vec[i];
        }
        cout << solution(vec, order, number_chefs) << endl;
    }
}