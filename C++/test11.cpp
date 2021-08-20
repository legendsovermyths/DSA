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

class Solution
{
public:
    string CountAndPrint(string s)
    {
        vector<int> vec;
        char prev = s[0];
        int count = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == prev)
            {
                count++;
            }
            else
            {
                vec.push_back(count);
                prev = s[i];
                count = 1;
            }
        }
        vec.push_back(count);
        int j = 0;
        int k = 0;
        string str = "";
        while (k < vec.size())
        {
            str = str + to_string(vec[k]) + s[j];
            j = j + vec[k];
            k = k + 1;
        }
        return str;
    }
    string countAndSay(int n)
    {

        if (n == 1)
        {
            return "1";
        }
        string s = "11";
        for (int i = 1; i < n - 1; i++)
        {
            s = CountAndPrint(s);
        }
        return s;
    }
};
int main()
{
    w(t)
    {
        ll d, D, P, Q;
        cin >> D >> d >> P >> Q;
        ll x = D / d;
        ll ans = ((x - 1) * P + ((x * (x - 1)) / 2 * Q)) * d;
        ans += P * d;
        ans += (P + x * Q) * (D % d);
        cout << ans << endl;
    }
}