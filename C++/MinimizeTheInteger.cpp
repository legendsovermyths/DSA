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

void Solution(string s)
{
    vi even, odd;
    loop(i, s.length())
    {
        if ((s[i] - '0') & 1)
            odd.push_back(s[i] - '0');
        else
            even.push_back(s[i] - '0');
    }
    int n = even.size(), m = odd.size();
    int i = 0, j = 0;
    vi answer(m + n, 0);
    while (i < n && j < m)
    {
        if (even[i] - '0' < odd[j] - '0')
        {
            answer[i + j] = even[i];
            i++;
        }
        else
        {
            answer[i + j] = odd[j];
            j++;
        }
    }
    while (i < n)
    {
        answer[i + j] = even[i];
        i++;
    }
    while (j < m)
    {
        answer[i + j] = odd[j];
        j++;
    }
    loop(i, m + n) cout << answer[i];
    cout << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    w(t)
    {
        string s;
        cin >> s;
        Solution(s);
    }
}