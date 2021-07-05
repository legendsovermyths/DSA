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

void MakePairs(int low, int high, vector<pair<int, int>> &pairs)
{
    pair<int, int> p = {low, high};
    pairs.push_back(p);
    int k = (low + high) / 2;
    if (k - 1 >= low)
    {
        MakePairs(low, k - 1, pairs);
    }
    if (k + 1 <= high)
    {
        MakePairs(k + 1, high, pairs);
    }
}
bool sort2(pair<int, int> p1, pair<int, int> p2)
{
    int l1 = p1.second - p1.first;
    int l2 = p2.second - p2.first;
    if (l1 != l2)
    {
        return l1 > l2;
    }
    else
    {
        return p1.first < p2.first;
    }
}
int main()
{
    w(T)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> pairs;
        MakePairs(1, n, pairs);
        sort(pairs.begin(), pairs.end(), sort2);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << pairs[i].first << ":" << pairs[i].second << endl;
        // }
        vector<int> arr(n + 1, 0);
        loop(i, n)
        {
            int k = (pairs[i].first + pairs[i].second) / 2;
            arr[k] = i + 1;
        }
        loop(i, n)
        {
            cout << arr[i + 1] << " ";
        }
        cout << endl;
    }
    return 0;
}
