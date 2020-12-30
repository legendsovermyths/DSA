#include <iostream>
#include <vector>
using namespace std;
string convertToString(char *a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}
bool isPalindrome(string s)
{
    if (s.length() == 1)
        return false;
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
void PalindromeUtil(string s, vector<vector<string>> &allPart, vector<string> &cur, int &count)
{
    if (s.length() == 0)
    {
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string s1 = s.substr(i, s.length());
        string s2 = s.substr(0, i);
        if (isPalindrome(s1))
        {
            cout << s1 << " ";
            count += 1;
            PalindromeUtil(s2, allPart, cur, count);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<string>> All;
        vector<string> curr;
        int k;
        cin >> k;
        char l[k];
        for (int i = 0; i < k; i++)
        {
            cin >> l[i];
        }
        string s = convertToString(l, k);
        int count = 0;
        PalindromeUtil(s, All, curr, count);

        // for (int i = 0; i < All.size(); i++)
        // {
        //     for (int j = 0; j < All[i].size(); j++)
        //     {
        //         count++;
        //     }
        // }
        cout << count << endl;
    }
}