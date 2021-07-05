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

int main()
{
    w(T)
    {
        int n;
        cin >> n;
        if (n <= 3)
        {
            cout << -1 << endl;
            continue;
        }
        if (n == 4)
        {
            cout << "3 1 4 2" << endl;
            continue;
        }
        int temp = !(n & 1);
        int temp2 = n - temp;
        vector<int> answer(n, 0);
        int odd = 1;
        int i = 0;
        while (odd <= temp2)
        {
            answer[i++] = odd;
            odd += 2;
        }
        // loop(i, n)
        // {
        //     cout << answer[i] << " ";
        // }
        odd -= 2;
        odd -= 3;
        int caution = odd;
        answer[i++] = odd;
        if (temp)
        {
            odd += 4;
            answer[i++] = odd;
        }
        else
        {
            odd += 2;
            answer[i++] = odd;
        }
        while (i < n)
        {
            odd -= 2;
            if (odd != caution)
            {
                answer[i++] = odd;
            }
        }
        loop(i, n)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}