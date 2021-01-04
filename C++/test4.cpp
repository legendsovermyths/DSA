#include <iostream>
#include <vector>
#include <stack>
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
bool isValid(string l)
{
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
    std::cout << isValid("(())") << std::endl;
}