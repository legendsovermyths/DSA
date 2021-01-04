#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
using namespace std;
bool isValid(string l)
{
    if (l == "")
        return false;
    stack<char> s;
    for (int i = 0; i < l.length(); i++)
    {
        if (l[i] == ')' && s.size() == 0)
            return false;
        else if (l[i] == ')')
            s.pop();
        else if (l[i] == '(')
            s.push('(');
    }
    if (s.size() != 0)
        return false;
    return true;
}
// void SolutionUtil(string l, set<string> &answers, int &minNumber)
// {
//     if (isValid(l) && minNumber <= l.length())
//     {

//         minNumber = l.length();
//         answers.insert(l);

//         return;
//     }
//     for (int i = 0; i < l.length(); i++)
//     {
//         if (l[i] == ')' || l[i] == '(')
//         {
//             string newS = l;
//             newS.erase(i, 1);
//             SolutionUtil(newS, answers, minNumber);
//         }
//     }
// }
int main()
{
    vector<string> answers2;
    set<string> s;
    string l = "(a)())()";
    string curr;
    int level = -1;
    queue<string> q;
    q.push(l);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (level == -1 || level == curr.length())
        {
            if (isValid(curr))
            {
                answers2.push_back(curr);
                level = curr.length();
            }
        }

        for (int i = 0; i < curr.length(); i++)
        {
            if (curr[i] == ')' || curr[i] == '(')
            {
                string ne = curr;
                ne.erase(i, 1);
                if (s.find(ne) == s.end())
                {
                    q.push(ne);
                    s.insert(ne);
                }
            }
        }
    }
    if (answers2.size() == 0)
        answers2.push_back("");

    return 0;
}