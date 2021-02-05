// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// return a string formed by compressing string s
// do not print anything

class Solution
{
public:
    void CheckAndReturn(stack<char> &st, string &s)
    {
        int count = s.length();
        if (count % 2 == 1)
        {
            st.push(s[count - 1]);
            s.pop_back();
        }
        else
        {
            string s1 = s.substr(0, count / 2);
            string s2 = s.substr(count / 2, count / 2);
            if (s1 == s2)
            {
                cout << s1 << " " << s2 << " ";
                st.push('*');
                st.push(count / 2 - 1);
                s.erase(count / 2, count / 2);
                s.pop_back();
            }
            else
            {
                st.push(s[count - 1]);
                s.pop_back();
            }
        }
    }
    string compress(string s)
    {
        stack<char> st;
        while (s.length() > 0)
        {

            int count = s.length();
            if (count % 2 == 1)
            {
                st.push(s[count - 1]);
                s.pop_back();
            }
            else
            {
                string s1 = s.substr(0, count / 2);
                string s2 = s.substr(count / 2, count / 2);
                if (s1 == s2)
                {
                    st.push('*');
                    st.push(s[count / 2 - 1]);
                    s.erase(count / 2, count / 2);
                    s.pop_back();
                }
                else
                {
                    st.push(s[count - 1]);
                    s.pop_back();
                }
            }
        }
        string toReturn = "";
        while (st.size())
        {
            char j = st.top();
            toReturn = toReturn + j;
            st.pop();
        }
        return toReturn;
    }
};

// { Driver Code Starts.

int main()
{

    string s = "zzzzzzz";
    Solution obj;
    cout << obj.compress(s) << "\n";

    return 0;
}
// } Driver Code Ends
