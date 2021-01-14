// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    int longestSubsequence(int N, int A[])
    {
        int M = *max_element(A, A + N);
        vector<int> dpVec(M + 1, 0);
        for (int i = 0; i < N; i++)
        {
            if (A[i] > 0 && A[i] < M)
                dpVec[A[i]] = max(dpVec[A[i] - 1], dpVec[A[i] + 1]) + 1;
            else if (A[i] == 0)
                dpVec[A[i]] = dpVec[A[i] + 1] + 1;
            else if (A[i] == M)
                dpVec[A[i]] = dpVec[A[i] - 1] + 1;
        }
        int to_Return = *max_element(dpVec.begin(), dpVec.end());
        // for (int i = 0; i <= M; i++)
        // {
        //     cout << dpVec[i] << " ";
        // }
        // std::cout << std::endl;
        return to_Return;
    }
};

// { Driver Code Starts.

int main()
{

    int N = 7;
    int A[N] = {10, 9, 4, 5, 4, 8, 6};

    Solution ob;
    cout << ob.longestSubsequence(N, A) << endl;

    return 0;
} // } Driver Code Ends