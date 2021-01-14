// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// Function to count set bits in the given number x
// n: input to count the number of set bits
int bin(int n, int &checker)
{
    if (n == 0)
    {
        return 0;
    }
    if (n % 2 == 1)
    {
        checker = checker + 1;
        bin(n / 2, checker);
    }
    else
    {
        bin(n / 2, checker);
    }
}
int printBin(int n)
{
    if (n == 0)
    {
        return 0;
    }
    printBin(n / 2);
    cout << n % 2;
}
int countSetBits(int n)
{
    int checker = 0;
    int sum = 0;
    printBin(17);
    cout << endl;
    return sum;
}

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) //while testcases exist
    {
        int n;
        cin >> n; //input n

        cout << countSetBits(n) << endl; // print the answer
    }
    return 0;
}
// } Driver Code Ends