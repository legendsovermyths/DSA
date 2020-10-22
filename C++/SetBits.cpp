
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int N, int count)
    {
        if (N == 0)
        {
            return count;
        }
        if (N % 2 == 1)
        {
            return (helper(int(N / 2), count + 1));
        }
        return helper(N / 2, count);
    }
    int setBits(int N)
    {
        int count = 0;

        count = helper(N, 0);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
