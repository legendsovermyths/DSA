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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    w(t)
    {
        bool checker = true;
        int n;
        cin >> n;
        int k = n;
        vl arr(2 * n, 0);
        loop(i, 2 * n) cin >> arr[i];
        sort(all(arr), greater<ll>());
        ll tempres = 0;
        for (int i = 0; i < 2 * k; i += 2)
        {
            if (arr[i] != arr[i + 1])
            {
                cout << "NO" << endl;
                checker = false;
                break;
            }
            else if (i < 2 * n - 2 && arr[i] == arr[i + 2])
            {
                cout << "NO" << endl;
                checker = false;
                break;
            }
            else
            {
                arr[i] -= 2 * tempres;
                if (arr[i] % (2 * n) != 0)
                {
                    checker = false;
                    cout << "NO" << endl;
                    break;
                }
                else
                {
                    arr[i] /= (2 * n);
                }
                n--;
                tempres += arr[i];
            }
        }
        unordered_map<int, int> umap;
        if (checker)
        {
            for (int i = 0; i < 2 * k; i += 2)
            {
                if (arr[i] <= 0 || umap[arr[i]] == 1)
                {
                    checker = false;
                    cout << "NO" << endl;
                    break;
                }
                umap[arr[i]] = 1;
            }
            if (checker)
                cout << "YES" << endl;
        }
    }
}