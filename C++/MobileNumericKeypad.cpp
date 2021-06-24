// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    void Calc(int N, int k, long long &count, vector<vector<char>> &Matrix, vector<int> x_steps, vector<int> y_steps, int curr_x, int curr_y, string answer, vector<string> &answers)
    {

        if (k == N)
        {
            count += 1;
            answers.push_back(answer);
            return;
        }
        for (int i = 0; i < 5; i++)
        {
            int new_x = x_steps[i] + curr_x;
            int new_y = y_steps[i] + curr_y;

            if (new_x >= 0 && new_y >= 0 && new_x < 4 && new_y < 3 && Matrix[new_x][new_y] != 'a')
            {
                string newAns = answer + Matrix[new_x][new_y];
                Calc(N, k + 1, count, Matrix, x_steps, y_steps, new_x, new_y, newAns, answers);
            }
        }
    }
    long long getCount(int N)
    {
        vector<int> x_steps = {1, -1, 0, 0, 0};
        vector<int> y_steps = {0, 0, 1, -1, 0};
        vector<vector<char>> Matrix = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'a', '0', 'a'}};
        long long total = 0;
        vector<string> answers;
        string answer = "";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Calc(N, 1, total, Matrix, x_steps, y_steps, i, j, answer + Matrix[i][j], answers);
            }
        }
        Calc(N, 1, total, Matrix, x_steps, y_steps, 3, 1, "0", answers);
        for (int i = 0; i < answers.size(); i++)
        {
            cout << answers[i] << endl;
        }
        cout << answers.size();
        return total;
    }
};

// { Driver Code Starts.
int main()
{

    int n = 25;

    Solution ob;
    cout << ob.getCount(n) << "\n";

    return 0;
}
// } Driver Code Ends