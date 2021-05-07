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

vector<vector<int>> win = {{0, 1, 2},
                           {3, 4, 5},
                           {6, 7, 8},
                           {0, 3, 6},
                           {1, 4, 7},
                           {2, 5, 8},
                           {0, 4, 8},
                           {2, 4, 6}};

int isCWin(string board, char c)
{
    int checker = 0;
    for (int i = 0; i < 8; i++)
        if (board[win[i][0]] == c &&
            board[win[i][1]] == c &&
            board[win[i][2]] == c)
            checker++;
    return checker;
}

int isValid(string board)
{
    int xCount = 0, oCount = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 'X')
            xCount++;
        if (board[i] == 'O')
            oCount++;
    }
    if (xCount == oCount || xCount == oCount + 1)
    {
        if (isCWin(board, 'O') == 1 && xCount != oCount)
        {
            return 3;
        }
        if (isCWin(board, 'O') == 1 && xCount == oCount)
        {
            if (isCWin(board, 'X') == 1)
                return 3;
            return 1;
        }
        if (isCWin(board, 'X') == 1 && xCount != oCount + 1)
            return 3;
        if (isCWin(board, 'X') == 1 && xCount == oCount + 1)
            return 1;
        if (xCount == 5 && oCount == 4)
            return 1;
        return 2;
    }
    return 3;
}

int main()
{
    w(T)
    {
        string board = "";
        loop(i, 9)
        {
            char c;
            cin >> c;
            board = board + c;
        }
        cout << isValid(board) << endl;
    }
}