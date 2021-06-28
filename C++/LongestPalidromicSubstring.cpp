#include <bits/stdc++.h>
using namespace std;
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define loop(k, n) for (int k = 0; k < n; k++)
#define deb(x) cout << #x << "= " << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define Loop(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define ll long long
#define PI 3.1415926535897932384626
typedef vector<int> vi;
typedef vector<ll> vl;

string longestPalindrome(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int maxi = 1, st = 0, ed = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = s[i] == s[i + 1];
        if (s[i] == s[i + 1])
        {
            st = i;
            ed = i + 1;
            maxi = 2;
        }
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < s.length() - i; j++)
        {
            int k = i + j;
            if (s[k] == s[j])
            {
                dp[j][k] = dp[j + 1][k - 1];
                if (dp[j][k] == 1 && k - j + 1 > maxi)
                {
                    maxi = k - j + 1;
                    st = j;
                    ed = k;
                }
            }
        }
    }
    cout << st << " " << maxi << " " << ed << endl;
    cout << s.substr(st, maxi);

    loop(i, n)
    {
        loop(j, n)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    longestPalindrome("aacabdkacaa");
}