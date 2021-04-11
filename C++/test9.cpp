#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
bool canCook(vector<int> Ranks, long long int order, int time, int n)
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
            cout << sum2 << " ";
        }
        time_taken = 0;
        sum = sum2 + sum;
        sum2 = 0;
    }
    cout << sum << " ";
    return sum >= order;
}
int main()
{
    vector<int> vec = {1, 2, 3, 4};
    int n = 4;
    long long order = 10;
    int time = 11;
    canCook(vec, order, time, n);
    return 0;
}
