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

int Sum(vector<int> Row, int i, int j)
{
    int sum = 0;
    for (int k = j; k <= i; k++)
    {
        sum += Row[k];
    }
    return sum;
}

int CheckTemp(vector<int> temp)
{
    unordered_map<int, int> umap;
    umap[0] = 1;
    int sum = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        sum += temp[i];
        if (umap[sum])
            return i;
        umap[sum]++;
    }
    return -1;
}
void Solution(int row, int col, vector<vector<int>> &Matrix)
{
    int answer;
    int st = -1, ed = -1;
    vector<int> temp(row, 0);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 0; k < row; k++)
            {
                temp[k] = Sum(Matrix[k], i, j);
            }
            int index = CheckTemp(temp);
            if (index != -1)
            {
                cout << index << endl;
                if (ed - st < i - j)
                {
                    for (int l = 0; l < row; l++)
                    {
                        cout << temp[l] << ' ';
                    }
                    ed = i;
                    st = j;
                    answer = index;
                }
            }
        }
    }
    cout << answer << " " << st << " " << ed;
}
int main()
{
    int row = 4, col = 4;
    vector<vector<int>> Matrix = {{9, 7, 16, 5}, {1, -6, -7, 3}, {1, 8, 7, 9}, {7, -2, 0, 10}};
    Solution(row, col, Matrix);
}