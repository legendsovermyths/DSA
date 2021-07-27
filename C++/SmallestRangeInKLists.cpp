// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends
// you are required to complete this function
// function should print the required range
class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i; i < k; i++)
        {
            pq.push({arr[i][0], i});
        }
        vector<int> idx(k, 0);
        int range = 1000;
        vector<int> answer;
        while (pq.size() == k)
        {
            pair<int, int> x = pq.top();
            answer.push_back(x.first);
            pq.pop();
            if (idx[x.second] + 1 < n)
            {
                pq.push({arr[x.second][idx[x.second] + 1], x.second});
            }
            idx[x.second] += 1;
        }
        for (int j = 0; j < answer.size(); j++)
        {
            cout << answer[j] << ' ';
        }
        cout << endl;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}

// } Driver Code Ends