// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

const int no_of_chars = 256;

string findSubString(string str);

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;

        cout << findSubString(str).size() << endl;
    }
    return 0;
}
// } Driver Code Ends

string findSubString(string str)
{
    // Your code goes here
}