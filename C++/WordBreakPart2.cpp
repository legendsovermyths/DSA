// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isValid(vector<string> &dict, string newStr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (newStr == dict[i])
            {
                return true;
            }
        }
        return false;
    }

    void SolutionUtil(vector<string> &answers, string remaining, vector<string> &dict, int n, string answer)
    {
        if (remaining == "")
        {
            answer = answer.substr(0, answer.size() - 1);
            answers.push_back(answer);
            return;
        }
        for (int i = 0; i < remaining.size(); i++)
        {
            string newStr = remaining.substr(i);
            if (isValid(dict, newStr, n))
            {
                string ne = newStr + " " + answer;
                SolutionUtil(answers, remaining.substr(0, i), dict, n, ne);
            }
        }
    }

    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        vector<string> answers;
        SolutionUtil(answers, s, dict, n, "");
        return answers;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends