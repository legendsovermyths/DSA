#include <bits/stdc++.h>
using namespace std;
int Solution(int k, vector<int> arr, int n)
{
    int mini = INT_MAX;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = temp + arr[j];
            }
            if (arr[i] + k < arr[j])
            {
                temp = temp + arr[j] - (arr[i] + k);
            }
        }
        if (temp < mini)
        {
            mini = temp;
        }
    }
    return mini;
}
int main()
{
    vector<int> arr = {1, 5, 1, 5, 5, 1};
    cout << Solution(3, arr, 6);
}