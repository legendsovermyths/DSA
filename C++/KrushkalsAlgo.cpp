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

int N = 1000;
vl parents(N, 0);
vl size(N, 0);

void initialize(int i)
{
    parents[i] = i;
    size[i] = 1;
}

int find_n(int i)
{
    if (parents[i] == i)
        return i;
    return parents[i] = find_n(parents[i]);
}

void Union(int a, int b)
{
    a = find_n(a);
    b = find_n(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parents[b] = a;
        size[a] += size[b];
    }
}

// int main()
// {
//     loop(i, N)
//     {
//         initialize(i);
//     }
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> edges;
//     loop(i, n)
//     {
//         int u, v;
//         cin >> u >> v;
//         edges.push_back({u, v});
//     }
//     bool cycle = false;
//     for (auto i : edges)
//     {
//         int u = i[0];
//         int v = i[1];
//         int x = find_n(u);
//         int y = find_n(v);
//         if (x == y)
//         {
//             cycle = true;
//         }
//         else
//         {
//             Union(u, v);
//         }
//     }
//     if (cycle)
//     {
//         cout << "cycle is present" << endl;
//     }
//     else
//     {
//         cout << "cycle is not present" << endl;
//     }
// }

int main()
{
    loop(i, N)
    {
        initialize(i);
    }
    int m, n;
    cin >> m >> n;
    vector<vector<int>> edges;
    int cost = 0;
    loop(i, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    for (auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        if (find_n(u) == find_n(v))
        {
            continue;
        }
        else
        {
            cout << u << " " << v << endl;
            Union(u, v);
            cost += w;
        }
    }
    cout << cost << endl;
    return 0;
}