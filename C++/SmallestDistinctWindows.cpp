// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

const int no_of_chars = 256;

string findSubString(string str);

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;

        cout << findSubString(str).size() << endl;
    }
    return 0;
}
// } Driver Code Ends

string findSubString(string str)
{
    vector<int> Visited(CHAR_MAX, 0);
    int counter = 0;
    int minWindow = INT_MAX;
    int totalDistinct = 0;
    unordered_map<char, int> umap;
    int size = str.length();
    for (int i = 0; i < size; i++)
    {
        if (umap[str[i]] == 0)
        {
            totalDistinct++;
            umap[str[i]] = 1;
        }
    }
    int start = 0;
    for (int i = 0; i < size; i++)
    {
        Visited[str[i]]++;
        if (Visited[str[i]] == 1)
        {
            counter++;
        }
        if (counter == totalDistinct)
        {
            while (Visited[str[start]] > 1)
            {
                if (Visited[str[start]] > 1)
                {
                    Visited[str[start]]--;
                    start++;
                }
            }
            minWindow = min(minWindow, i - start + 1);
        }
    }
    cout << minWindow << " ";
}