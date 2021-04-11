#include <bits/stdc++.h>
using namespace std;
vector<long long> Solution(vector<long long> arr, int n)
{
    sort(arr.begin(), arr.end());
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    vector<long long> to_return;
    if (sum == arr[n])
    {
        for (int i = 0; i < n; i++)
        {
            to_return.push_back(arr[i]);
        }
        return to_return;
    }
    else
    {
        sum += arr[n];
        long long residue = sum - arr[n + 1];
        bool ok = true;
        for (int i = 0; i < n + 1; i++)
        {

            if (arr[i] == residue && ok)
            {
                ok = false;
            }
            else
            {
                to_return.push_back(arr[i]);
            }
        }
        if (to_return.size() != n + 1)
        {
            return to_return;
        }
    }
    to_return = {};
    to_return.push_back(-1);
    return to_return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n + 2, 0);
        for (int i = 0; i < n + 2; i++)
        {
            cin >> arr[i];
        }
        vector<long long> answer = Solution(arr, n);
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}