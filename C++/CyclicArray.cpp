#include <iostream>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int num1;
        cin >> num1;

        int arr1[num1];

        for (int i = 0; i < num1; i++)
        {
            cin >> arr1[i];
        }
        cout << arr1[num1 - 1] << " ";
        for (int i = 0; i < num1 - 1; i++)
        {
            cout << arr1[i] << " ";
        }
    }
    cout << "\n";
}