#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{

    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int partition_r(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

int Kthmin(int arr[], int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1)
    {
        int pi = partition_r(arr, low, high);
        if (pi - low == k - 1)
            return arr[pi];
        if (pi - low > k - 1)
            return Kthmin(arr, low, pi - 1, k);

        return Kthmin(arr, pi + 1, high, k - pi + low - 1);
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int num;
        cin >> num;
        int arr[num];
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        int position_min;
        cin >> position_min;
        int len = sizeof(arr) / sizeof(arr[0]);
        cout << Kthmin(arr, 0, len - 1, position_min);
    }
}