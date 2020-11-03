#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class job
{
public:
    int ID = 0;
    int deadline = 0;
    int profit = 0;
};
bool sort_deadline(job job1, job job2)
{
    return job1.profit > job2.profit;
}
bool sort_profit(job job1, job job2)
{
    return job1.deadline > job2.deadline;
}
void solution(job arr[], int n)
{
    int i = 0, sum = 0, j = 1;
    sort(arr, arr + n, sort_deadline);
    vector<int> containsAnswer;
    for (i = 0; i < n; i++)
    {
        cout << arr[i].deadline << " " << j << endl;
        if (arr[i].deadline >= j)
        {
            sum += arr[i].profit;
            j++;
        }
    }
    cout << j - 1 << " " << sum << endl;
    return;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        job arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].ID;
            cin >> arr[i].deadline;
            cin >> arr[i].profit;
        }
        solution(arr, n);
    }
    return 0;
}