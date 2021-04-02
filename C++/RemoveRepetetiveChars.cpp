// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string removeConsecutiveCharacter(string S)
    {
        stack<char> s;
        int count = S.length();
        s.push(S[0]);
        for (int i = 0; i < count; i++)
        {
            if (s.top() != S[i])
            {
                s.push(S[i]);
            }
        }
        string to_return = "";
        count = s.size();
        for (int i = 0; i < count; i++)
        {
            to_return = s.top() + to_return;
            s.pop();
        }
        return to_return;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsecutiveCharacter(s) << endl;
    }
}

// } Driver Code Ends