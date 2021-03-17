// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int arr[], int n)
    {
        vector<int> walls;
        walls.push_back(arr[0]);
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > walls[k])
            {
                walls.push_back(arr[i]);
                k++;
            }
        }
        int currWall = walls[0];
        int r = walls.size();
        int index = 1;
        int boundWall;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == walls[index])
            {
                currWall = walls[index];
                index++;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends