#include <bits/stdc++.h>
using namespace std;
int solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int right = n - 1;
    int left = 0;
    int count = 0;
    while (left < n)
    {
        if (s[left] == '*')
        {
            s[left] = 'x';
            count++;
            break;
        }
        left++;
    }
    while (right >= 0)
    {
        if (s[right] == '*' && right != left)
        {
            s[right] = 'x';
            count++;
            break;
        }
        right--;
    }
    while (left + k < n && left < right)
    {

        left = left + k;
        if (left >= right)
        {
            return count;
        }
        if (s[left] == '*')
        {
            s[left] = 'x';
            count++;
        }
        else if (s[left] == 'x')
        {
            return count;
        }
        else
        {
            while (left >= 0 && s[left] != '*')
            {
                left--;
                if (s[left] == '*')
                {
                    s[left] = 'x';
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}