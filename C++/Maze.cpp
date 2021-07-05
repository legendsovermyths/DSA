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

vector<int> x_moves = {1, -1, 0, 0};
vector<int> y_moves = {0, 0, 1, -1};
int n, m;

void DFS(vector<string> &Matrix, int i, int j, int &req, int required)
{
    // cout << req << endl;
    if (req == required)
        return;
    for (int q = 0; q < 4; q++)
    {
        int new_x = i + x_moves[q];
        int new_y = j + y_moves[q];
        if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && Matrix[new_x][new_y] != '#' && Matrix[new_x][new_y] != 'F' && req < required)
        {
            Matrix[new_x][new_y] = 'F';
            req += 1;
            DFS(Matrix, new_x, new_y, req, required);
        }
    }
}

int main()
{
    int k;
    cin >> n >> m >> k;
    vector<string> Matrix(n);
    int count_s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> Matrix[i];
    }
    if (k == 0)
    {
        loop(i, n)
        {
            cout << Matrix[i] << endl;
        }
        return 0;
    }
    int st_i, st_j;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matrix[i][j] == '.')
            {
                st_i = i;
                st_j = j;
                count_s++;
            }
        }
    }
    int required = count_s - k;
    // deb(required);
    int req = 0;
    DFS(Matrix, st_i, st_j, req, required);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matrix[i][j] == 'F')
                Matrix[i][j] = '.';
            else if (Matrix[i][j] == '.')
                Matrix[i][j] = 'X';
        }
    }
    loop(i, n)
    {
        cout << Matrix[i] << endl;
    }
    return 0;
}