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
    vector<vector<bool>> vec(Alen + 1, vector<bool>(Blen + 1, false));
    if (Clen != Alen + Blen)
    {
        return false;
    }
    int j = 0, k = 0;
    for (int i = 0; i < Clen; i++)
    {
        if (C[i] == A[j])
        {
            j = j + 1;
            vec[j][k] = true;
        }
        else if (C[i] == B[k])
        {
            k = k + 1;
            vec[j][k] = true;
        }
    }
    // for (int i = 0; i <= Alen; i++)
    // {
    //     for (int j = 0; j <= Blen; j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    j = 0;
    k = 0;
    for (int i = 0; i < Clen; i++)
    {

        if (C[i] == B[k])
        {
            k = k + 1;
            vec[j][k] = true;
        }
        else if (C[i] == A[j])
        {
            j = j + 1;
            vec[j][k] = true;
        }
    }
    // for (int i = 0; i <= Alen; i++)
    // {
    //     for (int j = 0; j <= Blen; j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return vec[Alen][Blen];
}
//XXXXX YYXYXYX XXYYXXXYXYYX
