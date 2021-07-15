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

int SUM(int i, int k, int sum, vi &arr, int z, vector<vector<int>> &dp)
{
    if (i >= 0 && i < arr.size() && k >= 0 && z >= 0)
    {

        if (dp[i][z] != -1)
            return dp[i][z];
        sum += max(SUM(i + 1, k - 1, sum, arr, z, dp), SUM(i - 1, k - 1, sum, arr, z - 1, dp)) + arr[i];
        return dp[i][z] = sum;
    }

    return 0;
}

int main()
{
    w(T)
    {
        int n, k, z;
        cin >> n >> k >> z;
        vector<vector<int>> dp(n + 1, vector<int>(z + 2, -1));
        vi arr(n, 0);
        loop(i, n) cin >> arr[i];

        cout << SUM(0, k, 0, arr, z, dp) << endl;
    }
    return 0;
}