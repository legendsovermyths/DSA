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
bool sort_profit(job job1, job job2)
{
    return job1.profit > job2.profit;
}
bool sort_deadline(job job1, job job2)
{
    return job1.deadline > job2.deadline;
}
bool appointDeadline(job thisJob, vector<bool> &deadLineArr)
{
    bool checker = false;
    for (int i = 1; i <= thisJob.deadline; i++)
    {
        if (deadLineArr[thisJob.deadline - i])
        {
            deadLineArr[thisJob.deadline - i] = false;

            checker = true;
            break;
        }
    }
    if (checker)
        return true;
    return false;
}

void solution(job arr[], int n)
{
    int sum = 0;
    vector<int> deadline;
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        deadline.push_back(arr[i].deadline);
    }
    maxDeadline = *max_element(deadline.begin(), deadline.end());
    vector<bool> deadlineArr(maxDeadline + 1, true);
    sort(arr, arr + n, sort_profit);
    vector<int> containsAnswer;
    for (int j = 0; j < n; j++)
    {
        if (appointDeadline(arr[j], deadlineArr))
        {
            sum = sum + arr[j].profit;
            containsAnswer.push_back(1);
        };
    }
    cout << containsAnswer.size() << " " << sum << endl;
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