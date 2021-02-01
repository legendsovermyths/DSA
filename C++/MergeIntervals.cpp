#include <bits/stdc++.h>
using namespace std;
bool sorts(vector<int> vec1, vector<int> vec2)
{
    return vec1[0] < vec2[0];
}
vector<vector<int>> Solution(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), sorts);
    int i = 0, j = 1, k = 0;
    vector<vector<int>> solution;
    vector<int> temp(2, 0);
    int count = intervals.size();
    while (j < count)
    {
        if (intervals[i][1] >= intervals[j][0] && intervals[i][1] >= intervals[j][1])
        {
            j++;
        }
        else if (intervals[i][1] >= intervals[j][0])
        {
            i++;
            j++;
        }
        else
        {
            temp[0] = intervals[k][0];
            temp[1] = intervals[i][1];
            solution.push_back(temp);
            i++;
            k = i;
            j += 1;
        }
    }
    temp[0] = intervals[k][0];
    temp[1] = intervals[i][1];
    solution.push_back(temp);
    return solution;
}
int main()
{
    vector<vector<int>> intervals = {{1, 4}, {1, 4}};
    vector<vector<int>> sol = Solution(intervals);
    for (int i = 0; i < sol.size(); i++)
    {
        cout << "[" << sol[i][0] << "," << sol[i][1] << "] ";
    }
}
// [[1,3],[2,6],[8,10],[15,18]]