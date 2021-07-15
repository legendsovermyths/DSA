#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vec(2 * n, 0);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        vector<int> answer(2 * n, 0);
        for (int i = 0; i < 2 * n; i += 2)
        {
            answer[i] = vec[i / 2];
        };
        for (int i = 1; i < 2 * n; i += 2)
        {
            answer[i] = vec[2 * n - i / 2 - 1];
        }
        for (int i = 0; i < 2 * n; i++)
        {
            cout << answer[i] << ' ';
        }
        cout << endl;
    }
}