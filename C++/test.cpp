#include <iostream>
#include <vector>
using namespace std;
void vectorCheck(vector<vector<int>> checkThis)
{
    cout << checkThis.size();
}
int main()
{
    vector<vector<int>> g1 = {{1, 2, 3}};
    vectorCheck(g1);
    return 0;
}