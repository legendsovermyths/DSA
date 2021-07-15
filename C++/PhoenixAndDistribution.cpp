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
    w(t)
    {
        int n, k;
        cin >> n >> k;
        string arr;
        cin >> arr;
        sort(arr.begin(), arr.end());
        if (k == n)
        {
            cout << arr[n - 1] << endl;
            continue;
        }
        char prev = arr[0];
        char current;
        int count = 0;
        loop(i, k)
        {
            current = arr[i];
            if (prev != current)
            {
                count++;
            }
            prev = arr[i];
        }
        if (count >= 1)
        {
            string s1 = arr[0] + arr.substr(k);
            bool ans = arr[0] < arr[k - 1];
            if (ans)
                cout << arr[k - 1] << endl;
            else
                cout << s1 << endl;
            continue;
        }
        prev = arr[k];
        current;
        count = 0;
        Loop(i, k, n)
        {
            current = arr[i];
            if (prev != current)
            {
                count++;
            }
            prev = arr[i];
        }
        if (count >= 1)
        {
            string s1 = arr[0] + arr.substr(k);
            bool ans = arr[0] < arr[k - 1];
            if (ans)
                cout << arr[k - 1] << endl;
            else
                cout << s1 << endl;
        }
        else
        {
            vector<string> answer(k);
            loop(i, n)
            {
                answer[i % k] += arr[i];
            }
            string ans = *max_element(answer.begin(), answer.end());
            cout << ans << endl;
        }
    }
    return 0;
}