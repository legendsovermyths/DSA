#include <iostream>
#include <algorithm>
using namespace std;
class cans
{
public:
    long long int index;
    long long int number;
};
bool compareTwoNumber(cans *a, cans *b)
{
    if (a->number != b->number)
        return a->number > b->number;
    return false;
}
int main()
{
    unsigned long long int totalBullets = 0;
    int m;
    cin >> m;
    cans *arr[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new cans();
        cin >> arr[i]->number;
        arr[i]->index = i + 1;
    }
    sort(arr, arr + m, compareTwoNumber);
    for (int i = 0; i < m; i++)
    {
        totalBullets = totalBullets + (i)*arr[i]->number + 1;
    }
    cout << totalBullets << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << arr[i]->index << " ";
    }
}