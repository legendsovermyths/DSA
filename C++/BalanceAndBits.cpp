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
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<ll> vl;

void Solution(string vec)
{
    int n = vec.length();
    if (vec[0] == '0' || vec[n - 1] == '0')
    {
        cout << "NO" << endl;
        return;
    }
    int count1 = 0, count0 = 0;
    loop(i, n)
    {
        if (vec[i] == '1')
            count1++;
        if (vec[i] == '0')
            count0++;
    }
    if ((count1 & 1) || (count0 & 1))
    {
        cout << "NO" << endl;
        return;
    }
    vector<char> dp(n, '$');
    dp[0] = '(';
    dp[n - 1] = ')';
    loop(i, n)
    {
        if (vec[i] == '0')
        {
            dp[i] = ')';
            break;
        }
    }
    Loop(i, n - 1, -1)
    {
        if (vec[i] == '0')
        {
            dp[i] == '(';
            break;
        }
    }

    int count = 0;
    loop(i, n)
    {
        if (vec[i] == '1' && (count & 1) && dp[i] == '$')
        {
            dp[i] = ')';
            count++;
        }
        else if (vec[i] == '1' && dp[i] == '$')
        {
            dp[i] = '(';
            count++;
        }
    }
    count = 0;
    loop(i, n)
    {
        if (vec[i] == '0' && (count & 1) && dp[i] == '$')
        {
            dp[i] = ')';
            count++;
        }
        else if (vec[i] == '0' && dp[i] == '$')
        {
            dp[i] = '(';
            count++;
        }
    }
    vector<char> dp2(n);
    loop(i, n)
    {
        if (vec[i] == '0' && dp[i] == ')')
            dp2[i] = '(';
        else if (vec[i] == '0' && dp[i] == '(')
            dp2[i] = ')';
        else
            dp2[i] = dp[i];
    }
    cout << "YES" << endl;
    loop(i, n)
    {
        cout << dp[i];
    }
    cout << endl;
    loop(i, n)
    {
        cout << dp2[i];
    }
    cout << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    w(t)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution(s);
    }
}