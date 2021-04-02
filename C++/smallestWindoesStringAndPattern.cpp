// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"

class Solution
{
public:
    string smallestWindow(string s, string p)
    {
        int count1 = s.length();
        int count2 = p.length();
        if (count1 < count2)
            return "-1";
        vector<int> strin(256, 0);
        vector<int> pat(256, 0);
        for (int i = 0; i < count2; i++)
        {
            pat[p[i]]++;
        }
        int start = 0;
        int stratIndex = -1;
        int tollength = 0;
        int window = 0;
        int MinWindow = INT_MAX;
        for (int i = 0; i < count1; i++)
        {
            strin[s[i]]++;
            if (strin[s[i]] <= pat[s[i]])
            {
                tollength++;
            }
            if (count2 == tollength)
            {
                while (strin[s[start]] > pat[s[start]] || pat[s[start]] == 0)
                {
                    if (strin[s[start]] > pat[s[start]])

                        strin[s[start]]--;
                    start++;
                }
                window = i - start + 1;
                if (window < MinWindow)
                {
                    MinWindow = window;
                    stratIndex = start;
                }
            }
        }
        if (stratIndex == -1)
            return "-1";
        return s.substr(stratIndex, MinWindow);
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
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
} // } Driver Code Ends