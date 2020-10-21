#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
int main()
{
    list<int> vec;
    unordered_map<int, int> umap;
    int i = 5;
    umap[1] = 0;
    umap[2] = 1;
    umap[3] = 1;
    umap[4] = 2;
    umap[5] = 4;
    umap[6] = 3;
    while (umap[i] != 0)
    {
        vec.push_front(umap[i]);
        i = umap[i];
    }
    while (!vec.empty())
    {
        cout << vec.front() << " ";
        vec.pop_front();
    }
}
//1,2,3,4,5,6
//0,1,1,2,3,2