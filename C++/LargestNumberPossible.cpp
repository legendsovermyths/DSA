// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    string findLargest(int N, int S)
    {
        if (S == 0 && N != 1)
        {
            return "-1";
        }
        if (N * 9 < S)
        {
            return "-1";
        }
        if (N == 1)
        {
            return to_string(S);
        }
        string answer = "";
        string ss = to_string(S);
        if (S < 9)
        {
            answer = answer + ss;
            N = N - 1;
            while (N--)
            {
                answer = answer + '0';
            }
            return answer;
        }
        else
        {
            while (N > 0 && S >= 9)
            {
                answer = answer + '9';
                S = S - 9;
                N = N - 1;
            }
            if (S > 0 && N > 0)
            {
                answer = answer + to_string(S);
                N = N - 1;
            }
            while (N > 0)
            {
                answer = answer + "0";
                N--;
            }
            return answer;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, S;
        cin >> N >> S;

        Solution ob;
        cout << ob.findLargest(N, S) << "\n";
    }
    return 0;
} // } Driver Code Ends