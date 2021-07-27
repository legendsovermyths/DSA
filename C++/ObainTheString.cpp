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
void Solution()
{
    string s, z;
    cin >> s;
    cin >> z;
    unordered_map<char, vector<int>> umap;

    loop(i, s.length())
    {
        umap[s[i]].push_back(i);
    }
    loop(i, z.length())
    {
        if (umap[z[i]].empty())
        {
            cout << -1 << endl;
            return;
        }
    }
    int Curr = -1;
    int count = 1;

    loop(i, z.length() - 1)
    {
        int index = Search(umap[z[i]], Curr);
        Curr = umap[z[i]][index] + 1;
        int index2 = Search(umap[z[i + 1]], Curr);
        // deb2(index, index2);
        if (index2 >= umap[z[i + 1]].size() || umap[z[i]][index] >= umap[z[i + 1]][index2])
        {
            count++;
            Curr = -1;
        }
    }
    cout << count << endl;
}

int main()
{
    w(t)
    {
        Solution();
    }
}