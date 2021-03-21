// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
} // } Driver Code Ends

// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &str)
{
    unordered_map<char, int> umap;
    umap['I'] = 1;
    umap['V'] = 5;
    umap['X'] = 10;
    umap['L'] = 50;
    umap['D'] = 500;
    umap['M'] = 1000;
    umap['C'] = 100;
    int count = str.length();
    int answer = 0;
    int prev = umap[str[0]];
    for (int i = 0; i < count; i++)
    {
        answer = answer + umap[str[i]];
        if (prev < umap[str[i]])
        {
            answer = answer - 2 * prev;
        }
        prev = umap[str[i]];
    }
    return answer;
}