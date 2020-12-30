#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(string s)
{
    if (s.length() == 0)
        return false;
    int l = 0;
    int h = s.length() - 1;
    while (h > l)
    {
        if (s[l++] != s[h--])
        {
            return false;
        }
    }
    return true;
}
void PalindromeUtil(string s, vector<vector<string>> &allPart, vector<string> &cur)
{
    if (s.length() == 0)
    {
        allPart.push_back(cur);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string s1 = s.substr(i, s.length());
        string s2 = s.substr(0, i);
        if (isPalindrome(s1))
        {
            cur.push_back(s1);
            PalindromeUtil(s2, allPart, cur);
            cur.pop_back();
        }
    }
}
int main()
{
    vector<vector<string>> All;
    vector<string> curr;

    PalindromeUtil("aniina", All, curr);
    for (int i = 0; i < All.size(); i++)
    {
        for (int j = 0; j < All[i].size(); j++)
            cout << All[i][j] << " ";
        cout << "\n";
    }
}