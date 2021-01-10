// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        cout << isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
} // } Driver Code Ends

/*You are required to complete this method */
bool isInterleave(string A, string B, string C)
{
    int Alen = A.length();
    int Blen = B.length();
    int Clen = C.length();
    vector<vector<bool>> vec(Alen, vector<bool>(Blen, false));
    if (Clen != Alen + Blen)
    {
        return false;
    }
    int j = 0, k = 0;
    for (int i = 0; i < Clen; i++)
    {
        if (C[i] == A[j])
        {
            vec[j++][k] = true;
            if (j == Alen)
                j = Alen - 1;
        }
        else if (C[i] == B[k])
        {
            vec[j][k++] = true;
            if (k == Blen)
                k = Blen - 1;
        }
    }
    for (int i = 0; i < Alen; i++)
    {
        for (int j = 0; j < Blen; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return vec[Alen - 1][Blen - 1];
}
