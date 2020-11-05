#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool isValid(vector<vector<int>> &vact, int i, int j, vector<vector<bool>> &vis)
{
    int row = vact.size();
    int cols = vact[0].size();
    return i < row && j < cols && !vis[i][j] && vact[i][j] == 1 && i >= 0 && j >= 0;
}
class item
{
public:
    int index = 0;
    int weight = 1;
    int value = 1;
    int valuePerWeight = value / weight;
};
int main()
{
    item item1;
    item1.index = 1;
    item1.value = 100;
    item1.weight = 2;
    cout << item1.valuePerWeight;
}
void print()
{
    cout << "Hello";
    void print_2()
    {
        }
}