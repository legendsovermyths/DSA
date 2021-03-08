// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int AlternatingaMaxLength(vector<int> &nums)
    {
        int up = 0, down = 0;
        int count = 1;
        int n = nums.size();
        if (n == 1)
            return 1;
        bool currUP;
        bool found = false;
        int k = 0;
        while (!found && k < n - 1)
        {
            if (nums[k] > nums[k + 1])
            {
                up = nums[k];
                count = 1;
                currUP = true;
                found = true;
            }
            else if (nums[k] < nums[k + 1])
            {
                currUP = false;
                down = nums[k];
                found = true;
                count = 1;
            }
            else if (nums[k] == nums[k + 1])
            {
                k++;
            }
        }

        for (int i = k + 1; i < n; i++)
        {
            if (currUP == true)
            {
                if (nums[i] >= up)
                {
                    up = nums[i];
                }
                else
                {
                    down = nums[i];
                    currUP = false;
                    count++;
                }
            }
            else
            {
                if (nums[i] <= down)
                {
                    down = nums[i];
                }
                else
                {
                    up = nums[i];
                    currUP = true;
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.AlternatingaMaxLength(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends