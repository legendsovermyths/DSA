// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int minFlips(string s);
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << minFlips(s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int minFlips(string S)
{
    int count = S.length();
    int coun = 0;
    for (int i = 0; i < count; i++)
    {
        if (i % 2 == 0)
        {
            if (S[i] != '1')
            {
                coun++;
            }
        }
        else
        {
            if (S[i] != '0')
            {
                coun++;
            }
        }
    }
    return min(coun, count - coun);
}