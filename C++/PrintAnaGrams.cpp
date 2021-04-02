// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string>> Anagrams(vector<string> &string_list);

// } Driver Code Ends
//User function Template for C++
bool sort2(pair<string, int> p1, pair<string, int> p2)
{
    return p1.first < p2.first;
}
vector<vector<string>> Anagrams(vector<string> &string_list)
{
    vector<pair<string, int>> vec1;
    int count = string_list.size();
    for (int i = 0; i < count; i++)
    {
        pair<string, int> p;
        p.first = string_list[i];
        p.second = i;
        vec1.push_back(p);
    }
    for (int i = 0; i < count; i++)
    {
        sort(vec1[i].first.begin(), vec1[i].first.end());
    }
    sort(vec1.begin(), vec1.end(), sort2);
    vector<vector<string>> to_return;
    int n = 0;
    int index = 0;
    vector<string> vec;
    string curr = vec1[0].first;
    string prev = vec1[0].first;
    while (n < count && index < count)
    {
        while (prev == curr && index < count)
        {
            vec.push_back(string_list[vec1[index].second]);
            index++;
            if (index < count)
                curr = vec1[index].first;
        }
        if (index < count)
        {
            prev = vec1[index].first;
        }
        n = n + vec.size();
        to_return.push_back(vec);
        vec = {};
    }

    return to_return;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        vector<vector<string>> result = Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends