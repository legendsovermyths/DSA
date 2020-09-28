#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> arr, int key)
{
    int left = 0;
    int right = arr.size();
    int mid = int((left + right) / 2);
    while (left <= right)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
            mid = int((left + right) / 2);
        }
        else if (arr[mid] > key)
        {
            right = mid - 1;
            mid = int((left + right) / 2);
        }
    }
    return -1;
}
int main()
{
    vector<int> g1 = {1, 9, 13, 24, 65, 100, 1123, 1132};
    cout << binarySearch(g1, 65);

    return 0;
}