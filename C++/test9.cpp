#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<char, char> umap;
    umap['A'] = 'C';
    bool x = umap['B'] == 0;
    cout << x << endl;
    return 0;
}