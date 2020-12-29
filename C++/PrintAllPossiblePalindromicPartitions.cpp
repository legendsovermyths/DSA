#include <iostream>
using namespace std;
bool isPalindrome(string s)
{
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
void PalindromeUtil(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string s1 = s.substr(i, s.length() - 1);
        string s2 = s.substr(0, i);
        if (isPalindrome(s1))
        {
            cout << s1 << " ";
            PalindromeUtil(s2);
        }
    }
}
int main()
{
    PalindromeUtil("nitin");
}