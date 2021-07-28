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
int Search(vector<int> &vec, int curr)
{
    int left = 0, right = vec.size() - 1;
    int mid = (right + left) / 2;
    while (left <= right)
    {
        if (curr < vec[mid])
        {
            right = mid - 1;
            mid = (right + left) / 2;
        }
        else if (curr > vec[mid])
        {
            left = mid + 1;
            mid = (right + left) / 2;
        }
        else
        {
            return mid;
        }
    }
    return left;
}

int main()
{
    // vi vec = {1, 2, 4, 6, 8, 10, 24};
    // int index = Search(vec, 2);
    // cout << index << " " << vec[index] << " ";
    unordered_map<char, int> mp;
    mp['c'] = 3;
    mp['a'] = 8;
    mp['t'] = 8;
    mp['j'] = 1;
    for (auto i : mp)
    {
        cout << i.first << ":" << i.second << endl;
    }
    mp.erase('t');
    cout << endl;
    for (auto i : mp)
    {
        cout << i.first << ":" << i.second << endl;
    }
}