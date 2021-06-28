#include <bits/stdc++.h>
using namespace std;
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define loop(k, n) for (int k = 0; k < n; k++)
#define deb(x) cout << #x << "= " << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define Loop(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define ll long long
#define PI 3.1415926535897932384626
typedef vector<int> vi;
typedef vector<ll> vl;
bool isValid(vector<int> includedIndex, int j)
{
    for (int i = 0; i < includedIndex.size(); i++)
    {
        if (j == includedIndex[i])
        {
            return false;
        }
    }
    return true;
}

void SolutionUtil(int totalSum, int &minDif, vector<int> &sol, vector<int> answer, vector<int> &finalAns, vector<int> includedIndex)
{
    int sum = 0;
    for (int i = 0; i < answer.size(); i++)
    {
        sum += answer[i];
    }
    int diff = abs(totalSum / 2 - sum);
    if (diff < minDif)
    {
        minDif = diff;
        finalAns = answer;
    }

    for (int i = 0; i < sol.size(); i++)
    {
        if (isValid(includedIndex, i))
        {
            answer.push_back(sol[i]);
            includedIndex.push_back(i);
            SolutionUtil(totalSum, minDif, sol, answer, finalAns, includedIndex);
            answer.pop_back();
            includedIndex.pop_back();
        }
    }
}

int main()
{
    vector<int> sol = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    vector<int> includedIndex;
    vector<int> finalAns;
    vector<int> answer;
    int total = 0;
    for (int i = 0; i < sol.size(); i++)
    {
        total += sol[i];
    }
    int minDif = INT_MAX;
    SolutionUtil(total, minDif, sol, answer, finalAns, includedIndex);
    for (int i = 0; i < finalAns.size(); i++)
    {
        cout << finalAns[i] << " ";
    }
    cout << endl;
    return 0;
}