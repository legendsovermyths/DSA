#include <bits/stdc++.h>
using namespace std;
bool sorts(vector<int> vec1, vector<int> vec2)
{
    if (vec1[0] == vec2[0])
        return vec1[1] < vec2[1];
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
        if (intervals[i][1] >= intervals[j][0])
        {
            if (intervals[i][1] < intervals[j][1])
                i++;
            j++;
        }
        else
        {
            temp[0] = intervals[i][0];
            cout << "i: " << i << "k: " << k << " j: " << j;
            temp[1] = max(intervals[i][1], intervals[j][1]);
            solution.push_back(temp);
            i = j;
            j += 1;
        }
    }
    temp[0] = intervals[i][0];
    temp[1] = intervals[j - 1][1];
    solution.push_back(temp);
    return solution;
}
int main()
{
    vector<vector<int>> intervals = {{2, 3}, {2, 2}, {3, 3}, {1, 3}, {5, 7}, {2, 2}, {4, 6}};
    vector<vector<int>> sol = Solution(intervals);
    for (int i = 0; i < sol.size(); i++)
    {
        cout << "[" << sol[i][0] << "," << sol[i][1] << "] ";
    }
}
// [[1,3],[2,6],[8,10],[15,18]]
// [[1,4],[2,3]]
// [[2,3],[4,5],[6,7],[8,9],[1,10]]
// [[2,3],[2,2],[3,3],[1,3],[5,7],[2,2],[4,6]]