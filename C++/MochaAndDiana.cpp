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

void initialize(int i, vi &parents, vi &size)
{
    parents[i] = i;
    size[i] = 1;
}

int find_n(int i, vi &parents)
{
    if (parents[i] == i)
        return i;
    return parents[i] = find_n(parents[i], parents);
}

void Union(int a, int b, vi &parents, vi &size)
{
    a = find_n(a, parents);
    b = find_n(b, parents);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parents[b] = a;
        size[a] += size[b];
    }
}
int main()
{
    vi parents1(N, 0);
    vi size1(N, 0);
    vi parents2(N, 0);
    vi size2(N, 0);
    loop(i, N)
    {
        initialize(i, parents1, size1);
        initialize(i, parents2, size2);
    }
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> edges1;
    vector<vector<int>> dp1(n, vector<int>(n, 0));
    vector<vector<int>> dp2(n, vector<int>(n, 0));
    vector<vector<int>> edges2;
    loop(i, m1)
    {
        int u, v;
        cin >> u >> v;
        if (dp1[u - 1][v - 1] == 0)
        {
            edges1.push_back({u - 1, v - 1});
            dp1[u - 1][v - 1] = 1;
            dp1[v - 1][u - 1] = 1;
        }
    }
    loop(i, m2)
    {
        int u, v;
        cin >> u >> v;
        if (dp2[u - 1][v - 1] == 0)
        {
            edges2.push_back({u - 1, v - 1});
            dp2[u - 1][v - 1] = 1;
            dp2[v - 1][u - 1] = 1;
        }
    }
    for (auto i : edges1)
    {
        int u = i[0];
        int v = i[1];
        int x = find_n(u, parents1);
        int y = find_n(v, parents1);
        Union(x, y, parents1, size1);
    }
    for (auto i : edges2)
    {
        int u = i[0];
        int v = i[1];
        int x = find_n(u, parents2);
        int y = find_n(v, parents2);
        Union(x, y, parents2, size2);
    }
    vector<vector<int>> answer;

    loop(i, n)
    {
        loop(j, n)
        {
            if (dp1[i][j] == 0 && dp2[i][j] == 0)
            {
                int x1 = find_n(i, parents1);
                int x2 = find_n(i, parents2);
                int y1 = find_n(j, parents1);
                int y2 = find_n(j, parents2);
                if (x1 != y1 && x2 != y2)
                {
                    answer.push_back({i, j});
                    Union(i, j, parents2, size2);
                    Union(i, j, parents1, size1);
                }
            }
        }
    }
    cout << answer.size() << endl;
    loop(i, answer.size())
    {
        cout << answer[i][0] + 1 << " " << answer[i][1] + 1;
        cout << "\n";
    }
}