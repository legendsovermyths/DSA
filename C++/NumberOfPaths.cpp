// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool isValid(int i, int j, int M, int N)
{
    return i >= 0 && j >= 0 && i < M && j < N;
}
void SolutionUtil(int i, int j, int M, int N, long long int &count, int X_Move[], int Y_Move[])
{
    if (i == M - 1 && j == N - 1)
        count = count + 1;
    for (int k = 0; k < 2; k++)
    {
        int next_i = i + X_Move[k];
        int next_j = j + Y_Move[k];
        if (isValid(next_i, next_j, M, N))
        {
            SolutionUtil(next_i, next_j, M, N, count, X_Move, Y_Move);
        }
    }
}
long long numberOfPaths(int m, int n)
{
    long long count = 0;
    int X_Move[] = {1, 0};
    int Y_Move[] = {0, 1};
    SolutionUtil(0, 0, m, n, count, X_Move, Y_Move);
    return count;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> m >> n;
        cout << numberOfPaths(m, n) << endl;
    }
    return 0;
} // } Driver Code Ends