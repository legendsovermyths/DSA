#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
string CountAndPrint(string s)
{
    vector<int> vec;
    char prev = s[0];
    int count = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == prev)
        {
            count++;
        }
        else
        {
            vec.push_back(count);
            prev = s[i];
            count = 1;
        }
    }
    vec.push_back(count);
    int j = 0;
    int k = 0;
    string str = "";
    while (k < vec.size())
    {
        str = str + to_string(vec[k]) + s[j];
        j = j + vec[k];
        k = k + 1;
    }
    return str;
}
void recursive(int n)
{
    if (n == 1)
    {
        cout << 1;
    }
    string s = "11";
    for (int i = 1; i < n - 1; i++)
    {
        cout << s << " ";
        s = CountAndPrint(s);
    }
    cout << s << endl;
}
int main()
{
    int t;
    cin >> t;
    recursive(t);
}