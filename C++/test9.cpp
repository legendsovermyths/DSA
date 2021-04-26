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
    string s = "Anirudh";
    cout << s.substr(0, 5) << endl;
    queue<int> q;
}
