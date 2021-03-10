#include <bits/stdc++.h>
using namespace std;
int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            return 0;
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        vector<int> mem(n, 0);
        mem[0] = vec[0];
        int answer = 0;
        for (int i = 1; i < n; i++)
            mem[i] = mem[i - 1] + vec[i];
        for (int i = 0; i < n - 1; i++)
            answer = abs(mem[i]) + answer;

        cout << answer << endl;
    }
    return 0;
}