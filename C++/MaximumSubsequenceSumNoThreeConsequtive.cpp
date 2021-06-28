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

int Solution(vector<int> &arr)
{
    int count = arr.size();
    vector<int> dp(count, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[0] + arr[1]);
    for (int i = 2; i < count; i++)
    {
        if (i > 2)
            dp[i] = max(dp[i - 2] + arr[i], max(arr[i - 1] + arr[i] + dp[i - 3], dp[i - 1]));
        else
            dp[i] = max(arr[0] + arr[1], max(arr[0] + arr[2], arr[1] + arr[2]));
    }
    for (int i = 0; i < count; i++)
    {
        cout << dp[i] << ' ';
    }
    cout << endl;
    return dp[count - 1];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << Solution(arr) << endl;
}