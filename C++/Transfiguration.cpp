// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

public:
    int transfigure(string A, string B)
    {
        unordered_map<char, int> umap1;
        unordered_map<char, int> umap2;
        int count = A.length();
        int count2 = B.length();
        if (count != count2)
            return -1;
        for (int i = 0; i < count; i++)
        {
            umap1[A[i]]++;
            umap2[B[i]]++;
        }
        for (int i = 0; i < count; i++)
        {
            if (umap1[A[i]] != umap2[A[i]])
                return -1;
        }
        int answer = 0;
        int j = count - 1;
        int i = count - 1;
        while (j >= 0 && i >= 0)
        {
            if (A[i] != B[j])
            {
                answer++;
                i--;
            }
            j--;
            i--;
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
        string A, B;
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure(A, B) << endl;
    }
} // } Driver Code Ends