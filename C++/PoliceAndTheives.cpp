// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution
{
public:
    int catchThieves(char arr[], int n, int k)
    {
        vector<int> police;
        vector<int> thieves;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 'P')
                police.push_back(i);
            else
                thieves.push_back(i);
        }
        int i = 0, j = 0;
        int answer = 0;
        int T = thieves.size(), P = police.size();
        while (i < P && j < T)
        {
            if (abs(police[i] - thieves[j]) <= k)
            {
                answer++;
                i++;
                j++;
            }
            else if (police[i] > thieves[j])
                j++;
            else
                i++;
        }
        return answer;
    }
};

// { Driver Code Starts.
// T, T, P, P, T, P
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        char arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.catchThieves(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends