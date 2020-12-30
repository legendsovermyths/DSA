// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string findMaximumNum(string str, int k);

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        cout << findMaximumNum(str, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

string compareTwoStrings(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] - '0' > s2[i] - '0')
            return s1;
        if (s2[i] - '0' > s1[i] - '0')
            return s2;
    }
    return s1;
}
bool IsSwapIfeasible(char c, char r)
{
    if (c - '0' < r - '0')
        return true;
    return false;
}
string swap(string hell, int i, int j)
{
    string ne;
    ne = hell;
    char t = ne[i];
    ne[i] = ne[j];
    ne[j] = t;
    return ne;
}
void findMaxUtil(int swaps, vector<string> &allNumbers, string curr, int k, string &max)
{
    max = compareTwoStrings(max, curr);
    if (k == swaps)
    {
        return;
    }
    for (int i = 0; i < curr.length(); i++)
    {
        for (int j = i + 1; j < curr.length(); j++)
        {
            if (IsSwapIfeasible(curr[i], curr[j]))
            {
                string ne = swap(curr, i, j);
                findMaxUtil(swaps + 1, allNumbers, ne, k, max);
            }
        }
    }
}
string findMaximumNum(string str, int k)
{
    vector<string> allNumbers;
    allNumbers.push_back(str);
    string max = allNumbers[0];
    findMaxUtil(0, allNumbers, str, k, max);

    return max;
}