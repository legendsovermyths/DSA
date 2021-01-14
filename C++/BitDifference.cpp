// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// Function to find number of bits to be flip
// to convert A to B
int countBitsFlip(int a, int b)
{

    int count = 0;
    int r1 = 0, r2 = 0;
    if (a % 2 != b % 2)
    {
        count++;
    }
    while (a != 0 || b != 0)
    {
        a = a / 2;
        b = b / 2;
        if (a % 2 != b % 2)
        {
            count++;
        }
    }

    return count;
}

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;   // input the testcases
    while (t--) //while testcases exist
    {
        int a, b;
        cin >> a >> b; //input a and b

        cout << countBitsFlip(a, b) << endl;
    }
    return 0;
} // } Driver Code Ends
  //0010100
  //1011100