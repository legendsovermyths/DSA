// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minimumNumberOfSwaps(string S)
    {
        stack<int> s;
        s.push('s');
        vector<int> openBrackets;
        int count = S.length();
        int k = 0;
        for (int i = 0; i < count; i++)
        {
            if (S[i] == '[')
            {
                openBrackets.push_back(i);
            }
        }
        int answer = 0;
        for (int i = 0; i < count; i++)
        {
            if (S[i] == '[')
            {
                k++;
                s.push('[');
            }
            else if (S[i] == ']' && s.top() == '[')
            {
                s.pop();
            }
            else if (S[i] == ']' && s.top() != '[')
            {
                answer = answer + openBrackets[k] - i;
                swap(S[i], S[openBrackets[k]]);
                s.push('[');
                k++;
            }
        }
        return answer;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0;
} // } Driver Code Ends
