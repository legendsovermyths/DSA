// { Driver Code Starts
#include <bits/stdc++.h>
#include <string>

using namespace std;

vector<string> possibleWords(int a[], int n);

int main()
{

    int T;

    cin >> T; //testcases

    while (T--)
    { //while testcases exist
        int N;

        cin >> N; //input size of array

        int a[N]; //declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; //input the elements of array that are keys to be pressed
        }

        vector<string> res = possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends

//Complete this function

vector<string> possibleWords(int a[], int N)
{
}