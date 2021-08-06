// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void Sol(vector<string> &answer, string s, int currIndex, string ans)
    {
        if (currIndex == s.length())
            return;
        Sol(answer, s, currIndex + 1, ans);
        answer.push_back(ans + s[currIndex]);
        Sol(answer, s, currIndex + 1, ans + s[currIndex]);
    }
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> answer;
        Sol(answer, s, 0, "");
        sort(answer.begin(), answer.end());
        return answer;
    }
};

// { Driver Code Starts.
int main()
{
    string s = "abcdef";
    Solution ob;
    vector<string> res = ob.AllPossibleStrings(s);
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
    return 0;

} // } Driver Code Ends