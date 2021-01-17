// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    int maxSubstring(string S)
    {
        int n = S.length();
        int tempSum = 0, finalSum = 0;
        tempSum = S[0] == 0 ? 1 : -1;
        finalSum = tempSum;
        for (int i = 1; i < n; i++)
        {
            if (S[i] == '0')
            {
                tempSum = max(tempSum + 1, 1);
                if (tempSum > finalSum)
                    finalSum = tempSum;
            }
            if (S[i] == '1')
            {
                tempSum = max(tempSum - 1, -1);
                if (tempSum > finalSum)
                    finalSum = tempSum;
            }
        }
        return finalSum;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.maxSubstring(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends