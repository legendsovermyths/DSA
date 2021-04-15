#include <bits/stdc++.h>
using namespace std;
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

bool isBridge(ll key, vi vec2, ll n2)
{
    ll left = 0, right = n2 - 1;
    while (left <= right)
    {
        ll mid = (right + left) / 2;
        if (vec2[mid] == key)
        {
            return 1;
        }
        else if (vec2[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}

ll solve(vi vec1, vi vec2, ll n1, ll n2)
{
    vi bridges;
    loop(i, n1)
    {
        if (isBridge(vec1[i], vec2, n2))
        {
            bridges.push_back(vec1[i]);
        }
    }
    if (bridges.size() == 0)
    {
        ll sum1 = 0;
        ll sum2 = 0;
        loop(i, n1) sum1 += vec1[i];
        loop(i, n1) sum2 += vec2[i];
        return max(sum1, sum2);
    }
    vi arr1;
    vi arr2;
    ll k = 0;
    ll sum1 = 0;
    ll sum2 = 0;
    loop(i, n1)
    {
        if (vec1[i] == bridges[k])
        {
            arr1.push_back(sum1);
            arr1.push_back(vec1[i]);
            sum1 = 0;
            k++;
        }
        else
        {
            sum1 += vec1[i];
        }
    }
    k = 0;
    arr1.push_back(sum1);
    loop(i, n2)
    {
        if (vec2[i] == bridges[k])
        {
            arr2.push_back(sum2);
            arr2.push_back(vec2[i]);
            sum2 = 0;
            k++;
        }
        else
        {
            sum2 += vec2[i];
        }
    }
    arr2.push_back(sum2);
    ll to_return = 0;
    ll n = arr1.size();
    loop(i, n)
    {
        to_return += max(arr1[i], arr2[i]);
    }
    return to_return;
}

int main()
{
    while (true)
    {
        ll n1;
        cin >> n1;
        if (n1 == 0)
            break;
        vi vec1(n1, 0);
        loop(i, n1)
        {
            cin >> vec1[i];
        }
        ll n2;
        cin >> n2;
        vi vec2(n2, 0);
        loop(i, n2)
        {
            cin >> vec2[i];
        }
        cout << solve(vec1, vec2, n1, n2) << endl;
    }
    return 0;
}
// 4 -5 100 1000 1005
//3 -12 1000 1001