#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &nums, int index, int n)
{
    int k = 1;
    for (int i = index; i < (index + n) / 2; i++)
    {
        int t = nums[i];
        nums[i] = nums[n - k];
        nums[n - k] = t;
        k++;
    }
}
void nextPermutation(vector<int> &nums)
{
    int count = nums.size();
    int firstDecreasing = -1;
    int index = 0;
    int jusbigger = 0;
    for (int i = count - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            firstDecreasing = nums[i];
            index = i;
            break;
        }
    }
    int prev = firstDecreasing;
    int nextIndex = index;
    for (int i = index + 1; i < count; i++)
    {
        if (firstDecreasing == -1)
            break;
        if (nums[i] <= firstDecreasing)
        {
            jusbigger = prev;
            nextIndex = i - 1;
            break;
        }
        if (i == count - 1 && nums[count - 1] > firstDecreasing)
        {
            nextIndex = count - 1;
        }
        prev = nums[i];
    }
    iter_swap(nums.begin() + index, nums.begin() + nextIndex);
    cout << nextIndex << ' ';
    if (index == nextIndex)
    {
        index = index - 1;
    }
    reverse(nums, index + 1, count);
    cout << index;
    cout << jusbigger << endl;
    cout << firstDecreasing << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
}

int main()
{
    vector<int> nums = {1, 5, 1};
    nextPermutation(nums);

    return 0;
}