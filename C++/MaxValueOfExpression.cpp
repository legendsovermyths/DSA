#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cal(int x, int y, char op)
{
    if (op == '+')
    {
        return x + y;
    }
    else if (op == '-')
    {
        return x - y;
    }
    return x * y;
}
int calcMin(vector<vector<int>> &m, vector<vector<int>> &M, int i, int j, vector<char> op)
{

    int min_value = 9999;
    int a = 0, b = 0, c = 0, d = 0;
    for (int k = i; k < j; k++)
    {
        a = cal(M[i][k], m[k + 1][j], op[k]);
        b = cal(m[i][k], m[k + 1][j], op[k]);
        c = cal(M[i][k], M[k + 1][j], op[k]);
        d = cal(m[i][k], M[k + 1][j], op[k]);
        min_value = min(a, min(b, min(c, min(d, min_value))));
    }

    return min_value;
}
int calcMax(vector<vector<int>> &m, vector<vector<int>> &M, int i, int j, vector<char> op)
{

    int max_value = -9999;
    int a = 0, b = 0, c = 0, d = 0;
    for (int k = i; k < j; k++)
    {
        a = cal(M[i][k], m[k + 1][j], op[k]);
        b = cal(m[i][k], m[k + 1][j], op[k]);
        c = cal(M[i][k], M[k + 1][j], op[k]);
        d = cal(m[i][k], M[k + 1][j], op[k]);
        max_value = max(a, max(b, max(c, max(d, max_value))));
    }

    return max_value;
}
int getThingsetUp(vector<int> operands, vector<char> op)
{
    vector<vector<int>> vec(operands.size(), vector<int>(operands.size(), 0));
    vector<vector<int>> vecM(operands.size(), vector<int>(operands.size(), 0));
    for (int r = 0; r < operands.size(); r++)
    {
        vec[r][r] = operands[r];
        vecM[r][r] = operands[r];
    }
    for (int s = 1; s < operands.size(); s++)
    {
        for (int i = 0; i < operands.size() - s; i++)
        {
            int j = i + s;
            vec[i][j] = calcMin(vec, vecM, i, j, op);
            vecM[i][j] = calcMax(vec, vecM, i, j, op);
        }
    }
    for (int s = 0; s < operands.size(); s++)
    {
        for (int i = 0; i < operands.size(); i++)
        {
            cout << vecM[s][i] << " ";
        }
        cout << "\n";
    }

    return vecM[0][operands.size() - 1];
}
int main()
{
    vector<char> op;
    vector<int> operands;

    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '-' || input[i] == '+' || input[i] == '*')
        {
            op.push_back(input[i]);
        }
        else
        {
            operands.push_back(input[i] - '0');
        }
    }
    cout << getThingsetUp(operands, op) << endl;
}