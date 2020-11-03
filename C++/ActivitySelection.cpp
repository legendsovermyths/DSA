#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class meeting
{
public:
    int startingPoint = 0;
    int endingPoint = 0;
    int index = 0;
};
bool sort_meeting(meeting meeting1, meeting meeting2)
{
    return meeting1.endingPoint < meeting2.endingPoint;
}
vector<int> solution(meeting arr[], int n)
{
    vector<int> solution_1;
    sort(arr, arr + n, sort_meeting);
    solution_1.push_back(arr[0].index);
    for (int i = 0; i < n - 1; i++)
    {

        if (arr[i].endingPoint <= arr[i + 1].startingPoint)
        {

            solution_1.push_back(arr[i + 1].index);
        }
        else
        {
            arr[i + 1] = arr[i];
        }
    }
    for (int j = 0; j < solution_1.size(); j++)
    {
        cout << solution_1[j] << " ";
    }
    return solution_1;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        meeting arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].startingPoint;
            arr[i].index = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].endingPoint;
        }
        solution(arr, n);
        cout << "\n";
    }
}