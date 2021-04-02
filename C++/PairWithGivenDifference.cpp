#include <bits/stdc++.h>
using namespace std;
void Solution(vector<int> &dp, int diff, int n)
{

    sort(dp.begin(), dp.end());
    int left = 0, right = 1;
    while (right >= left && right < n)
    {
        if (dp[right] - dp[left] > diff)
        {
            left++;
        }
        else if (dp[right] - dp[left] < diff)
        {
            right++;
        }
        else if (dp[right] - dp[left] == diff)
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int diff;
        cin >> diff;
        vector<int> dp;
        cout << n;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            dp.push_back(t);
        }
        Solution(dp, diff, n);
    }
    return 0;
}