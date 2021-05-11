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

int findNumbers(map<int, vector<int>> &umap, int r, int i, int n)
{
    int x = 1;
    int counter = 0;

    counter = umap[r].size() - 1;
    umap[r].pop_back();
    while (i * x + r <= n)
    {
        counter += umap[i * x + r].size();

        x++;
    }

    return counter;
}
int main()
{
    w(T)
    {
        int n, m;
        cin >> n >> m;
        int counter = 0;
        map<int, vector<int>> umap;
        Loop(i, 1, n + 1)
        {
            umap[m % i].push_back(i);
        }
        // itr(it, umap)
        // {
        //     cout << it->first << ": ";
        //     // loop(i, it->second.size())
        //     // {
        //     //     cout << it->second[i] << " ";
        //     // }
        //     // cout << endl;
        // }
        Loop(i, 1, n + 1)
        {
            int r = m % i;
            counter += findNumbers(umap, r, i, n);
        }
        cout << counter << endl;
    }
    return 0;
}