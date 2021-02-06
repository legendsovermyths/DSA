// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution
{
public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<vector<int>> startend(n, vector<int>(2, 0));
        int st, ed;
        for (int i = 0; i < n; i++)
        {
            if (gallery[i] != -1)
            {
                ed = gallery[i] + i;
                st = i - gallery[i];
                startend[i][0] = st;
                startend[i][1] = ed;
            }
            else
            {
                ed = INT_MIN;
                st = INT_MIN;
                startend[i][0] = st;
                startend[i][1] = ed;
            }
        }
        sort(startend.begin(), startend.end());
        int target = INT_MIN;
        int answer = 1;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            cout << startend[i][0] << ':' << startend[i][1] << " ";
            cout << endl;
        }

        while (j < n && startend[j][0] <= 0)
        {
            cout << j << ' ';
            if (target < startend[j][1])
                target = startend[j][1];
            j++;
        }
        if (target == INT_MIN)
            return -1;
        int prev = target;
        cout << endl;
        cout << target << endl;
        while (target < n)
        {
            while (j < n && startend[j][0] <= prev)
            {
                cout << j << ' ';
                if (target < startend[j][1])
                {
                    target = startend[j][1];
                }
                j++;
            }
            answer++;
            prev = target;
        }

        cout << "target: " << target;
        if (target < n - 1)
            return -1;

        return answer;
    }
};
// {-1, 2, 2, -1, 0, 0}
//{0,-1,0,0,4,5}
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int gallery[n];
        for (int i = 0; i < n; i++)
            cin >> gallery[i];
        Solution obj;
        cout << obj.min_sprinklers(gallery, n) << endl;
    }
}
// } Driver Code Ends
//2, 3, 4, -1, 0, 0, 0, 0, 0
// 2, 3, 4, -1, 2, 0, 0, -1, 0