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

void Solve(string s, vector<string> &vec, int dots, int finaldots, bool &solved)
{

    if (dots >= finaldots && solved == false)
    {

        vec[vec.size() - 1] += s;
        cout << "YES" << endl;
        loop(i, vec.size())
        {
            cout << vec[i] << endl;
        }
        solved = true;
        return;
    }

    int si = s.length();
    int k = 0;
    loop(i, si)
    {
        if (s[i] == '.')
        {
            break;
        }
        k++;
    }
    loop(i, 3)
    {
        if (k <= 8 && s.length() >= k + i + 1)
        {
            string sub = s.substr(k + i + 2);
            string sub2 = s.substr(0, k + i + 2);
            vec.push_back(sub2);
            Solve(sub, vec, dots + 1, finaldots, solved);
            vec.pop_back();
        }
    }
}

int main()
{
    vector<string> vec;
    string s = "read.meexample.txtb.cpp";
    int dots = 0;
    int finalDots = 0;
    bool solved = false;
    int si = s.length();
    int k = 0;
    loop(i, s.size())
    {
        if (s[i] == '.')
        {
            finalDots++;
        }
    }
    Loop(i, si - 1, -1)
    {
        if (k > 3)
        {
            cout << "NO" << endl;
            return 0;
        }
        if (s[i] == '.')
        {
            break;
        }
        k++;
    }
    Solve(s, vec, dots, finalDots, solved);
    if (!solved)
        cout << "NO" << endl;
}