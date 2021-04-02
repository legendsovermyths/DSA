// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main()
{

    vector<string> dict = {"i", "like", "sam", "sung", "samsung", "mobile",
                           "ice", "cream", "icecream", "man", "go", "mango"};
    string line = "ilike";
    cout << wordBreak(line, dict) << "\n";
}
// } Driver Code Ends

//User function template for C++

// A : given string to search
// B : vector of available strings
bool IsWordPresent(string A, vector<string> &B)
{
    int count = B.size();
    for (int i = 0; i < count; i++)
    {
        if (B[i] == A)
        {
            return true;
        }
    }
    return false;
}
void Solution(string A, vector<string> &B, int &count)
{
    if (count > 0)
    {
        return;
    }
    int n = A.length();
    if (A == "")
    {
        count += 1;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        string toCheck = A.substr(0, i);
        if (IsWordPresent(toCheck, B))
        {
            string newA = A.substr(i);
            cout << newA << " ";
            Solution(newA, B, count);
        }
    }
}
int wordBreak(string A, vector<string> &B)
{
    int count = 0;
    Solution(A, B, count);
    if (count > 0)
    {
        return true;
    }
    return false;
}