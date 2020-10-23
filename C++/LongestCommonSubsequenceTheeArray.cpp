#include <iostream>
using namespace std;
#include <algorithm>
int longestSub(int num1, int num2, int num3, int arr1[], int arr2[], int arr3[])
{
    int table[num1 + 1][num2 + 1][num3 + 1] = {};
    for (int i = 1; i <= num1; i++)
    {
        for (int j = 1; j <= num2; j++)
        {
            for (int k = 1; k <= num3; k++)
            {
                if (arr1[i - 1] == arr2[j - 1] && arr2[j - 1] == arr3[k - 1])
                {
                    table[i][j][k] = 1 + table[i - 1][j - 1][k - 1];
                }
                if (arr1[i - 1] != arr2[j - 1] || arr1[i - 1] != arr3[k - 1] || arr2[j - 1] != arr3[k - 1])
                {
                    table[i][j][k] = max(table[i - 1][j][k], max(table[i][j - 1][k], table[i][j][k - 1]));
                }
            }
        }
    }
    return table[num1][num2][num3];
}
int main()
{
    int num1;
    cin >> num1;
    int arr1[num1];
    for (int i = 0; i < num1; i++)
    {
        cin >> arr1[i];
    }
    int num2;
    cin >> num2;
    int arr2[num2];
    for (int i = 0; i < num2; i++)
    {
        cin >> arr2[i];
    }
    int num3;
    cin >> num3;
    int arr3[num3];
    for (int i = 0; i < num3; i++)
    {
        cin >> arr3[i];
    }
    cout << longestSub(num1, num2, num3, arr1, arr2, arr3);
}