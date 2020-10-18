#include <iostream>
using namespace std;
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
        int z = 0, o = 0, t = 0;
        for (int i = 0; i < num; i++)
        {
            if (arr[i] == 0)
                z++;
            if (arr[i] == 1)
                o++;
            if (arr[i] == 2)
                t++;
        }
        int sort_array[num];
        int count = 0;
        while (z--)
        {
            sort_array[count] = 0;
            count++;
        }
        while (o--)
        {
            sort_array[count] = 1;
            count++;
        }
        while (t--)
        {
            sort_array[count] = 2;
            count++;
        }
        for (int i = 0; i < num; i++)
        {
            cout << sort_array[i] << " ";
        }
        cout << "\n";
    }
}