// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// function to swap odd and even bits
unsigned int swapBits(unsigned int n)
{
    while (n > 0)
    {

        n = n / 2;
    }
}

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; //testcases
    while (t--)
    {
        unsigned int n;
        cin >> n; //input n

        //calling swapBits() method
        cout << swapBits(n) << endl;
    }
    return 0;
} // } Driver Code Ends