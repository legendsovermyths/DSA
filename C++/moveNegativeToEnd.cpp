#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int getMinPositiveInt(int arr[], int length)
{
    int minIndex = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] >= 0)
        {
            minIndex = i;
            break;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (arr[i] >= 0)
        {
            if (arr[minIndex] >= arr[i])
            {
                minIndex = i;
            }
        }
    }
    return minIndex;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        int arr[num];
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        swap(&arr[getMinPositiveInt(arr, num)], &arr[num - 1]);
        partition(arr, 0, num - 1);
        for (int i = 0; i < num; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
