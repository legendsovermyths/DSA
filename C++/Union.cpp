#include <iostream>
#include <unordered_map>
using namespace std;
int Union(int num1, int num2, int arr1[], int arr2[])
{
    int checker = num1;
    unordered_map<int, int> umap;
    for (int i = 0; i < num1; i++)
    {
        umap[arr1[i]] = 1;
    }
    for (int i = 0; i < num2; i++)
    {
        if (!umap[arr2[i]])
        {
            checker += 1;
        }
    }
    return checker;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int num1, num2;
        cin >> num1;
        cin >> num2;
        int arr1[num1], arr2[num2];
        for (int i = 0; i < num1; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < num2; i++)
        {
            cin >> arr2[i];
        }
        cout << Union(num1, num2, arr1, arr2) << endl;
    }
}
