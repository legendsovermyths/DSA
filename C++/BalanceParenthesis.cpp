// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return if the paranthesis are balanced or not
    bool ispar(string x)
    {
        stack<char> s;
        s.push('s');
        int count = x.length();
        for (int i = 0; i < count; i++)
        {
            if (x[i] == '}' && s.top() == '{')
            {
                // cout << s.top() << ' ';
                s.pop();
                // cout << s.top() << " ";
            }
            else if (x[i] == ')' && s.top() == '(')
            {
                s.pop();
            }
            else if (x[i] == ']' && s.top() == '[')
            {
                s.pop();
            }
            else if ((x[i] == '{') || (x[i] == '[') || (x[i] == '('))
            {
                s.push(x[i]);
                cout << s.top() << " ";
            }
            else
            {
                return false;
            }
        }
        if (s.size() != 1)
            return false;
        return true;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends