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

vector<vector<int>> dp(500, vector<int>(1 << 10, -1));
void Solution(int i, vector<vector<int>> &a, int mask, vector<int> answer, vector<int> &fin, bool &checker)
{

    if (i == a.size())
    {
        if (mask != 0)

        {
            fin = answer;
            checker = true;
        }
        return;
    }
    if (dp[i][mask] == 1)
        return;
    dp[i][mask] = 1;
    if (!checker)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            int newMask = a[i][j] xor mask;
            answer.push_back(j + 1);
            Solution(i + 1, a, newMask, answer, fin, checker);
            answer.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    loop(i, n) loop(j, m) cin >> a[i][j];
    vector<int> fi;
    bool checker = false;
    Solution(0, a, 0, {}, fi, checker);
    if (fi.size() == 0)
        cout << "NIE" << endl;
    else
    {
        cout << "TAK" << endl;
        loop(i, fi.size())
                cout
            << fi[i] << " ";
    }
    return 0;
}