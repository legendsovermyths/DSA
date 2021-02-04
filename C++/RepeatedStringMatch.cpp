// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

public:
    bool CheckForSubstring(string A, string B)
    {
        if (A.length() < B.length())
            return false;
        if (A.find(B) != std::string::npos)
        {
            return 1;
        }
        return 0;
    }

    int repeatedStringMatch(string A, string B)
    {
        int Alen = A.length();
        int Blen = B.length();
        int count = Blen / Alen;
        string A_copy1 = "";
        string A_copy2 = "";
        for (int i = 0; i <= count; i++)
            A_copy1 = A + A_copy1;
        for (int i = 0; i <= count + 1; i++)
            A_copy2 = A + A_copy2;
        if (CheckForSubstring(A, B))
        {
            return 1;
        }
        if (CheckForSubstring(A_copy1, B))
        {
            return count + 1;
        }
        if (CheckForSubstring(A_copy2, B))
        {
            return count + 2;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution obj;
        cout << obj.repeatedStringMatch(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends