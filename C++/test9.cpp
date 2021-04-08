#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> dp[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int bishu;
        cin >> bishu;
        int total = 0;
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] <= bishu)
            {
                total++;
                answer = answer + dp[i];
            }
        }
        cout << total << " " << answer << endl;
    }
    return 1;
}
