// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include <iostream>
#include <string.h>

using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
#include <unordered_map>
class Solution
{
public:
    // This function returns true if str1 and str2 are ismorphic
    // else returns false
    bool areIsomorphic(string str1, string str2)
    {
        unordered_map<char, char> umap;
        int count = str1.length();
        int count1 = str2.length();
        if (count != count1)
            return false;
        for (int i = 0; i < count; i++)
        {
            if (umap[str1[i]] == 0)
            {
                umap[str1[i]] = str2[i];
            }
            else if (umap[str1[i]] != str2[i])
            {
                return false;
            }
        }
        unordered_map<char, char> umap2;
        for (int i = 0; i < count; i++)
        {
            if (umap2[str2[i]] == 0)
            {
                umap2[str2[i]] = str1[i];
            }
            else if (umap2[str2[i]] != str1[i])
            {
                return false;
            }
        }

        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        Solution obj;
        cout << obj.areIsomorphic(s1, s2) << endl;
    }

    return 0;
} // } Driver Code Ends