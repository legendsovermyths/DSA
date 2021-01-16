// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
} // } Driver Code Ends

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool sorted(val p1, val p2)
{
    return p1.first < p2.first;
}
int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, sorted);
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            if (p[i].first > p[j].second && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    return dp[n - 1];
}
// {5  24 , 39 60 , 15 28 , 27 40 , 50 90}