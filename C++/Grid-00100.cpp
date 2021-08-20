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

void fillUp(vector<vector<int>> &Grid, int &strtCol, vector<int> &Row, vector<int> &Col, int n, int k, bool &checker, int &counter)
{
    int c = strtCol;
    int i = 0;
    while (c < n)
    {
        Grid[i][c] = 1;
        Row[i] += 1;
        Col[c] += 1;
        i++;
        c++;

        counter++;
        if (counter == k)
        {
            checker = true;
            return;
        }
    }
    strtCol++;
}
void fillDown(vector<vector<int>> &Grid, int &strtRow, vector<int> &Row, vector<int> &Col, int n, int k, bool &checker, int &counter)
{
    int r = strtRow;
    int c = 0;
    while (r < n)
    {
        Grid[r][c] = 1;
        Row[r] += 1;
        Col[c] += 1;
        r++;
        c++;

        counter++;
        if (counter == k)
        {
            checker = true;
            return;
        }
    }
    strtRow--;
}
void Solution(int n, int k)
{
    vector<int> Row(n, 0);
    vector<int> Col(n, 0);
    vector<vector<int>> Grid(n, vector<int>(n, 0));
    int strtCol = 0;
    int strtRow = n - 1;
    bool checker = false;
    int i = 0;
    int counter = 0;
    if (k == 0)
        checker = true;
    while (!checker)
    {
        if (i & 1)
            fillDown(Grid, strtRow, Row, Col, n, k, checker, counter);
        else
            fillUp(Grid, strtCol, Row, Col, n, k, checker, counter);
        i++;
    }
    int maxR = *max_element(all(Row));
    int minR = *min_element(all(Row));
    int maxC = *max_element(all(Col));
    int minC = *min_element(all(Col));
    int answer = pow(maxR - minR, 2) + pow(maxC - minC, 2);
    cout << answer << endl;
    loop(i, n)
    {
        loop(j, n) cout << Grid[i][j];
        cout << "\n";
    }
    return;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    w(T)
    {
        int n, k;
        cin >> n >> k;
        Solution(n, k);
    }
}